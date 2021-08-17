#include <bits/stdc++.h>

using namespace std;

const double eps = 1e-5;

set<int> bucket[401];

struct Student {
    string sid;
    int cid {};
    string name;
    int chinese {}, math {}, english {}, program {};
    int totalScore {};
    int rank {};
    int passedExam = 0;
    bool removed = false;
};

vector<Student> students;

void remove(const string &q);
void query(const string &q);
void calculateRank();
void generateStatistics(int cid);

void remove(const string &q) {
    int cnt = 0;
    for (auto &student : students) {
        if ((q == student.sid || q == student.name) && !student.removed) {
            student.removed = true;
            cnt++;
        }
    }
    calculateRank();
    cout << cnt << " student(s) removed." << endl;
}

void query(const string &q) {
    for (auto &student : students) {
        if ((student.sid == q || student.name == q) && !student.removed) {
            cout << student.rank << " " << student.sid << " " << student.cid << " " << student.name << " "
                 << student.chinese << " " << student.math << " " << student.english << " " << student.program << " "
                 << student.totalScore << " ";
            cout << fixed << setprecision(2)
                 << (student.chinese + student.math + student.english + student.program) / 4.0 + eps << endl;
        }
    }
}

void calculateRank() {
    for (auto &i : bucket) i.clear();
    for (int i = 0; i < students.size(); i++)
        if (!students[i].removed) bucket[students[i].totalScore].insert(i);
    int rk = 1;
    for (int i = 400; i >= 0; i--) {
        if (!bucket[i].empty()) {
            for (auto j : bucket[i]) students[j].rank = rk;
            rk += int(bucket[i].size());
        }
    }
}

void generateStatistics(int cid) {
    int totalChinese = 0, totalMath = 0, totalEnglish = 0, totalProgramming = 0;
    int passedChinese = 0, passedMath = 0, passedEnglish = 0, passedProgramming = 0;
    int numPass[5] = {0, 0, 0, 0, 0};
    int numStudents = 0;
    for (auto &student : students) {
        if ((cid == 0 || student.cid == cid) && !student.removed) {
            totalChinese += student.chinese;
            totalMath += student.math;
            totalEnglish += student.english;
            totalProgramming += student.program;
            passedMath += (student.math >= 60);
            passedEnglish += (student.english >= 60);
            passedProgramming += (student.program >= 60);
            passedChinese += (student.chinese >= 60);
            numStudents++;
            for (int j = 1; j < 5; j++) numPass[j] += (student.passedExam >= j);
            numPass[0] += (student.passedExam == 0);
        }
    }
    cout << "Chinese\n"
         << "Average Score: " << fixed << setprecision(2) << double(totalChinese) / numStudents + eps << endl;
    cout << "Number of passed students: " << passedChinese << endl
         << "Number of failed students: " << numStudents - passedChinese << endl;
    cout << endl;
    cout << "Mathematics\n"
         << "Average Score: " << fixed << setprecision(2) << double(totalMath) / numStudents + eps << endl;
    cout << "Number of passed students: " << passedMath << endl
         << "Number of failed students: " << numStudents - passedMath << endl;
    cout << endl;
    cout << "English\n"
         << "Average Score: " << fixed << setprecision(2) << double(totalEnglish) / numStudents + eps << endl;
    cout << "Number of passed students: " << passedEnglish << endl
         << "Number of failed students: " << numStudents - passedEnglish << endl;
    cout << endl;
    cout << "Programming\n"
         << "Average Score: " << fixed << setprecision(2) << double(totalProgramming) / numStudents + eps << endl;
    cout << "Number of passed students: " << passedProgramming << endl
         << "Number of failed students: " << numStudents - passedProgramming << endl;
    cout << endl;
    cout << "Overall:\n"
         << "Number of students who passed all subjects: " << numPass[4] << endl
         << "Number of students who passed 3 or more subjects: " << numPass[3] << endl
         << "Number of students who passed 2 or more subjects: " << numPass[2] << endl
         << "Number of students who passed 1 or more subjects: " << numPass[1] << endl
         << "Number of students who failed all subjects: " << numPass[0] << endl;
    cout << endl;
}

int main() {
    while (true) {
        cout << "Welcome to Student Performance Management System (SPMS).\n"
             << endl
             << "1 - Add\n"
             << "2 - Remove\n"
             << "3 - Query\n"
             << "4 - Show ranking\n"
             << "5 - Show Statistics\n"
             << "0 - Exit" << endl;
        cout << endl;
        int operation;
        cin >> operation;
        if (operation == 0) break;
        if (operation == 1) {
            while (true) {
                cout << "Please enter the SID, CID, name and four scores. Enter 0 to finish." << endl;
                string s;
                cin >> s;
                if (s == "0") break;
                bool bad = false;
                for (auto &student : students) {
                    if (s == student.sid && !student.removed) {
                        cout << "Duplicated SID." << endl;
                        bad = true;
                        break;
                    }
                }
                Student Input;
                cin >> Input.cid >> Input.name >> Input.chinese >> Input.math >> Input.english >> Input.program;
                Input.totalScore = Input.chinese + Input.math + Input.english + Input.program;
                Input.sid = s;
                Input.passedExam =
                    (Input.chinese >= 60) + (Input.math >= 60) + (Input.english >= 60) + (Input.program >= 60);
                Input.removed = false;
                if (bad) continue;
                students.push_back(Input);
                calculateRank();
            }
        }
        else if (operation == 2) {
            while (true) {
                cout << "Please enter SID or name. Enter 0 to finish." << endl;
                string input;
                cin >> input;
                if (input == "0") break;
                remove(input);
            }
        }
        else if (operation == 3) {
            while (true) {
                cout << "Please enter SID or name. Enter 0 to finish." << endl;
                string input;
                cin >> input;
                if (input == "0") break;
                query(input);
            }
        }
        else if (operation == 4) cout << "Showing the ranklist hurts students' self-esteem. Don't do that." << endl;
        else if (operation == 5) {
            cout << "Please enter class ID, 0 for the whole statistics." << endl;
            int id;
            cin >> id;
            generateStatistics(id);
        }
    }
    return 0;
}
