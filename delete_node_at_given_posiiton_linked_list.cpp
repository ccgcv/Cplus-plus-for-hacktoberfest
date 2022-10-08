//Delete a Linked List node at a given position

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
};

void push(Node** head, int new_data)
{
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = *head;
    *head = new_node;
}

void display(Node *head)
{
    while(head!= NULL)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
}

void delete_node(Node** head, int position)
{
    if(*head == NULL)
    return;
    
    Node*temp = *head;
    
    if(position == 0)  // if head is to be deleted
    {
        *head = temp->next;
        free(temp);
        return;
    }
    
    for(int i=0;i<position-1 && temp!=NULL;i++)  
    temp = temp->next;
    
    if(temp==NULL || temp->next == NULL)    // If position is more than number of nodes
    return;
    
    //Node temp->next is the node to be deleted
    // Store pointer to the next of node to be deleted
    Node* next_node = temp->next->next;
    
    free(temp->next);
    temp->next = next_node;
}

int main()
{
    Node* head = NULL;
    push(&head, 7);
    push(&head, 1);
    push(&head, 3);
    push(&head, 2);
    push(&head, 8);
 
    display(head);
    
    delete_node(&head,0);
    cout<<"\n";
    
    display(head);
}
