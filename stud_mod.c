#include <stdio.h>
#include <string.h>
#include "student.h"

void modify_student(void)
{
    struct student *temp;
    char choice, name[50], new_name[50];
    int roll, count = 0;
    float percentage, new_percentage;

    if(head == NULL)
    {
        printf("\nNo student records available!\n");
        return;
    }

    printf("\nEnter which record to search for modification");

    printf("\nR/r : Search by Roll Number");
    printf("\nN/n : Search by Name");
    printf("\nP/p : Search by Percentage");

    printf("\nEnter your choice: ");
    scanf(" %c", &choice);

    if(choice >= 'A' && choice <= 'Z')
        choice += 32;

    /* Search by Roll Number */

    if(choice == 'r')
    {
        printf("\nEnter roll number: ");
        scanf("%d", &roll);

        temp = head;

        while(temp != NULL)
        {
            if(temp->rollno == roll)
                break;

            temp = temp->next;
        }

        if(temp == NULL)
        {
            printf("\nStudent not found!\n");
            return;
        }
    }

    /* Search by Name */

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
                printf("Roll No: %d | Name: %s | Percentage: %.2f\n",
                       temp->rollno, temp->name, temp->percentage);

                count++;
            }

            temp = temp->next;
        }

        if(count == 0)
        {
            printf("\nStudent not found!\n");
            return;
        }

        if(count > 1)
        {
            printf("\nEnter roll number to select student: ");
            scanf("%d", &roll);

            temp = head;

            while(temp != NULL)
            {
                if(temp->rollno == roll &&
                   strcmp(temp->name, name) == 0)
                    break;

                temp = temp->next;
            }

            if(temp == NULL)
            {
                printf("\nInvalid selection!\n");
                return;
            }
        }
        else
        {
            temp = head;

            while(temp != NULL)
            {
                if(strcmp(temp->name, name) == 0)
                    break;

                temp = temp->next;
            }
        }
    }

    /* Search by Percentage */

    else if(choice == 'p')
    {
        printf("\nEnter percentage: ");
        scanf("%f", &percentage);

        temp = head;

        printf("\nMatching records:\n");

        while(temp != NULL)
        {
            if(temp->percentage == percentage)
            {
                printf("Roll No: %d | Name: %s | Percentage: %.2f\n",
                       temp->rollno, temp->name, temp->percentage);

                count++;
            }

            temp = temp->next;
        }

        if(count == 0)
        {
            printf("\nStudent not found!\n");
            return;
        }

        if(count > 1)
        {
            printf("\nEnter roll number to select student: ");
            scanf("%d", &roll);

            temp = head;

            while(temp != NULL)
            {
                if(temp->rollno == roll &&
                   temp->percentage == percentage)
                    break;

                temp = temp->next;
            }

            if(temp == NULL)
            {
                printf("\nInvalid selection!\n");
                return;
            }
        }
        else
        {
            temp = head;

            while(temp != NULL)
            {
                if(temp->percentage == percentage)
                    break;

                temp = temp->next;
            }
        }
    }
    else
    {
        printf("\nInvalid choice!\n");
        return;
    }
    // Display selected student */
    printf("\nSelected Student Details:\n");
    printf("Roll Number : %d\n", temp->rollno);
    printf("Name        : %s\n", temp->name);
    printf("Percentage  : %.2f\n", temp->percentage);
    // Update student details 
    printf("\nEnter updated name: ");
    scanf(" %49[^\n]", new_name);
    printf("Enter updated percentage: ");
    if(scanf("%f", &new_percentage) != 1 ||
       new_percentage < 0 || new_percentage > 100)
    {
        printf("\nInvalid percentage!\n");
        return;
    }
    strcpy(temp->name, new_name);
    temp->percentage = new_percentage;
    printf("\nStudent record modified successfully!\n");
}
