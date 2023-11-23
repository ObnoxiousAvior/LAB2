#include "func.h"

void search(medicine *arr, int n)
{	
	while(1)
	{
	int select;
	
	printf("Search:\n|1. By name\n|2. By price\n|3. By dose\n\n|0. Exit\n");
	
	scanf("%i", &select);
	
	if (!select) break;
	
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
						printf(ENTRYPRINT);
						found = 1;
					}
				}
				if (!found) printf(NOT_FOUND);
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
						printf(ENTRYPRINT);
						found = 1;
					}
				}
				if (!found) printf(NOT_FOUND);
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
						printf(ENTRYPRINT);
						found = 1;
					}
				}
				if (!found) printf(NOT_FOUND);
				break;
			}
			default:
				break;
		}
	}
}
