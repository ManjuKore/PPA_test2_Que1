#include <stdio.h>
#include <stdlib.h>
 
struct node
{
    int num;
    struct node *next;
}*front,*rear,*temp,*front1;
 
int peek();
void enq(int data);
void deq();
void create();

 
int count = 0;
 
int main()
{
	int ch,e,no;
	
    printf("\n1.enQueue");
    printf("\n2.Deque");
    printf("\n3.peek");
    printf("\n4.Exit");
   
    create();
    while (1)
    {
        printf("\n Enter choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter data : ");
            scanf("%d", &no);
            enq(no);
            break;
        case 2:
            deq();
            break;
        case 3:
            e = peek();
            if (e != 0)
                printf("current element : %d", e);
            else
                printf("\nqueue is empty");
            break;
        case 4:
	    exit(-1);
        default:
            printf("Invalid choice");
            break;
        }
    }
}
 

void create()
{
	front=rear=NULL;
}

void enq(int data)
{
    if (rear == NULL)
    {
        rear = (struct node *)malloc(1*sizeof(struct node));
        rear->next = NULL;
        rear->num = data;
        front = rear;
    }
    else
    {
        temp=(struct node *)malloc(1*sizeof(struct node));
        rear->next = temp;
        temp->num = data;
        temp->next = NULL;
 
        rear = temp;
    }
    count++;
}
 

void deq()
{
    front1 = front;
 
    if (front1 == NULL)
    {
        printf("\n Error:empty queue");
        return;
    }
    else
        if (front1->next != NULL)
        {
            front1 = front1->next;
            printf("\n Dequed value : %d", front->num);
            free(front);
            front = front1;
        }
        else
        {
            printf("\n Dequed value : %d", front->num);
            free(front);
            front = NULL;
            rear = NULL;
        }
        count--;
}
 

int peek()
{
    if ((front != NULL) && (rear != NULL))
        return(front->num);
    else
        return 0;
}

