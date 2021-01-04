#include<iostream>
#include "UL_Stack.h"

UL_Stack::UL_Stack(int size)
{
    m_size=size;
    m_top=-1;
    stack= new int[size];
    for (int i = 0; i < size; i++)
    {
        *(stack+i)=0;
    }
}

UL_Stack::~UL_Stack()
{
    //delete[] stack;
}

bool UL_Stack:: isEmpty(){
    return m_top==-1 ? true: false; 
}

bool UL_Stack:: isFull(){
    return m_top==(m_size-1) ? true: false;
}
void UL_Stack:: display(){
    std::cout<<"Stack volume is "<< m_size<< " \tNumber of element is: "<< m_top+1<< std::endl;
    for (int i = 0; i < m_top+1; i++)
    {
        std::cout << i <<" th element is "<< *(stack+i)<< std::endl;
    }
    
}

void UL_Stack :: push(int val){
    if (isFull())
    {
        std::cout<<"\nOVERFLOW\nStack is Full! Could not push "<< val<< "!\n";
    }
    else
    {
        *(stack+(++m_top))=val;
    }
    
}

int UL_Stack:: pop(){
    if (isEmpty())
    {
        std::cout<<"\nUNDERFLOW\nStack is Empty! Return -1\n";
        return -1;
    }
    else
    {
        return *(stack+(m_top--));
    }
}

int UL_Stack :: count(){
    return m_top+1;
}

int UL_Stack :: peek( int pos){
    if (pos>= 0 && pos <= m_top)
    {
        return *(stack+pos);
    }
    else
    {
        std::cout<<"Either Stack is Empty or Wrong Index\tMin Index: 0\tMax Index: "<< count()<< " Return -1\n"; 
        return -1;
    } 
}

void UL_Stack:: change(int val, int pos){
    if (pos>= 0 && pos <= m_top)
    {
        *(stack+pos)=val;
    }
    else
    {
        std::cout<< "Either Stack is Empty or Wrong Index\tMin Index: 0\tMax Index: "<< count()<< "\n";
    }
}