#include <stdio.h>
#include <stdlib.h>
#include "func.h"


void create(medicine **arr, int *n)
{
	printf("Enter the amount of entries: ");
	scanf("%i", n);
	
	system("clear");
	
	if(*n<=0) return;
	
	*arr = (medicine *)calloc(*n, sizeof(medicine));
	
	if(!arr) return;
	
	for(int i = 0; i < *n; i++)
	{
		printf("Entry number %i:\n", i+1);
		printf("|Enter a name: ");
		scanf("%s", (*arr)[i].name);
		printf("|Enter a price: ");
		scanf("%f", &(*arr)[i].price);
		printf("|Enter a dose: ");
		scanf("%i", &(*arr)[i].dose);
		
		system("clear");
	};
	
}

void read(medicine **arr, int *n)
{
	FILE *file = fopen("DB.txt","r");
	if(!file) return;
	
	if(fscanf(file,"%d",n)!=1)
	{
		fclose(file);
		return;
	};
	
	*arr = (medicine *)calloc(*n, sizeof(medicine));
		
	for(int i = 0; i < *n; i++)
	{
		if(fscanf(file, "%s %f %i", (*arr)[i].name, &(*arr)[i].price, &(*arr)[i].dose)!=3) break;
	};
	
	fclose(file);
}

void write(medicine *arr, int n)
{
	if(n<=0) return;
	FILE *file = fopen("DB.txt","w");
	if(!file)
	{
		printf("COULDN'T OPEN FILE");
		return;
	};
	
	fprintf(file, "%i\n" ,n);
	
	for(int i = 0; i < n; i++)
	{
		fprintf(file, "%s %f %i\n" ,arr[i].name, arr[i].price, arr[i].dose);
	}
	fclose(file);
};
