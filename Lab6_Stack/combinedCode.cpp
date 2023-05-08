#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

//////////////////////// IMPLEMENT STACK USING ARRAY /////////////////////

//implementation of stack using Array 
class Stack1{            //stack class
private:
    int TOP;            //initializing states
    int *Array;
    int sizeOfStack;

public:
    Stack1(int size){        //setting initial values of states
        TOP = -1;
        sizeOfStack = size;
        Array = new int[sizeOfStack];
    }
    
    bool isEmpty(){         //isEmpty function to check if stack is empty
        return TOP ==-1;
    }
    
    bool isFull(){          //isFull function to check if stack is full
        return TOP == sizeOfStack-1;
    }
    
    void push(int val){         //push function
        if (isFull()){
            cout<<"Stack overflow"<<endl;
            return;
        }else{
            TOP++;
            Array[TOP]=val;
        } 
    }
    
    int pop(){                  //pop function
        if (isEmpty()){
            cout<<"Stack Underflow"<<endl;
            return -1;
        }
        return Array[TOP--];
    }
    
    int stacktop(){                         //checking top
        if(isEmpty()){
            cout<<"stack is empty"<<endl;
            return -1;
        }else return Array[TOP];
    }
    
    void display(){                         //displaying stack
        if (isEmpty()){
            cout<<"Stack is empty"<<endl;
            return;
        }
        for(int i =TOP; i>=0;i--){
            cout<<Array[i]<<" ";
        }cout<<endl;
    }
    
    ~Stack1(){
        delete[] Array;
    }
};

////////////////////// IMPLEMENT STACK USING LINKED LIST//////////////

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

///////////////////////////////////////////////////////////////





int main(){
    int size;
    cout<<"Enter the stack size: "<<endl;
    cin>> size;
    
    Stack1 arr_stack(size);          //getting stack size
    
    auto start= steady_clock::now();        //clock running
    arr_stack.push(10);
    arr_stack.push(-120);
    arr_stack.push(50);
    arr_stack.push(-1);
    arr_stack.push(0);
    arr_stack.push(5);
    arr_stack.push(-6);
    arr_stack.push(-1718);
    arr_stack.push(209);
    arr_stack.push(7);
    arr_stack.display();
    arr_stack.pop();
    arr_stack.pop();
    arr_stack.pop();
    arr_stack.pop();
    arr_stack.pop();
    arr_stack.display();
    arr_stack.push(400);
    arr_stack.push(3660);
    arr_stack.push(-63);
    arr_stack.push(21);
    arr_stack.display();
    
    auto end= steady_clock::now();
    auto duration = duration_cast<chrono::nanoseconds>(end - start);
    cout << "Time taken in nanoseconds: "<<duration.count();
    cout << endl<<endl<<endl;
    
    ////////////////////////////////////////////////////////////
    
    Stack LL_stack;
    LL_stack.sizeOfStack = size;
    
    auto start1= steady_clock::now();        //clock running
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
    
    auto end1= steady_clock::now();
    auto duration1 = duration_cast<chrono::nanoseconds>(end1 - start1);
    cout << "Time taken in nanoseconds: "<<duration1.count();
    
    
    return 0;
    
}
