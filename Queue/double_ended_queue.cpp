// C++ implementation of De-queue using circular
// array
#include<iostream>
using namespace std;

class Deque {
public:
    int* arr;
    int rear;
    int front;
    int size;

    Deque (int size){
        arr = new int[size];
        this->size = size;
        int rear = -1;
        int front = -1;
    }    


    bool isFull(){
        return (front == (rear+1)%size);
    }

    bool isEmpty(){
        return (front == -1 && rear == -1);
    }

    void insertFront(int element){
        if(isEmpty()){
            front = 0;
            rear = 0;
            arr[0] = element;
            return;
        }

        if(isFull()){
            cout<<(-1)<<endl;
            return;
        }
        front = (front+1)%size;
        arr[front] = element;
    }


    void insertRear(int element){
        if(isFull()){
            cout<<(-1)<<endl;
            return;
        }

        if(isEmpty()){
            front = 0;
            rear = 0;
        }
        else
            rear = (rear+1)%size;
        arr[rear] = element;
    }

    void deleteFront(){
        if(isEmpty())
            cout<<(-1)<<endl;
        if(front==rear){
            front = -1;
            rear = -1;
        }
        else{
            front = (front+1)%size;
        }
    }

    void deleteRear(){
        if(isEmpty())
            cout<<(-1)<<endl;
        if(front==rear){
            front = -1;
            rear = -1;
        }
        else{
            rear = (rear+1)%size;
        }
    }

    int getFront(){
        if(isEmpty())
            return -1;
         
        return arr[front];
    }

    int getRear(){
        if(isEmpty() || rear<0)
            return -1;
        return arr[rear];
    }

};

// Driver program to test above function
int main()
{
    Deque dq(10);
    int choice,input;
    while(true) {
        cin >> choice;
        switch (choice) {
            case 1:
                cin >> input;
                dq.insertFront(input);
                break;
            case 2:
                cin >> input;
                dq.insertRear(input);
                break;
            case 3:
                dq.deleteFront();
                break;
            case 4:
                dq.deleteRear();
                break;
            case 5:
                cout << dq.getFront() << "\n";
                break;
            case 6:
                cout << dq.getRear() << "\n";
                break;
            default:
                return 0;
        }
    }
    
    return 0;
}
