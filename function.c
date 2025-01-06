#include<stdio.h>
#include <ctype.h>
#include <string.h>
#include"function.h"
#include <windows.h> 

Student students[100];
Teacher teachers[100];
int number = 0;
int numbers = 0;

void printMenuHome(){
	printf("\n");
	printf("\t   CHOOSE YOUR ROLE\n");
	printf("\t======================\n");
	printf("\t[1] Admin.\n");
	printf("\t[2] Exit the program.\n");
	printf("\t======================\n");
}

void printMenu(){
	printf("\n");
	printf("\t\tMENU\n");
	printf("\t======================\n");
	printf("\t[1] Student management.\n");
	printf("\t[2] teacher management.\n");
	printf("\t[3] Exit the menu.\n");
	printf("\t======================\n");
}

void inputMenu(){
	int choice;
	do{
		printMenu();
		printf("\tnhap lua chon cua ban : ");
		scanf("%d", &choice);
		printf("\n");
		fflush(stdin);
		switch(choice){
			case 1:
				system("cls");
				inputStudentMenu();
				break;
			case 2:
				system("cls");
				inputTeacherMenu();
				break;
			case 3:
				system("cls");
				break;
			default:
				printf("\tsai cu phap!\n");
		}
	}while(choice != 3);
}

void inputStudentMenu(){
	loadFromFileStudent();
	int choice;
    do {
    	displayMenuStudent();
        printf("Moi Ban nhap lua chon : ");
        scanf("%d", &choice);
        getchar(); 

        switch (choice) {
            case 1:
                displayStudents();
                pressToExitOrReturn();
                break;
            case 2:
                addStudent();
                pressToExitOrReturn();
                break;
            case 3:
                editStudent();
                pressToExitOrReturn();
                break;
            case 4:
                deleteStudent();
                pressToExitOrReturn();
                break;
            case 5:
                searchStudentByName();
                pressToExitOrReturn();
                break;
            case 6:
                sortStudentsByName();
                pressToExitOrReturn();
                break;
            case 7:
                saveToFileStudent();
                printf("du lieu duoc luu thanh cong!\n");
                pressToExitOrReturn();
                break;
            case 8:
                saveToFileStudent();
                break;
            default:
            	system("cls");
                printf("luu chon khong hop le.\n");
                pressToExitOrReturn();
        }
    }while(choice != 8);
}

void inputTeacherMenu(){
	loadFromFileTeacher();
	int choice;
    do{
    	displayMenuTeacher();
        
        printf("Moi Ban nhap lua chon : ");
        scanf("%d", &choice);
        getchar(); 

        switch (choice) {
            case 1:
                displayTeachers();
                pressToExitOrReturn();
                break;
            case 2:
                addTeacher();
                pressToExitOrReturn();
                break;
            case 3:
                editTeacher();
                pressToExitOrReturn();
                break;
            case 4:
                deleteTeacher();
                pressToExitOrReturn();
                break;
            case 5:
                searchTeacherByName();
                pressToExitOrReturn();
                break;
            case 6:
                saveToFileTeacher();
                printf("du lieu duoc luu thanh cong!\n");
                pressToExitOrReturn();
                break;
            case 7:
                saveToFileTeacher();
                break;
            default:
            	system("cls");
                printf("luu chon khong hop le.\n");
                pressToExitOrReturn();
        }
    }while(choice != 7);
}

void printExit(){
	printf("\t====Thank You======\n");
	printf("\t====See You Soon===");
	printf("\n");
}

void displayMenuStudent() {
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

void displayMenuTeacher() {
	system("cls");
    printf("***Student Management System Using C***\n");
	printf("                  TEACHER MENU\n");
	printf("       =======================================\n");
	printf("       | [1] hien thi danh sach giao vien.   |\n");
	printf("       |-------------------------------------|\n");
	printf("       | [2] them giao vien vao danh sach.   |\n");
	printf("       |-------------------------------------|\n");
	printf("       | [3] sua  thong tin giao vien tru id.|\n");
	printf("       |-------------------------------------|\n");
	printf("       | [4] xoa giao vien khoi danh sach.   |\n");
	printf("       |-------------------------------------|\n");
	printf("       | [5] tim kiem giao vien.             |\n");
	printf("       |-------------------------------------|\n");
	printf("       | [6] luu lai danh sach giao vien.     |\n");
	printf("       |-------------------------------------|\n");
	printf("       | [7] Exit.                           |\n");
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

void displayTeachers() {
	system("cls");
	int i; 
	printf("\n          --- Display All Teacher ---\n");
	printf("\nTeacher list:\n");
	printf("=================================================================================");
    printf("\n| %-3s | %-20s | %-30s | %-15s |\n", "ID", "Name", "Email", "Phone");
    printf("=================================================================================\n");
    for ( i = 0; i < numbers; i++) {
        printf("| %-3d | %-20s | %-30s | %-15s |\n", teachers[i].id, teachers[i].name, teachers[i].email, teachers[i].phone);
        printf("---------------------------------------------------------------------------------\n");
    }
    printf("\n");
}

void addStudent() {
	system("cls");
	int add=number;
    char choice[1];
	int i;
	char afterGmail[] = "@gmail.com";
	printf("\t\t**Add a new student**\n");
	addStudent:
	printf("\tEnter the ID: ");
	int check = 0;
	scanf("%d", &students[add].id);
	fflush(stdin);
	for(i = 0; i < number; i++){
		if(students[add].id == students[i].id||students[add].id < 1||students[add].id > 1000){
			check = 1;
		}
	}
	if(check != 1){
		addName:
		printf("\tnhap ten: ");
		fgets(students[add].name, sizeof(students[add].name), stdin);
		students[add].name[strcspn(students[add].name,"\n")] = '\0';
		for(i=0;i<strlen(students[add].name);i++){		
			if(students[add].name[i]== 32&&students[add].name[i+1]==32){
				printf("\tError: ten kong hop le.\n");
				goto addName;	
			}
			if(students[add].name[i] < 65 ||students[add].name[i] > 122){
				printf("\tError: ten kong hop le.\n");
				goto addName;	
			}
		}
		if(students[add].name[0]== 32||strlen(students[add].name) < 1){
			printf("\tError: ten kong hop le.\n");
			goto addName;	
		}
		addMail:
		printf("\tnhap email: ");
		fgets(students[add].email, sizeof(students[add].email), stdin);
		students[add].email[strcspn(students[add].email,"\n")] = '\0';
		int same = 0;
		for(i = 0; i < number; i++){
			if(strcmp(students[add].email, students[i].email) == 0){
				same = 1;
			}
		}
		if(same == 1){
			printf("\tError: email da ton tai.\n");
			goto addMail;
		}
		for(i=0;i<strlen(students[add].email);i++){		
			if(students[add].email[i]== 32){
				goto addMail;		
			}
		}
		int len = strlen(students[add].email);
		int emailLen = strlen(afterGmail);
		if (len <= emailLen){
			goto addMail;
		}
		if (strcmp(students[add].email + len - emailLen, afterGmail) != 0){
			goto addMail;
		}
		addPhone:
		printf("\tEnter the Phone: ");
		same = 0;
		fgets(students[add].phone, sizeof(students[add].phone), stdin);
		students[add].phone[strcspn(students[add].phone,"\n")] = '\0';
		for(i = 0; i < number; i++){
			if(strcmp(students[add].phone, students[i].phone) == 0){
				same = 1;
			}
		}
		if(same == 1){
			printf("\tError: This Phone is already exists.\n");
			goto addPhone;
		}
		for(i=0;i<strlen(students[add].phone);i++){		
			if(students[add].phone[i]== 32) {
				goto addPhone;		
			}
		}
		if (strlen(students[add].phone)!=10) {
	        goto addPhone;
	    }
	    for (i = 0; i < strlen(students[add].phone); i++){
	        if (students[add].phone[i] < '0' || students[add].phone[i] > '9'){
	            goto addPhone;
	        }
	    }
		(number)++;
		printf("\tthem sinh vien thanh cong!!\n");
		
	}else{
		printf("\tError: id da ton tai.\n");
		goto addStudent;
	}
}

void addTeacher() {
    system("cls");
    int add = numbers;
    char choice[1];
    int i;
    char afterGmail[] = "@gmail.com";
    printf("\t\t**Add a new teacher**\n");
	addTeacher:
    printf("\tnhap ID: ");
    int check = 0;
    scanf("%d", &teachers[add].id);
    fflush(stdin);
    for (i = 0; i < numbers; i++) {
        if (teachers[add].id == teachers[i].id || teachers[add].id < 1 || teachers[add].id > 1000) {
            check = 1;
        }
    }
    if (check != 1) {
    addName:
        printf("\tnhap ten: ");
        fgets(teachers[add].name, sizeof(teachers[add].name), stdin);
        teachers[add].name[strcspn(teachers[add].name, "\n")] = '\0';
        for (i = 0; i < strlen(teachers[add].name); i++) {        
            if (teachers[add].name[i] == 32 && teachers[add].name[i + 1] == 32) {
                printf("\tError: ten khong hop le.\n");
                goto addName;    
            }
            if (teachers[add].name[i] < 65 || teachers[add].name[i] > 122 ) {
                printf("\tError: ten khong hop le.\n");
                goto addName;    
            }
        }
        if (teachers[add].name[0] == 32 || strlen(teachers[add].name) < 1) {
            printf("\tError: ten khong hop le.\n");
            goto addName;    
        }
    	addMail:
        printf("\tNhap email: ");
        fgets(teachers[add].email, sizeof(teachers[add].email), stdin);
        teachers[add].email[strcspn(teachers[add].email, "\n")] = '\0';
        int same = 0;
        for (i = 0; i < numbers; i++) {
            if (strcmp(teachers[add].email, teachers[i].email) == 0) {
                same = 1;
            }
        }
        if (same == 1) {
            printf("\tError: Email da ton tai.\n");
            goto addMail;
        }
        for (i = 0; i < strlen(teachers[add].email); i++) {        
            if (teachers[add].email[i] == 32) {
                goto addMail;        
            }
        }
        int len = strlen(teachers[add].email);
        int emailLen = strlen(afterGmail);
        if (len <= emailLen) {
            goto addMail;
        }
        if (strcmp(teachers[add].email + len - emailLen, afterGmail) != 0) {
            goto addMail;
        }
    	addPhone:
        printf("\tNhap Phone: ");
        same = 0;
        fgets(teachers[add].phone, sizeof(teachers[add].phone), stdin);
        teachers[add].phone[strcspn(teachers[add].phone, "\n")] = '\0';
        for (i = 0; i < number; i++) {
            if (strcmp(teachers[add].phone, teachers[i].phone) == 0) {
                same = 1;
            }
        }
        if (same == 1) {
            printf("\tError: so dien thoai da ton tai.\n");
            goto addPhone;
        }
        for (i = 0; i < strlen(teachers[add].phone); i++) {        
            if (teachers[add].phone[i] == 32) {
                goto addPhone;        
            }
        }
        if (strlen(teachers[add].phone) != 10) {
            goto addPhone;
        }
        for (i = 0; i < strlen(teachers[add].phone); i++) {
            if (teachers[add].phone[i] < '0' || teachers[add].phone[i] > '9') {
                goto addPhone;
            }
        }
        (numbers)++;
        printf("\tTeacher duoc them thanh cong!!\n");
    } else {
        printf("\tError: ID da ton tais.\n");
        goto addTeacher;
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
            printf("sua sinh vien : %s\n", students[i].name);
            Student updated_student = students[i];
            printf("nhap ten moi(de trong de giu nguyen): ");
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

void editTeacher() {
    system("cls");
    printf("\n          --- Update Teacher Information ---\n");
    int id;
    int i;
    printf("Please enter the ID of the teacher you want to edit: ");
    scanf("%d", &id);
    getchar();
    for (i = 0; i < numbers; i++) {
        if (teachers[i].id == id) {
            printf("Editing teacher: %s\n", teachers[i].name);
            Teacher updated_teacher = teachers[i];
            printf("Enter new name (leave blank to keep the same): ");
            fgets(updated_teacher.name, 50, stdin);
            updated_teacher.name[strcspn(updated_teacher.name, "\n")] = 0;
            printf("Enter new email: ");
            fgets(updated_teacher.email, 50, stdin);
            updated_teacher.email[strcspn(updated_teacher.email, "\n")] = 0;
            printf("Enter new phone number: ");
            fgets(updated_teacher.phone, 50, stdin);
            updated_teacher.phone[strcspn(updated_teacher.phone, "\n")] = 0;

            if (validateInput(updated_teacher, 1)) {
                teachers[i] = updated_teacher;
                printf("Teacher information successfully updated!\n");
            }
            return;
        }
    }

    printf("Error: Teacher ID not found.\n");
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

void deleteTeacher() {
    system("cls");
    printf("\n          --- Delete Teacher Information ---\n");
    int id;
    int i, j;
    printf("Nhap ID giao vien muon xoa: ");
    scanf("%d", &id);
    getchar();

    for (i = 0; i < numbers; i++) {
        if (teachers[i].id == id) {
            printf("Ban co chac muon xoa giao vien '%s'? (y/n): ", teachers[i].name);
            char confirm;
            scanf("%c", &confirm);
            getchar();

            if (confirm == 'y' || confirm == 'Y') {
                for (j = i; j < numbers - 1; j++) {
                    teachers[j] = teachers[j + 1];
                }
                numbers--;
                printf("Giao vien duoc xoa thanh cong!\n");
            } else {
                printf("Da huy xoa.\n");
            }
            return;
        }
    }

    printf("Error: Khong co ID giao vien.\n");
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
    printf("==================================================================================\n");
    printf("| %-5s | %-20s | %-30s | %-15s|\n", "ID", "Name", "Email", "Phone");
    printf("==================================================================================\n");
    int found = 0;
    for ( i = 0; i < number; i++) {
        if (strstr(students[i].name, query) != 0) {
            printf("| %-5d | %-20s | %-30s | %-15s|\n", students[i].id, students[i].name, students[i].email, students[i].phone);
            printf("----------------------------------------------------------------------------------\n");
            found = 1;
        }
    }
    if (!found) {
    	printf("============================================\n");
        printf("||khong tim thay hoc sinh trong danh sach.||\n");
        printf("============================================\n");
    }
}

void searchTeacherByName() {
    system("cls");
    printf("\n          --- Search Teacher Information ---\n");
    char query[50];
    int i;
    printf("Nhap ten giao vien can tim: ");
    fgets(query, 50, stdin);
    query[strcspn(query, "\n")] = 0;

    printf("\nKet qua tim kiem duoc la:\n");
    printf(" %-5s  %-20s  %-30s  %-15s\n", "ID", "Name", "Email", "Phone");
    printf("-------------------------------------------------------------\n");
    int found = 0;
    for (i = 0; i < numbers; i++) {
        if (strstr(teachers[i].name, query) != 0) {
            printf(" %-5d %-20s %-30s %-15s\n", teachers[i].id, teachers[i].name, teachers[i].email, teachers[i].phone);
            found = 1;
        }
    }
    if (!found) {
        printf("Khong tim thay giao vien.\n");
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

void saveToFileStudent() {
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

void saveToFileTeacher() {
    system("cls");
    FILE *file = fopen("teachers.dat", "wb");
    if (file == NULL) {
        printf("Error: khong the luu tru vao file.\n");
        return;
    }
    fwrite(&numbers, sizeof(int), 1, file);
    fwrite(teachers, sizeof(Teacher), numbers, file);
    fclose(file);
}

void loadFromFileStudent() {
    FILE *file = fopen("students.dat", "rb");
    if (file == NULL) {
        printf("khong tim thay du lieu.\n");
        return;
    }
    fread(&number, sizeof(int), 1, file);
    fread(students, sizeof(Student), number, file);
    fclose(file);
}

void loadFromFileTeacher() {
    FILE *file = fopen("teachers.dat", "rb");
    if (file == NULL) {
        printf("No data found.\n");
        return;
    }
    fread(&numbers, sizeof(int), 1, file);
    fread(teachers, sizeof(Teacher), numbers, file);
    fclose(file);
}

void pressToExitOrReturn() {
    char choice;
    printf("\n           [0] Exit      [1] Back to menu\n");
    scanf("%c", &choice);  
    getchar();  

    if (choice == '0') {
        printf("Exiting...\n");
        return ; 
    } else if (choice == '1') {
    	
        return;
    } else {
        printf("lua chon khong hop le !\n");
        return;
    }
}
