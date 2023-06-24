#include <errno.h>
#include <stdio.h>
#include <string.h>

void readFile(FILE *file, const char *filename, char *text) {
    file = fopen(filename, "r"); // opens the file
    if (file != NULL) {
        while (fgets(text, 200, file)) {
            printf("%s", text);
        }
        fclose(file);
    } else {
        printf("Could not find file!\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: readfile <file>\n");
        return 0;
    } else if (argc > 2) {
        printf("Too many arguments!\n");
        return 0;
    }

    FILE *farg;
    char str[200];
    char fname[50];
    strcpy(fname, argv[1]);
    readFile(farg, fname, str);

    return 0;
}
