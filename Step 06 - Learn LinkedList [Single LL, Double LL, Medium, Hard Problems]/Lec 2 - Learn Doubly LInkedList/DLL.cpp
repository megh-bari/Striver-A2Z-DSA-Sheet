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

// delete the kth element

Node *removeKthElement(Node *head, int k)
{
    if (head == NULL)
        return NULL;

    int cnt = 0;
    Node *kNode = head;

    while (kNode != NULL)
    {
        cnt++;
        if (cnt == k)
            break;

        kNode = kNode->next;
    }

    Node *prev = kNode->back;
    Node *front = kNode->next;

    if (prev == NULL && front == NULL)
    {
        return NULL;
    }
    else if (prev == NULL)
    {
        return removeHead(head);
    }
    else if (front == NULL)
    {
        return removeTail(head);
    }

    prev->next = front;
    front->back = prev;

    kNode->next = NULL;
    kNode->back = NULL;

    delete kNode;

    return head;
}

// delete Node from the DLL

void remoeveNode(Node *temp)
{
    Node *prev = temp->back;
    Node *front = temp->next;

    if (front == NULL)
    {
        prev->next = nullptr;
        temp->back = nullptr;
        free(temp);

        return;
    }

    prev->next = front;
    front->back = prev;

    temp->next = temp->back = nullptr;

    free(temp);
}

// insertion head (before)

Node *insertBeforeHead(Node *head, int val)
{
    Node *newHead = new Node(val, head, nullptr);
    head->back = newHead;
    return newHead;
}
// insertion tail (before)

Node *insertBeforeTail(Node *head, int val)
{
    if (head->next == NULL)
    {
        return insertBeforeHead(head, val);
    }
    Node *tail = head;

    while (tail->next != NULL)
    {
        tail = tail->next;
    }
    Node *prev = tail->back;
    Node *newNode = new Node(val, tail, prev);
    prev->next = newNode;
    tail->back = newNode;
    return head;
}

// insertion kth element (before)

Node *insertBeforeKthElement(Node *head, int k, int val)
{
    if (k == 1)
    {
        return insertBeforeHead(head, val);
    }
    Node *temp = head;
    int cnt = 0;
    while (temp != NULL)
    {
        cnt++;

        if (cnt == k)
            break;
        temp = temp->next;
    }
    Node *prev = temp->back;
    Node *newNode = new Node(val, temp, prev);

    prev->next = newNode;
    temp->back = newNode;

    return head;
}

// insert element in given node (before)

void insertBeforeGivenNode(Node* node, int val){
    Node* prev = node->back;
    Node* newNode = new Node(val, node, prev);

    prev->next = newNode;
    node->back = newNode;
}

int main()
{

    vector<int> arr = {12, 5, 8, 7};
    Node *head = convertArryToDLL(arr);

    // deletion

    // print(head);
    // head = removeHead(head);
    // print(head);

    // head = removeTail(head);
    // print(head);

    // head = removeKthElement(head, 1);
    // print(head);

    // remoeveNode(head->next->next);
    // print(head);

    // insertion

    // head = insertBeforeHead(head, 10);
    // print(head);

    // head = insertBeforeTail(head, 20);
    // print(head);

    // head = insertBeforeKthElement(head, 3, 20);
    // print(head);

    insertBeforeGivenNode(head->next, 100);
    print(head);

    return 0;
}