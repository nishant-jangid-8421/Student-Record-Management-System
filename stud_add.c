#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "student.h"
int generate_rollno(void)
{
	int roll = 1;
	struct student *temp;

	while(1)
	{
		temp = head;

		while(temp != NULL)
		{
			if(temp->rollno == roll)
				break;

			temp = temp->next;
		}

		if(temp == NULL)
			return roll;

		roll++;
	}
}
void add_student(void)
{
    struct student *newnode, *temp;

    newnode = malloc(sizeof(struct student));

    if(newnode == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    newnode->rollno = generate_rollno();

    printf("Enter student name: ");
    scanf(" %49[^\n]", newnode->name);

    printf("Enter percentage: ");
    if(scanf("%f", &newnode->percentage) != 1 ||
       newnode->percentage < 0 || newnode->percentage > 100)
    {
        printf("Invalid percentage!\n");
        free(newnode);
        return;
    }

    newnode->next = NULL;

    if(head == NULL)
    {
        head = newnode;
    }
    else
    {
        temp = head;

        while(temp->next != NULL)
            temp = temp->next;

        temp->next = newnode;
    }

    printf("\nStudent added successfully!");
    printf("\nRoll Number: %d\n", newnode->rollno);
}
