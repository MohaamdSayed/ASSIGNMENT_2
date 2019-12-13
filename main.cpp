#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int to_num(string str) {
    // object from the class stringstream
    stringstream data(str);
    // i used strinstream to convert from string to int
    int result = 0;
    data >> result;
    return result;
}

class date {
protected:
    int day = 0, month = 0, year = 0;

    void string_to_int(const string &string_date) {
        int index[2];
        int num = 0;
        for (int i = 0; i < string_date.length(); i++) {
            if (string_date[i] == '-') {
                index[num] = i;
                num++;
            }
        }
        string tempDay = string_date.substr(0, index[0]);
        string tempMonth = string_date.substr(index[0] + 1, index[1] - index[0]);
        string tempYear = string_date.substr(index[1] + 1, 100);
        day = to_num(tempDay);
        month = to_num(tempMonth);
        year = to_num(tempYear);
    }

    string stringDate;
public:
    date(const string &_date = "10-10-2000") {
        string_to_int(_date);
        stringDate = _date;
    };

    void set(const string &_date) {
        string_to_int(_date);
        stringDate = _date;
    }

    void print() {
        cout << stringDate << endl;
    }

    void get(int Grad) {
        cout << day << "-" << month << "-" << year + Grad << endl;
    }

    string getString() {
        return stringDate;
    }


    bool isOlder(const date &date2) {
        return date2.year > year
               || (date2.year == year && date2.month > month)
               || (date2.year == year && date2.month == month && date2.day > day);
    }

    bool isEqual(const date &date2) {
        return (date2.year == year && date2.month == month && date2.day == day);
    }
};

class person {
protected:
    string name;
    date birthday;
public:
    person(const string &_name = "NewPerson", const string &_date = " 10-10-2000") {
        name = _name;
        birthday.set(_date);
    }

    void setName(const string &_name) {
        name = _name;
    }

    void setBday(const string &_date) {
        birthday.set(_date);
    }

    void print() {
        cout << "NAME is " << name;
        cout << "\nBirthday is at " << birthday.getString() << endl;
    }
};

class student : public person {
protected:
    string major;
    date add;
public:
    student(const string &_major = "newStudent", const string &_date = "10-10-2000") {
        major = _major;
        add.set(_date);
    };

    void setAdmission(const string &_date = "10-10-2000") {
        add.set(_date);
    }

    void setMajor(const string &_major) {
        major = _major;
    }

    void print() {
        person::print();
        cout << "The Major is " << major;
        cout << "\nAdmission Date is " << add.getString() << endl;
    }

    void grad_date(int degreeYears = 5) {
        cout << "Graduaton date is ";
        add.get(degreeYears);
    }

};

class instructor : public person {
protected:
    double salary;
    date hiring_date;
public:
    instructor(const double &_salary = 1200, const string &_date = "10-10-2000") {
        salary = _salary;
        hiring_date.set(_date);
    }

    void setSalary(const double &_salary) {
        salary = _salary;
    }

    void set_hiring_date(const string &_date) {
        hiring_date.set(_date);
    }

    void instructor_seniority(instructor teacher2) {
        bool older = hiring_date.isOlder(teacher2.hiring_date);
        bool equal = hiring_date.isEqual(teacher2.hiring_date);
        if (equal) cout << "Both instructor hired same day" << endl;
        else if (older)cout << name << " has seniority above " << teacher2.name << endl;
        else cout << teacher2.name << " has seniority above " << name << endl;
    }

    void print() {
        person::print();
        cout << "Salary is " << salary;
        cout << "\nHiring date is " << hiring_date.getString();
    }
};

int main() {
    student me("Mechanical Engineering", "23-9-2016");
    me.setName("Mohamed Sayed");
    me.setBday("6-6-1997");
    me.print();
    me.grad_date(5);

    instructor teacher1(2000, "1-6-2017"), teacher2(2000, "3-7-2016");
    teacher1.setName("Mohamed");
    teacher2.setName("Basel");
    teacher1.instructor_seniority(teacher2);


    return 0;
}