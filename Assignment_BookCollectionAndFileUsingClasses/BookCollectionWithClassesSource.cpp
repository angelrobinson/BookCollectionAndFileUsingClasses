/********************
*Assignment:  Book Collection And File Using Classes
*For this project you must create a C++ project that will:
*
*-Create a class called Books
*    should contain at least one constructor
*    ensure that all variables associated with your books are data members of the class
*    ensure that all functions associated with your books are member functions of the class
*    ensure that each data member has an accessor, and modifier method.
*
*-Create a vector called bookCollection
*	 Should be a vector of Book objects
*	 When a book is created, users should be prompted to type in:
*		The title of the book
*		The author
*		The Copyright Date
*		Any other additional data
*	 Use the getLine() function rather than just "cin" to get any string user input
*
*-Create a NON-member function which provides a menu for the user to:
*    Add a book to the collection
*    Display the books currently in the collection
*    Remove a book from the collection
*    Stop adding books and store the data in an external file
*
*-Use the “push_back()” function appropriately to add the books to the collection
*-Correctly use an iterator to move through and display the collection
*-Correctly use an iterator for removing a specific book when necessary.
*-Put the collection in alphabetic order before storing to the external file,
*        only after all titles are added and any desired titles have been removed
*        Should happen immediately before the file is written
*-Ensure that the external file is open for writing
*-Name the file appropriately within the programming
*        Do not have the user enter a file name
*-After the collection has been written to the file, make sure the file is correctly closed.
*-Next, open the file for reading, and read the data into a new vector called "displayCollection"
*-Use this vector to display the list of books to the user
*-Lastly the program should ask if the user would like to run the program again
*        If they choose yes, ensure that both vectors are cleared out, and the program starts over again
*        If they choose no, the program should then end
*-Make sure that you use functions for each of the different menu options
*        Creating and displaying the menu itself
*        Adding a book to the list
*        Displaying the current list (Also used at the end of the program)
*        Removing a book from the list
*            This function will call the display function to show the list
*            Then it will ask the user which book they want to remove
*-Also create functions for the following:
*        Writing the collection to the file
*        Clearing out the two vectors at the end of the program (use a pointer for this)
*
*
*
* Author: Angela Robinson
* Date:  June 1, 2018
*
**********************/

// PreProcessor Directives
#include <iostream>
#include <stdio.h>
#include <string>
#include <iomanip>
#include <list>
#include <algorithm>
#include "Books.h"

using namespace std;

int menu();

//Main Program
int main()
{
	//variables
	list<Books> bookCollection;
	list<Books> displayCollection;
	
	int choice;
	char cont = 'Y';

	//code
	while (cont == 'Y')
	{
		//offer menu and get choice
		choice = menu();

		//loop while choice isn't exit
		while (choice != 6)
		{
			switch (choice)
			{
			case 1:
				addBook(bookCollection);
				cout << "adding book. . . " << endl;
				break;
			case 2:
				removeBook(bookCollection);
				break;
			case 3:
				displayBooks(bookCollection);
				break;
			case 4:
				//bookCollection.sort(); //TODO: figure out sort
				saveBooks(bookCollection);
				break;
			case 5:
				openBooks(displayCollection);
				cout << "The saved list you just opened is: \n";
				displayBooks(displayCollection);
				break;
			default:
				cout << "That is not a valid entry, please try again." << endl;
				break;

			}
			
			choice = menu();
		}

		
		cout << "Would you like to run the program again? (Y or N) ";
		cin >> cont;

		cont = toupper(cont);
		
		if (cont == 'Y')
		{
			bookCollection.clear();
			displayCollection.clear();

		}

	}


	//if user doesn't want to run program again
	cin.ignore();//clear buffer
	cout << "Press any key to exit . . .";

	getchar(); //this will accept any charcter including Enter
			   //system("Pause");
	return 0;
}

