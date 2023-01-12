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

void insert(struct Node *p, int index, int x){
    // int k=1;
    // struct Node *head = first;
    // p = head;
    struct Node *temp = new Node;

    if(index < 0 || index > length(p)){
        return;
    }

    temp->prev = NULL;
    temp->data =x;
    temp->next = NULL;

    if(index ==0){
        temp->next = first;
        first->prev =temp;
        first =temp;

    }

    else{
        for(int i =0; i <index -1; i++){
            p = p->next;
        }
        temp->prev = p;
        temp->next = p->next;
        
        if(p->next){
            p->next->prev = temp;
            
        }
        p->next = temp;
    }

}

int Delete(struct Node *p, int index){
    int i,x=-1;

    
    if(index < 0 || index > length(p)){
        return -1;
    }
    if(index == 1){
        first = first->next;
        if(first){
            first->prev =NULL;
        }
        x = p->data;
        free(p);
        
    }

    else{
        for(int i =0; i < index-1; i++){
            p = p->next;
        }

        
       
        p->prev->next = p->next;
        if(p->next){
             p->next->prev = p->prev;
        }
        x = p->data;
        free(p);
    }

    return x; 
}

int main(){
    int A[] = {10,2,5,7,1};
    create(A,5);
    Delete(first,2);

    display(first);
    return 0;
}
