#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node *next;
};

class LinkedList{
    private:
    Node *first;
    public:
    LinkedList(){
        first = NULL;
    }
    LinkedList(int A[], int n);
    ~LinkedList();

    void Display();
    void Insert(int index, int x);
    void Delete(int index);
    int Length();
};

LinkedList::LinkedList(int A[], int n){
   
    int i=0;
    Node *t, *last;
    first= new Node;
    first->data = A[0];
    first->next = NULL;
    last=first;

    for(int i =1; i <n; i++){
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last =t;

        
    }

}

LinkedList::~LinkedList(){
    Node *p = first;
    while(first){
        first=first->next;
        delete p;
        p = first;
    }
}

void LinkedList::Display(){
    Node *p = first;
     while(p!= NULL){
        cout<<p->data<<" ";
        p=p->next;
    }
}

int main(){
    int A[]={1,2,4,5};
    LinkedList l(A,4);
    l.Display();
}