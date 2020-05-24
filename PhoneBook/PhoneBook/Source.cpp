#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <cstring>


using namespace std;

void ShowList(), AddUser(), FindUser(), DeleteUser();

int main()
{
	int Select;
	do
	{
		cout<<"Select a command"<<endl<<"1)Show list"<<endl<<"2)Add User"<<endl<<"3)Find User"<<endl<<"4)Delete User"<<endl<<"5)Exit the program"<<endl;

		cin>>Select;

		switch (Select)

		{

		case 1:
			ShowList();
			break;

			case 2:
				AddUser();
				break;

			case 3:
				FindUser();
				break;
			case 4:
				DeleteUser();
				break;
			case 5:
				exit(0);
			default:
				printf("There is no such command\n");
				getchar();
				system("cls");
				break;
		} 
	}while (1);
	return 0;

}

void ShowList()
{
	FILE* f;
	f = fopen("Users.txt", "r");
	int Count = 1;
	char Symbol;

	printf("1 ");
	Symbol = getc(f);
	while (Symbol != EOF)

	{

		printf("%c", Symbol);
		if (Symbol == '\n')
		{
			Count++;
			printf("%d ", Count);
		}

		Symbol = getc(f);
	}
	getchar();
	printf("\nPress Enter to complete the command");
	getchar();
	system("cls");
}

void AddUser()

{

	//char Name[50], Surname[50], Patronymic[50], Number[50];
	vector <string> Name(50);
	vector <string> Surname(50);
	vector <string> Patronymic(50);
	vector <string> Number(50);

	FILE* f;

	f = fopen("Users.txt", "a+");
	printf("Enter name:");
	scanf("%s", &Name);
	fprintf(f, "%s ", &Name);
	printf("Enter Surname:");
	scanf(" %s", &Surname);
	fprintf(f, "%s ", &Surname);	
	printf("Enter Patronymic:");
	scanf(" %s", &Patronymic);
	fprintf(f, "%s ", &Patronymic);
	printf("Enter Number:");
	scanf(" %s", &Number);
	fprintf(f, "%s ", &Number);
	fputs("\n", f);
	fclose(f);
	printf("\nContact successfully added!");
	getchar();
	printf("\nPress Enter to complete the command");
	getchar();
	system("cls");
}

void FindUser()
{
	FILE* f;
	f = fopen("Users.txt", "rt");

	int i = 0;

	char word[50];
	//vector <char> word(50);


	printf("Enter abonent:");

	scanf("%s", &word);
	
	ifstream input("Users.txt");

	char buffer[1024];
	//vector <char> buffer(1024);

	printf("\nContacts that could be found:\n");
	//char* foundStr = NULL;
	//foundStr = strstr(buffer, word);
	while (input.getline(buffer, 1024)) {

		if (strstr(buffer, word))
		{
			printf("%s\n", buffer);
			i++;
		}
	}
	if (i == 0) printf("No contacts found\n");

	fclose(f);
	getchar();
	printf("\nPress Enter to complete the command");
	getchar();
	system("cls");
}

void DeleteUser()

{

	FILE* f, * fp2;

	char c;

	int Line, Count = 1, Temporary = 1;
	printf("The current list of contacts:\n");
	f = fopen("Users.txt", "r");
	printf("1 ");
	c = getc(f);
	while (c != EOF)

	{

		printf("%c", c);
		if (c == '\n')
		{
			Count++;
			printf("%d ", Count);
		}

		c = getc(f);
	}

	rewind(f);



	printf(" \n Enter line number of the line to be deleted:");

	scanf("%d", &Line);
	Count = 0;
	while (!feof(f)) {

		fscanf(f, "%*[^\n]%*c");

		Count++;

	}

	if (Line >= Count)
	{
		printf("No User with such number\n");
	}
	else

	{

		fp2 = fopen("NotUsers.txt", "w");

		rewind(f);

		c = getc(f);

		while (c != EOF) {

			if (c == '\n')

				Temporary++;

			if (Temporary != Line)

			{

				putc(c, fp2);

			}

			c = getc(f);

		}
		
		printf("\nContact successfully deleted!\nContact list updated:\n");

		fclose(f);

		fclose(fp2);

		remove("Users.txt");

		rename("NotUsers.txt", "Users.txt");

		f = fopen("Users.txt", "r");

		c = getc(f);

		while (c != EOF) {

			printf("%c", c);

			c = getc(f);

		}

	}
	fclose(f);
	getchar();
	printf("\nPress Enter to complete the command");
	getchar();
	system("cls");
}





