// Class representing a node in the linked list
class Node {
    public:
        int data;
        Node* next;
        Node(int new_data) {
            this->data = new_data;
            this->next = nullptr;
        }
    };

    class Stack {

        // head of the linked list
        Node* head;
    
    public:
        // Constructor to initialize the stack
        Stack() { this->head = nullptr; }
    
        // Function to check if the stack is empty
        bool isEmpty() {
          
            // If head is nullptr, the stack is empty
            return head == nullptr;
        }
    
        // Function to push an element onto the stack
        void push(int new_data) {
          
            // Create a new node with given data
            Node* new_node = new Node(new_data);
    
            // Check if memory allocation for the new node
            // failed
            if (!new_node) {
                cout << "\nStack Overflow";
            }
    
            // Link the new node to the current top node
            new_node->next = head;
    
            // Update the top to the new node
            head = new_node;
        }
    
        // Function to remove the top element from the stack
        void pop() {
    
            // Check for stack underflow
            if (this->isEmpty()) {
                cout << "\nStack Underflow" << endl;
            }
            else {
                // Assign the current top to a temporary
                // variable
                Node* temp = head;
    
                // Update the top to the next node
                head = head->next;
    
                // Deallocate the memory of the old top node
                delete temp;
            }
        }
    
        // Function to return the top element of the stack
        int peek() {
    
            // If stack is not empty, return the top element
            if (!isEmpty())
                return head->data;
            else {
                cout << "\nStack is empty";
                return INT_MIN;
            }
        }
    };