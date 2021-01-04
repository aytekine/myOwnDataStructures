#ifndef UL_STACK_DEF
#define UL_STACK_DEF

class UL_Stack
{
private:
    int m_size;
    int m_top;
    int *stack;

public:
    UL_Stack(int size);
    ~UL_Stack();

public:
    bool isEmpty();
    bool isFull();
    int pop();
    void push(int val);
    void display();
    int count();
    int peek(int pos);
    void change(int val, int pos);
};
#endif