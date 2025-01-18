// optimal

ListNode *reverseList(ListNode *head)
{
    ListNode *temp = head;
    ListNode *prev = NULL;
    while (temp != NULL)
    {
        ListNode *front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}

// optimal - using recursion

ListNode *reverseList(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    ListNode *newHead = reverseList(head->next);
    ListNode *front = head->next;
    front->next = head;
    head->next = NULL;

    return newHead;
}