#include <iostream>
class Node{
public:
    int data;
    Node *next;
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};

using namespace std;

Node* reverseN(Node* head){
    Node* temp = head;

    if(head->next){
        head = reverseN(head->next);
        temp->next->next = temp;
        temp->next = NULL; 
    }

    return head;
}

Node* NextLargeNumber(Node *head) {

    head = reverseN(head);

    int carry = 1,num;
    Node* prev = NULL;
    Node* curr = head;
    while(curr){
        num = ((curr->data)+carry)%10;
        carry = ((curr->data)+carry)/10;
        curr->data = num;
        prev = curr;
        curr = curr->next;
    }

    if(carry){
        Node* newNode = new Node(carry);
        prev->next = newNode;
    }

    return reverseN(head);
}

Node* takeinput() {
    int data;
    cin >> data;
    Node* head = NULL, *tail = NULL;
    while(data != -1){
        Node *newNode = new Node(data);
        if(head == NULL)                  {
            head = newNode;
            tail = newNode;
        }
        else{
            tail -> next = newNode;
            tail = newNode;
        }
        cin >> data;
    }
    return head;
}

void print(Node *head) {
    Node *temp = head;
    while(temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout<<endl;
}

int main() {
    Node *head = takeinput();
    
    head = NextLargeNumber(head);
    print(head);
    return 0;
}



