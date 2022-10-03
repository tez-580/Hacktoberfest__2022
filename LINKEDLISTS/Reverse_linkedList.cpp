// This Code Is contributed by Kunal Chauhan
// github:- https://github.com/Kunal-Chauhan7

#include<iostream>

using namespace std;

// Declaring class of Node
class Node{
    public:
    int data;
    Node* next;
    Node(int d){
        this->data = d;
    }
};

void PrintLL(Node* n){
    while(n->next != NULL){
        cout<<n->data<<" -> ";
        n = n->next;
    }
}

void ReverseLL(Node* head){
    Node* curr = head; // makking a node which will point to the current node
    Node* nextN = NULL;  // making a pointer which will point towards next node
    Node* prev = NULL; // making a pointer which will point towards the prev Node
    while(curr->next != NULL){ // Untill current node reaches the End of the Linked List The loop will run
        nextN = curr->next; // we are pointing our next pointer towards the next node from current
        curr->next = prev; // the current node will point towards the previous node now
        prev = curr; // now the previous node will become the next node
        curr = nextN;  // now the current will point towards the next node
    }
    head = prev; // the head will now point to the prev node so that our head will become tail
}

int main(){

    // Making object of class node
    Node* head = new Node(0);
    Node* one = new Node(7);
    Node* two = new Node(14);
    Node* three = new Node(21);
    Node* four = new Node(28);
    Node* tail = new Node(0);
    // providing the next node 
    head->next = one;
    one->next = two;
    two->next = three;
    three->next = four;
    four->next = tail;
    tail->next = NULL;
    cout<<"Link List Before Reversing: "<<endl;
    //priting the linked list
    PrintLL(head);
    //calling the revese linklist 
    ReverseLL(head);
    cout<<"Link List After Reversing: "<<endl;
    //priting the linked list
    PrintLL(four);
    return 0;
}
