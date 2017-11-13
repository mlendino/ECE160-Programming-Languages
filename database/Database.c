#include <stdio.h>

void display();
void modify();
void save();
void retrieve();
typedef struct database
{
	char lastName[30];
	char firstAndMiddleNames[35];
	float salary;
	int yearHired;
} DBENTRY;

DBENTRY entries[20];

int main(int argc, char *argv[])
{
for(int i = 0; i < 20; i++)
{
		entries[i].lastName[0] = 0;
		entries[i].firstAndMiddleNames[0] = 0;
        entries[i].salary = -1;
        entries[i].yearHired = -1;
}
int menuOpt;
printf("\t\t\tMENU - DATABASE\n"); //\t means tab, this approximately centers the headings
printf("\t\t\t----------------------------\n\n\n");
printf("1 - Display any record\n\n");
printf("2 - Modify any record\n\n");
printf("3 - Save the records\n\n");
printf("4 - Retrieve the records\n\n");
printf("5 - Quit\n\n\n");
menuOpt = ' '; //first assign menuOpt to the space then the while condition is true so run while loop
while(menuOpt != 5)
{
	while(menuOpt<1 || menuOpt > 5) //only false when user inputs 1or2or3or4
		{
		printf("WHAT IS YOUR CHOICE?\n[1=Disp, 2=Edit, 3=Save, 4=Load, 5=Quit]: "); //itll always output this for a given input\{1,2,3,4}
		scanf("%d", &menuOpt); //we assign their response to the variable menuOpt so while condition = false
		} //then it runs the if statement corresponding to their input
	if(menuOpt == 1)
	{
		display(); //if they enter a 1, then run display
	}
	if(menuOpt == 2)
	{
		modify(); //if they enter a 2, then run modify
	}
	if(menuOpt == 3)
	{
		save(); //if they enter a 3 then run save()
	}
	if(menuOpt == 4)
	{
		retrieve(); //if they enter a 4 then run retrieve()
	}
	if(menuOpt == 5)
	{
		return 0;
	}
	menuOpt = 0;

}
return 0;
} // end of main()

void display()
{
char again;
int recNum;

again = 'Y';
while(again == 'Y' || again == 'y')
	{
	printf("\nWhat record number do you want to display? ");
	scanf("%d", &recNum);
    if(recNum<0||recNum>=20)
    {
        printf("Record number is out of bounds.\n");
    }
	else
    {
        printf("The last name of record %d is %s\n", recNum, entries[recNum].lastName);
        printf("The first and middle name of record %d is %s\n", recNum, entries[recNum].firstAndMiddleNames);
        printf("The salary of record %d is %f\n", recNum, entries[recNum].salary);
        printf("The year hired of record %d is %d\n\n\n", recNum, entries[recNum].yearHired);
    }
	again = 'x';
	while(again != 'Y' && again != 'y' && again != 'N' && again != 'n')
		{
		printf("Do you want to look up another record (Y/N)? ");
		scanf(" %c", &again);
		}
	}
}

void modify()
{
char again;
int recNum;

again = 'Y';
while(again == 'Y' || again == 'y')
	{
	printf("\nWhat record number do you want to modify? ");
	scanf("%d", &recNum);
        if(recNum<0||recNum>=20)
        {
            printf("Record number is out of bounds.\n");
        }
        else
        {
            printf("Enter the last name of record number %d: ", recNum);
            scanf(" %[^\n]", &entries[recNum].lastName);
            printf("Enter the first and middle name of record number %d: ", recNum);
            scanf(" %[^\n]", &entries[recNum].firstAndMiddleNames);
            printf("Enter the salary of record number %d: ", recNum);
            scanf("%f", &entries[recNum].salary);
            printf("Enter the year that record number %d was hired: ", recNum);
            scanf("%d", &entries[recNum].yearHired);
        }
	again = 'x';
        while(again != 'Y' && again != 'y' && again != 'N' && again != 'n')
                {
                printf("\n\nDo you want to modify another record (Y/N)? ");
                scanf("\n %c", &again);
                }
        }
}

void save()
{
FILE *file; //file pointers

file = fopen("company.db", "wb"); //open file in binary mode
char* arrayBase = (char*) entries; //declaring a pointer called arrayBase, this pointer points to the first element of the array, we change it to a pointer to char to read each byte of the array
					//rather than entries at a time by casting to char* (i.e. the (char*))
for(int i = 0; i < sizeof(entries); i++) //a loop, conditions are true at first, and is used to get the ith byte of the entries array,note this is false when you reach the last element,i=sizeof(entries)
{
	fputc(*(arrayBase+i), file); //writing each byte of entry to the file... *(arrayBase+i) follows the pointer "arrayBase+i" to get each byte
}
fclose(file); //close file

}

void retrieve()
{
FILE *file;

file = fopen("company.db", "rb");
char* arrayBase = (char*)entries;

for(int i = 0; i < sizeof(entries); i++)
{
	*(arrayBase+i) = fgetc(file); //read each byte of the file in the same order and assign it to *(arrayBase+i) byte by byte so we can use the function in the rest of the program
}
fclose(file);

}

