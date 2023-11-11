typedef struct medicine{
	char name[40];
	float price;
	int dose;
}medicine;

void create(medicine **arr, int *n);
void write(medicine *arr, int n);
void read(medicine **arr, int *n);

void search(medicine *arr, int n);
