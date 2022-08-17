#include <bits/stdc++.h>

using namespace std;

class Node{
public:
	int data;
	Node* next;

	Node(int data){
		this->data = data;
		this->next = NULL;
	}
};

int main(){

	Node n1(1);
	Node *head = &n1;

	Node n2(2);
	n1.next = &n2;

	// Dynamically
	Node *n3 = new Node(3);
	n2.next = n3;
	Node *n4 = new Node(4);
	// only n4 because n4 is already containing address of next node and we want to pass only address 
	n3 -> next = n4;

	// head = head->next;
	// cout<<head->data;
	while(head){		//means loop till head is not NULL
		cout<<head->data<<" ";
		head = head->next;
	}
}