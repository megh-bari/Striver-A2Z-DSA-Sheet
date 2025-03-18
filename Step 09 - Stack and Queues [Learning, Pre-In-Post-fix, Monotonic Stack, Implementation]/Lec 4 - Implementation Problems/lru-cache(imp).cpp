//! I added comments using ChatGPT to understand this imp problem

class LRUCache {
    public:
        class node {
        public:
            int key;    
            int val;    
            node* next; 
            node* prev; 
            
            // Constructor
            node(int _key, int _val) {
                key = _key;
                val = _val;
            }
        };
    
        // Dummy nodes to mark the boundaries of the DDL
        node* head = new node(-1, -1); 
        node* tail = new node(-1, -1); 
        int cap; // Capacity of the LRU Cache
        unordered_map<int, node*> mpp; // Hash map to store key-node pairs
    
        LRUCache(int capacity) {
            cap = capacity;
            
            // Initialize the DDL with dummy nodes
            head->next = tail;
            tail->prev = head;
        }
    
        // Function to insert a new node after the head node
        void insertAfter(node* newNode) {
            node* temp = head->next;    // Point to the current first node
            newNode->next = temp;       // New node points to current first node
            newNode->prev = head;       // New node's previous is head
            head->next = newNode;       // Head now points to the new node
            temp->prev = newNode;       // Current first node's previous is new node
        }
    
        // Function to delete a specific node from the DDL
        void deletionOfNode(node* delNode) {
            node* delPrev = delNode->prev;  // Previous node of the node to delete
            node* delNext = delNode->next;  // Next node of the node to delete
            delPrev->next = delNext;        // Link previous node to next node
            delNext->prev = delPrev;        // Link next node to previous node
        }
    
        // Function to get the value of a key from the LRU Cache
        int get(int key) {
            if (mpp.find(key) != mpp.end()) {   // If key exists in the cache
                node* resnode = mpp[key];       // Get the corresponding node
                int res = resnode->val;         // Get the value associated with the key
                mpp.erase(key);                 // Remove key from hash map
                deletionOfNode(resnode);        // Delete the node from current position
                insertAfter(resnode);           // Move the node to the front of the list
                mpp[key] = head->next;          // Update hash map with new position
                return res;                     // Return the value
            }
            return -1;  // Return -1 if key is not found
        }
    
        // Function to put a key-value pair into the LRU Cache
        void put(int key, int value) {
            if (mpp.find(key) != mpp.end()) {   // If key already exists
                node* existingNode = mpp[key];  // Get the existing node
                mpp.erase(key);                 // Remove key from hash map
                deletionOfNode(existingNode);   // Delete the node from current position
            }
            if (mpp.size() == cap) {            // If cache is at full capacity
                mpp.erase(tail->prev->key);     // Remove the least recently used node from hash map
                deletionOfNode(tail->prev);     // Delete the least recently used node
            }
            insertAfter(new node(key, value));  // Insert new node with key-value pair
            mpp[key] = head->next;              // Update hash map with new node position
        }
    };