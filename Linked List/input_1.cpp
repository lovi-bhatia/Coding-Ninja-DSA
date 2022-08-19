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

Node* inputData(){
	int data;
	cin>>data;
	Node* head = NULL;
	while(data!=-1){
		Node* n = new Node(data);
		if(head == NULL){
			head = n;
		}
		else{
			Node* temp = head;
			while(temp->next){
				temp = temp->next;
			}
			temp->next = n;
		}
		cin>>data;
	}
	return head;
}

void print(Node* head){
	while(head){
		cout<<head->data<<" ";
		head = head->next;
	}
}

int main(){
	Node* head;
	head = inputData();
	print(head);
}