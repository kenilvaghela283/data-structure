#include <stdio.h>
#include <conio.h>

#define MAX 50

int deque[MAX];
int front = -1, rear = -1;

void insert()
{
    int value, choice;

    if ((front == 0 && rear == MAX - 1) ||
        (front == rear + 1))
    {
        printf("\nDeque Overflow!");
        return;
    }

    printf("\n1. Insert at Front");
    printf("\n2. Insert at Rear");
    printf("\nEnter choice: ");
    scanf("%d", &choice);

    printf("Enter value: ");
    scanf("%d", &value);

    if (front == -1)
    {
        front = rear = 0;
        deque[front] = value;
    }
    else if (choice == 1)
    {
        if (front == 0)
            front = MAX - 1;
        else
            front--;

        deque[front] = value;
    }
    else if (choice == 2)
    {
        if (rear == MAX - 1)
            rear = 0;
        else
            rear++;

        deque[rear] = value;
    }
    else
    {
        printf("\nInvalid choice!");
        return;
    }

    printf("\nValue inserted successfully.");
}

void delete_element()
{
    int choice, value;

    if (front == -1)
    {
        printf("\nDeque Underflow!");
        return;
    }

    printf("\n1. Delete from Front");
    printf("\n2. Delete from Rear");
    printf("\nEnter choice: ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        value = deque[front];

        if (front == rear)
        {
            front = rear = -1;
        }
        else if (front == MAX - 1)
        {
            front = 0;
        }
        else
        {
            front++;
        }

        printf("\nDeleted value = %d", value);
    }
    else if (choice == 2)
    {
        value = deque[rear];

        if (front == rear)
        {
            front = rear = -1;
        }
        else if (rear == 0)
        {
            rear = MAX - 1;
        }
        else
        {
            rear--;
        }

        printf("\nDeleted value = %d", value);
    }
    else
    {
        printf("\nInvalid choice!");
    }
}

void modify()
{
    int pos, value, i, count = 0;

    if (front == -1)
    {
        printf("\nDeque is empty!");
        return;
    }

    i = front;

    while (1)
    {
        count++;

        if (i == rear)
            break;

        i++;

        if (i == MAX)
            i = 0;
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
        i++;

        if (i == MAX)
            i = 0;
    }

    printf("Enter new value: ");
    scanf("%d", &value);

    deque[i] = value;

    printf("\nValue modified successfully.");
}

void display()
{
    int i;

    if (front == -1)
    {
        printf("\nDeque is empty!");
        return;
    }

    printf("\nDeque elements are:\n");

    i = front;

    while (1)
    {
        printf("%d ", deque[i]);

        if (i == rear)
            break;

        i++;

        if (i == MAX)
            i = 0;
    }
}

void main()
{
    int choice;

    clrscr();

    do
    {
        printf("\n\n========== DOUBLE QUEUE ==========");
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
