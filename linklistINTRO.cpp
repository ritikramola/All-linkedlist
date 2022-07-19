link list =linear data structure

NODE =[data|(address)next data address]

[3| ]-->[5| ]-->[8| ]

DYNAMIC(GROW AND SHRINK EASILY)


LINKED LIST EXAMPLE

  head	    710        810
{  [5|710]-->[8|810]-->[12|null]   }


TYPES:
1.link list
2.doubly link list
3.cicular link list
4.cicular doubly link list

to implement node
class linkedlistNode{
public:
	int data;
	linkedlistNode * Next;
}


implement on ONElinkedlist.cpp;


*****************SINGLY LINKED LIST***********************

     710          830          1023
[5| ]------>[10| ]----->[12| ]------>[9| null]


...................................INSERTION AT START AND END AND MIDDLE...........................

**InsertAtHead(function)            {SAME FOR TAIL using tail function}

temp->next=head;
head=temp;

it shows reverse answer thats why we use TAIL eg=i/p 2 7 9 o/p 9 7 2

**TAIL(ending node) is used for proper  order of data

adds nodes at the end of linkedlistNode

it gives proper anser eg i/p=1 7 9 10 o/p 1 7 9 10

**MIDDLE(in b/w data)
using middle we can insert node at any postition


************************************DELETION****************

deletenode(pos)

for middlenode 
		 TEMP-> NEXT = CURR->NEXT

FOR LAST nodes
		prev->next=curr->next                //temp = prev

for first node
		there is no prev thatss why we hav to handle differently

	for last and middle node at
		we use prev and curr 2 variables





**************INSERTION,TRAVERSE AND DELETION (ALL ABOVE)******************************************


88888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888
/////////////////////////////////////DOUBLY LINKED LIST/////////////////*****************//


     PREV  DATA  NEXT                           NULL
      [   | 3 |    ]---->[ |   | ]----->[ |   | ]


INSERTION AT HEAD
same as before BUT here we hav to connect 
(in 3 steps)
		temp->next=head;
		head->prev=temp;
		head=temp;

INSERTION AT TAIL
similar to sigle and head;

INSERTION at ANY postition
	same as singly 


	******************CIRCULAR LINKED LIST**********************************************
	same as singly linked list  only 1 difference ;
	here the last node connects to the first node i.e. head;

	
























































































/