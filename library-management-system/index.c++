#include <string>
#include <vector>

using namespace std;

// Library management system
// Features:

// Add a book
// Add a member
// Issue a book to a member
// Return a book
// Search for a book
// A book can be either available or issued
// A member can have multiple books
// We should know which member currently has which book,

class Book
{
private:
    string name;
    string serial_number;
    bool is_issued;

public:
    Book(string book_name, string serial_number)
    {
        this->name = book_name;
        this->serial_number = serial_number;
        this->is_issued = false;
    }
    string getName()
    {
        return this->name;
    }
    string getserialNumber()
    {
        return this->serial_number;
    }
    bool isAvailable()
    {
        return !(this->is_issued);
    }
    void markIssued()
    {
        this->is_issued = true;
    }
    void markReturned()
    {
        this->is_issued = false;
    }
};

class Member
{
private:
    string name;
    string member_id;
    vector<string> assigned_books;

public:
    Member(string name, string member_id)
    {
        this->name = name;
        this->member_id = member_id;
        this->assigned_books = {};
    }

    string getname()
    {
        return this->name;
    }
    string findId()
    {
        return this->member_id;
    }
    vector<string> booksAssigned()
    {
        return assigned_books;
    }
    void assignBook(string book_id)
    {
        this->assigned_books.push_back(book_id);
    }

    void removeBook(string book_id)
    {
        // will write the logic to remove the entry from the vector ()
    }
};

class IssueRecord
{
private:
    Book *book;
    Member *member;

public:
    IssueRecord(Book *book, Member *member)
    {
        this->book = book;
        this->member = member;
    }

    void createRecord()
    {
        book->markIssued();
        member->assignBook(book->getserialNumber());
    }

    void deleteRecord()
    {
        this->book->markReturned();
        this->member->removeBook(book->getserialNumber());
    }
};

class LibraryManager
{
private:
    vector<int> book_array() /// book container
        Book book;
    Member member;
    Issue issue;

public:
    void addBook(book book)
    {
        // we will add the book from here
    }

    void Member(Member member)
    {
        // we will add the member from here
    }

    void IssueBook(Member member)
    {
        // we will Issue the book
    }

    void ReturnBook(Book book)
    {
        // we will return the book from here
    }
}
