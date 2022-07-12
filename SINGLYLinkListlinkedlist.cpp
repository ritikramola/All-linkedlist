#include<bits/stdc++.h>
using namespace std;

class Node{
public:
	int data;
	Node* next;

//CONSTRUCTOR
	Node(int data)
	{
		this -> data = data;
		this -> next = NULL;
	}
	//DESTRUCTOR
	~Node(){
		int value = this->data;
		//TO FREE
		if(this->next != NULL)
		{
			delete next;
			this->next=NULL;
		}
		cout<<"MEMORY IS FREE AT NODE : "<<value<<endl;
	}
};

//*****************INSERT at HEAD FUNCTION*********************
void insertatHead(Node* &head,int d)  //12 comes here
{
	//create new node
	Node* temp=new Node(d);   //temp=12
	temp->next=head;         //temp ka next to recent head that is 10
	head=temp;				//now temp(i.e 12) is head               {same goes for 56 ,456}
}

//**********TO INSERT AT TAIL**************

void insertatTail(Node* &tail,int d)
{
	Node* temp=new Node(d);
	tail->next=temp;
	tail=temp;
}

//**************TO PRINT THE INSERTED NODE*****************
void print(Node* &head)
{
	Node* temp=head;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
}

//*******************INSERT IN MIDDLE IN GIVEN LINKED LIST(starting,end ,in between)*********** 
                     
void insertatposition(Node* &tail,Node* &head,int pos,int d)
{

//INSERT AT START
	if(pos==1)
	{
		insertatHead(head, d);
		return;
    }

	Node* temp=head;
	int count=1;
	while(count< pos-1)
	{
		temp=temp->next;
		count++;
	}

	if (temp->next == NULL){
		insertatTail(tail,d);
		return;  }
		/* code */
	
	Node* nodetoinsert=new Node(d);
	nodetoinsert->next=temp->next;
	temp->next=nodetoinsert;
}

//***********************************DELETION OF NODE***********************

void deleteNode(int pos,Node* &head)  //pos to delete
{
	//AT HEAD POSITION................
	if (pos==1)
	{
		Node* temp=head;
		head = head->next;
		//memory free
		temp->next=NULL;
		delete temp;
	}else
	{
		//AT LAST AND IN MIDDLE
		Node* curr=head;
		Node* prev=NULL;

		int cnt=1;
		while(cnt < pos)
		{
			prev=curr;
			curr=curr->next;
			cnt++;
		}
		prev->next=curr->next;
		curr->next=NULL;  
		delete curr;
	}
}

int main()
{
	//create new node
	Node* node1=new Node(10);

	//cout<<node1 -> data <<endl;
	//cout<<node1 -> next <<endl;

//***************************INSERT NODE AT HEAD**************************
	//head pointed to node1
	Node* head=node1;
	Node* tail=node1;     //{head and tail are currently Pointing at same address(10) in starting}
	//print(head);

	insertatTail(tail,12);
	//print(head);

	insertatTail(tail,56);

	insertatposition(tail,head,4,30);
	print(head);

	cout<<head->data<<endl;
	cout<<tail->data<<endl;


	deleteNode(4,head);
	print(head);
}





