#include<bits/stdc++.h>

using namespace std;

/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next,*prev;
    Node()
    {
        this->data = 0;
        next = NULL;
        prev= NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
        this->prev= NULL;
    }
    Node(int data, Node* next, Node *prev)
    {
        this->data = data;
        this->next = next;
        this->prev= prev;
    }
};

*/

Node* reverseDLL(Node* head)
{   
    if(head==NULL || head->next == NULL){
        return head;
    }
    Node* last = NULL;
    Node* current = head;

    while(current!=NULL){
        last = current->prev;
        current->prev = current->next;
        current->next = last;
        current = current->prev;
    }

    return last->prev;
}

