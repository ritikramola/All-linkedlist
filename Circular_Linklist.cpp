#include<bits/stdc++.h>
using namespace std;
class Node{
public:
	int data;
	Node* next;

	Node(int d)
	{
		this->data=d;
		this->next=NULL;
	}

	 ~Node()
	 {
	 	int value=this->data;
		if(this->next!= NULL)
	 	{
	 		delete next;
	 		next=NULL;
	 	}
		cout<<"memory freed is "<<value<<endl;
	}
};

//insertion of data
void insertAtNode(Node* &tail,int element,int d)
{
	//.........FOR EMPTY LIST
	if(tail==NULL)
	{
		Node* new_node=new Node(d);
		tail=new_node;
		new_node->next=new_node;
	}else 
	{
		Node* curr=tail;

		while(curr->data!= element)
		{
			curr=curr->next;
		}

		//element found
		Node* temp=new Node(d);
		temp->next=curr->next;
		curr->next=temp;
	}
}

void print(Node* &tail)
{
	Node* temp=tail;
	//cout<<tail->data<<" ";
	if(tail==NULL)
	{
		cout<<"list is empty";
	}

	do{
		cout<<tail->data<<" ";
		tail=tail->next;
	}while(tail!=temp);
	cout<<endl;
}

//for deleting any node
void todeletion(Node* &tail,int d)
{
	//NULL CASE
	if(tail == NULL)
	{
		cout<<"THE LIST IS EMPTY";
		return;
	}
	else
	{
		//linked list containing any element
		Node* prev=tail;
		Node* curr=prev->next;
		while(curr->data!=d)
		{
			prev=curr;
			curr=curr->next;
		}
		prev->next=curr->next;
		//for 1 linked list
		if(tail==curr)
		{
			tail=NULL;
		}
		//for greater than 2 linked list
		if(tail==curr)
		{
			tail=prev;
		}
		curr->next=NULL;
		delete curr;
	}
}
int main()
{
	Node* tail= NULL;

	insertAtNode(tail,5,3);
	print(tail);
	insertAtNode(tail,3,5);
	print(tail);
	insertAtNode(tail,5,7);
	print(tail);
	insertAtNode(tail,7,8);
	print(tail);
	insertAtNode(tail,3,4);
	print(tail);
	insertAtNode(tail,5,6);
	print(tail);
	todeletion(tail,8);
	print(tail);
	//return 0;
}