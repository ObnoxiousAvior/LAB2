#include "func.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void search(medicine *arr, int n)
{
	int select;
	
	printf("Search:\n|1. By name\n|2. By price\n|3. By dose\n");
	
	scanf("%i", &select);
	
	system("clear");
	
	switch(select)
	{
		case 1:{
			char tag[40];
			int found = 0;
			printf("Enter a name: ");
			
			scanf("%s",tag);
			
			for(int i = 0; i<n; i++)
			{
				if(!strcmp(arr[i].name,tag))
				{
					printf("A match found: %s %0.2f %i\n", arr[i].name, arr[i].price, arr[i].dose);
					found = 1;
				}
			}
			if (!found) printf("Couldn't find any matches\n\n");
			break;
		}
		case 2:{
			float tag;
			int found = 0;
			printf("Enter a price: ");
			
			scanf("%f",&tag);
			
			for(int i = 0; i<n; i++)
			{
				if(arr[i].price==tag)
				{
					printf("A match found: %s %0.2f %i\n", arr[i].name, arr[i].price, arr[i].dose);
					found = 1;
				}
			}
			if (!found) printf("Couldn't find any matches\n\n");
			break;
		}
		case 3:{
			int tag;
			int found = 0;
			printf("Enter a dose: ");
			
			scanf("%i",&tag);
			
			for(int i = 0; i<n; i++)
			{
				if(arr[i].dose==tag)
				{
					printf("A match found: %s %0.2f %i\n", arr[i].name, arr[i].price, arr[i].dose);
					found = 1;
				}
			}
			if (!found) printf("Couldn't find any matches\n\n");
			break;
		}
		default:
			break;
	}
	printf("%c",'\n');
}
