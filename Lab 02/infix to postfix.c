#include <stdio.h>
#include <ctype.h>

#define MAX 100

int top = -1;
char stack[MAX];

void push(char ch)
{
    if (top >= MAX - 1)
    {
        printf("Stack overflow\n");
    }
    else
    {
        top++;
        stack[top] = ch;
    }
}

char pop()
{
    if (top <= -1)
    {
        printf("Stack underflow\n");
        return '\0';
    }
    else
    {
        char val = stack[top];
        top--;
        return val;
    }
}

int precedence(char sym)
{
    if (sym == '^')
        return 3;
    else if (sym == '/' || sym == '*')
        return 2;
    else if (sym == '+' || sym == '-')
        return 1;
    else
        return 0;
}

int infix_to_postfix(char infix[], char postfix[])
{
    int i = 0;
    int j = 0;
    char ch;

    while (infix[i] != '\0')
    {
        ch = infix[i];

        if (ch == ' ')
        {
            i++;
            continue;
        }

        else if (isalnum(ch))
        {
            postfix[j++] = ch;
        }

        else if (ch == '(')
        {
            push(ch);
        }

        else if (ch == ')')
        {
            while (top != -1 && stack[top] != '(')
            {
                postfix[j++] = pop();
            }

            if (top != -1 && stack[top] == '(')
            {
                pop();
            }
            else
            {
                printf("Invalid expression: Unmatched closing bracket\n");
                return 0;
            }
        }

        else
        {
            while (top != -1 &&
                   stack[top] != '(' &&
                   precedence(stack[top]) >= precedence(ch))
            {
                postfix[j++] = pop();
            }

            push(ch);
        }

        i++;
    }

    while (top != -1)
    {
        if (stack[top] == '(')
        {
            printf("Invalid expression: Unmatched opening bracket\n");
            return 0;
        }

        postfix[j++] = pop();
    }

    postfix[j] = '\0';

    return 1;
}

int main()
{
    char infix[MAX];
    char postfix[MAX];

    printf("Enter infix: ");
    scanf("%99s", infix);

    if (infix_to_postfix(infix, postfix))
    {
        printf("Postfix expression: %s\n", postfix);
    }

    return 0;
}

