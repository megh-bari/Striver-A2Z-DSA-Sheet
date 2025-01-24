Node* findTail(Node* head){
    Node* tail = head;

    while(tail->next!=NULL) tail= tail->next;
    return tail;
}
vector<pair<int, int>> findPairs(Node* head, int k)
{
   vector<pair<int, int>> ans;
   if(head==NULL) return ans;
   Node* left = head;
   Node* right = findTail(head);

   while(left->data<right->data){
       if(left->data+right->data==k){
           ans.push_back({left->data, right->data});
           left = left->next;
           right= right->prev;
       }else if(left->data+right->data<k){
           left = left->next;
       }else
           right= right->prev;
       
   }
   return ans;
}