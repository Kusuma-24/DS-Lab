#include<stdio.h>
#define MAX 3

int queue[MAX] ;
int rear = -1;
int front = -1;

void enqueue(int val)
{
    if ((front == 0 && rear == MAX-1) || front == rear+1) {
        printf("queue is full");
    }else
    {
        if (front == -1) {
            front = 0;
        }
        rear = (rear + 1) % MAX ;
        queue[rear] = val;
        printf("Inserted %d to queue" , val);
    }
}

void deque ()
{
    int element ;
    if (front == -1) {
        printf("queue is empty");
    }
    else{
        element = queue[front];
        if(front == rear){
            front = -1;
            rear = -1;
        }else{
            front = (front+1) % MAX;
        }
        printf("Popped %d from queue" , element);
    }
}

void display()
{
    if (front == -1){
        printf("Queue is empty");
    }
    else{
        printf("Queue elements are :");
        for(int i = front ; i!= rear; i = (i+1)%MAX){
            printf("%d  " , queue[i]);
        }
        printf("%d" , queue[rear]);
    }
}

int main()
{
    int choice ;
    int val;

    do{
        printf("\n\nEnter 1 to insert \n2 to pop \n3 to display \n4 to exit :");
        scanf("%d" , &choice);

        switch(choice)
        {
        case 1 :
            printf("enter the element:");
            scanf("%d" , &val);
            enqueue(val);
            break;

        case 2 :
            deque();
            break;

        case 3:
            display();
            break;

        case 4 :
            printf(" Exiting the program:");
            break;
        }
    }while(choice != 4);
    return 0;
}
