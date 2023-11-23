#include "func.h"

/*RECOMENDUYU POMENYAT VID PRINTFof CHTOBI NE SPALILI CHO VI VORUETE BESPLATNO BEZ SMS I REGISTRACII. 
/ TAKJE STOIT UBRAT' VSE system("clear")
  YA OTVETSTVENNOST' ZA VASHI OCENKI S SEBYA SNIMAUYU*/

// DEFINING GLOBAL VARIABLES

medicine *arr = NULL; // Database structure array
int n = 0; // Amount of variables

int main()
{
	system("clear"); // Clearing the contents of a terminal

	int stopCycle = 1; // Flag stopping the main loop
	
	int key = 0;
	
	while(stopCycle){
	
		if (!key){
			printf("What would you like to do?\n|1. Create a database \n|2. Print the database \n|3. Search in the database \n|0. Exit the program\n");
			scanf("%i", &key);
		}
		
		system("clear");
		
		switch (key)
		{
			case 1:
				chooseCreationMethod(); // Function defined for choosing the way you create a DB
				key = 0;
				break;
				
			case 2:
				if(!arr) 
					{
						int check = whereDatabase();
						
						if (check == 1) stopCycle = 0; // If user stops
						else key = 0; // In case of an error of a successful execution
					}
				else
					{
						for (int i = 0; i<n; i++) printf(ENTRYPRINT); // ENTRYPRINT is defined in func.h
						
						printf("%c",'\n');
						key = 0;
					}
				break;
				
			case 3:
				if(!arr) 
					{
						int check = whereDatabase();
						
						if (check == 1) stopCycle = 0;
						else key = 0;
					}
				else
					{
						search(arr,n);
						key = 0;
						system("clear");
					}
				break;
				
			default:
				stopCycle = 0;
				break;
			}
		}
		
		
	if (arr) free(arr); // If dynamic memory is allocated for arr, free the utilized memory

	system("clear");

	return 0;
}
