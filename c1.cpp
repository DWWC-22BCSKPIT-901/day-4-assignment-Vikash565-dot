#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int countStudents(vector<int>& students, vector<int>& sandwiches) {
    queue<int> studentQueue;
    int count0 = 0, count1 = 0;

    for (int student : students) {
        if (student == 0) count0++;
        else count1++;
        studentQueue.push(student);
    }

    for (int sandwich : sandwiches) {
        if ((sandwich == 0 && count0 == 0) || (sandwich == 1 && count1 == 0)) {
            break;
        }

        while (!studentQueue.empty() && studentQueue.front() != sandwich) {
            studentQueue.push(studentQueue.front());
            studentQueue.pop();
        }
        if (studentQueue.front() == sandwich) {
            studentQueue.pop();
            if (sandwich == 0) count0--;
            else count1--;
        }
    }

    return studentQueue.size(); // Number of students unable to eat
}

int main() {
    vector<int> students = {1, 1, 1, 0, 0, 1};
    vector<int> sandwiches = {1, 0, 0, 0, 1, 1};

    cout << "Number of students unable to eat: " << countStudents(students, sandwiches) << endl;

    return 0;
}
