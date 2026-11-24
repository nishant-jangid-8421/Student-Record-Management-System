#include <stdio.h>
#include <string.h>
#include "student.h"

void display_student(void)
{
    struct student *temp;
    int name_width = 4;
    int width, i;

    if(head == NULL)
    {
        printf("\nNo student records available!\n");
        return;
    }

    temp = head;

    // Find maximum name length
    while(temp != NULL)
    {
        if((int)strlen(temp->name) > name_width)
            name_width = strlen(temp->name);

        temp = temp->next;
    }

    // Calculate total table width
width = 32 + name_width;

    // Print top border
    for(i = 0; i < width; i++)
        printf("-");

    printf("\n");

    printf("| %-10s | %-*s | %-12s |\n",
           "Roll No.", name_width, "Name", "Percentage");

    for(i = 0; i < width; i++)
        printf("-");

    printf("\n");

    temp = head;

    while(temp != NULL)
    {
        printf("| %-10d | %-*s | %-12f |\n",
               temp->rollno,
               name_width, temp->name,
               temp->percentage);

        temp = temp->next;
    }

    for(i = 0; i < width; i++)
        printf("-");

    printf("\n");
}
void reverse_student(void)
{
    struct student *prev = NULL;
    struct student *current = head;
    struct student *next = NULL;
    if(head == NULL)
    {
        printf("\nNo student records available!\n");
        return;
    }
    while(current != NULL)
    {
        next = current->next;// supposse 10 20 30 next = &20
        current->next = prev; // 10->next =0;
        prev = current;//prev= curruent (&10)
        current = next;// curr =&20 ;
    }
    head = prev;
    printf("\nList reversed successfully!\n");
}
