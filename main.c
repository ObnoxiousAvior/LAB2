#include <stdio.h>
#include <stdlib.h>
#include "func.h"

int main()
{
	system("clear"); //Clearing the contents of the terminal
	
	medicine *arr = NULL;
	int n = 0;
	
	int stopCycle = 1;
	
	int tempKey = 0;
	
	while(stopCycle){
		int key = 0;
		
		key += tempKey;
		tempKey = 0;
		
		if (!key)
		{
			printf("What would you like to do?\n|1. Create a database \n|2. Print the database \n|3. Search in the database\n|0. Exit the program\n");
			scanf("%i", &key);
		}
		system("clear");
		
		switch (key)
		{
			case 1:{
				int key2;
				
				printf("Do you want to:\n|1. Write the new one \n|2. Load an existing one from a file\n");
				scanf("%i", &key2);
				
				system("clear");
				
				if (key2==1) {	
					create(&arr, &n);
					if(!arr) 
					{
						printf("!ERROR CREATING THE DATABASE!\n");
						stopCycle = 0;
						break;
					}
					else
					{
						printf("Created %d entries\n\n", n);
					}
					write(arr,n);
					}
				else if(key2==2){
					read(&arr, &n);
					if(!arr) 
					{
						printf("ERROR READING THE DATABASE\n");
						stopCycle = 0;
						break;
					}
					else
					{
						printf("Loaded %d entries\n\n", n);
					}
				}
				break;
			}
			case 2:
				if(!arr) 
					{
						int key3;
						printf("Couldn't find the database. Would you like to create one?\n|1 - Yes\n|2 - No\n");
						scanf("%i", &key3);
						if(key3==1) tempKey=1;
						else stopCycle = 0;
						break;
					}
					else
					{
						for(int i = 0; i<n; i++) printf("Name: %s; Price: %0.2f; Dose: %i;\n", arr[i].name, arr[i].price, arr[i].dose);
						printf("%c",'\n');
					}
				
				break;
			case 3:
				if(!arr) 
					{
						int key3;
						printf("Couldn't find the database. Would you like to create one?\n|1 - Yes\n|2 - No\n");
						scanf("%i", &key3);
						if(key3==1) tempKey=1;
						else stopCycle = 0;
						break;
					}
					else
					{
						search(arr,n);
					}
				break;
			default:
				stopCycle = 0;
				break;
		}
	}
	if (arr) free(arr);
	system("clear");
	return 0;
}
