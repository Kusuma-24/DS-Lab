#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void insert_front(struct Node **head)
{
    struct Node *newnode;

    newnode = (struct Node*)malloc(sizeof(struct Node));

    if(newnode == NULL){
        printf("Memory allocaction failed");
        return;
    }

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    newnode->next = *head;
    *head = newnode;
}

void insert_end(struct Node **head)
{
    struct Node *newnode, *temp;

    newnode = (struct Node*)malloc(sizeof(struct Node));

    if(newnode == NULL){
        printf("Memory allocaction failed");
        return;
    }

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    newnode->next = NULL;

    if (*head == NULL)
    {
        *head = newnode;
    }
    else
    {
        temp = *head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newnode;
    }
}

void insert_position(struct Node **head)
{
    struct Node *newnode, *temp;
    int pos, i;

    newnode = (struct Node*)malloc(sizeof(struct Node));

    if(newnode == NULL){
        printf("Memory allocaction failed");
        return;
    }

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    printf("Enter position: ");
    scanf("%d", &pos);

    if (pos < 1)
    {
        printf("Invalid position\n");
        free(newnode);
        return;
    }

    if (pos == 1)
    {
        newnode->next = *head;
        *head = newnode;
        return;
    }

    temp = *head;

    for (i = 1; i < pos - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Invalid position\n");
        free(newnode);
        return;
    }

    newnode->next = temp->next;
    temp->next = newnode;
}

void delete_front(struct Node **head)
{
    struct Node *temp;

    if (*head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    temp = *head;
    *head = (*head)->next;

    free(temp);
}

void delete_end(struct Node **head)
{
    struct Node *temp, *prev;

    if (*head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    temp = *head;

    if (temp->next == NULL)
    {
        *head = NULL;
        free(temp);
        return;
    }

    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    free(temp);
}

void delete_position(struct Node **head)
{
    struct Node *temp, *prev;
    int pos, i;

    printf("Enter position: ");
    scanf("%d", &pos);

    if (*head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    if (pos < 1)
    {
        printf("Invalid position\n");
        return;
    }

    temp = *head;

    if (pos == 1)
    {
        *head = temp->next;
        free(temp);
        return;
    }

    for (i = 1; i < pos && temp != NULL; i++)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Invalid position\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

void display(struct Node *head)
{
    struct Node *temp;

    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    temp = head;

    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main()
{
    struct Node *head = NULL;
    int choice;

    do
    {
        printf("\n1. Insert at Beginning");
        printf("\n2. Insert at End");
        printf("\n3. Insert at Position");
        printf("\n4. Delete from Beginning");
        printf("\n5. Delete from End");
        printf("\n6. Delete from Position");
        printf("\n7. Display");
        printf("\n8. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1: insert_front(&head);
                    break;

            case 2: insert_end(&head);
                    break;

            case 3: insert_position(&head);
                    break;

            case 4: delete_front(&head);
                    break;

            case 5: delete_end(&head);
                    break;

            case 6: delete_position(&head);
                    break;

            case 7: display(head);
                    break;

            case 8: printf("Exiting...");
                    break;

            default: printf("Invalid choice\n");
        }

    } while (choice != 8);

    return 0;
}

