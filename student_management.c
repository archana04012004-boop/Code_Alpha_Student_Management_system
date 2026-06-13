#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int roll;
    char name[50];
    float marks;
};

void addStudent() {
    FILE *fp = fopen("student.dat", "ab");
    struct Student s;

    printf("Enter Roll No: ");
    scanf("%d", &s.roll);

    printf("Enter Name: ");
    scanf("%s", s.name);

    printf("Enter Marks: ");
    scanf("%f", &s.marks);

    fwrite(&s, sizeof(s), 1, fp);
    fclose(fp);

    printf("Student Added Successfully!\n");
}

void displayStudents() {
    FILE *fp = fopen("student.dat", "rb");
    struct Student s;

    printf("\nRoll\tName\tMarks\n");

    while(fread(&s, sizeof(s), 1, fp)) {
        printf("%d\t%s\t%.2f\n", s.roll, s.name, s.marks);
    }

    fclose(fp);
}

void searchStudent() {
    FILE *fp = fopen("student.dat", "rb");
    struct Student s;
    int roll, found = 0;

    printf("Enter Roll No to Search: ");
    scanf("%d", &roll);

    while(fread(&s, sizeof(s), 1, fp)) {
        if(s.roll == roll) {
            printf("Found: %d %s %.2f\n", s.roll, s.name, s.marks);
            found = 1;
            break;
        }
    }

    if(!found)
        printf("Record Not Found\n");

    fclose(fp);
}

int main() {
    int choice;

    while(1) {
        printf("\n1.Add Student");
        printf("\n2.Display Students");
        printf("\n3.Search Student");
        printf("\n4.Exit");
        printf("\nEnter Choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayStudents();
                break;
            case 3:
                searchStudent();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid Choice");
        }
    }
}