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

int length(Node *head) {
   
    int count=0;
    while(head)
    {
        count++;
        head=head->next;
    }
    return count;
}

Node *reverse(Node*head2)
{
    Node *p=head2,*q=NULL,*r=NULL;
    while(p)
    {
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    head2=q;
    return q;
}

bool isPalindrome(Node *head)
{
    if(head==NULL)
        return true;
    //Write your code here
    Node *p=head;
    int x=length(head)/2;
    
    for(int i=1;i<x;i++)
    {
        p=p->next;
    }
    Node *head2=p->next;
    p->next=NULL;
   head2= reverse(head2);
   
    while(head&&head2)
    {
        if(head->data!=head2->data)
            return false;
        head=head->next;
        head2=head2->next;
    }
    return true;
}

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		Node *head = takeinput();
		bool ans = isPalindrome(head);

		if (ans) cout << "true";
		else cout << "false";

		cout << endl;
	}

	return 0;
}