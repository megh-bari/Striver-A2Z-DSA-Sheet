//! I added comments using ChatGPT to understand this imp problem

class LFUCache {
    public:
        // Node structure for doubly linked list
        struct Node {
            int key, value, cnt;  // cnt tracks frequency of access
            Node* next;
            Node* prev;
            Node(int _key, int _value) {
                key = _key;
                value = _value;
                cnt = 1;  // Initialize frequency count to 1
            }
        };
        
        // Doubly linked list to store nodes with same frequency
        struct List {
            int size;
            Node* head;  // Dummy head node
            Node* tail;  // Dummy tail node
            List() {
                head = new Node(0, 0);
                tail = new Node(0, 0);
                head->next = tail;
                tail->prev = head;
                size = 0;
            }
            
            // Add node at front of list (after dummy head)
            void addFront(Node* node) {
                Node* temp = head->next;
                node->next = temp;
                node->prev = head;  // Fixed: was head->prev = head
                head->next = node;
                temp->prev = node;
                size++;
            }
    
            // Remove node from list
            void removeNode(Node* deleteNode) {
                Node* delPrev = deleteNode->prev;
                Node* delNext = deleteNode->next;
                delPrev->next = delNext;
                delNext->prev = delPrev;
                size--;
            }
        };
    
        map<int, Node*> keyNode;         // Maps key to its node
        map<int, List*> freqList;        // Maps frequency to list of nodes with that frequency
        int maxSizeCache;                // Maximum capacity
        int minFreq;                     // Current minimum frequency
        int currSize;                    // Current size of cache
        
        LFUCache(int capacity) {
            maxSizeCache = capacity;
            minFreq = 0;
            currSize = 0;
        }
        
        // Update node frequency after access
        void updateFreqList(Node* node) {
            keyNode.erase(node->key);
            freqList[node->cnt]->removeNode(node);
            
            // Update minFreq if needed
            if(node->cnt == minFreq && freqList[node->cnt]->size == 0) { 
                minFreq++;
            }
            
            // Get or create the next frequency list
            List* nextHigherFreqList = nullptr;  
            if(freqList.find(node->cnt+1) != freqList.end()) {
                nextHigherFreqList = freqList[node->cnt + 1];
            } else {
                nextHigherFreqList = new List();  // Create new list if not exists
            }
            
            node->cnt += 1;
            nextHigherFreqList->addFront(node);
            freqList[node->cnt] = nextHigherFreqList;
            keyNode[node->key] = node;
        }
    
        // Get value for key, returns -1 if not found
        int get(int key) {
            if(keyNode.find(key) != keyNode.end()) {
                Node* node = keyNode[key];
                int val = node->value;
                updateFreqList(node); 
                return val;
            }
            return -1;
        }
    
        // Insert or update key-value pair
        void put(int key, int value) {
            if(maxSizeCache == 0) {
                return;
            }
            
            // If key exists, update value and frequency
            if(keyNode.find(key) != keyNode.end()) {
                Node* node = keyNode[key];
                node->value = value;
                updateFreqList(node);  
                return; 
            }
            
            // If at capacity, remove least frequently used element
            if(currSize == maxSizeCache) {
                // Remove LFU node (least recently used among least frequent)
                List* list = freqList[minFreq];
                keyNode.erase(list->tail->prev->key);  
                list->removeNode(list->tail->prev);  
                currSize--;
            }
            
            // Add new node with frequency 1
            currSize++;
            minFreq = 1;
            List* listFreq = nullptr;  
            if(freqList.find(minFreq) != freqList.end()) {
                listFreq = freqList[minFreq];
            } else {
                listFreq = new List();
            }
            
            Node* node = new Node(key, value);
            listFreq->addFront(node);
            keyNode[key] = node; 
            freqList[minFreq] = listFreq;
        }
    };
    
    /**
     * Your LFUCache object will be instantiated and called as such:
     * LFUCache* obj = new LFUCache(capacity);
     * int param_1 = obj->get(key);
     * obj->put(key,value);
     */