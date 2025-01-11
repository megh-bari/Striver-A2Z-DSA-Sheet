#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

public:
    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }

public:
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

Node *convertArrToLL(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *mover = head;

    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

int lengthOfLL(Node *head)
{
    int cnt = 0;
    Node *temp = head;
    while (temp)
    {
        temp = temp->next;
        cnt++;
    }
    return cnt;
}

int checkIfPresent(Node* head, int val){
     Node *temp = head;
    while (temp)
    {
        if(temp->data==val) return 1;
        temp = temp->next;
    }
    return 0;
}
int main()
{
    // pointer
    // Node *y = new Node(arr[0], nullptr);
    // cout << y->data;

    // object
    // Node y =  Node(arr[0], nullptr);
    // cout << y.next;
    vector<int> arr = {2, 5, 8, 7};

    Node *head = convertArrToLL(arr);

    // cout << head->data << endl;
    cout << lengthOfLL(head);
    cout << checkIfPresent(head, 5);
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}