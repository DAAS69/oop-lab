#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Calendar {
    string task;
    int year;
    string** months;

public:
    Calendar() {
        months = new string*[12];

        for (int i = 0; i < 12; i++) {
            int daysInMonth = findMax(i + 1);
            months[i] = new string[daysInMonth];
        }
    }

    void set_year(int year) {
        this->year = year;
    }

    int findMax(int month) {		
        if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
            return 31;
        else if (month == 4 || month == 6 || month == 9 || month == 11)
            return 30;
        else
            return 28;
    }

    void add_task(string task, int day, int month) {
        if (month < 1 || month > 12 || day < 1 || day > findMax(month)) {
            cout << "Invalid date!" << endl;
            return;
        }
        months[month - 1][day - 1] = task;
        cout << "Task Added: " << task << " on " << day << "/" << month << "/" << year << endl;
    }

    void remove_task(int day, int month) {
        if (month < 1 || month > 12 || day < 1 || day > findMax(month)) {
            cout << "Invalid date!" << endl;
            return;
        }
        months[month - 1][day - 1] = "";
        cout << "Task Removed from: " << day << "/" << month << "/" << year << endl;
    }

    void show_task() {
        cout << "\n" << endl;
        cout << left << setw(20) << "Task" << setw(20) << "DATE" << endl;
        cout << endl;
        for (int i = 0; i < 12; i++) {
            int max = findMax(i + 1);
            for (int j = 0; j < max; j++) {
                if (!months[i][j].empty()) {
                    cout << left << setw(20) << months[i][j] << j + 1 << "/" << i + 1 << "/" << year << endl;
                }
            }
        }
        cout << "\n" << endl;
    }

    ~Calendar() {
        for (int i = 0; i < 12; i++) {
            delete[] months[i];
        }
        delete[] months;
        cout << "Calendar Destroyed!" << endl;
    }
};

int main() {
    Calendar calendar;
    calendar.set_year(2025);
    calendar.add_task("hello world", 21, 12);
    calendar.add_task("study oop", 10, 2);
    calendar.add_task("study dld", 11, 2);

    calendar.show_task();
    return 0;
}
