#include "func.h"

extern medicine *arr; // Extern keyword means that the variable is initialized somewhere else in the linked files
	
extern int n;

void create(medicine **arr, int *n)
{

	printf("Enter the amount of entries: ");
	scanf("%i", n);
	
	system("clear");
	
	if(*n<=0) return;
	
	*arr = (medicine *)calloc(*n, sizeof(medicine)); // Allocate memory for arr of the size *n * sizeof(medicine)
	
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
	
	fprintf(file, "%i\n", n);
	
	for(int i = 0; i < n; i++)
	{
		fprintf(file, "%s %f %i\n" ,arr[i].name, arr[i].price, arr[i].dose);
	}
	
	fclose(file);
}


int whereDatabase()
{
	int key;
	printf("Couldn't find the database. Would you like to create one?\n|1 - Yes\n|2 - No\n");
	scanf("%i", &key);
	
	system("clear");
	
	if(key==1)
	{
		if (!chooseCreationMethod()) return 0; // ERROR
	}
	else
	{
		return 1; // STOP
	}
	return 2; // SUCCESS
}

int chooseCreationMethod()
{
	int key;
	
	printf("Do you want to:\n|1. Write the new one \n|2. Load an existing one from a file\n");
	scanf("%i", &key);
	
	system("clear");
	
	if (key==1){
		
		create(&arr, &n);
		
		if(!arr){
			printf("!ERROR CREATING THE DATABASE!\n\n");
			
			while((getchar())!='\n'); //clearing the input stream of useless stuff left from error
			
			return 0;
		}
		else printf("Created %d entries\n\n", n);

		write(arr,n);
		
		return 1;
	}
	else if (key==2){
	
		read(&arr, &n);
		
		if(!arr){
			printf("ERROR READING THE DATABASE\n\n");
			return 0;
		}
		else printf("Loaded %d entries\n\n", n);
	}
		return 1;
	}
}
