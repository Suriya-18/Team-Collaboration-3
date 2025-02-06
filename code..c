#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY 0x5A // Simple XOR encryption key

void encrypt_decrypt(const char *input_file, const char *output_file) {
    FILE *fin = fopen(input_file, "rb");
    FILE *fout = fopen(output_file, "wb");
    
    if (!fin || !fout) {
        printf("Error opening files!\n");
        return;
    }
    
    int ch;
    while ((ch = fgetc(fin)) != EOF) {
        fputc(ch ^ KEY, fout); // XOR encryption/decryption
    }
    
    fclose(fin);
    fclose(fout);
    printf("Operation completed successfully!\n");
}

int main() {
    char input_file[256], output_file[256], choice;
    
    printf("Enter input file name: ");
    scanf("%s", input_file);
    
    printf("Enter output file name: ");
    scanf("%s", output_file);
    
    printf("Encrypt (E) or Decrypt (D)? ");
    scanf(" %c", &choice);
    
    if (choice == 'E' || choice == 'e') {
        encrypt_decrypt(input_file, output_file);
    } else if (choice == 'D' || choice == 'd') {
        encrypt_decrypt(input_file, output_file);
    } else {
        printf("Invalid choice!\n");
    }
    
    return 0;
}
