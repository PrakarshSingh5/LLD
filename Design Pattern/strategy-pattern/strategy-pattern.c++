class Person {
private:
    string name;
    string address;
    string phone;
    int age;

public:
    string getName() {
        return name;
    }

    void setAddress(string address) {
        this->address = address;
    }
};

class Student : public Person {
private:
    string className;
    int marks;
    int attendance;

public:
    void study() {
        cout << "Student is studying\n";
    }

    void takeExam() {
        cout << "Student is taking exam\n";
    }

    void checkAttendance() {
        cout << "Attendance: " << attendance << endl;
    }
};

class Teacher : public Person {
private:
    string subject;
    int salary;
    string standard;

public:
    void teach() {
        cout << "Teacher is teaching\n";
    }
};



// Desing Pattern : 

// Class : 
// Operation , Addition , Substraction , Multiplication , Division 
// Variables : a, b

class Operation {
    public : 
     virtual int operation(int a, int b)=0;
};

class Addition:public Operation {
    public: 
     int operation (int a, int b) override{
            return a+b;
     }
};

class Substraction:public Operation {
    public: 
     int operation (int a, int b) override{
            return a-b;
     }
};

class Division:public Operation {
    public: 
     int operation (int a, int b) override{
            return a/b;
     }
};

class Mulitplication:public Operation {
    public: 
     int operation (int a, int b) override{
            return a*b;
     }
};

class Calculator {

private:
    Operation* operation;

public:
     void setOperation(Operation* operation){
        this->operation=operation;
     }
};
int main(){
    Calculator calc;

    calc(setOperation(new Addition()));
    int val = calc.operation(10,20);
    cout<<val;  // 30
}