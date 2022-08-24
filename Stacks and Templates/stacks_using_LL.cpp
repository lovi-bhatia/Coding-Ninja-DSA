#include <iostream>
using namespace std;

class Node {
   public:
    int data;
    Node *next;

    Node(int data) {
        this->data = data;
        next = NULL;
    }
};



class Stack {
    // Define the data members
    int size;
    Node* head;
   public:
    Stack() {
        // Implement the Constructor
        size = 0;
        head = NULL;
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        // Implement the getSize() function
        return size;
    }

    bool isEmpty() {
        // Implement the isEmpty() function
        return size==0;
    }

    void push(int element) {
        // Implement the push() function
        Node* temp = new Node(element);
        temp->next = head;
        head = temp;
        size++;
    }

    int pop() {
        // Implement the pop() function
        if(!head)
            return -1;
        // creating p to delete it later to empty memory of popped element
        Node* p = head;
        int data = head->data;
        head = head->next;
        size--;
        delete p;
        return data;
    }

    int top() {
        // Implement the top() function
        return head->data;
    }
};

int main() {
    Stack st;

    int q;
    cin >> q;

    while (q--) {
        int choice, input;
        cin >> choice;
        switch (choice) {
            case 1:
                cin >> input;
                st.push(input);
                break;
            case 2:
                cout << st.pop() << "\n";
                break;
            case 3:
                cout << st.top() << "\n";
                break;
            case 4:
                cout << st.getSize() << "\n";
                break;
            default:
                cout << ((st.isEmpty()) ? "true\n" : "false\n");
                break;
        }
    }
}