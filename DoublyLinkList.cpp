#include<bits/stdc++.h>
using namespace std;

class Node{
public:
	int data;
	Node* prev;
	Node* next;

//....constructor....//
	Node(int d)
	{
		this->data=d;
		this->next=NULL;
		this->prev=NULL;
    } 

    ~Node()
    {
    	int value=this->data;
    	if(next!= NULL)
    	{
    		delete next;
    		next=NULL;
    	}
    	cout<<"Memory free for node with data  "<<value<<endl;
    }
};

void insertnewNode(Node* &head,int d)
{
	if(head==NULL)                 //if there is no list
	{
		Node* temp=new Node(d);
		temp=head;
	}else{
	Node* temp=new Node(d);

	temp->next=head;
	head->prev=temp;
	head = temp;
  	}
}

void insertnewTail(Node* &tail,int d)
{
	Node* temp=new Node(d);
	tail->next=temp;
	temp->prev=tail;
	tail = temp;
}

void insertnewPosition(Node* &head,Node* &tail,int d,int pos)
{
	if(pos==1)
	{
		insertnewNode(head, d);
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
		insertnewTail(tail,d);
		return;  }
		/* code */
	
	Node* nodetoinsert=new Node(d);

	nodetoinsert->next=temp->next;
	temp->next->prev=nodetoinsert;
	temp->next=nodetoinsert;
	nodetoinsert->prev=temp;
}

void todelete(Node* &head,int pos)
{
	if (pos==1)
	{
		Node* temp=head;
		temp->next->prev=NULL;
		head = temp->next;

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
		curr->prev=NULL;
		prev->next=curr->next;
		curr->next=NULL;  
		delete curr;
	}
}
//TO PRINT THE NODE
void print(Node* &head)
{
 	Node* temp=head;

 	while(temp != NULL)
 	{
 		cout<< temp->data<<" ";
 		temp = temp->next;
 	}
 	cout<<endl;
}
//TO GET LENGTH OF THE NODE
int getlength(Node* &head)
{
	int len=0;
	Node* temp=head;

 	while(temp != NULL){
 		temp = temp->next;
 		len++;
 	}
 	return len;
}

int main()
{
	Node* node1=new Node(10);
	Node* head=node1;
	Node* tail=node1;

	//print(head);
	//cout<<getlength(head)<<" ";

	insertnewNode(head,19);
	//print(head);

	insertnewNode(head,21);
	print(head);


 	insertnewTail(tail,25);
	print(head);

	insertnewPosition(head,tail,13,2);

	print(head);

	todelete(head,5);
	print(head);
}