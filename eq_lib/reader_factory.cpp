#include "reader_factory.h"

#include <filesystem>

#include "cmd_reader.h"
#include "file_reader.h"

std::unique_ptr<Reader> createReader(int argc, const char **argv) {
    if (argv[1] == std::string_view("L") ||
        argv[1] == std::string_view("Q") ||
        argv[1] == std::string_view("C")) {
        return std::make_unique<CommandlineReader>(argc, argv);
    }
    if (std::filesystem::exists(argv[1])) {
        return std::make_unique<FileReader>(std::make_unique<std::ifstream>(argv[1]));
    }
    return nullptr;
}
