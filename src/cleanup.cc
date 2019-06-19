#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

void print_usage(const std::string& program_name) {
    std::cerr << "clean up white space into a single space char for each line" << std::endl;
    std::cerr << "Usage: " << program_name << " [filenames...]" << std::endl;
    std::cerr << "\tIf no filename is given, it is read from the standard input" << std::endl;
}

void cleanup(std::istream &istream) {
    std::string line;
    while (std::getline(istream, line)) {
        std::istringstream ss{line};
        std::vector<std::string> tokens{std::istream_iterator<std::string>{ss}, std::istream_iterator<std::string>{}};
        if (tokens.empty()) continue;
        std::cout << tokens.front();
        for (int i=1; i<tokens.size(); i++)
            std::cout << " " + tokens[i];
        std::cout << std::endl;
    }
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

    if (arguments.empty()) cleanup(std::cin);
    else for (const auto& file : arguments) {
        std::ifstream ifs{file};
        cleanup(ifs);
    }

    return EXIT_SUCCESS;
}