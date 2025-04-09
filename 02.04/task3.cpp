#include <fstream>
#include <cstring>

using namespace std;

class Student {
private:
    char* fullName;
    char birthDate[15];
    char phone[15];
    char city[30];
    char country[30];
    char schoolName[50];
    char schoolCity[30];
    char schoolCountry[30];
    int groupNumber;

public:
    Student() : fullName(nullptr), groupNumber(0) {}

    Student(const char* name, const char* birth, const char* phoneNum, int group)
        : groupNumber(group) {
        fullName = new char[strlen(name) + 1];
        strcpy(fullName, name);
        strncpy(birthDate, birth, 15);
        strncpy(phone, phoneNum, 15);
    }

    ~Student() {
        delete[] fullName;
    }

    inline const char* getFullName() const { return fullName; }
    inline int getGroupNumber() const { return groupNumber; }

    void input() {
        char temp[100];
        cout << "Enter full name: ";
        cin.getline(temp, 100);
        fullName = new char[strlen(temp) + 1];
        strcpy(fullName, temp);

        cout << "Enter birth date: "; cin.getline(birthDate, 15);
        cout << "Enter phone: "; cin.getline(phone, 15);
        cout << "Enter city: "; cin.getline(city, 30);
        cout << "Enter country: "; cin.getline(country, 30);
        cout << "Enter school name: "; cin.getline(schoolName, 50);
        cout << "Enter school city: "; cin.getline(schoolCity, 30);
        cout << "Enter school country: "; cin.getline(schoolCountry, 30);
        cout << "Enter group number: "; cin >> groupNumber;
        cin.ignore();
    }

    void display() const {
        cout << "Full Name: " << (fullName ? fullName : "N/A")
            cout << "\nBirth Date: " << birthDate
            cout << "\nPhone: " << phone
            cout << "\nCity: " << city
            cout << "\nCountry: " << country
            cout << "\nSchool: " << schoolName
            cout << "\nSchool City: " << schoolCity
            cout << "\nSchool Country: " << schoolCountry
            cout << "\nGroup Number: " << groupNumber << "\n";
    }
};
