#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

struct node *f = NULL;
struct node *r = NULL;

void linkedListTraversal (struct node *head)
{
    struct node *ptr = head;

    while(ptr!=NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }

    printf("\n");
}

int isEmpty()
{
    if(f == NULL) return 1;
    else return 0;
}

int isFull()
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    
    if(ptr == NULL) return 1;
    else return 0;
}

void enqueue (int value)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));

    if(isFull()) printf("Full\n");
    else
    {
        ptr->data = value;
        ptr->next = NULL;

        if(isEmpty())
        {
            f = r = ptr;
        }
        else
        {
            r->next = ptr;
            r = ptr;
        }
    }
}

void dequeue()
{
    struct node *ptr = f;

    if(isEmpty()) printf("Empty\n");
    else
    {
        f = ptr->next;
        free(ptr);
    }
}

int main()
{
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);

    linkedListTraversal(f);

    dequeue();
    dequeue();

    enqueue(6);

    linkedListTraversal(f);
}