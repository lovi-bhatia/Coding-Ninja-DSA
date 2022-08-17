#include <bits/stdc++.h>

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

using namespace std;

Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newnode = new Node(data);
		if (head == NULL)
		{
			head = newnode;
			tail = newnode;
		}
		else
		{
			tail->next = newnode;
			tail = newnode;
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

int lengthc(Node* head){
	int count = 0;
	while(head){
		head = head->next;
		count++;
	}
	return count;
}

Node *appendLastNToFirst(Node *head, int n)
{
    //Write your code here
    Node* temp1 = head;
    Node* temp2 = head;
    int length = lengthc(head);
    if(length == 0)
    	return head;

    while(temp2->next){
    	temp2 = temp2->next;
    }
    for(int i=1;i<length-n;i++){
    	temp1 = temp1->next;
    }
    temp2->next = head;
    head = temp1->next;
    temp1->next = NULL;

    return head;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Node *head = takeinput();
		int n;
		cin >> n;
		head = appendLastNToFirst(head, n);
		print(head);
	}
	return 0;
}