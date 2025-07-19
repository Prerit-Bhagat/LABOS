#include<iostream>
using namespace std;
class node
{
	public:
		int data;
		node *next,*prev;
		node(int data)
		{
			this->data=data;
			next=prev=NULL;
		}
};
void print(node *head)
{
	if(!head)return;
	while(head)
	{
		cout<<head->data<<' ';
		head=head->next;
	}
	return;
}
void insertatmid(node *&head)
{
	node *root=head;
	while(root && root->data!=2)
	{
		root=root->next;
	}
	node *newnode=new node(19992);
	if(root->next)
	{
		cout<<"ene\n";
		newnode->next=root->next;
		root->next=newnode;
		newnode->prev=root;
		newnode->next->prev=newnode;
		print(head);
		cout<<endl;
//		root->next->prev=newnode;
//		newnode->next=root->next;
//		root->next=newnode;
//		newnode->prev=root;
		return;
	}
	else
	{
		root->next=newnode;
		newnode->prev=root;
		return;
	}
}
int main()
{
	node *head=new node(1);
	node *body1=new node(2);
	node *body2=new node(3);
	head->next=body1;
	body1->prev=head;
	body1->next=body2;
	body2->prev=body1;
	insertatmid(head);
	print(head);
	
}
