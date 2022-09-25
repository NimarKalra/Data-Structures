//Nimarpreet Singh  Branch:ECE  SID:21105075
#include <iostream>             
using namespace std;                  

//Creating Node class
class Node{
    public:
    //Creating class objects
    string name;
    int age;
    Node*next; //A pointer for next node
    Node*prev; //A pointer for previous node
    //constructor
    Node(string name,int age){
        this->name=name;
        this->age=age;
        next=NULL; //initialize next as NULL
        prev=NULL; //initialize prev as NULL
    }
};

//Insert node at end of LinkedList
void append(Node* &head, string name, int age){
    //Creating a pointer and storing address of head in temp
    Node*temp=head;
    //Creating a new node and storing name and age in it
    Node*new_node=new Node(name,age);
    //Inserting node in empty list
    if(temp==NULL){
        head=new_node;
    }
    //Inserting node in non empty list
    else{
        while(temp->next!=NULL){temp=temp->next;}
        temp->next=new_node;
        new_node->prev=temp;
    }
}

//Insert node at start 
void insertAtHead(Node*&head,string name,int age){
    //Creating a Node pointer and storing address of new node in it 
    Node*new_node=new Node(name,age);
    //Inserting new node at head
    new_node->next=head;
    head->prev=new_node;
    head=new_node;
}

//Function to print LinkedList start to end
void print(Node*head){
    Node*temp=head;
    while(temp!=NULL){cout<<"{Name:"<<temp->name<<" Age:"<<temp->age<<"}"<<"<=>";temp=temp->next;}
    cout<<endl;
}

//Function to delete any node excluding last node
void deleteNode(Node*&head,int i){
    if(i==0){
        Node*temp=head;
        head=temp->next;
        head->prev=NULL;
        delete temp;
    }else{
        Node*temp=head;
        for(int j=0;j<i;j++){temp=temp->next;}
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        delete temp;
    }
}

//Function to delete last node
void deleteEnd(Node* &head){
    Node*temp=head;
    while(temp->next!=NULL){temp=temp->next;}
    temp->prev->next=NULL;
    delete temp;
}

int main(){
    //Initialising an linked list
    Node*head=NULL;
	int noOfFamilyMem;
    //Taking numbers of family members as input
	cout<<"Enter Number Of Family Members:";cin>>noOfFamilyMem;
    //Inserting family members details in doubly linked list
	for(int i=1;i<=noOfFamilyMem;i++){
		string name;
		int age;
		cout<<"Enter Family Member "<<i<<" Name:";cin.ignore();getline(cin,name);
		cout<<"Enter Family Member "<<i<<" Age:";cin>>age;
        //appending data name and age in doubly linked list
		append(head,name,age);
	}
    cout<<endl;
    //Displaying Family details
    cout<<"Doubly Linked list with my family members as elements is shown below:"<<endl;
    cout<<endl;
    print(head);
}

/*BONUS QUESTION
Q.Try to find a way to link the family members doubly-linked list based on their relationship.
Ans.One way to link the family members doubly-linked list is by sorting the doubly linked list according to age in decending order.By doing so we will get a doubly linked list in which older generation people will be close to head of double linked list and the new generation people will be close to tail of the doubly linked list.
*/
