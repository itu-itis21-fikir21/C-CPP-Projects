#include <stdio.h>
#include <stdlib.h>



typedef struct student_data {
    char name[26];
    char id[5];
    char letter_grade;
    int exams[3];
    int hws[3];

} STUDENT_DATA;

typedef enum bool {
    FALSE,
    TRUE
} BOOL;

// Fucntion Declarations
BOOL read_from_text_file(FILE *text_file, STUDENT_DATA *a_student);

BOOL write_into_binary_file(FILE *binary_file, STUDENT_DATA *a_student);

BOOL read_from_binary_file(FILE *binary_file, STUDENT_DATA *a_student);

BOOL write_into_text_file(FILE *text_file, STUDENT_DATA *a_student);

int main(int argc, char *argv[]) {
    //getting arguments
    if (argc != 4) {
        printf("Enter:\n");
        printf("%s ", argv[0]);
        printf("\"Source Text File Name\" ");
        printf("\"Destination Text File Name\" ");
        printf("\"Destination Binary File Name\" ");
        // source file name
        //destination text file name
        // destination binary file name
        return 1;
    }

    char *src_text_file_name = argv[1];
    char *dst_text_file_name = argv[2];
    char *binary_file_name = argv[3];

    STUDENT_DATA a_student;

    FILE *text_file;
    FILE *binary_file;

    // Read from txt, write into binary
    printf("\nRead from text file and write into file started...\n");
    // Open related file
    if (!(text_file = fopen(src_text_file_name, "r"))) {
        printf("\nCannot open %s\n", src_text_file_name);
        return 1;
    }
    if (!(binary_file = fopen(binary_file_name, "wb"))) {
        printf("\nCannot open %s\n", binary_file_name);
        return 1;
    }

    while (read_from_text_file(text_file, &a_student)) {
        write_into_binary_file(binary_file, &a_student);
    }
    // Call related function to read and write
    // Close related files
    fclose(text_file);
    fclose(binary_file);

    // Give information to the user
    printf("\nRead from text file and write into binary file completed!\n");

    // Read from binary, write into txt
    printf("\nRead from binary file and write into text file started...\n");
    // Open related file
    if (!(binary_file = fopen(binary_file_name, "rb"))) {
        printf("\nCannot open %s\n", binary_file_name);
        return 1;
    }
    if (!(text_file = fopen(dst_text_file_name, "w"))) {
        printf("\nCannot open %s\n", dst_text_file_name);
        return 1;
    }

    while (read_from_binary_file(binary_file, &a_student)) {
        write_into_text_file(text_file, &a_student);
    }
    // Call related function to read and write
    // Close related files
    fclose(text_file);
    fclose(binary_file);

    // Give information to the user
    printf("\nRead from binary file and write into text file completed!\n");
    // Open related file
    // Call related function to read and write
    // Close related files

    // Give information to the user

    // 2D array dynamic allocation example
    int **grades_matrix;
    // Get memory with malloc
    grades_matrix = (int **) malloc(5 * sizeof(int *));
    // Read src_text_file_name
    if (!(text_file = fopen(src_text_file_name, "r"))) {
        printf("\nCannot open %s\n", src_text_file_name);
        return 1;
    }
    // Fill the matrix with Exams and HW grades
    // rows are students; columns are Exams and HWs totally 6 grade
    for (int i = 0; i < 5; i++) {
        read_from_text_file(text_file, &a_student);
        grades_matrix[i] = (int *) malloc(6 * sizeof(int));
        for (int j = 0; j < 3; j++) {
            grades_matrix[i][j] = a_student.exams[j];
            grades_matrix[i][3 + j] = a_student.hws[j];
        }
    }
    // Print the 2D array
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 6; j++) {
            printf("%d ", grades_matrix[i][j]);
        }
        printf("\n");
    }
    // Free the memory
    for (int i = 0; i < 5; i++) {
        free(grades_matrix[i]);
    }
    free(grades_matrix);


    return 0;
}

BOOL read_from_text_file(FILE *text_file, STUDENT_DATA *a_student) {
    int amount_read;
    amount_read = fscanf(text_file, "%s %s %d %d %d %d %d %d %c", a_student->name, a_student->id, &a_student->exams[0],
                         &a_student->exams[1], &a_student->exams[2],
                         &a_student->hws[0], &a_student->hws[1], &a_student->hws[2], &a_student->letter_grade);

    if (amount_read == 9) return TRUE;
    else return FALSE;


}

BOOL write_into_binary_file(FILE *binary_file, STUDENT_DATA *a_student) {
    int amount_written;

    amount_written = fwrite(a_student, sizeof(STUDENT_DATA), 1, binary_file);
    if (amount_written != 1) return FALSE;
    else return TRUE;
}

BOOL read_from_binary_file(FILE *binary_file, STUDENT_DATA *a_student) {
    int amount_read;
    amount_read = fread(a_student, sizeof(STUDENT_DATA), 1, binary_file);

    if (amount_read == 1) return TRUE;
    else return FALSE;
}

BOOL write_into_text_file(FILE *text_file, STUDENT_DATA *a_student) {
    int amount_written = fprintf(text_file, "%-26s %-5s %3d %3d %3d %3d %3d %3d %c", a_student->name, a_student->id,
                                 a_student->exams[0], a_student->exams[1], a_student->exams[2],
                                 a_student->hws[0], a_student->hws[1], a_student->hws[2], a_student->letter_grade);

    if (amount_written < 0) return FALSE;
    else return TRUE;

}

