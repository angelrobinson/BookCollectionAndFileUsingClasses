#include "Books.h"
#include <iostream>
#include <stdio.h>
#include <string>
#include <iomanip>
#include <vector>
#include <iterator>
#include <algorithm>
#include <fstream>

using namespace std;

Books::Books()
{
	//empty constructor to make empty book
	//user will most likely access the set methods
};

Books::Books(string bTitle, string bAuthor, string bCopyright)
{
	//second constructor to add a book without prompts
	title = bTitle;
	author = bAuthor;
	copyright = bCopyright;
}

Books::~Books()
{
	//deconstructor
};

//get and set access methods
string Books::getTitle() { return title; };
string Books::getAuthor() { return author; };
string Books::getCopyright() { return copyright; };
void Books::setTitle() 
{ 
	//ask user to enter in name of book to add
	cout << "\nWhat is the name of the book you want to add to your collection? ";

	//clear buffer and get full name of book including spaces
	cin.ignore();
	getline(cin, title);
	title[0] = toupper(title[0]); //make sure first letter is capitalized
	
};

void Books::setAuthor() 
{ 
	//ask user to enter in name of book Author to add
	cout << "\nWho is the Author of the Book? ";

	//clear buffer and get full name of book including spaces
	
	getline(cin, author);
	author[0] = toupper(author[0]); //make sure first letter is capitalized
	
};

void Books::setCopyright() 
{ 
	
	int month = 0;
	int day = 0;
	int year = 0;

	//get month of the copyright date
	while (month < 1 || month > 12)
	{
		cout << "\nWhat is the month of the copyright date (1-12)? ";
		cin >> month;

		//verify that input is a digit, if not, change month to 0 so that it is less than 1 and repeats the propmpt
		if (cin.fail())
		{
			cout << "That is not a valid entry.";
			month = 0;
			cin.clear();
			cin.ignore();
		}
	}
	
	// based on what month they gave ask for the day of the month
	switch (month)
	{
	case 2: //if february
	{
		//get year
		while (year < 1000 || year > 9999)
		{
			cout << "What is the Year of the copyright date (yyyy)? ";
			cin >> year;

			if (cin.fail())
			{
				month = 0;
				cin.clear();
				cin.ignore();
			}
		}

		//see if year is a leap year
		if (year % 4 == 0)
		{
			//if leap year ask for 1-29 days
			while (day < 1 || day > 29)
			{
				cout << "What is the day of the copyright date (1-29)? ";
				cin >> day;
				if (cin.fail())
				{
					month = 0;
					cin.clear();
					cin.ignore();
				}
			}
			
		}
		else
		{
			//if not leap year ask for 1-28 days
			while (day < 1 || day > 28)
			{
				cout << "What is the day of the copyright date (1-28)? ";
				cin >> day;
				if (cin.fail())
				{
					month = 0;
					cin.clear();
					cin.ignore();
				}
			}
			
		}
		
		break;
	}
	//if April, June, September, or November ask for days 1-30
	case 4:
	case 6:
	case 9: 
	case 11:
		while (day < 1 || day > 30)
		{
			cout << "What is the day of the copyright date (1-30)? ";
			cin >> day;
			if (cin.fail())
			{
				month = 0;
				cin.clear();
				cin.ignore();
			}
		}
		//because I asked for the year in case 2, I need to ask fo rthe year in all cases.
		while (year < 1000 || year > 9999)
		{
			cout << "What is the Year of the copyright date (yyyy)? ";
			cin >> year;
			if (cin.fail())
			{
				month = 0;
				cin.clear();
				cin.ignore();
			}
		}
		break;
	default:
		//if not Feb or a 30 day month, ask for 1-31 days
		while (day < 1 || day > 31)
		{
			cout << "What is the day of the copyright date (1-31)? ";
			cin >> day;
			if (cin.fail())
			{
				month = 0;
				cin.clear();
				cin.ignore();
			}
		}
		//because I asked for the year in case 2, I need to ask fo rthe year in all cases.
		//TODO: if I have time, put this in it's own method
		while (year < 1000 || year > 9999)
		{
			cout << "What is the Year of the copyright date (yyyy)? ";
			cin >> year;
			if (cin.fail())
			{
				month = 0;
				cin.clear();
				cin.ignore();
			}
		}
		break;
	}
		
	cin.ignore();
	
	
	

	copyright = to_string(month) + "/" + to_string(day) + "/" + to_string(year);
	
};

void Books::displayBook() 
{
	//display book information
	cout << "Book: " << title
		<< "\tAuthor: " << author 
		<< "\tCopyright Date: " << copyright << endl;
};

bool Books::operator==(const Books& book2)
{
	if (title == book2.title && author == book2.author && copyright == book2.copyright)
	{
		return true;
	}
	else
	{
		return false;
	}
	
};

bool Books::operator!=(const Books& book2)
{
	return !(operator==(book2));
};

bool Books::operator<(const Books& book2)const
{
	if (title < book2.title)
	{
		return true;
	}
	else
	{
		return false;
	}
	
};
//friendly functions
int menu()
{
	
	int input = 0;

	cout << std::string(60, '#') << endl;
	cout << "\t What would you like to do today?\n";
	cout << "\t 1. Add A Book\n";
	cout << "\t 2. Remove a Book\n";
	cout << "\t 3. See what books you have\n";
	cout << "\t 4. Save your list of books to file\n";
	cout << "\t 5. Open & display your list of books from file\n";
	cout << "\t 6. Exit\n";
	cout << std::string(60, '#') << endl;
	cout << "\nPlease enter your choice: ";
	cin >> input;


	//verify a number was put in, if not make input zero to flag the default message of not valid entry
	if (cin.fail())
	{
		input = 0;
		cin.clear();
		cin.ignore();
	}
	

	return input;

};


void addBook(list<Books>& collection)
{
	//choice 1 of menu

	//create empty book
	Books book;

	//get information of book set methods
	book.setTitle();
	book.setAuthor();
	book.setCopyright();

	//display information that was entered by user
	book.displayBook();

	//add to the collection
	collection.push_back(book);

};

void displayBooks(list<Books> collection)
{
	//sort the collection
	//collection.sort();
	
	
	int count = 1;
	
	while (!collection.empty())
	{
		//display book information for each book in he list
		cout << count << ". " << endl;
		
		collection.front().displayBook(); 	
		collection.pop_front();
		count++;
	};
	

};


void removeBook(list<Books>& collection)
{
	displayBooks(collection);

	//ask user to enter in name of book to remove
	string bookName;
	
	cout << "What is the name of the book you want to remove from your collection? ";
	
	//clear buffer and get full name of book including spaces
	cin.ignore();
	getline(cin, bookName);

	bookName[0] = toupper(bookName[0]); //make sure first letter is capitalized

	
	
	
	//iterate through the book collection and compare what entered to name
	//delete if matches
	int max = collection.size();
	int count = 1;

	while (count <= max)
	{
		string title = collection.front().getTitle();
		Books temp(title, collection.front().getAuthor(), collection.front().getCopyright());

		if (title != bookName)
		{	

			
			//This is not consistent. The first test I did it seemed to erase the whole list. The second test I did, the programm hung with what seemed to be an infinate loop
			//collection.remove(temp);
			
			collection.push_back(temp);
			
			
		}
		
		collection.pop_front();
		count++;
	

	}

	if (collection.size() == max)
	{
		cout << "That book was not found in the list.\n";
		cout << "Nothing was deleted from the list\n";
	}
	
};

void saveBooks(list<Books> collection)
{
	
	collection.sort();

	//declare file stream
	ofstream saveFile;

	//open file stream
	saveFile.open("Books.txt", ios::in);

	if (saveFile.fail())
	{
		cout << "Something went wrong and the file Books.txt could not be created." << endl;
	}

	//write to the file.
	//this will overwrite what ever was in the file before
	while (!collection.empty())
	{
		cout << "Saving book...\n";
		collection.front().displayBook();
		saveFile << collection.front().getTitle() << '-'
			<< collection.front().getAuthor() << '-'
			<< collection.front().getCopyright() << endl;
		
		collection.pop_front();
		
		
	};
	
	
	
	//close file
	saveFile.close();
};

list<Books> openBooks(list<Books>& collection)
{
	//delcare file stream
	ifstream inFile;

	//open file
	inFile.open("Books.txt");

	if (inFile.fail())
	{
		cout << "There is not a file named Books.txt" << endl;
	}

	//variable to hold the read in name
	string name;
	string author;
	string date;
	
	//read each line
	getline(inFile, name, '-');
	getline(inFile, author, '-');
	getline(inFile, date, '\n');
	//cin.ignore();
	while (inFile.good())
	{
		//inFile >> name >> author >> date;
		getline(inFile, name, '-');
		getline(inFile, author, '-');
		getline(inFile, date, '\n');
		Books temp(name, author, date);
		collection.push_back(temp);
		
	}

	//close file
	inFile.close();

	return collection;
};

