#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node* next;

}*first = NULL,*second=NULL, *third=NULL;

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

void create2(int B[], int n){
    int i;
    struct Node *t, *last;
    second= new Node;
    second->data = B[0];
    second->next = NULL;
    last=second;

    for(int i =1; i <n; i++){
        t = new Node;
        t->data = B[i];
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

/*
    To Insert before first Node:

    1) Take a new Node t
    2) Initialize with data to store
    3) Make it point on first
    4) Move first to new Node

    Node *t = new Node;
    t->data = 10
    t->next->first;
    first=t;

    How to insert after given position:

    1) Take a new Node t
    2) t points on position +1th Index;
    3) Node pos should point on t;

    \/ - Works perfectly for 1st and last nodes as well:

    Node *t =new Node;
    t->data = 10;
    p=first;

    for(int i=0; i <p-1;i++){
     p = p->next;
    }

    t->next = p->next;
    p->next =t;

   Time for Insertion
   Min-> O(1);
   Max O(n);







*/
void Insertion(struct Node *p,int index,int val){
    int i;
    if(index < 0 || index > countNode(p)){
        return;
    }

    struct Node *t = new Node;
  

    t->data = val;

    if(index == 0){
        t->next=first;
        first=t;
    }

    else{
        for(i=0;i<index-1;i++){
            p=p->next;

        }

        t->next=p->next;
        p->next=t;

    }

}

void InsertionAtLast(struct Node *p, int val){
    struct Node *t = new Node;
    struct Node *last;
    t->data= val;
    t->next = NULL;

    if(first == NULL){
        first = last = t ;
    }

    else{
        last->next =t;
        last = t;

    }


}


void InsertInsortedLL(struct Node *p, int val){
  
    

    struct Node *t, *q = NULL;

    t = new Node;
    t->data = val;

    t->next = NULL;

    if(first == NULL){
        first=t;
    }

    else{
        while(p && p->data < val){
            q =p;
            p = p->next;

        }

        if(p==first){
            t->next =first;
            first-t;
        }

        else{
            t->next = q->next;
            q->next=t;

        }
    }  
}


int Deletion(struct Node *p, int pos){

    struct Node *q = NULL;
    int i,x =-1;

    if(pos < 1 || pos > countNode(p)){
        return -1;
    }

    if(pos==1){
        q =first;
        x=first->data;
        first=first->next;
        free(q);
        return x;

    }

    else{
        for(i =0; i <pos-1;i++){
            q=p;
            p=p->next;
        }

        q->next = p->next;
        x = p->data;
        free(q);
        return x;
    }

}
/* Time 

Min- O(1) - when list is Unsorted
Max- o(n) - when list is sorted

*/
int IsLLSorted(struct Node *p){

    int val = -32768;
   
        while(p){

            
            if(p->data < val){
                return false;
            }
            val = p->data;
            p = p->next;
            
        }
    

    return true;
}


void RemoveDuplicates(struct Node *p){
    struct Node *q = p->next;

    while(q){
        if(p->data != q->data){
            p=p->next;
            q=q->next;
        }

        else{
            p->next=q->next;
            q=q->next;
            free(q);
        }
    }



}

/*Reversing a Linked List
    |- Reversing an Element
    |- Reversing a Node

    

*/

void Reverse(struct Node *p){
  /*  Reversing an Element:
    * Take an Array
    * Copy all elements of LL to that Array
    * Again Reverse copy all element from an array to LL
  */

    int arr[countNode(p)];
    p = first;
    int i=0;
    while(p){
        arr[i] = p->data;
        p= p->next;
        i++;
    }

    p = first;
    i--;

    while(p){
        p->data = arr[i];
        p=p->next;
        i--;
    }


}

void ReverseUsingNode(struct Node *p){
    /*
    Sliding Pointer Approach is used
    3 pointers are used and they are traversed 
    As we are doing it till p becomes null so
     when all the address are changed we will make q as the first Node
     
    */

   struct Node *q = NULL;
   struct Node *r = NULL;

   while(p){
    r =q;
    q=p;
    p=p->next;

    q->next=r;

   }

   first =q;

}


void ReverseRecurssive(struct Node *q, struct Node *p){
    if(p){
        ReverseRecurssive(p,p->next);
        p->next =q;
    }
    else{
        first =q;
    }
}

void concatenate(struct Node *p, struct Node *q){
    third = p;
    while(p->next){
        p = p->next;
    }

    p->next = q;
}

/* Merge LL

Take 2 Integer pointers
    |- first points to first Node of 1st LL;
    |- second points to first Node of 2nd LL;

    * Compare first and Second
    * Take 2 integer Pointers
    * |- Last, Third
    * Points Last and Third to the one which of smaller out of first and second
    * (Consider first is Smaller)
    * Move first to Next Node of first;
    * Now make last->next = NULL;
    * Else if second is smaller then do the same for second
    * 
    * Compare first data with second
    * Make Last->next points on smaller Node
    * Bring Last upon That Node
    * move second to second->next;
    * Make Last as NULL;
    


*/

void Merge(struct Node *p, struct Node *q){
    struct Node *last;
    if(p->data < q->data){
        
        last = third = p;
        p= p->next;
        third->next = NULL;

    }

    else{
        last = third = q;
        q = q->next;
        third->next = NULL;
    }

    while(p && q){
        if(p->data < q->data){
            last->next = p;
            last = p;
            p = p->next;
            last->next = NULL;
           

        }

        else{
            last->next = q;
            last = q;
            q=q->next;
            last->next = NULL;
        }
    }

    if(p!=NULL){
        last->next = p;

    }
   if(q!= NULL){
    last->next = q;
   }

}

/* Check Loop:

If the last Node of LinkedList Points to any Node of the Linked List It forms the Cycle/Loop int he Linked List

If Loop is not present in the Linked List then it is Linear Linked List

Linear LL:
Linked List is Linear if its Last Node is null;

loop or not:
* store address of Node and If you come accross same address again:
* Two pointer
            |- Consider 2 tracks 1 is Linear and second is Circular
            |- If both Node start at same time with different speed then if Track is Linear they won't meet again but if the 
            track is circular, they will meet again.
                    | |
                    \ /
                     v


*/  

int CheckLoop(struct Node *f){
    struct Node *p,*q;
    p=q=f;

    do{
        p=p->next;
        q=q->next;

        q=q?q->next:q;

    }while(p && q && p!=q);

    if(p == q){
        return true;
    }
    else{
        return false;
    }
}







int main(){

    struct Node *t1, *t2;
   int A[] = { 10,30,50,70,90};
   create(A,5);
   
   t1 = first->next->next;
   t2 = first->next->next->next->next;
   t2->next = t1;

   cout<<CheckLoop(first)<<endl;
    return 0;
}

