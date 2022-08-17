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


Node *mergeTwoSortedLinkedLists(Node *head1, Node *head2)
{
    //Write your code here
    if(head1==NULL)
    	return head2;
    if(head2 == NULL)
    	return head1;

    Node *p = NULL, *q=NULL;
    if(head1->data < head2->data){
    	p = head1;
    	q = head1;
    	head1 = head1->next;
    }
    else{
    	p = head2;
    	q = head2;
    	head2 = head2->next;
    }

    while(head1 && head2){
    	if(head1->data<head2->data){
    		q->next = head1;
    		q = q->next;
    		head1 = head1->next;
    	}
    	else{
    		q->next = head2;
    		q = q->next;
    		head2 = head2->next;
    	}
    }
    if(head1)
    	q->next = head1;
 	if(head2)
    	q->next = head2;
       
    return p;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Node *head1 = takeinput();
		Node *head2 = takeinput();
		Node *head3 = mergeTwoSortedLinkedLists(head1, head2);
		print(head3);
	}
	return 0;
}


