#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *back;

public:
    Node(int data1, Node *next1, Node *back1)
    {
        data = data1;
        next = next1;
        back = back1;
    }

public:
    Node(int data2)
    {
        data = data2;
        next = nullptr;
        back = nullptr;
    }
};

// array to DLL

Node *convertArryToDLL(vector<int> &arr)
{

    Node *head = new Node(arr[0]);
    Node *prev = head;

    for (int i = 1; i < arr.size(); i++)
    {

        Node *temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }

    return head;
}

void print(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// delete head

Node *removeHead(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }

    Node *prev = head;
    head = head->next;

    head->back = nullptr;
    prev->next = nullptr;

    delete prev;

    return head;
}

// delete tail
Node *removeTail(Node *head)
{

    if (head == NULL || head->next == NULL)
    {
        delete head;
        return NULL;
    }

    Node *tail = head;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }

    Node *newTail = tail->back;
    newTail->next = NULL;
    delete tail;

    return head;
}

int main()
{

    vector<int> arr = {12, 5, 8, 7};
    Node *head = convertArryToDLL(arr);
    // print(head);
    // head = removeHead(head);
    // print(head);

    head = removeTail(head);
    print(head);

    return 0;
}