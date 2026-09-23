#include <stdio.h>
#include <conio.h>

#define MAX 10

int queue[MAX];
int priority[MAX];
int rear = -1;

void insert()
{
    int value, p, i;

    if (rear == MAX - 1)
    {
        printf("\nPriority Queue is Full!");
        return;
    }

    printf("\nEnter value: ");
    scanf("%d", &value);

    printf("Enter priority: ");
    scanf("%d", &p);

    rear++;

    queue[rear] = value;
    priority[rear] = p;

    /* Arrange according to priority */
    for (i = rear; i > 0; i--)
    {
        if (priority[i] < priority[i - 1])
        {
            /* Swap priority */
            int temp;
            temp = priority[i];
            priority[i] = priority[i - 1];
            priority[i - 1] = temp;

            /* Swap value */
            temp = queue[i];
            queue[i] = queue[i - 1];
            queue[i - 1] = temp;
        }
        else
        {
            break;
        }
    }

    printf("\nElement inserted successfully.");
}

void delete_element()
{
    int i, value;

    if (rear == -1)
    {
        printf("\nPriority Queue is Empty!");
        return;
    }

    value = queue[0];

    /* Shift elements to the left */
    for (i = 0; i < rear; i++)
    {
        queue[i] = queue[i + 1];
        priority[i] = priority[i + 1];
    }

    rear--;

    printf("\nDeleted element = %d", value);
}

void display()
{
    int i;

    if (rear == -1)
    {
        printf("\nPriority Queue is Empty!");
        return;
    }

    printf("\nElement\tPriority\n");

    for (i = 0; i <= rear; i++)
    {
        printf("%d\t%d\n", queue[i], priority[i]);
    }
}

void main()
{
    int choice;

    clrscr();

    do
    {
        printf("\n\n===== PRIORITY QUEUE =====");
        printf("\n1. Insert");
        printf("\n2. Delete");
        printf("\n3. Display");
        printf("\n4. Exit");

        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                insert();
                break;

            case 2:
                delete_element();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("\nExiting...");
                break;

            default:
                printf("\nInvalid choice!");
        }

    } while (choice != 4);

    getch();
}
