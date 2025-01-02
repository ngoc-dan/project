#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include"function.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	loadFromFile();
    while (1) {
    	displayMenu();
        int choice;
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
                saveToFile();
                printf("du lieu duoc luu thanh cong!\n");
                pressToExitOrReturn();
                break;
            case 8:
            	system("cls");
                printf("thoat khoi chuong trinh ...\n");
                saveToFile();
                exit(0);
            default:
            	system("cls");
                printf("luu chon khong hop le.\n");
                pressToExitOrReturn();
        }
    }
	return 0;
}
