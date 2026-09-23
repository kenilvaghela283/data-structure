#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

#define MAX 50

char stack[MAX];
int top = -1;

void push(char ch)
{
    stack[++top] = ch;
}

char pop()
{
    return stack[top--];
}

int priority(char ch)
{
    if (ch == '^')
        return 3;
    if (ch == '*' || ch == '/')
        return 2;
    if (ch == '+' || ch == '-')
        return 1;
    return 0;
}

void main()
{
    char infix[MAX], postfix[MAX];
    int i, j = 0;
    char ch;

    clrscr();

    printf("Enter infix expression: ");
    gets(infix);

    for (i = 0; infix[i] != '\0'; i++)
    {
        ch = infix[i];

        /* If operand, add to postfix */
        if (isalnum(ch))
        {
            postfix[j++] = ch;
        }

        /* If opening bracket */
        else if (ch == '(')
        {
            push(ch);
        }

        /* If closing bracket */
        else if (ch == ')')
        {
            while (top != -1 && stack[top] != '(')
            {
                postfix[j++] = pop();
            }

            if (top != -1)
                pop();   /* Remove '(' */
        }

        /* If operator */
        else
        {
            while (top != -1 &&
                   stack[top] != '(' &&
                   priority(stack[top]) >= priority(ch))
            {
                postfix[j++] = pop();
            }

            push(ch);
        }
    }

    /* Pop remaining operators */
    while (top != -1)
    {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';

    printf("\nPostfix expression: %s", postfix);

    getch();
}
