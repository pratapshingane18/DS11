#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node* next;

}*first = NULL;

void create(int A[], int n){
    int i;
    struct Node *t, *last;
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


void display(struct Node *p){
    while(p!= NULL){
        cout<<p->data<<" ";
        p=p->next;
    }
}

void RecursiveDisplay( struct Node *p){
    if(p!=0){
        cout<<p->data<<endl;
        RecursiveDisplay(p->next);
    }
}

void ReverseRecursiveDisplay( struct Node *p){
    if(p!=0){
        
        ReverseRecursiveDisplay(p->next);
        cout<<p->data<<endl;
    }
}

int countNode(struct Node *p){
    int c=0;

    while(p!=0){
        c++;
        p = p->next;

    }

    return c;
}

int countRecursive(struct Node *p){

    if(p==0){
        return 0;
    }
    else{
        return 1 + countRecursive(p->next) ;
    }
}

int sum(struct Node *p){

    int sum =0;
    while(p!=0){
        sum += p->data;
        p = p->next;
    }
    return sum;
}

int sumRecurrsive(struct Node *p){
    if(p ==0){
        return 0;

    }

    else{
        return sumRecurrsive(p->next) + p->data;
    }
}

int MaximumElement(struct Node *p){
    int CurrMax = -32768;
    while(p!=0){
        if(p->data > CurrMax){
            CurrMax = p->data;
            p = p->next;
        }
    }

    return CurrMax;
}

int MaxEleRecursive(struct Node* p){
    int x =0;
    if(p ==0){
        return -32768;
    }

    else{
        x = MaxEleRecursive(p->next);

        // if(x > p->data){
        //     return x;
        // }

        // else{
        //     return p->data;
        // }

        return x>p->data?x:p->data;
    }
}

Node* Search(struct Node *p, int Key){

    while(p!=0){
        if(Key == p->data ){
            cout<<"Element "<<p->data<<" is present in the LL"<<endl;

        }
        
        p=p->next;

    }

    return NULL;
}


Node* searchRecursive(struct Node *p, int key){
    if(p == NULL){
        return NULL;
    }

    if(key == p->data){
        return p;
    }

    return searchRecursive(p->next, key);
}

struct Node* searchfast(struct Node *p, int key){
    struct Node* q = NULL;

    while(p != NULL){
        if(key == p->data){
            q->next = p->next;
            p->next = first;
            first = p;
        }

        q=p;
        p = p->next;
    }
    return 0;
}
int main(){

    struct Node *temp;
    int A[] ={1,2,3,4,5,6};
    create(A,6);
    // ReverseRecursiveDisplay(first);
    temp = searchfast(first ,2);
   if(temp!=NULL){
    cout<<"Element is found"<<endl;
   }
   else{
    cout<<"Element is not found"<<endl;

   } 

   
    display(first);
    return 0;
}

