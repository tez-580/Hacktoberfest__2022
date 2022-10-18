#include<bits/stdc++.h>

using namespace std;

class node {
        public:
                int data; // data field
        struct node * next;
};

void display(class node * head) {
        node * current = head; // current node set to head
        //traverse until current node isn't NULL
        while (current != NULL) {
                printf("%d ", current -> data);
                current = current -> next; // go to next node
        }
}

node * creatnode(int d) {
        node * temp = (node * ) malloc(sizeof(node));
        temp -> data = d;
        temp -> next = NULL;
        return temp;
}

//merging two sorted list 
node * mergeList(node * split1, node * split2) {
        node * newhead = NULL;
        //base cases
        if (split1 == NULL)
                return split2;
        if (split2 == NULL)
                return split1;

        if (split1 -> data <= split2 -> data) {
                newhead = split1;
                newhead -> next = mergeList(split1 -> next, split2);
        } else {
                newhead = split2;
                newhead -> next = mergeList(split1, split2 -> next);
        }
        return newhead;
}

//split list for merge sort
void splitList(node * head, node ** split1, node ** split2) {
        node * slow = head;
        node * fast = head -> next;

        while (fast != NULL) {
                fast = fast -> next;
                if (fast != NULL) {
                        slow = slow -> next;
                        fast = fast -> next;
                }
        }

        * split1 = head;
        * split2 = slow -> next;
        //spliting
        slow -> next = NULL;
}

//merge sort
void mergeSort(node ** refToHead) {
        node * head = * refToHead;
        node * split1, * split2;
        //base case
        if (head == NULL || head -> next == NULL) {
                return;
        }
        //split the list in two halves
        splitList(head, & split1, & split2);
        //recursively sort the two halves
        mergeSort( & split1);
        mergeSort( & split2);

        * refToHead = mergeList(split1, split2);

        return;
}

node * findIntersection(node * head1, node * head2) {
        //base case
        if (head1 == NULL && head2 == NULL)
                return NULL;

        node * head4 = NULL, * temp;
        //for inserting the first common node
        while (head1 != NULL && head2 != NULL && head4 == NULL) {
                if (head1 -> data < head2 -> data) {
                        head1 = head1 -> next;
                }
                //intersection nodes(intersection)
                else if (head1 -> data == head2 -> data) {
                        head4 = creatnode(head1 -> data);
                        temp = head4;
                        head1 = head1 -> next;
                        head2 = head2 -> next;
                } else {
                        head2 = head2 -> next;
                }
        }

        //for other common nodes(intersection)
        while (head1 != NULL && head2 != NULL) {
                if (head1 -> data < head2 -> data) {
                        head1 = head1 -> next;
                }
                //intersection nodes
                else if (head1 -> data == head2 -> data) {
                        temp -> next = creatnode(head1 -> data);
                        temp = temp -> next;

                        head1 = head1 -> next;
                        head2 = head2 -> next;
                } else {
                        head2 = head2 -> next;
                }
        }

        return head4;
}

int main() {
        printf("creating the linked list by inserting new nodes at the end\n");
        printf("enter 0 to stop building the list, else enter any integer\n");
        int k;
        node * curr, * temp;
        cout << "enter list1...\n";
        scanf("%d", & k);
        node * head1 = creatnode(k); //buliding list, first node
        scanf("%d", & k);
        temp = head1;

        ///////////////////inserting at the end//////////////////////
        while (k) {
                curr = creatnode(k);
                temp -> next = curr; //appending each node
                temp = temp -> next;
                scanf("%d", & k);
        }
        cout << "displaying list1...\n";
        display(head1); // displaying the list
        cout << "\nenter list2...\n";
        scanf("%d", & k);
        node * head2 = creatnode(k); //buliding list, first node
        scanf("%d", & k);
        temp = head2;

        ///////////////////inserting at the end//////////////////////
        while (k) {
                curr = creatnode(k);
                temp -> next = curr; //appending each node
                temp = temp -> next;
                scanf("%d", & k);
        }
        cout << "displaying list1...\n";
        display(head2);

        //sort both the lists
        mergeSort( & head1);
        mergeSort( & head2);

        cout << "\ndisplaying their intersection...\n";

        node * head4 = findIntersection(head1, head2);
        if (head4)
                display(head4);
        else
                cout << "No intersection found\n";
        return 0;
}
