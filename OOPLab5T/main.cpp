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




