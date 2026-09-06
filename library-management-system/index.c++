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
    string getName()
    {
        return this->name;
    }

    string getserialNumber()
    {
        return this->serial_number;
    }
    bool isAvailable();
void markIssued();
void markReturned();
}

class Member
{
private:
    string name;
    bool is_book_assign;
    string id_no;

public:
    string getname()
    {
        return this->name;
    }
    bool isAssign()
    {
        return this->is_book_assign;
    }
    string findId()
    {
        return this->id_no;
    }
}

class Issue
{
private:
    Book book;
    Member member;

public:
    IssueBook()
    {
        // mark book is issued
        //  mark book issued to which member
    }

}

class Return
{

}

class LibraryManager
{
private:

    vector<int>book_array() ///book container 
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
