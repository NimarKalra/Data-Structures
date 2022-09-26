/*Question.1 While traversing a single-circular linked list, which condition establishes that the traversing element/variable has reached the first element? */

//Ans 1
//create a basic circular linked list
#include <iostream>
using namespace std;
//Creating Node class
class Node{
    //Creating class objects
    public:
    int data;
    Node*next;
    //Calling Node constructor
    Node(int data)
    {
        this->data=data;
        next=NULL;
    }
};
//insert a node at end on linked list
void append(Node* &head, int data){
    Node* temp = head;
    Node* new_node=new Node(data);
    if(temp==NULL)
    {
        head=new_node;new_node->next=head;
        return;
    }
    while(temp->next!=head){temp=temp->next;}   //This condition establishes that the traversing element(temp) has reached the first element
    temp->next=new_node;
    new_node->next=head;
}
//print elements of linked list from head to the last node.
void print(Node*&head){
    Node*temp=head;
    do{cout<<temp->data<<"->";temp=temp->next;}
    while(temp!=head);
}

int main(){
    Node*head=NULL;
    append(head,1);
    append(head,2);
    append(head,3);
    append(head,4);
    print(head);
}
/*
With reference to above example of circular linked list.
while(temp->next!=head)
{
    temp=temp->next;
}
establishes that the traversing element has reached the first element.
We Know that in circular linked list the last node of linked list points to head of that linked list, so we can check if any node points to head of linked list then that node is the end of circular linked list.
*/

/*Question.2  What are the practical applications of a circular linked list? (Try to find applications in your respective fields).
Practical applications of circular linked list:
1) Circular Linked Lists can be used to manage the computing resources of the computer.
2) Data structures such as stacks and queues are implemented with the help of the circular linked lists.
3) Circular Linked List is also used in the implementation of advanced data structures such as a Fibonacci Heap.
4) It is also used in computer networking for token scheduling.
5) Round Robin scheduling technique in games.
6) Audio/Video Streaming
7) Circular Escalators
*/
