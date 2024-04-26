#include <iostream>
#include <string>

using namespace std;

// ���������� ����� GraduateStudent
class GraduateStudent {
private:
    string name;
    int age;
    string thesisTitle;

public:
    GraduateStudent() : name(""), age(0), thesisTitle("") {}
    GraduateStudent(const string& n, int a, const string& title) : name(n), age(a), thesisTitle(title) {}
    // �������������� ��������� ������ � ���� ��� ��������-����������
    friend ostream& operator<<(ostream& os, const GraduateStudent& gs) {
        os << "Name: " << gs.name << ", Age: " << gs.age << ", Thesis Title: " << gs.thesisTitle;
        return os;
    }
    // �������������� ��������� �������� � ������ ��� ��������-����������
    friend istream& operator>>(istream& is, GraduateStudent& gs) {
        cout << "Enter name: ";
        is >> gs.name;
        cout << "Enter age: ";
        is >> gs.age;
        cout << "Enter thesis title: ";
        is.ignore(); // ��� �������� �������� ���������� �����
        getline(is, gs.thesisTitle);
        return is;
    }
    // ����������� ��������� ��� ��������-����������
    GraduateStudent(const GraduateStudent& other) : name(other.name), age(other.age), thesisTitle(other.thesisTitle) {}

    // �������� ��������� ��� ��������-����������
    GraduateStudent& operator=(const GraduateStudent& other) {
        if (this != &other) {
            name = other.name;
            age = other.age;
            thesisTitle = other.thesisTitle;
        }
        return *this;
    }
};
// ���������� ����� Person
class Person {
protected:
    string lastName;
    string firstName;
    string middleName;
    int age;
    double weight;

public:
    // ����������� �� �������������
    Person() : lastName("NoLastName"), firstName("NoFirstName"), middleName("NoMiddleName"), age(0), weight(0.0) {}

    // ����������� � �����������
    Person(const string& last, const string& first, const string& middle, int a, double w)
        : lastName(last), firstName(first), middleName(middle), age(a), weight(w) {}

    // ����������
    virtual ~Person() {}

    // ������� �����
    virtual void print() const {
        cout << "Last Name: " << lastName << ", First Name: " << firstName
            << ", Middle Name: " << middleName << ", Age: " << age << ", Weight: " << weight << endl;
    }

    // ������� ��������������� ���
    void setAge(int newAge) {
        age = newAge;
    }

    // ������� ��� �������� ����� � ���������
    void input() {
        cout << "Enter Last Name: ";
        cin >> lastName;
        cout << "Enter First Name: ";
        cin >> firstName;
        cout << "Enter Middle Name: ";
        cin >> middleName;
        cout << "Enter Age: ";
        cin >> age;
        cout << "Enter Weight: ";
        cin >> weight;
    }
};

// �������� ���� - ������
class Student : public Person {
public:
    int grade; // г� ��������

    // ����������� �� �������������
    Student() : Person(), grade(0) {}

    // ����������� � �����������
    Student(const string& last, const string& first, const string& middle, int a, double w, int g = 0)
        : Person(last, first, middle, a, w), grade(g) {}

    // ����������
    ~Student() {}

    // ������� �����
    void print() const override {
        Person::print();
        cout << "Grade: " << grade << endl;
    }

    // ������� ��������������� �����
    void setGrade(int newGrade) {
        grade = newGrade;
    }

    // ������� ��� �������� ����� � ���������
    void input() {
        Person::input();
        cout << "Enter Grade: ";
        cin >> grade;
    }
};




