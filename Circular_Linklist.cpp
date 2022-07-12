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

	// ~Node()
	// {
	// 	int value=this->data;
	// 	this->data=NULL;
	// 	if(this->next!= NULL)
	// 	{
	// 		delete next;
	// 		next=NULL;
	// 	}
	//	cout<<"memory freed is "<<value<<endl;
//
};

void insertAtNode(Node* &tail,int d,int element)
{
	//.........FOR EMPTY LIST
	if(tail==NULL)
	{
		Node* temp=new Node(d);
		tail=temp;
		temp->next=temp;
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

	do{
		cout<<tail->data<<" ";
		tail=tail->next;
	}while(tail!=temp);
	cout<<endl;
}
int main()
{
	Node* tail= NULL;

	insertAtNode(tail,5,1);
	print(tail);
	insertAtNode(tail,19,2);
	print(tail);
	insertAtNode(tail,65,3);
	print(tail);
	return 0;
}