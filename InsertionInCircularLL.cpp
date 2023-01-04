/*
Insertion Before Head
Insertion at any position

Insertion at any position
- new Node t;
-t points to next of node you want to insert after
- the node you want to insert after points to t

Insertion Before Head:
- Make new Node t;
- t points to Head;
- The last node of the LL points to t

Logically No need to Move Head



*/

#include <iostream>
using namespace std;
 
class Node{
public:
    int data;
    Node* next;
};
 
class CircularLinkedList{
private:
    Node* head;
public:
    CircularLinkedList(int A[], int n);
    void Display();
    void recursiveDisplay(Node* p);
    Node* getHead(){ return head; }
    ~CircularLinkedList();
    void Insert(Node *p, int index, int x);
    int Length(Node *p);

   
};
 
CircularLinkedList::CircularLinkedList(int *A, int n) {
 
    Node* t;
    Node* tail;
 
    head = new Node;
 
    head->data = A[0];
    head->next = head;
    tail = head;
 
    for (int i=1; i<n; i++){
        t = new Node;
        t->data = A[i];
        t->next = tail->next;
        tail->next = t;
        tail = t;
    }
}
 
void CircularLinkedList::Display() {
    Node* p = head;
    do {
        cout << p->data << " -> " << flush;
        p = p->next;
    } while (p != head);
    cout << endl;
}
 
void CircularLinkedList::recursiveDisplay(Node *p) {
    static int flag = 0;
    if (p != head || flag == 0){
        flag = 1;
        cout << p->data << " -> " << flush;
        recursiveDisplay(p->next);
    }
    flag = 0;
}
 
CircularLinkedList::~CircularLinkedList() {
    Node* p = head;
    while (p->next != head){
        p = p->next;
    }
 
    while (p != head){
        p->next = head->next;
        delete head;
        head = p->next;
    }
 
    if (p == head){
        delete head;
        head = nullptr;
    }
 
}
 
 int CircularLinkedList:: Length(Node *p){
    int len =0;

    do{
        len++;
        p=p->next;

    }
    while(p!=head);

    return len;

 }
 void CircularLinkedList:: Insert(Node *p, int index, int x){
    Node *t;
    int i;

    if(index < 0 || index>Length(p)){
        return;
    }

    if(index ==0){
        t= new Node;
        t->data =x;

        if(head == NULL){
            head =t;
            head->next = head;
        }

        while(p->next != NULL){
            p = p->next;
        }
        p->next = t;
        t->next = head;
        head=t;

    }

    else{
        for(int i =0; i <index -1; i++){
           p=p->next;
        }

        t = new Node;
        t->data = x;
        t->next = p->next;
        p->next = t;

    }

 }
int main() {
 
    int A[] = {1, 3, 5, 7, 9};
    
    CircularLinkedList cl(A, sizeof(A)/sizeof(A[0]));
    Node* h = cl.getHead();
    cl.Insert(h,2,100);
    cl.Display();
 
    
    cl.recursiveDisplay(h);
 
    return 0;
}
