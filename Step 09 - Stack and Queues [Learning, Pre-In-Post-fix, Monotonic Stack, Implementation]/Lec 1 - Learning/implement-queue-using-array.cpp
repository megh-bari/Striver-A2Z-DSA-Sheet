class Queue {
    public:
      vector<int> arr;
      int size;
      int capacity;
      int front;
  
      Queue(int qSize) {
          size = 0;
          front = 0;
          capacity = qSize;
          arr.resize(qSize);
      }
  
      // Function to add an element
      // to queue.
      void enqueue(int x) {
  
          // If queue is full
          if (size == capacity) {
              return;
          }
  
          arr[size] = x;
  
          // Increment queue size.
          size++;
      }
  
      // Function to pop front
      // element from queue.
      void dequeue() {
  
          // If queue is empty
          if (size == 0) {
              return;
          }
  
          // Shift all the elements
          // to the left.
          for (int i = 1; i < size; i++) {
              arr[i - 1] = arr[i];
          }
  
          // decrement queue size
          size--;
      }
  
      // Function which returns
      // the front element.
      int getFront() {
  
          // If queue is empty
          if (size == 0)
              return -1;
  
          return arr[front];
      }
    }