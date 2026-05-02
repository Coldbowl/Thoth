#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void to_base(long number, const int base, char* result) {
    const char digits[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz+/";
    char temp[64];
    int i = 0;

    while (number > 0) {
        temp[i++] = digits[number % base];
        number /= base;
    }

    int j = 0;
    while (i>0) {
        result[j++] = temp[--i];
    }
    result[j] = '\0'; // I'll be back...
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("I am Thoth, keeper of knowledge. Speak your query.\n");
        printf("  thoth base <number> <base>\n");
        printf("  thoth unit <value> <from> <to>\n");
        return 0;
    }


    if (strcmp(argv[1], "base") == 0) { // Why on earth would anyone make a function return 0 if the result is true?
        char *p1, *p2, *p3; // I don't like putting the asterisk after the identifier, but sometimes, you just gotta take it like a man!

        if (argc != 5) {
            printf("Even the Gods require proper sacrifice. Usage: thoth base <number> <from> <to>\n");
            return 1;
        }

        if (strstr(argv[2], ".") == NULL || strstr(argv[2], ",") == NULL) { // strstr returns a pointer to where the substring is found
            printf("Whole numbers only in base conversion. Thoth saves his wisdom on fractions for matters incomprehensible to the mortal mind.\n");
            return 1;
        }

        const long base = strtol(argv[3], &p1, 10);

        if (base < 2 || base > 64) {
            printf("Thoth recognises only bases 2 through 64. Do not test his patience.\n");
            return 1;
        }

        const long from = strtol(argv[3], &p1, 10);
        const long to = strtol(argv[4], &p2, 10);
        const long number = strtol(argv[2], &p3, (int)from);

        if (p3 == argv[2]) {
            printf("Thoth does not waste time with ineffective offerings. Thoth cannot decipher '%s' as a base %ld number.\n", argv[2], from);
            return 1;
        }

        char result[64];
        to_base(number, (int)to, result);

        if (result[0] == '\0') {
            printf("Thoth sees nothing. Was your cipher zero?");
            return 1;
        }

        printf("%s\n", result);
    }
    return 0;
}