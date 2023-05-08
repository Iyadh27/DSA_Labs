#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

struct Node{
    int data;
    Node* next;
};


struct Stack{
    Node* top;
    int sizeOfStack;
    int curSize;

    Stack(){
        top = nullptr;
        curSize = 0;
    }
    
    bool isEmpty(){
        return top ==nullptr;
    }
    
    bool isFull(){
        return curSize == sizeOfStack;
    }
    
    void push(int val){
        if (isFull()){
            cout<<"Stack overflow\n";
            return;
        }else{
            Node* newNode = new Node();
            newNode->data = val;
            newNode->next = top;
            top = newNode;
            curSize++;
        }
        
    }
    
    int pop(){
        if (isEmpty()){
            cout<<"Stack Underflow\n";
            return -1;
        }
       int val = top->data;
       Node* temp = top;
       top = top->next;
       delete temp;
       curSize--;
       return val;
    }
    
    int stacktop(){
        if(isEmpty()){
            cout<<"stack is empty\n";
            return -1;
        }else return top->data;
    }
    
    void display(){
        if (isEmpty()){
            cout<<"Stack is empty\n";
            return;
        }
        Node* temp = top;
        while (temp != nullptr){
            cout<< temp->data<<" ";
            temp = temp->next;
        }cout<<endl;
    }
    
    
};

int main(){
    int size;
    cout<<"Enter the stack size: "<<endl;
    cin>> size;
    Stack LL_stack;
    LL_stack.sizeOfStack = size;
    
    auto start= steady_clock::now();
    LL_stack.push(10);
    LL_stack.push(-120);
    LL_stack.push(50);
    LL_stack.push(-1);
    LL_stack.push(0);
    LL_stack.push(5);
    LL_stack.push(-6);
    LL_stack.push(-1718);
    LL_stack.push(209);
    LL_stack.push(7);
    LL_stack.display();
    LL_stack.pop();
    LL_stack.pop();
    LL_stack.pop();
    LL_stack.pop();
    LL_stack.pop();
    LL_stack.display();
    LL_stack.push(400);
    LL_stack.push(3660);
    LL_stack.push(-63);
    LL_stack.push(21);
    LL_stack.display();
    
    auto end= steady_clock::now();
    auto duration = duration_cast<chrono::nanoseconds>(end - start);
    cout << "Time taken in nanoseconds: "<<duration.count();
    return 0;
    
    
}
