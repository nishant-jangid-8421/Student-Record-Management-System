#include <stdio.h>
#include <stdlib.h>
#include "student.h"

void save_student(void)
{
    FILE *fp;
    struct student *temp;

    fp = fopen("student.dat", "w");

    if(fp == NULL)
    {
        printf("\nFile opening failed!\n");
        return;
    }

    temp = head;

    while(temp != NULL)
    {
        fprintf(fp, "%d|%s|%.2f\n",
                temp->rollno,
                temp->name,
                temp->percentage);

        temp = temp->next;
    }

    fclose(fp);

    printf("\nRecords saved successfully!\n");
}

void load_student(void)
{
    FILE *fp;
    struct student *newnode, *temp;
    char line[100];

    fp = fopen("student.dat", "r");

    if(fp == NULL)
        return;

    while(fgets(line, sizeof(line), fp) != NULL)
    {
        newnode = malloc(sizeof(struct student));

        if(newnode == NULL)
        {
            printf("\nMemory allocation failed!\n");
            fclose(fp);
            return;
        }

        if(sscanf(line, "%d|%49[^|]|%f",
                  &newnode->rollno,
                  newnode->name,
                  &newnode->percentage) != 3)
        {
            free(newnode);
            continue;
        }

        newnode->next = NULL;

        if(head == NULL)
            head = newnode;
        else
        {
            temp = head;

            while(temp->next != NULL)
                temp = temp->next;

            temp->next = newnode;
        }
    }

    fclose(fp);

    printf("\nRecords loaded successfully!\n");
}
