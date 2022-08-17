#include <iostream>

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

Node *midPoint(Node *head)
{
    // Write your code here
    if(head==NULL || head->next==NULL)
    	return head;

    Node* slow = head;
    Node* fast = head;

    while(fast && fast->next && fast->next->next){
    	slow = slow->next;
    	fast = fast->next->next;
    }
    return slow;
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

Node* mergeSort(Node* head) {
	if(head==NULL || head->next == NULL)
		return head;
	Node* mid = midPoint(head);
	Node* half1 = head;
	Node* half2 = mid->next;
	mid->next = NULL;
	half1 = mergeSort(half1);
	half2 = mergeSort(half2);
	return mergeTwoSortedLinkedLists(half1,half2);	
}

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		Node *head = takeinput();
		head = mergeSort(head);
		print(head);
	}

	return 0;
}