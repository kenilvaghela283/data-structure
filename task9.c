#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void insert()
{
    struct node *newnode, *temp;
    int value;

    newnode = (struct node *)malloc(sizeof(struct node));

    if (newnode == NULL)
    {
        printf("\nMemory allocation failed!");
        return;
    }

    printf("\nEnter value: ");
    scanf("%d", &value);

    newnode->data = value;
    newnode->next = NULL;

    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newnode;
    }

    printf("\nNode inserted successfully.");
}

void delete_node()
{
    struct node *temp, *prev;
    int value;

    if (head == NULL)
    {
        printf("\nLinked list is empty!");
        return;
    }

    printf("\nEnter value to delete: ");
    scanf("%d", &value);

    temp = head;
    prev = NULL;

    while (temp != NULL && temp->data != value)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("\nValue not found!");
        return;
    }

    if (prev == NULL)
    {
        head = temp->next;
    }
    else
    {
        prev->next = temp->next;
    }

    free(temp);

    printf("\nNode deleted successfully.");
}

void modify()
{
    struct node *temp;
    int oldvalue, newvalue;

    if (head == NULL)
    {
        printf("\nLinked list is empty!");
        return;
    }

    printf("\nEnter value to modify: ");
    scanf("%d", &oldvalue);

    temp = head;

    while (temp != NULL && temp->data != oldvalue)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("\nValue not found!");
        return;
    }

    printf("Enter new value: ");
    scanf("%d", &newvalue);

    temp->data = newvalue;

    printf("\nNode modified successfully.");
}

void display()
{
    struct node *temp;

    if (head == NULL)
    {
        printf("\nLinked list is empty!");
        return;
    }

    printf("\nSingly Linked List:\n");

    temp = head;

    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL");
}

void main()
{
    int choice;

    clrscr();

    do
    {
        printf("\n\n===== SINGLY LINKED LIST =====");
        printf("\n1. Insert");
        printf("\n2. Delete");
        printf("\n3. Modify");
        printf("\n4. Display");
        printf("\n5. Exit");

        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                insert();
                break;

            case 2:
                delete_node();
                break;

            case 3:
                modify();
                break;

            case 4:
                display();
                break;

            case 5:
                printf("\nExiting...");
                break;

            default:
                printf("\nInvalid choice!");
        }

    } while (choice != 5);

    getch();
}
