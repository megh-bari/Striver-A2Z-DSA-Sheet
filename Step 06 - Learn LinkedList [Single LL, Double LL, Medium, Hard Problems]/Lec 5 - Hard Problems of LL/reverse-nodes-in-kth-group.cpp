Node *reverseLinkedList(Node *head){
    Node *temp = head;
    Node *prev = NULL;

    while (temp != NULL){
        Node *front = temp->next;
        temp->next = prev;

        prev = temp;
        temp = front;
    }
    return prev;
}

Node *findKthNode(Node *temp, int k){
    k -= 1;

    while (temp != NULL && k > 0){
        k--;
        temp = temp->next;
    }
    return temp;
}

Node *kReverse(Node *head, int k){
    Node *temp = head;

    Node *prevLast = NULL;

    while (temp != NULL){
        Node *kthNode = findKthNode(temp, k);

        if (kthNode == NULL){

            if (prevLast){
                prevLast->next = temp;
            }

            break;
        }

        Node *nextNode = kthNode->next;

        kthNode->next = NULL;

        reverseLinkedList(temp);

        if (temp == head){
            head = kthNode;
        }
        else{
            prevLast->next = kthNode;
        }

        prevLast = temp;

        temp = nextNode;
    }
    return head;
}