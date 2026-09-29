#include <stdio.h>

char stack[100];
int top = -1;

void push(char ch)
{
    stack[++top] = ch;
}

char pop()
{
    return stack[top--];
}

int main()
{
    int i = 0;
    int j = 0;
    int found = 0;

    char result[100];
    char word[50];
    char ch;

    printf("Enter a word: ");
    scanf("%s", word);

    printf("Enter a character: ");
    scanf(" %c", &ch);

    while (word[i] != '\0')
    {
        if (word[i] == ch)
        {
            found = 1;

            result[j++] = ch;

            while (top != -1)
            {
                result[j++] = pop();
            }

            i++;
            break;
        }
        else
        {
            push(word[i]);
        }

        i++;
    }

    if (found == 0)
    {
        printf("Character not found in the word.\n");
    }
    else
    {
        while (word[i] != '\0')
        {
            result[j++] = word[i];
            i++;
        }

        result[j] = '\0';

        printf("Result = %s\n", result);
    }

    return 0;
}

