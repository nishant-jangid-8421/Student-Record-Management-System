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
        printf("\n******** STUDENT RECORD MENU ********\n");
        printf("a/A : Add new record\n");
        printf("d/D : Delete a record\n");
        printf("s/S : Show the list\n");
        printf("m/M : Modify a record\n");
        printf("v/V : Save records\n");
        printf("e/E : Exit\n");
        printf("t/T : Sort the list\n");
        printf("l/L : Delete all records\n");
        printf("r/R : Reverse the list\n");

        printf("\nEnter your choice: ");
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

                if(exit_choice == 's')
                    save_student();
                else if(exit_choice != 'e')
                {
                    printf("\nInvalid choice!");
                    break;
                }

                delete_all();
                return 0;

            default:
                printf("\nInvalid menu choice!");
        }
    }

    return 0;
}
