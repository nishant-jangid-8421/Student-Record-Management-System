#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

void delete_student(void)
{
    struct student *temp, *prev;
    char choice, name[50];
    int roll, count = 0;

    if(head == NULL)
    {
        printf("\nNo student records available!\n");
        return;
    }

    printf("\nR/r : Delete by Roll Number");
    printf("\nN/n : Delete by Name");
    printf("\nEnter your choice: ");
    scanf(" %c", &choice);

    if(choice >= 'A' && choice <= 'Z')
        choice += 32;

    if(choice == 'r')
    {
        printf("\nEnter roll number: ");
        scanf("%d", &roll);

        temp = head;
        prev = NULL;

        while(temp != NULL)
        {
            if(temp->rollno == roll)
            {
                if(prev == NULL)
                    head = temp->next;
                else
                    prev->next = temp->next;

                free(temp);

                printf("\nStudent deleted successfully!\n");
                return;
            }

            prev = temp;
            temp = temp->next;
        }

        printf("\nStudent record not found!\n");
    }

    else if(choice == 'n')
    {
        printf("\nEnter student name: ");
        scanf(" %49[^\n]", name);

        temp = head;

        printf("\nMatching records:\n");

        while(temp != NULL)
        {
            if(strcmp(temp->name, name) == 0)
            {
                printf("Roll No: %d | Name: %s\n",temp->rollno, temp->name);
                count++;
            }
            temp = temp->next;
        }
        if(count == 0)
        {
            printf("\nStudent not found!\n");
            return;
        }
        printf("\nEnter roll number to delete: ");
        scanf("%d", &roll);
        temp = head;
        prev = NULL;
        while(temp != NULL)
        {
            if(temp->rollno == roll && strcmp(temp->name, name) == 0)
            {
                if(prev == NULL)
                    head = temp->next;
                else
                    prev->next = temp->next;
                free(temp);
                printf("\nStudent deleted successfully!\n");
                return;
            }
            prev = temp;
            temp = temp->next;
        }

        printf("\nInvalid roll number or student not found!\n");
    }

    else
    {
        printf("\nInvalid choice!\n");
    }
}
void delete_all(void)
{
    struct student *temp;

    if(head == NULL)
    {
        printf("\nNo student records available!\n");
        return;
    }

    while(head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }

    printf("\nAll student records deleted successfully!\n");
}
