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

