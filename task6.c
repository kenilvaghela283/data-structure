#include <stdio.h>
#include <conio.h>

#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void insert()
{
    int value;

    if ((rear + 1) % MAX == front)
    {
        printf("\nCircular Queue Overflow!");
        return;
    }

    printf("\nEnter value: ");
    scanf("%d", &value);

    if (front == -1)
    {
        front = 0;
        rear = 0;
    }
    else
    {
        rear = (rear + 1) % MAX;
    }

    queue[rear] = value;

    printf("\nValue inserted successfully.");
}

void delete_element()
{
    int value;

    if (front == -1)
    {
        printf("\nCircular Queue Underflow!");
        return;
    }

    value = queue[front];

    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front = (front + 1) % MAX;
    }

    printf("\nDeleted value = %d", value);
}

void modify()
{
    int pos, value, i, count = 0;

    if (front == -1)
    {
        printf("\nQueue is empty!");
        return;
    }

    /* Count number of elements */
    i = front;

    while (1)
    {
        count++;

        if (i == rear)
            break;

        i = (i + 1) % MAX;
    }

    printf("\nEnter position to modify: ");
    scanf("%d", &pos);

    if (pos < 1 || pos > count)
    {
        printf("\nInvalid position!");
        return;
    }

    i = front;

    for (count = 1; count < pos; count++)
    {
        i = (i + 1) % MAX;
    }

    printf("Enter new value: ");
    scanf("%d", &value);

    queue[i] = value;

    printf("\nValue modified successfully.");
}

void display()
{
    int i;

    if (front == -1)
    {
        printf("\nCircular Queue is empty!");
        return;
    }

    printf("\nCircular Queue elements are:\n");

    i = front;

    while (1)
    {
        printf("%d ", queue[i]);

        if (i == rear)
            break;

        i = (i + 1) % MAX;
    }
}

void main()
{
    int choice;

    clrscr();

    do
    {
        printf("\n\n====== CIRCULAR QUEUE ======");
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
                delete_element();
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
