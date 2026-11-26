#include <stdio.h>
#include <string.h>
#include <strings.h>
#include "student.h"

void sort_student(void)
{
    struct student *temp, *next;
    char choice;
    int roll;
    char name[50];
    float percentage;

    if(head == NULL || head->next == NULL)
    {
        printf("\nNot enough records to sort!\n");
        return;
    }

    printf("\nN/n : Sort by Name");
    printf("\nP/p : Sort by Percentage");
    printf("\nEnter your choice: ");
    scanf(" %c", &choice);

    if(choice >= 'A' && choice <= 'Z')
        choice += 32;

    switch(choice)
    {
        case 'n':
        {
            for(temp = head; temp->next != NULL; temp = temp->next)
            {
                for(next = temp->next; next != NULL; next = next->next)
                {
                    if(strcasecmp(temp->name, next->name) > 0)
                    {
                        roll = temp->rollno;
                        temp->rollno = next->rollno;
                        next->rollno = roll;

                        strcpy(name, temp->name);
                        strcpy(temp->name, next->name);
                        strcpy(next->name, name);

                        percentage = temp->percentage;
                        temp->percentage = next->percentage;
                        next->percentage = percentage;
                    }
                }
            }

            break;
        }

        case 'p':
        {
            for(temp = head; temp->next != NULL; temp = temp->next)
            {
                for(next = temp->next; next != NULL; next = next->next)
                {
                    if(temp->percentage < next->percentage)
                    {
                        roll = temp->rollno;
                        temp->rollno = next->rollno;
                        next->rollno = roll;

                        strcpy(name, temp->name);
                        strcpy(temp->name, next->name);
                        strcpy(next->name, name);

                        percentage = temp->percentage;
                        temp->percentage = next->percentage;
                        next->percentage = percentage;
                    }
                }
            }

            break;
        }

        default:
            printf("\nInvalid choice!\n");
            return;
    }

    printf("\nRecords sorted successfully!\n");
}
