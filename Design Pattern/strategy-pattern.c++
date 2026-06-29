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