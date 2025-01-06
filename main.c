#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include"function.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int choice;
	do{
		printMenuHome();
		printf("\tNhap lua chon : ");
		scanf("%d", &choice);
		printf("\n");
		fflush(stdin);
		switch(choice){
			case 1:
				system("cls");
				inputMenu();
				break;
			case 2:
				printExit();
				break;
			default:
				system("cls");
				printf("\tsai cu phap!\n");
				
		}
	}while(choice != 2);
	return 0;
}
