#include<stdio.h>
#include <ctype.h>
#include <string.h>
#include"function.h"
#include <windows.h> 

Student students[100];
int number = 0;

void displayMenu() {
	system("cls");
    printf("***Student Management System Using C***\n");
	printf("                  STUDENT MENU\n");
	printf("       =======================================\n");
	printf("       | [1] hien thi danh sach sinh vien.   |\n");
	printf("       |-------------------------------------|\n");
	printf("       | [2] them sinh vien vao danh sach.   |\n");
	printf("       |-------------------------------------|\n");
	printf("       | [3] sua  thong tin sinh vien tru id.|\n");
	printf("       |-------------------------------------|\n");
	printf("       | [4] xoa sinh vien.                  |\n");
	printf("       |-------------------------------------|\n");
	printf("       | [5] tim kiem sinh vien.             |\n");
	printf("       |-------------------------------------|\n");
	printf("       | [6] sap sep sinh vien theo ten.     |\n");
	printf("       |-------------------------------------|\n");
	printf("       | [7] luu lai danh sach hoc sinh.     |\n");
	printf("       |-------------------------------------|\n");
	printf("       | [8] Exit.                           |\n");
	printf("       =======================================\n");
	printf("\n");	
}

void displayStudents() {
	system("cls");
	int i; 
	printf("\n          --- Display All Students ---\n");
	printf("\nStudent list:\n");
	printf("=================================================================================");
    printf("\n| %-3s | %-20s | %-30s | %-15s |\n", "ID", "Name", "Email", "Phone");
    printf("=================================================================================\n");
    for ( i = 0; i < number; i++) {
        printf("| %-3d | %-20s | %-30s | %-15s |\n", students[i].id, students[i].name, students[i].email, students[i].phone);
        printf("---------------------------------------------------------------------------------\n");
    }
    printf("\n");
}

void addStudent() {
	system("cls");
    if (number >= 100) {
        printf("Error: danh sach sinh vien da day.\n");
        return;
    }
	printf("\n          --- Add a New Student ---\n");
    Student new_student;
    printf("moi ban nhap id: ");
    scanf("%d", &new_student.id);
    getchar();
    printf("moi ban nhap ten: ");
    fgets(new_student.name, 50, stdin);
    new_student.name[strcspn(new_student.name, "\n")] = 0;
    printf("moi ban nhap email: ");
    fgets(new_student.email, 50, stdin);
    new_student.email[strcspn(new_student.email, "\n")] = 0;
    printf("moi ban nhap phone: ");
    fgets(new_student.phone, 50, stdin);
    new_student.phone[strcspn(new_student.phone, "\n")] = 0;

    if (validateInput(new_student, 0)) {
        students[number++] = new_student;
        printf("hoc sinh duoc them thanh cong !\n");
    }
}

void editStudent() {
	system("cls");
	printf("\n          --- Update Student Information ---\n");
    int id;
    int i;
    printf("moi nhap id hoc sinh muon sua : ");
    scanf("%d", &id);
    getchar();

    for ( i = 0; i < number; i++) {
        if (students[i].id == id) {
            printf("Editing student: %s\n", students[i].name);
            Student updated_student = students[i];
            printf("nhap tem moi(de trong de giu nguyen): ");
            fgets(updated_student.name, 50, stdin);
            updated_student.name[strcspn(updated_student.name, "\n")] = 0;
            printf("nhap email moi: ");
            fgets(updated_student.email, 50, stdin);
            updated_student.email[strcspn(updated_student.email, "\n")] = 0;
            printf("nhap so dien thoai moi: ");
            fgets(updated_student.phone, 50, stdin);
            updated_student.phone[strcspn(updated_student.phone, "\n")] = 0;

            if (validateInput(updated_student, 1)) {
                students[i] = updated_student;
                printf("hoc sinh cap nhap thanh cong !\n");
            }
            return;
        }
    }

    printf("Error: khong tim thay id sinh vien.\n");
}

void deleteStudent() {
	system("cls");
	printf("\n          --- delete student information ---\n");
    int id;
    int i,j;
    printf("nhap id sinh vien muon xoa: ");
    scanf("%d", &id);
    getchar();

    for ( i = 0; i < number; i++) {
        if (students[i].id == id) {
            printf("ban co chac muon xoa sinh vien thu %s? (y/n): ", students[i].name);
            char confirm;
            scanf("%c", &confirm);
            getchar();

            if (confirm == 'y' || confirm == 'Y') {
                for ( j = i; j < number - 1; j++) {
                    students[j] = students[j + 1];
                }
                number--;
                printf("sinh vien duoc xoa thanh cong!\n");
            } else {
                printf("da huy xoa.\n");
            }
            return;
        }
    }

    printf("Error: khong co id hoc sinh.\n");
}

void searchStudentByName() {
	system("cls");
	printf("\n          --- Search student information ---\n");
    char query[50];
    int i;
    printf("nhap ten hoc sinh can tim: ");
    fgets(query, 50, stdin);
    query[strcspn(query, "\n")] = 0;

    printf("\nket qua tim kiem duoc la :\n");
    printf(" %-5s  %-20s  %-30s  %-15s\n", "ID", "Name", "Email", "Phone");
    printf("-------------------------------------------------------------\n");
    int found = 0;
    for ( i = 0; i < number; i++) {
        if (strstr(students[i].name, query) != NULL) {
            printf(" %-5d %-20s %-30s %-15s\n", students[i].id, students[i].name, students[i].email, students[i].phone);
            found = 1;
        }
    }
    if (!found) {
        printf("khong tim thay hoc sinh.\n");
    }
}

void sortStudentsByName() {
	system("cls");
	printf("\n          --- arrange students ---\n");
	int i,j;
    for ( i = 0; i < number - 1; i++) {
        for ( j = i + 1; j < number; j++) {
            if (strcmp(students[i].name, students[j].name) > 0) {
                Student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
    printf("hoc sinh duoc sap sep theo ten.\n");
    displayStudents();
}

int validateInput(Student new_student, int skip_id) {
    if (strlen(new_student.name) == 0 || strlen(new_student.email) == 0 || strlen(new_student.phone) == 0) {
        printf("Error: khong de trong.\n");
        return 0;
    }
   int i;
    for ( i = 0; i < number; i++) {
        if (!skip_id && students[i].id == new_student.id) {
            printf("Error: id bi trung lap.\n");
            return 0;
        }
        if (strcmp(students[i].email, new_student.email) == 0) {
            printf("Error: email bi trung lap.\n");
            return 0;
        }
        if (strcmp(students[i].phone, new_student.phone) == 0) {
            printf("Error: so dien thoai trung lap.\n");
            return 0;
        }
    }
    return 1;
}

void saveToFile() {
	system("cls");
    FILE *file = fopen("students.dat", "wb");
    if (file == NULL) {
        printf("Error: khong the luu tru vao file.\n");
        return;
    }
    fwrite(&number, sizeof(int), 1, file);
    fwrite(students, sizeof(Student), number, file);
    fclose(file);
}

void loadFromFile() {
    FILE *file = fopen("students.dat", "rb");
    if (file == NULL) {
        printf("khong tim thay du lieu.\n");
        return;
    }
    fread(&number, sizeof(int), 1, file);
    fread(students, sizeof(Student), number, file);
    fclose(file);
}
void pressToExitOrReturn() {
    char choice;
    printf("\n           [0] Exit      [1] Back to menu\n");
    scanf("%c", &choice);  
    getchar();  

    if (choice == '0') {
        printf("Exiting...\n");
        return 0; 
    } else if (choice == '1') {
    	
        return;
    } else {
        printf("lua chon khong hop le !\n");
        return;
    }
}
