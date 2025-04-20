#include <stdio.h>
#include <stdlib.h>

void createFile(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error creating file. Please check your permissions.\n");
        return;
    }
    fprintf(file, "This is the initial content of the file.\n");
    fclose(file);
    printf("Successfully created the file: %s\n", filename);
}

void readFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error reading file. It may not exist yet.\n");
        return;
    }
    char ch;
    printf("Reading content of the file:\n");
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }
    fclose(file);
    printf("\nFinished reading the file.\n");
}

void writeFile(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file for writing. Please check your permissions.\n");
        return;
    }
    printf("Enter new content (end with Ctrl+D on Unix or Ctrl+Z on Windows):\n");
    char input[256];
    while (fgets(input, sizeof(input), stdin) != NULL) {
        fprintf(file, "%s", input);
    }
    fclose(file);
    printf("Successfully wrote new content to the file: %s\n", filename);
}

void appendToFile(const char *filename) {
    FILE *file = fopen(filename, "a");
    if (file == NULL) {
        printf("Error opening file for appending. Please check your permissions.\n");
        return;
    }
    printf("Enter content to append (end with Ctrl+D on Unix or Ctrl+Z on Windows):\n");
    char input[256];
    while (fgets(input, sizeof(input), stdin) != NULL) {
        fprintf(file, "%s", input);
    }
    fclose(file);
    printf("Successfully appended content to the file: %s\n", filename);
}

int main() {
    const char *filename = "example.txt";
    int choice;

    while (1) {
        printf("\nFile Operations Menu\n");
        printf("1. Create a file\n");
        printf("2. Read a file\n");
        printf("3. Write to a file\n");
        printf("4. Append to a file\n");
        printf("5. Exit\n");
        printf("Choose an operation (1-5): ");
        scanf("%d", &choice);
        getchar();  // Clear newline character left by scanf

        switch (choice) {
            case 1:
                createFile(filename);
                break;
            case 2:
                readFile(filename);
                break;
            case 3:
                writeFile(filename);
                break;
            case 4:
                appendToFile(filename);
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice! Please choose between 1 and 5.\n");
        }
    }

    return 0;
}
