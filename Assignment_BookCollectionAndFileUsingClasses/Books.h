#pragma once
#include <string>
#include <stdio.h>
#include <iostream>
#include <list>

using namespace std;

class Books
{
//friendly function
	friend int menu();
	friend void addBook(list<Books> &);
	friend void displayBooks(list<Books>);
	friend void removeBook(list<Books> &); 
	friend void saveBooks(list<Books>);
	friend list<Books> openBooks(list<Books>&);
private:
	string title;
	string author;
	string copyright;

public:
//constructor and deconstructor
	Books();
	Books(string, string, string);
	~Books();
//function Prototypes
	string getTitle();
	string getAuthor();
	string getCopyright();
	void setTitle();
	void setAuthor();
	void setCopyright();
	void displayBook();
	bool operator==(const Books&);
	bool operator!=(const Books&);
	bool operator<(const Books&) const;
};

