// Library management system 
// Features:

// 1. Add book
// 2. Add member
// 3. Issue book
// 4. Return book
// 5. Search book


class Book {
    private:
        string name;
        string serial_number;
    
    public:
        string getName(){
            return this->name;
        }

        int getserialNumber(){
            return this->serial_number;
        }
}

class Member {
    private:
        string name;
        bool is_book_assign;
        string id_no;
    public:
        string getname(){
            return this->name;
        }
        bool isAssign(){
            return this->is_book_assign;
        }
        string findId(){
            return this->id_no;
        }
}

class LibraryManager{
    private:
        

    public:
        

        
}

class Issue{

}

