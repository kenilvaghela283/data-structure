#include <stdio.h>
#include <conio.h>

#define MAX 50

int queue[MAX];
int front = -1, rear = -1;

void insert()
{
    int value;

    if (rear == MAX - 1)
    {
        printf("\nQueue Overflow!");
        return;
    }

    printf("\nEnter value: ");
    scanf("%d", &value);

    if (front == -1)
        front = 0;

    rear++;
    queue[rear] = value;

    printf("\nValue inserted successfully.");
}

void delete_element()
{
    int value;

    if (front == -1 || front > rear)
    {
        printf("\nQueue Underflow!");
        return;
    }

    value = queue[front];
    front++;

    printf("\nDeleted value = %d", value);

    if (front > rear)
    {
        front = -1;
        rear = -1;
    }
}

void modify()
{
    int pos, value;

    if (front == -1 || front > rear)
    {
        printf("\nQueue is empty!");
        return;
    }

    printf("\nEnter position to modify: ");
    scanf("%d", &pos);

    if (pos < 1 || pos > (rear - front + 1))
    {
        printf("\nInvalid position!");
        return;
    }

    printf("Enter new value: ");
    scanf("%d", &value);

    queue[front + pos - 1] = value;

    printf("\nValue modified successfully.");
}

void display()
{
    int i;

    if (front == -1 || front > rear)
    {
        printf("\nQueue is empty!");
        return;
    }

    printf("\nQueue elements are:\n");

    for (i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }
}

void main()
{
    int choice;

    clrscr();

    do
    {
        printf("\n\n===== SIMPLE QUEUE =====");
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
