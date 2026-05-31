#include <cstdio>
#include <vector>
#include <fstream>
#include <string>

void readfile(std::vector<std::string> &file, const bool &lineNum);
void help();

int main(int argc, char *argv[]) {
    std::vector<std::string> file_names;
    bool lineNum {};

    if (argc == 1) {
        fprintf(stderr, "[FILENAME] or/and [OPTION] must be added\n");
        fprintf(stderr, "Try 'show --help' or 'show -h' for more information\n");
        return 1;
    } else {
        for (int i = 1; i < argc; i++) {
            if (argv[i] == std::string("-h") || argv[i] == std::string("--help")) {
                help();
                return 0;
            } else if (argv[i] == std::string("-n") || argv[i] == std::string("--number")) {
                lineNum = true;
                continue;
            } else if (argv[i][0] == '-') {
                fprintf(stderr, "show: invalid option '%s'\n", argv[i]);
                fprintf(stderr, "Try 'show --help' or 'show -h' for more information\n");
                return 1;
            } else {
                file_names.push_back(argv[i]);
            }
        }

        if (file_names.empty()) {
            fprintf(stderr, "[FILENAME] must be added\n");
            fprintf(stderr, "Try 'show --help' or 'show -h' for more information\n");
            return 1;
        }
    }

    readfile(file_names, lineNum);

    return 0;
}

void readfile(std::vector<std::string> &file, const bool &lineNum) {
    for (const auto &filename : file) {
        std::ifstream name(filename);

        if (!name.is_open()) {
            fprintf(stderr, "show: %s: No such File or Directory\n", filename.c_str());
            continue;
        } else {
            std::string line;
            int lnum {1};
            printf("\n\t=== %s ===\n", filename.c_str());
            while (std::getline(name, line)) {
                if (lineNum) {
                    printf("%5d  %s\n", lnum, line.c_str());
                    ++lnum;
                } else printf("%s\n", line.c_str());
            }
            printf("\n");
        }
    }
}

void help() {
    printf("\n\t=== Help ===\n");
    printf("Usage: show [OPTION]... [FILENAME]...\n");
    printf("Print the content of FILENAME to standard output.\n\n");
    printf("Options:\n");
    printf("  -n, --number\t\tAdd line numbers before each line\n");
    printf("  -h, --help\t\tShow this help message and exit\n");
    printf("\nExamples:\n");
    printf("  show file.txt\t\tPrint the content of file.txt\n");
    printf("  show -h\t\tShow this help message and exit\n");
}
