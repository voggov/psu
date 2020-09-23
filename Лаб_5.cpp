// Лаб_5.cpp: главный файл проекта.

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


using namespace System;

int   main(void)
{
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);
	int i,a,nzk;
	char mas[20];
	struct student
	{
		char famil[20];
		char name[20];
		int Nomzach;
	} stud[3];

	for(i=0;i<3;i++)
	{
		printf("vvedite familiy\n"); scanf ("%20s",stud[i].famil);
	}
	for(i=0;i<3;i++)
	{
		printf("vvedite name studenta %s\n",stud[i].famil); scanf ("%20s",stud[i].name);
	}
	for(i=0;i<3;i++)
	{
		printf("vvedite nomer zk %s %s\n",stud[i].famil,stud[i].name); scanf ("%d",&stud[i].Nomzach);
	}

	while (true) {
	system("cls");
	printf("nagmite cifru dlya poiska");
	printf("\n 1-familiya");
	printf("\n 2-name studenta");
	printf("\n 3-nomer zk\n");
	printf("\n 4-vihod\n");
	scanf("%d",&a);
	
	if (a == 1) {
		char search[20];
		printf("vvedite familiy: ");
		scanf("%20s",&search);
		for (int i=0;i<3;i++) {
			if (strcmp (stud[i].famil, search) == 0) 
				printf("%s %s %d \n" , stud[i].famil,stud[i].name,stud[i].Nomzach);
		}
		system("pause");
		
	
	
	}
	if (a == 2) {
		char search[20];
		printf("vvedite name: ");
		scanf("%20s",&search);
		for (int i=0;i<3;i++) {
			if (strcmp (stud[i].name, search) == 0) 
				printf("%s %s %d \n" , stud[i].famil,stud[i].name,stud[i].Nomzach);
		}
		system("pause");
		
	
	
	}
	if (a == 3) {
		 int search;
		printf("vvedite nomer zk: ");
		scanf("%d",&search);
		for (int i=0;i<3;i++) {
			if (stud[i].Nomzach == search) 
				printf("%s %s %d \n" , stud[i].famil,stud[i].name,stud[i].Nomzach);
		}
		system("pause");
		
	
	
	
	}
	if (a == 4) {
		break;	
	}
	}

	
} 

