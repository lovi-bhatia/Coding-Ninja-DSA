#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

Node *takeinput()
{
    int data;
    cin >> data;
    Node *head = NULL, *tail = NULL;
    while (data != -1)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        cin >> data;
    }
    return head;
}

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node *deleteNode(Node *head, int pos)
{
    // Write your code here.
    Node* temp = head;
    int count = 0;
    if(head==NULL)
        return head;
    if(pos==0){
        return head->next;
        
    }
    while(temp && count<pos-1){
        temp = temp->next;
        count++;
    }
    if(temp==NULL)
        return head;
    
    if(temp->next!=NULL){
        temp->next = temp->next->next;
        
    }
    return head;
        
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        Node *head = takeinput();
        int pos;
        cin >> pos;
        head = deleteNode(head, pos);
        print(head);
    }

    return 0;
}   



// Node* temp = head;
//     Node* p;
//     int count = 0;
//     if(pos == 0){
//         head = head->next;
//         delete temp;
//         return head;
//     }
//     while(count<pos-1){
//         temp = temp->next;
//         count++;
//     }
//     if(temp!=NULL){
//         p = temp->next;
//         temp->next = p->next;
//         p->next = NULL;
//         delete p;
//     }
//     return head;