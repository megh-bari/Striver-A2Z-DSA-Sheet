// struct Node
// {
//     int data;
//     struct Node *next;
//     struct Node *bottom;

//     Node(int x)
//     {
//         data = x;
//         next = NULL;
//         bottom = NULL;
//     }
// };

Node *merge(Node *list1, Node *list2)
{
    Node *dummyNode = new Node(-1);
    Node *res = dummyNode;

    while (list1 != NULL && list2 != NULL)
    {
        if (list1->data < list2->data)
        {
            res->bottom = list1; // Use bottom pointer
            list1 = list1->bottom;
        }
        else
        {
            res->bottom = list2; // Use bottom pointer
            list2 = list2->bottom;
        }
        res = res->bottom;
    }
    if (list1)
        res->bottom = list1;
    else
        res->bottom = list2;

    Node *flattenedList = dummyNode->bottom; // Extract the flattened list
    delete dummyNode;                        // Free memory
    return flattenedList;
}

Node *flatten(Node *root)
{
    if (root == NULL || root->next == NULL)
        return root;

    // Recursively flatten the rest of the list
    Node *mergeHead = flatten(root->next);

    // Disconnect the next pointer to prevent interference
    root->next = nullptr;

    // Merge the current list with the flattened list
    root = merge(root, mergeHead);
    return root;
}