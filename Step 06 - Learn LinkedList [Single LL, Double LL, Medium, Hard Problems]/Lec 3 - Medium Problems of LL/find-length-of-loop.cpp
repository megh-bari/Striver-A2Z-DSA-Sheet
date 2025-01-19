// brute hashing 
int lengthOfLoop(Node *head) {
    unordered_map<Node*, int> mpp;

    Node* temp = head;
    int timmer = 0;
    while (temp != NULL) {
        if (mpp.find(temp) != mpp.end()) {
            int loopLength = timmer - mpp[temp];
            return loopLength;
        }
        mpp[temp] = timmer;
        temp = temp->next;
        timmer++;
    }
  
    return 0;
}
// optimal - tortoise and hare algo

int findeLength(Node *slow, Node *fast) {
  int cnt = 0; 
  do {
    cnt++;
    fast = fast->next;
  } while (slow != fast);

  return cnt;
}


int lengthOfLoop(Node *head) {
  Node *slow = head;
  Node *fast = head;

  while (fast != NULL && fast->next != NULL) {
    slow = slow->next;
    fast = fast->next->next;

    if (slow == fast) {

      return findeLength(slow, fast);
    }
  }
  return 0;
}