// Node class representing a single node in the linked list
class Node {
    public:
        int data;
        Node* next;
        Node(int new_data)
        {
            this->data = new_data;
            this->next = nullptr;
        }
    };

    class Queue {

        // Pointer to the front and the rear of the linked list
        Node *front, *rear;
    
    public:
        // Constructor to initialize the front and rear
        Queue() { front = rear = nullptr; }
    
        // Function to check if hte queu is empty
        bool isEmpty()
        {
            // If the front and rear are null, then the queue is
            // empty, otherwise it's not
            if (front == nullptr) {
                return true;
            }
            return false;
        }
    
        // Function to add an element to the queue
        void enqueue(int new_data) { // push()
    
            // Create a new linked list node
            Node* new_node = new Node(new_data);
    
            // If queue is empty, the new node is both the front
            // and rear
            if (this->isEmpty()) {
                front = rear = new_node;
                return;
            }
    
            // Add the new node at the end of the queue and
            // change rear
            rear->next = new_node;
            rear = new_node;
        }
    
        // Function to remove an element from the queue
        void dequeue() { //pop()
    
            // If queue is empty, return
            if (this->isEmpty()) {
                cout << "Queue Underflow\n";
                return;
            }
    
            // Store previous front and move front one node
            // ahead
            Node* temp = front;
            front = front->next;
    
            // If front becomes nullptr, then change rear also
            // to nullptr
            if (front == nullptr)
                rear = nullptr;
    
            // Deallocate memory of the old front node
            delete temp;
        }
    
        // Function to get the front element of the queue
        int getFront() { // start
          
          // Checking if the queue is empty
            if (this->isEmpty()) {
                cout << "Queue is empty\n";
                return INT_MIN;
            }
            return front->data;
        }
    
        // Function to get the rear element of the queue
        int getRear() { // end
    
          // Checking if the queue is empty
            if (this->isEmpty()) {
                cout << "Queue is empty\n";
                return INT_MIN;
            }
          
            return rear->data;
        }
    };