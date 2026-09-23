#include <stdio.h>
#define MAX 5

int stack[MAX];
int top = -1;

void push()
{
    int value;

    if (top == MAX - 1)
        printf("\nStack Overflow!");
    else
    {
        printf("Enter value: ");
        scanf("%d", &value);
        top++;
        stack[top] = value;
        printf("Value pushed successfully.\n");
    }
}

void pop()
{
    if (top == -1)
        printf("\nStack Underflow!");
    else
    {
        printf("Deleted value = %d\n", stack[top]);
        top--;
    }
}

void peep()
{
    int pos;

    printf("Enter position from top: ");
    scanf("%d", &pos);

    if (top - pos + 1 < 0)
        printf("Invalid position!\n");
    else
        printf("Value = %d\n", stack[top - pos + 1]);
}

void modify()
{
    int pos, value;

    printf("Enter position from top: ");
    scanf("%d", &pos);

    if (top - pos + 1 < 0)
        printf("Invalid position!\n");
    else
    {
        printf("Enter new value: ");
        scanf("%d", &value);
        stack[top - pos + 1] = value;
        printf("Value modified successfully.\n");
    }
}

void display()
{
    int i;

    if (top == -1)
        printf("\nStack is empty!");
    else
    {
        printf("\nStack elements:\n");
        for (i = top; i >= 0; i--)
            printf("%d\n", stack[i]);
    }
}

int main()
{
    int choice;

    do
    {
        printf("\n\n--- STACK MENU ---");
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Peep");
        printf("\n4. Modify");
        printf("\n5. Display");
        printf("\n6. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: peep(); break;
            case 4: modify(); break;
            case 5: display(); break;
            case 6: printf("Exit"); break;
            default: printf("Invalid choice!");
        }

    } while(choice != 6);

    return 0;
}