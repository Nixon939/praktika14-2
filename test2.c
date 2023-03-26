#include <stdio.h>
#include <ctype.h>

int main() {
    FILE *input_file, *output_file;
    int c;
    int alphabet[26] = {0}; // массив для хранения количества каждой буквы алфавита
    
    input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Error open input.txt\n");
        return 1;
    }
    
    // считываем текст из файла и подсчитываем количество каждой буквы алфавита
    while ((c = fgetc(input_file)) != EOF) {
        if (isalpha(c)) {
            alphabet[tolower(c) - 'a']++;
        }
    }
    
    fclose(input_file);
    
    output_file = fopen("output.txt", "w");
    if (output_file == NULL) {
        printf("Error open output.txt\n");
        return 1;
    }
    
    // выводим буквы алфавита и их количество в файл output.txt
    for (int i = 0; i < 26; i++) {
        if (alphabet[i] > 0) {
            fprintf(output_file, "%c - %d\n", 'a' + i, alphabet[i]);
        }
    }
    
    fclose(output_file);
    
    return 0;
}
