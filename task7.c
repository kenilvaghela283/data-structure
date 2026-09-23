#include <stdio.h>
#include <conio.h>

#define MAX 10

int queue[MAX];
int front = -1, rear = -1;

void insert()
{
    int pid;

    if (rear == MAX - 1)
    {
        printf("\nProcess Queue is Full!");
        return;
    }

    printf("\nEnter Process ID: ");
    scanf("%d", &pid);

    if (front == -1)
        front = 0;

    rear++;
    queue[rear] = pid;

    printf("\nProcess inserted successfully.");
}

void delete_process()
{
    int pid;

    if (front == -1 || front > rear)
    {
        printf("\nProcess Queue is Empty!");
        return;
    }

    pid = queue[front];
    front++;

    printf("\nProcess %d is deleted.", pid);

    if (front > rear)
    {
        front = -1;
        rear = -1;
    }
}

void display()
{
    int i;

    if (front == -1)
    {
        printf("\nProcess Queue is Empty!");
        return;
    }

    printf("\nProcesses in Queue:\n");

    for (i = front; i <= rear; i++)
    {
        printf("P%d ", queue[i]);
    }
}

void main()
{
    int choice;

    clrscr();

    do
    {
        printf("\n\n===== PROCESS QUEUE =====");
        printf("\n1. Insert Process");
        printf("\n2. Delete Process");
        printf("\n3. Display Processes");
        printf("\n4. Exit");

        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                insert();
                break;

            case 2:
                delete_process();
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
