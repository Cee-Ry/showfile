#include <cstdio>
#include <vector>
#include <fstream>
#include <string>

using vecStr = std::vector<std::string>;
using read = std::ifstream;

void readfile(vecStr &file, vecStr &content);

int main(int argc, char *argv[]) {
    vecStr file_contents;
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

    readfile(file_names, file_contents);

    return 0;
}

void readfile(vecStr &file, vecStr &content) {
    std::string line;
    for (int i = 0; i < file.size(); i++) {
        std::ifstream name(file.at(i));

        if (!name.is_open()) {
            printf("show: %s: No such File or Option\n", file.at(i).c_str());
            printf("Try 'show --help' or 'show -h' for more information\n");
            exit(1);
        } else {
            while (std::getline(name, line)) {
                content.push_back(line);
            }

            printf("=== %s ===\n\n", file.at(i).c_str());
            for (int j = 0; j < content.size(); j++) {
                printf("%s\n", content.at(j).c_str());
            }
        }
    }
}
