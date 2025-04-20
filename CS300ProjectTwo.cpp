// Generic library imports
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// Struct definition for a course
struct Course {
    string courseID;
    string courseName;
    vector<string> prereqList;
};

// Converts any string to be purely uppercase
string toUpper(string str) {
    for (int i = 0; i < str.length(); i++) {
        str[i] = toupper(str[i]);
    }
    return str;
}

// Load courses from the file into the vector (NO CSVParser FILE)
void loadCourses(string fileName, vector<Course>& courses) {
    ifstream file;
    file.open(fileName);

    // Throws an error if the file name that gets given does not exist
    if (!file.is_open()) {
        cout << "ERROR: Could not open file" << endl;
        return;
    }

    // Grabs all of the line from the file and separates the strings by using the comma as the indicator
    string line;
    while (getline(file, line)) {
        Course course;
        string temp = "";
        int stringCount = 0;

        for (int i = 0; i <= line.length(); i++) {
            if (i == line.length() || line[i] == ',') {
                if (stringCount == 0) {
                    course.courseID = temp;
                }
                else if (stringCount == 1) {
                    course.courseName = temp;
                }
                else {
                    course.prereqList.push_back(temp);
                }
                temp = "";
                stringCount++;
            }
            else {
                temp += line[i];
            }
        }

        courses.push_back(course);
    }

    file.close();
    cout << "Data Loaded Successfully" << endl;
}

// Partitioning function
int partition(vector<Course>& courses, int low, int high) {
    Course pivot = courses[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (courses[j].courseID < pivot.courseID) {
            i++;
            Course temp = courses[i];
            courses[i] = courses[j];
            courses[j] = temp;
        }
    }

    Course temp = courses[i + 1];
    courses[i + 1] = courses[high];
    courses[high] = temp;

    return i + 1;
}

// QuickSort algorithm used for sorting the courses within the vector
void quickSort(vector<Course>& courses, int low, int high) {
    if (low < high) {
        int partitionIndex = partition(courses, low, high);
        quickSort(courses, low, partitionIndex - 1);
        quickSort(courses, partitionIndex + 1, high);
    }
}

// Prints out an alphabetically sorted list for the information in the data file
void printCourseList(vector<Course> courses) {
    quickSort(courses, 0, courses.size() - 1);

    for (int i = 0; i < courses.size(); i++) {
        cout << courses[i].courseID << ", " << courses[i].courseName << endl;
    }
}

// Prints out the info for a singular course
void printCourseInfo(vector<Course> courses, string courseNumber) {
    for (int i = 0; i < courses.size(); i++) {
        if (toUpper(courses[i].courseID) == toUpper(courseNumber)) {
            cout << courses[i].courseID << ", " << courses[i].courseName << endl;
            cout << "Prerequisites: ";

            if (courses[i].prereqList.size() == 0) {
                cout << "None" << endl;
            }
            else {
                for (int j = 0; j < courses[i].prereqList.size(); j++) {
                    cout << courses[i].prereqList[j];
                    if (j < courses[i].prereqList.size() - 1) {
                        cout << ", ";
                    }
                }
                cout << endl;
            }
            return;
        }
    }

    cout << "Course Not Found." << endl;
}

// MAIN program function with menu
int main() {
    vector<Course> courses;
    string fileName;
    string courseNumber;
    int choice = 0;

    while (choice != 9) {
        cout << "\nMenu:" << endl;
        cout << "  1. Load Course Data" << endl;
        cout << "  2. Print Course List" << endl;
        cout << "  3. Print Course Information" << endl;
        cout << "  9. Exit Program" << endl;
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter File Name: ";
            cin.ignore();
            getline(cin, fileName);
            if (fileName.empty()) {
                fileName = "courses.csv";
            }
            loadCourses(fileName, courses);
            break;
        case 2:
            printCourseList(courses);
            break;
        case 3:
            cout << "Enter Course Number: ";
            cin >> courseNumber;
            courseNumber = toUpper(courseNumber);
            printCourseInfo(courses, courseNumber);
            break;
        case 9:
            cout << "Program Closed." << endl;
            break;
        default:
            cout << "Invalid Option." << endl;
            break;
        }
    }

    return 0;
}