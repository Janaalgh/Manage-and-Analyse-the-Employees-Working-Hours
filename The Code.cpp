#include <iostream>
#include <string>
using namespace std;

int main() {
    const int MaxSize = 20;
    const int WeekDays = 5;
    int highest_hour = 0;
    int lowest_hour = 0;
    int highest_day = 0;
    int lowest_day = 0;
    int size = 4;
    string EmployeeNames[MaxSize] = {"Noura", "Aziz", "Deem", "Omar"};
    string DaysOfTheWeek[WeekDays] = {"Sun", "Mon", "Tue", "Wed", "Thu"};
    int HoursWorked[MaxSize][WeekDays] = {
        {8, 7, 7, 5, 9},
        {9, 9, 10, 12, 5},
        {6, 10, 11, 10, 9},
        {8, 11, 5, 8, 12},
    };

    cout << "Name\t";
    for (int i = 0; i < WeekDays; i++) {
        cout << DaysOfTheWeek[i] << "\t";
    }
    cout << endl;

    for (int i = 0; i < size; ++i) {
        cout << endl << EmployeeNames[i] << "\t";
        for (int j = 0; j < WeekDays; ++j) {
            cout << HoursWorked[i][j] << "\t";
        }
    }
    cout << endl;

    for (int i = 0; i < WeekDays; i++) {
        for (int j = 0; j < size; j++) {
            if (HoursWorked[j][i] < 6) {
                HoursWorked[j][i] = 6;
                cout << endl << "The hours for " << EmployeeNames[j] << " on " << DaysOfTheWeek[i] << " was changed to be 6";
            }
        }
    }
    cout << endl << endl;

    cout << "Name\t";
    for (int i = 0; i < WeekDays; i++) {
        cout << DaysOfTheWeek[i] << "\t";
    }
    cout << endl;

    for (int i = 0; i < size; ++i) {
        cout << endl << EmployeeNames[i] << "\t";
        for (int j = 0; j < WeekDays; ++j) {
            cout << HoursWorked[i][j] << "\t";
        }
    }
    cout << endl;

    for (int j = 0; j < MaxSize; ++j) {
        int totalHours = 0;
        for (int i = 0; i < size; ++i) {
            totalHours += HoursWorked[i][j];
        }

        if (totalHours > highest_hour) {
            highest_hour = totalHours;
            highest_day = j;
        }
        if (totalHours < lowest_hour) {
            lowest_hour = totalHours;
            lowest_day = j;
        }
    }

    cout << endl << "The day with the highest total working hours: ";
    switch (highest_day) {
    case 0:
        cout << "SUN";
        break;
    case 1:
        cout << "MON";
        break;
    case 2:
        cout << "TUE";
        break;
    case 3:
        cout << "WED";
        break;
    case 4:
        cout << "THU";
        break;
    default:
        cout << "right";
    }

    cout << endl << "The day with the lowest total working hours: ";
    switch (lowest_day) {
    case 0:
        cout << "SUN";
        break;
    case 1:
        cout << "MON";
        break;
    case 2:
        cout << "TUE";
        break;
    case 3:
        cout << "WED";
        break;
    case 4:
        cout << "THU";
        break;
    default:
        cout << "right";
    }
    cout << endl;

    while (true) {
        cout << "----------------------------------------------------------------------------------------------------------\n";
        cout << "\nChoose one of the following options: \n1. Add a new Employee. \n2. Enquire about an Employee. \n3. Exit. \n\n";
        char choose;
        cin >> choose;

        switch (choose) {
        case 1: {
            if (size < MaxSize) {
                string NewEmployee;
                int DailyHours;

                cout << "Enter Employee Name: ";
                cin >> NewEmployee;

                cout << "Enter the working hours of the week: ";
                for (int j = 0; j < WeekDays; j++) {
                    cin >> DailyHours;

                    HoursWorked[size][j] = DailyHours;
                }

                NewEmployee[0] = toupper(NewEmployee[0]);
                for (int i = 1; i < NewEmployee.length(); i++) {
                    NewEmployee[i] = tolower(NewEmployee[i]);
                }
                EmployeeNames[size] = NewEmployee;
                size++;

                cout << "\nName\t";
                for (int i = 0; i < WeekDays; i++) {
                    cout << DaysOfTheWeek[i] << "\t";
                }
                cout << endl;

                for (int i = 0; i < size; ++i) {
                    cout << endl << EmployeeNames[i] << "\t";
                    for (int j = 0; j < WeekDays; ++j) {
                        cout << HoursWorked[i][j] << "\t";
                    }
                }
                cout << endl;
            } else {
                cout << "The maximum number of employees has been reached. Please choose one of the other two options. \n";
            }
            break;
        }
        case 2: {
            string QueryName;
            cout << "Enter the name of an employee: ";
            cin >> QueryName;

            QueryName[0] = toupper(QueryName[0]);
            for (int i = 1; i < QueryName.length(); i++) {
                QueryName[i] = tolower(QueryName[i]);
            }

            int foundOf = -1;

            for (int i = 0; i < size; i++) {
                if (EmployeeNames[i] == QueryName) {
                    foundOf = i;
                }
            }
            if (foundOf != -1) {
                int weeklyHours = 0;
                for (int j = 0; j < WeekDays; j++) {
                    weeklyHours += HoursWorked[foundOf][j];
                }
                cout << QueryName << " has worked " << weeklyHours << " hours in the week.\n";

                int highestDay = 0;
                for (int i = 0; i < WeekDays; i++) {
                    if (HoursWorked[foundOf][i] > HoursWorked[foundOf][highestDay])
                        highestDay = i;
                }
                cout << "The day that " << QueryName << " has the highest working hours is " << DaysOfTheWeek[highestDay] << endl;

                int salary = 0;
                for (int i = 0; i < WeekDays; i++) {
                    if (HoursWorked[foundOf][i] <= 9) {
                        salary += HoursWorked[foundOf][i] * 100;
                    } else {
                        salary += 9 * 100 + (HoursWorked[foundOf][i] - 9) * 200;
                    }
                }
                cout << QueryName << " Salary: " << salary << " SAR in the week.\n";

            } else {
                cout << "Sorry, the employee does not exist." << endl;
            }
            break;
        }
        case 3: {
            cout << "Thank you for using our system.";
            return 0;
        }
        default: {
            cout << "Invalid choice. Please choose again. \n";
        }
        }
    }

    return 0;
}

