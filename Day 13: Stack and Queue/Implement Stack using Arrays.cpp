class Stack {

private:

    int ptr=-1;

    int size;

    int* arr;

public:

    

    Stack(int capacity) {

        this->size=capacity;

        arr = new int[capacity];

    }

 

    void push(int num) {

        if(isFull()){

            return;

        }

        ptr++;

        arr[ptr]=num;

    }

 

    int pop() {

        if(isEmpty()){

            return -1;

        }

        return arr[ptr--];

    }

    

    int top() {

        if(isEmpty()){

            return -1;

        }

        return arr[ptr];

    }

    

    int isEmpty() {

        return ptr==-1;

    }

    

    int isFull() {

        return ptr==size-1;

    }

    

};
