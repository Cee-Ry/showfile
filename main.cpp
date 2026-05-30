#include <cstdio>
#include <vector>
#include <fstream>
#include <string>

using str = std::string;
using vecStr = std::vector<str>;

void readfile(vecStr &file);
void help();

int main(int argc, char *argv[]) {
    vecStr file_names;

    if (argc == 1) {
        printf("[FILENAME] or/and [OPTION] must be added\n");
        printf("Try 'show --help' or 'show -h' for more information\n");
        return 1;
    } else {
        for (int i = 1; i < argc; i++) {
            file_names.push_back(argv[i]);

            if (argv[i] == str("-h") || argv[i] == str("--help")) {
                help();
                return 0;
            }
        }
    }

    readfile(file_names);

    return 0;
}

void readfile(vecStr &file) {
    vecStr content;
    str line;
    for (const auto &filename : file) {
        std::ifstream name(filename);

        if (!name.is_open()) {
            printf("show: %s: No such File or Option\n", filename.c_str());
            printf("Try 'show --help' or 'show -h' for more information\n");
            exit(1);
        } else {
            content.clear();
            while (std::getline(name, line)) content.push_back(line);

            printf("\n=== === %s === ===\n", filename.c_str());
            for (const auto &eachline : content) {
                printf("%s\n", eachline.c_str());
            }
            printf("\n");
        }
    }
}

void help() {
    printf("\n=== === Help === ===\n");
    printf("Usage: show [OPTION]... [FILENAME]...\n");
    printf("Print the content of FILENAME to standard output.\n\n");
    printf("Options:\n");
    printf("  -h, --help\t\tShow this help message and exit\n");
    printf("\nExamples:\n");
    printf("  show file.txt\t\tPrint the content of file.txt\n");
    printf("  show -h\t\tShow this help message and exit\n");
}
