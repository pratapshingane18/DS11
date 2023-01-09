/*
We can visit next and previous Node Using Doubly Linked List

How to define a Node of Doubly LL

    |prev|data|next|

    struct Node{
        struct Node *prev;
        int data;
        struct Node *next;
    }

    To create a New Node:

    struct Node *t;
    t = new Node;

    t->prev = NULL;
    t->data = 10;
    t->next = NULL;

    Operations of Doubly Linked List:
        * Displaying the linked list
        * Counting the No of Nodes
        * finding Max Min
        * Searching
        * Checking Loop is present or not
        * Concatenate LL
        * Creating List using Insertion
        * Insertion in sorted LL
        * Checking If LL is sorted
        * Merge LL
        * Removing Duplicates
        * Reversing LL
        * Reversing LL using Nodes
        * Sum of data of Nodes of LL
        

Difference in Singly LL and Doubly LL:
        Advanatge of Doubly LL is only that we can move in both the directions

       https://www.geeksforgeeks.org/difference-between-singly-linked-list-and-doubly-linked-list/ 
*/