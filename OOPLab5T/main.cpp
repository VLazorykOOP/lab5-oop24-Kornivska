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
    // Конструктор за замовчуванням
    Person() : lastName("NoLastName"), firstName("NoFirstName"), middleName("NoMiddleName"), age(0), weight(0.0) {}

    // Конструктор з параметрами
    Person(const string& last, const string& first, const string& middle, int a, double w)
        : lastName(last), firstName(first), middleName(middle), age(a), weight(w) {}

    // Деструктор
    virtual ~Person() {}

    // Функція друку
    virtual void print() const {
        cout << "Last Name: " << lastName << ", First Name: " << firstName
            << ", Middle Name: " << middleName << ", Age: " << age << ", Weight: " << weight << endl;
    }

    // Функція перепризначення віку
    void setAge(int newAge) {
        age = newAge;
    }

    // Функція для введення даних з клавіатури
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

// Похідний клас - школяр
class Student : public Person {
public:
    int grade; // Рік навчання

    // Конструктор за замовчуванням
    Student() : Person(), grade(0) {}

    // Конструктор з параметрами
    Student(const string& last, const string& first, const string& middle, int a, double w, int g = 0)
        : Person(last, first, middle, a, w), grade(g) {}

    // Деструктор
    ~Student() {}

    // Функція друку
    void print() const override {
        Person::print();
        cout << "Grade: " << grade << endl;
    }

    // Функція перепризначення класу
    void setGrade(int newGrade) {
        grade = newGrade;
    }

    // Функція для введення даних з клавіатури
    void input() {
        Person::input();
        cout << "Enter Grade: ";
        cin >> grade;
    }
};




