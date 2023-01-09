#include<iostream>
using namespace std;
struct Node{
    struct Node *prev;
    int data;
    struct Node *next;

}*first = NULL;

void create(int A[], int n){
    struct Node *t, *last;
    int i;

    first = new Node;
    first->data = A[0];
    first->prev = NULL;
    first->next = NULL;

    last = first;

    for(i =1; i <n; i++){
        t = new Node;
        t->data = A[i];
        t->next = last->next;
        t->prev = last;
        
        last->next = t;
        last =t;


    }


}

void display(struct Node *p){
    while(p){
        cout<<p->data;
        cout<<" ";
        p = p->next;
    }
    cout<<endl;
}

int length(struct Node *p){
    int length = 0;
     while(p){
        length += p->data;
        p = p->next;
    }
    cout<<endl;

    return length;
}

int main(){
    int A[] = {10,2,5,7,1};
    create(A,5);

    display(first);
    return 0;
}
