// Project3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

// Struct for linked list called node
struct node
{
	int data;
	node *next;
}*head = NULL, *tail = NULL, *p = NULL, *np = NULL;



// Function Prototypes
void queue(int value);	// queues integers into the linked list	
void dequeue();			// removes integers from the linked list
void display();			// displays the queued integers from the linked list.



int main()
{
	// Variables
	int choice;			// Variable for user choice on main menu.
	int value;			// Variable for the users Int. they are ading to queue.


	// cout display to welcome the user.
	cout << "Welcome! This program uses a Queue in a Linked List!" << endl;
	while (1) {
		cout << "+++++MENU+++++" << endl;
		cout << "1) Insert Int. into the queue" << endl;
		cout << "2) Delete number of the queue" << endl;
		cout << "3) Display the queue" << endl;
		cout << "4) Exit the program" << endl;
		cout << "Please make a selection by entering a number: ";
		cin >> choice;		// Get the users input for the queue.
		cout << endl;

		// Switch statement to implement users choice.
		switch (choice) {
		case 1: cout << "Enter an Int. to be inserted into the queue: ";
			cin >> value;		// Get the Int. the user wants to put into the queue.
			queue(value);		// Call the insert function and pass the user value.
			break;
		case 2: dequeue();   	// Call the delete function.
			break;
		case 3: display();		// Call the display function.
			break;
		case 4: exit(0);		// Exit the program.
			break;
		default: cout << "You have made an invalid selection. Please try again" << endl << endl;   // Catch error message for invalid selections.

		} // End of switch statement

	}// End of while statement

}// End of Main




void queue(int value)
{
	// Variables
	np = new node;
	np->data = value;
	np->next = NULL;


	if (head == NULL)
	{
		head = tail = np;
		tail->next = NULL;
	}
	else
	{
		tail->next = np;
		tail = np;
		tail ->next = NULL;
	}

	cout << "You have successfully inserted your integer into the list!" << endl << endl;

}// End of Insert




void dequeue()
{
	// Variable
	int x;

	if (head == NULL)
	{
		cout << "Empty Queue. Please insert numbers first!" << endl << endl;
	}
	else
	{
		p = head;
		x = p->data;
		head = head->next;
		delete(p);
		

		cout << "You have successfully deleted your integer" << endl << endl;

	} // End If/Else

		//cout << "You have successfully deleted your integer" << endl << endl;

} // End Dequeue

void display()
{
	if (head == NULL)
	{
		cout << "Empty Queue. Please insert numbers first!" << endl << endl;
	}
	else
	{


		node *temp = head;
		while (temp != NULL)
		{
			cout << temp->data;
			if (temp->next != NULL)
				cout << endl << endl;
			temp = temp->next;
		}

		delete(temp);
	}
}
