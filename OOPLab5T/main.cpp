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
// ���������� ����� Window
class Window {
protected:
    int width;
    int height;

public:
    Window(int w, int h) : width(w), height(h) {}

    virtual void draw() const {
        cout << "Drawing a window (" << width << "x" << height << ")" << endl;
    }
};

// ���������� ����� TitledWindow
class TitledWindow : public Window {
private:
    string title;

public:
    TitledWindow(int w, int h, const string& t) : Window(w, h), title(t) {}

    void draw() const override {
        cout << "Drawing a titled window (" << width << "x" << height << ") with title: " << title << endl;
    }
};

// ���������� ����� ButtonedWindow
class ButtonedWindow : public Window {
private:
    string buttonText;

public:
    ButtonedWindow(int w, int h, const string& bt) : Window(w, h), buttonText(bt) {}

    void draw() const override {
        cout << "Drawing a buttoned window (" << width << "x" << height << ") with button: " << buttonText << endl;
    }
};

int main() {
    int choice;
    cout << "Select a task:" << endl;
    cout << "1. Task 1 - Person and Student classes" << endl;
    cout << "2. Task 2 - Window, TitledWindow, and ButtonedWindow classes" << endl;
    cout << "3. Task 3 - Student and GraduateStudent classes" << endl;
    cout << "Your choice: ";
    cin >> choice;

    switch (choice) {
    case 1: {
        // Task 1 - Person and Student classes
        // ���������� ����� Person
        Person person1;
        cout << "Enter data for Person 1:" << endl;
        person1.input();
        cout << "\nPerson 1:" << endl;
        person1.print();

        // ���������� ����� Student
        Student student1;
        cout << "\nEnter data for Student 1:" << endl;
        student1.input();
        cout << "\nStudent 1:" << endl;
        student1.print();
        break;
    }
    case 2: {
        // Task 2 - Window, TitledWindow, and ButtonedWindow classes
        // ��������� ��'���� ����� ����� ����
        Window window(200, 100);
        TitledWindow titledWindow(300, 150, "My Titled Window");
        ButtonedWindow buttonedWindow(250, 120, "Click Me");

        // ������ ������ draw() ��� ������� ��'����
        window.draw();
        titledWindow.draw();
        buttonedWindow.draw();
        break;
    }
    case 3: {
        // Task 3 - Student and GraduateStudent classes
        // ���������� ����� GraduateStudent
        GraduateStudent gs1;
        cout << "Enter data for GraduateStudent 1:" << endl;
        cin >> gs1; // �������� � ���������
        cout << gs1 << endl; // ��������� �� �����
        break;
    }
    default:
        cout << "Invalid choice!" << endl;
    }

    return 0;
}




