#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define LENGTH_OF_FILE 1665
#define tc_clear_screen()                                                      \
    puts("\x1B[2J");                                                           \
    printf("\033[%d;%dH", 0, 0);

char *remove_quotes(char *str) {
    if (str == NULL || str[0] == '\0') {
        return str;
    }

    int len = strlen(str);

    if (str[0] == '"') {
        str++;
        len--;
    }

    while (len > 0 && str[len - 1] == '"') {
        str[len - 1] = '\0';
        len--;
    }
    return str;
}

int main() {
    srand(time(NULL));
    tc_clear_screen();
    int randNum = rand() % LENGTH_OF_FILE + 1;
    FILE *fp = fopen("quotes.csv", "r");
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }
    char *auther;
    char line[256];
    for (int i = 0; i < randNum; i++) {
        if (fgets(line, 256, fp) == NULL) {
            fprintf(stderr, "Invalid file length\n");
            fclose(fp);
            return 1;
        }
    }
    char *split = strstr(line, "\",\"");
    if (split == NULL) {
        fprintf(stderr, "Error parsing csv file\n");
        fclose(fp);
        return 1;
    }
    *split = '\0';
    auther = remove_quotes(line);
    if (strlen(auther) == 0) {
        auther = "Unknown";
    }

    char *quote = split + 3;
    quote[strcspn(quote, "\n")] = '\0';
    quote = remove_quotes(quote);
    printf("%s\n", quote);
    printf("\n- %s\n", auther);
    fclose(fp);
    return 0;
}
