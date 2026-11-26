#include <stdio.h>
#include <stdlib.h>
#include "student.h"

struct student *head = NULL;

int main()
{
	char choice, exit_choice;

	load_student();

	while(1)
	{
		printf("\n\033[1;36m******** STUDENT RECORD MENU ********\033[0m\n");

		printf("\033[1;32ma/A\033[0m : Add new record\n");
		printf("\033[1;31md/D\033[0m : Delete a record\n");
		printf("\033[1;33ms/S\033[0m : Show the list\n");
		printf("\033[1;35mm/M\033[0m : Modify a record\n");
		printf("\033[1;34mv/V\033[0m : Save records\n");
		printf("\033[1;31me/E\033[0m : Exit\n");
		printf("\033[1;36mt/T\033[0m : Sort the list\n");
		printf("\033[1;31ml/L\033[0m : Delete all records\n");
		printf("\033[1;36mr/R\033[0m : Reverse the list\n");

		printf("\n\033[1;37mEnter your choice: \033[0m");
		scanf(" %c", &choice);

		if(choice >= 'A' && choice <= 'Z')
			choice = choice + 32;

		switch(choice)
		{
			case 'a':
				add_student();
				break;

			case 'd':
				delete_student();
				break;

			case 's':
				display_student();
				break;

			case 'm':
				modify_student();
				break;

			case 'v':
				save_student();
				break;

			case 't':
				sort_student();
				break;

			case 'l':
				delete_all();
				break;

			case 'r':
				reverse_student();
				break;

			case 'e':
				printf("\nS/s : Save and Exit");
				printf("\nE/e : Exit without saving");
				printf("\nEnter your choice: ");
				scanf(" %c", &exit_choice);

				if(exit_choice >= 'A' && exit_choice <= 'Z')
					exit_choice = exit_choice + 32;

				switch(exit_choice)
				{
					case 's':
						save_student();
						break;

					case 'e':
						break;

					default:
						printf("\nInvalid choice!");
						continue;
				}

				delete_all();
				return 0;

			default:
				printf("\nInvalid menu choice!");
		}
	}

	return 0;
}
