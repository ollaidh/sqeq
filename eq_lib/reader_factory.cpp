#include "reader_factory.h"

#include <filesystem>

#include "cmd_reader.h"
#include "file_reader.h"

std::unique_ptr<Reader> createReader(int argc, const char **argv) {
    if (argc < 2) {
        throw std::invalid_argument("No input arguments! Please provide.");
    }
    if (argc == 2) {
        return std::make_unique<FileReader>(std::make_unique<std::ifstream>(argv[1]));
    }
    return std::make_unique<CommandlineReader>(argc, argv);
}
