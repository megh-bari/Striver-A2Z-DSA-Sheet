// brute - hashing
ListNode *detectCycle(ListNode *head)
{
    map<ListNode *, int> mpp;
    ListNode *temp = head;

    while (temp != NULL)
    {
        if (mpp.count(temp) != 0)
        {
            return temp;
        }
        mpp[temp] = 1;
        temp = temp->next;
    }
    return nullptr;
}

// optimal - slow fast (tortoise & hare)

    ListNode* detectCycle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                slow = head;
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return nullptr;
    }