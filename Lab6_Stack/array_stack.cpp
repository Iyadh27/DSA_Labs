#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

//implementation of stack using Array 
class Stack{            //stack class
private:
    int TOP;            //initializing states
    int *Array;
    int sizeOfStack;

public:
    Stack(int size){        //setting initial values of states
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
    
    ~Stack(){
        delete[] Array;
    }
};

int main(){
    int size;
    cout<<"Enter the stack size: "<<endl;
    cin>> size;
    Stack arr_stack(size);          //getting stack size
    
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
    return 0;
    
    
}
