//
// Created by Young Mo Kang on 2019-06-19.
//

#include <iostream>
#include <vector>
#include <fstream>

void print_usage(const std::string& program_name) {
    std::cerr << "Write files to standard output sequentially" << std::endl;
    std::cerr << "Usage: " << program_name << " [filenames...]" << std::endl;
    std::cerr << "\tIf no filename is given, it is read from the standard input" << std::endl;
}

void cat(std::istream &istream) {
    std::string buffer(std::istreambuf_iterator<char>(istream), {});
    std::cout << buffer;
}

int main(int argc, const char** argv) {
    std::ios_base::sync_with_stdio(false);
    std::string program_name{argv[0]};
    std::vector<std::string> arguments(argc - 1);
    for (int i=0; i<argc-1; i++) arguments[i] = argv[i+1];
    for (const auto &arg : arguments) {
        if (arg == "--help" || arg == "-h") {
            print_usage(program_name);
            return EXIT_SUCCESS;
        } else if (!std::ifstream{arg}.good()) {
            std::cerr << "Error: no such file " << arg << std::endl;
            return EXIT_FAILURE;
        }
    }

    if (arguments.empty()) cat(std::cin);
    else for (const auto& file : arguments) {
            std::ifstream ifs{file};
            cat(ifs);
        }

    return EXIT_SUCCESS;
}