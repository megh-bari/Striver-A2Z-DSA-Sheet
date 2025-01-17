// brute

ListNode *middleNode(ListNode *head)
{
    ListNode *temp = head;
    int cnt = 0;
    while (temp != NULL)
    {
        cnt++;
        temp = temp->next;
    }
    int midNode = (cnt / 2) + 1;
    temp = head;
    while (temp != NULL)
    {
        midNode = midNode - 1;
        if (midNode == 0)
            break;
        temp = temp->next;
    }
    return temp;
}

// better/optimal

ListNode *middleNode(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}