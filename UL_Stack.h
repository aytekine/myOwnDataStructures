#ifndef UL_STACK_DEF
#define UL_STACK_DEF

class UL_Stack
{
private:
    int m_size; //capacity of the stack
    int m_top;  //current stack pointer, i.e index of the array
    int *stack; // pointer to array

public:
    UL_Stack(int size); //constructor
    ~UL_Stack();        //destructor

public:
    bool isEmpty();     // if 0 stack is not empty, if 1 stack is empty
    bool isFull();      // if 0 stack is not full , if 1 stack is full
    int pop();          // Pop the last element from the Stack as in LIFO pattern
    void push(int val); // Push an element from the Stack as in LIFO pattern
    void display();     // Display all the elements of the Stack NOT FULL CAPACITY
    int count();        // Returns the current index of the stack
    int peek(int pos);  // Returns the <pos>th element of the stack
    void change(int val, int pos);  // Change the <pos>th element of the stack with <val>
};
#endif