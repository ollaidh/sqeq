#include "reader_factory.h"

#include "cmd_reader.h"
#include "file_reader.h"

std::unique_ptr<Reader> createReader(int argc, const char **argv) {
    // no input arguments provided in command line:
    if (argc < 2) {
        throw std::invalid_argument("No input arguments! Please provide.");
    }
    // one input argument - path to file is provided in command line - use the reading from file realization of reader:
    if (argc == 2) {
        return std::make_unique<FileReader>(std::make_unique<std::ifstream>(argv[1]));
    }
    // more than one input argument provided in command line - use the reading from command line realization of reader:
    return std::make_unique<CommandlineReader>(argc, argv);
}
