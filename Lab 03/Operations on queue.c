#include<stdio.h>
#define MAX 3

int queue[MAX];
int rear = -1;
int front = -1;

void insert(int value)
{
    if(rear == MAX - 1){
        printf("Queue if full\n\n");
        return ;
    }
    if (front == -1){
        front = 0;
    }
    rear ++ ;
    queue[rear] = value;
    printf("Value inserted succesfully\n\n");
}

void delete()
{
    if(front == -1 || front > rear){
        printf("\nQueue is empty\n\n");
        return ;
    }
    printf("Deleted the element %d\n\n" , queue[front]);
    front ++;
}

void display()
{
    if(front == -1 || front > rear){
        printf("\nQueue is empty\n");
        return ;
    }

    printf("\nThe queue elements are :");
    for (int i = front ; i<= rear ; i++){
        printf("%d  " , queue[i]);
    }
    printf("\n");
}

int main()
{
    int value;
    int choice;

    do{
        printf("1 to insert \n2 to delete \n3 to display \n4 to exit\n");
        printf("Enter the choice:");
        scanf("%d" , &choice);

        switch(choice)
        {
        case 1:
            printf("Enter the element:");
            scanf("%d", &value);
            insert(value);
            break;

        case 2:
            delete();
            break;

        case 3:
            display();
            break;

        case 4:
            printf("\nExiting the program...");
            break;

        default:
            printf("\nInvlid choice");
        }
    } while(choice!=4);

    return 0;
}
