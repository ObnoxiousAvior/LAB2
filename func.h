#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ENTRYPRINT "Name: %s; Price: %0.2f; Dose: %i;\n", arr[i].name, arr[i].price, arr[i].dose
#define NOT_FOUND "Couldn't find any matches\n\n"

typedef struct medicine{
	char name[40];
	float price;
	int dose;
}medicine;

void create(medicine **arr, int *n);
void write(medicine *arr, int n);
void read(medicine **arr, int *n);

void search(medicine *arr, int n);

int chooseCreationMethod();
int whereDatabase();
