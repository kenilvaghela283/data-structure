#include <stdio.h>
#define MAX 10

int stack[MAX];
int top1 = -1;
int top2 = MAX;

void push1()
{
    int value;

    if (top1 + 1 == top2)
        printf("\nStack Overflow!");
    else
    {
        printf("Enter value for Stack 1: ");
        scanf("%d", &value);
        top1++;
        stack[top1] = value;
        printf("Value pushed in Stack 1.\n");
    }
}

void push2()
{
    int value;

    if (top1 + 1 == top2)
        printf("\nStack Overflow!");
    else
    {
        printf("Enter value for Stack 2: ");
        scanf("%d", &value);
        top2--;
        stack[top2] = value;
        printf("Value pushed in Stack 2.\n");
    }
}

void pop1()
{
    if (top1 == -1)
        printf("\nStack 1 Underflow!");
    else
    {
        printf("Deleted value = %d\n", stack[top1]);
        top1--;
    }
}

void pop2()
{
    if (top2 == MAX)
        printf("\nStack 2 Underflow!");
    else
    {
        printf("Deleted value = %d\n", stack[top2]);
        top2++;
    }
}

void display()
{
    int i;

    printf("\nStack 1: ");
    if (top1 == -1)
        printf("Empty");
    else
        for (i = 0; i <= top1; i++)
            printf("%d ", stack[i]);

    printf("\nStack 2: ");
    if (top2 == MAX)
        printf("Empty");
    else
        for (i = MAX - 1; i >= top2; i--)
            printf("%d ", stack[i]);
}

int main()
{
    int choice;

    do
    {
        printf("\n\n--- DOUBLE STACK MENU ---");
        printf("\n1. Push Stack 1");
        printf("\n2. Pop Stack 1");
        printf("\n3. Push Stack 2");
        printf("\n4. Pop Stack 2");
        printf("\n5. Display");
        printf("\n6. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: push1(); break;
            case 2: pop1(); break;
            case 3: push2(); break;
            case 4: pop2(); break;
            case 5: display(); break;
            case 6: printf("\nExit"); break;
            default: printf("\nInvalid choice!");
        }

    } while(choice != 6);

    return 0;
}