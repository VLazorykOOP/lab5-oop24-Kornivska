#include <iostream>
#include <string>

using namespace std;

// Оголошення класу GraduateStudent
class GraduateStudent {
private:
    string name;
    int age;
    string thesisTitle;

public:
    GraduateStudent() : name(""), age(0), thesisTitle("") {}
    GraduateStudent(const string& n, int a, const string& title) : name(n), age(a), thesisTitle(title) {}
    // Перевизначення оператора виводу у потік для студента-дипломника
    friend ostream& operator<<(ostream& os, const GraduateStudent& gs) {
        os << "Name: " << gs.name << ", Age: " << gs.age << ", Thesis Title: " << gs.thesisTitle;
        return os;
    }
    // Перевизначення оператора введення з потоку для студента-дипломника
    friend istream& operator>>(istream& is, GraduateStudent& gs) {
        cout << "Enter name: ";
        is >> gs.name;
        cout << "Enter age: ";
        is >> gs.age;
        cout << "Enter thesis title: ";
        is.ignore(); // Щоб уникнути пропуску наступного вводу
        getline(is, gs.thesisTitle);
        return is;
    }
    // Конструктор копіювання для студента-дипломника
    GraduateStudent(const GraduateStudent& other) : name(other.name), age(other.age), thesisTitle(other.thesisTitle) {}

    // Оператор присвоєння для студента-дипломника
    GraduateStudent& operator=(const GraduateStudent& other) {
        if (this != &other) {
            name = other.name;
            age = other.age;
            thesisTitle = other.thesisTitle;
        }
        return *this;
    }
};
// Оголошення класу Person
class Person {
protected:
    string lastName;
    string firstName;
    string middleName;
    int age;
    double weight;

public:




