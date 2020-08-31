#include <stdio.h>
#include <stdlib.h>

struct node
{
    char data;
    struct node *next;
};

struct node *top = NULL;

void push(char item)
{
    struct node *nptr = malloc(sizeof(struct node));
    nptr->data = item;
    nptr->next = top;
    top = nptr;
}

void pop()
{
    if (top == NULL)
    {
        printf("Stack is empty \n");
    }
    else
    {
        struct node *temp;
        temp = top;
        top = top->next;
        // printf("%c deleted\n", temp->data);
        free(temp);
    }
}

void display()
{
    while (top != NULL)
    {
        if (top->data == '*')
        {
            printf("There is a misssing */ \n");
        }
        else
        {
            printf("There is a misssing %c \n", top->data);
        }
        pop();
    }
}

int main(int argc, char *argv[])
{
    char *input = argv[1];
    int i = 0;
    int commentMode = 0;
    int stringMode = 0;
    int charMode = 0;
    int multilineComment = 0;
    int error = 0;
    while (input[i] != '\0')
    {
        // printf("%c", input[i]);
        i++;
        if (commentMode)
        {
            if (input[i] == '\n')
            {
                commentMode = 0;
            }
        }
        else if (stringMode)
        {
            if (input[i] == '"')
            {
                pop();
                stringMode = 0;
            }
        }
        else if (charMode)
        {
            if (input[i] == '\'')
            {
                pop();
                charMode = 0;
            }
        }
        else if (multilineComment)
        {
            if (input[i] == '*' && input[i + 1] == '/')
            {
                pop();
                multilineComment = 0;
            }
        }
        else
        {
            switch (input[i])
            {

            case '/':
                if (input[i + 1] == '/')
                {
                    commentMode = 1;
                }
                else if (input[i + 1] == '*')
                {
                    push('*');
                    multilineComment = 1;
                }
                break;

            case '(':
                push('(');
                break;

            case ')':
                if (top != NULL)
                {
                    if (top->data == '(')
                    {
                        pop();
                    }
                    else
                    {
                        printf("There is a missing (\n");
                        error = 1;
                    }
                }
                else
                {
                    printf("There is a missing (");
                    error = 1;
                }

                break;

            case '{':
                push('{');
                break;

            case '}':
                if (top != NULL)
                {
                    if (top->data == '{')
                    {
                        pop();
                    }
                    else
                    {
                        printf("There is a missing {\n");
                        error = 1;
                    }
                }
                else
                {
                    printf("There is a missing {\n");
                    error = 1;
                }

                break;

            case '[':
                push('[');
                break;

            case ']':
                if (top != NULL)
                {
                    if (top->data == '[')
                    {
                        pop();
                    }
                    else
                    {
                        printf("There is a missing ]\n");
                        error = 1;
                    }
                }
                else
                {
                    printf("There is a missing [\n");
                    error = 1;
                }

                break;

            case '"':
                push('"');
                stringMode = 1;
                break;

            case '\'':
                push('\'');
                charMode = 1;
                break;

            default:
                break;
            }
        }
    }

    if (top != NULL)
    {
        display();
    }
    else if (error == 0)
    {
        printf("There are no errors \n");
    }

    return 0;
}
