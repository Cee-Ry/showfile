#include <cstdio>
#include <vector>
#include <fstream>
#include <string>

using vecStr = std::vector<std::string>;
using read = std::ifstream;

void readfile(vecStr &file);

int main(int argc, char *argv[]) {
    vecStr file_names;

    if (argc == 1) {
        printf("[FILENAME] or/and [OPTION] must be add\n");
        printf("Try 'show --help' or 'show -h' for more information\n");
        return 1;
    } else {
        for (int i = 1; i < argc; i++) {
            file_names.push_back(argv[i]);
        }
    }

    readfile(file_names);

    return 0;
}

void readfile(vecStr &file) {
    vecStr content;
    std::string line;
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
