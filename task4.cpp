#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Task {
    string name;
    bool status = false; // false for pending, true for completed
};

vector<Task> tasks;

void add_task(const string& name) {
    for (const auto& task : tasks) {
        if (task.name == name) {
            cout << "Task already exists." << endl;
            return;
        }
    }
    tasks.push_back({name, false});
    cout << "Task has been added successfully." << endl;
}

void view_tasks() {
    if (tasks.empty()) {
        cout << "List is empty." << endl;
        return;
    }
    cout << "============================================================" << endl;
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << "Task #" << i + 1 << " - " << tasks[i].name << ", Status: ";
        cout << (tasks[i].status ? "Completed" : "Pending") << endl;
    }
    cout << "============================================================" << endl;
}

void mark_completed(int n) {
    if (n <= 0 || n > tasks.size()) {
        cout << "No such task exists." << endl;
        return;
    }
    tasks[n - 1].status = true;
    cout << "Task #" << n << " has been marked as completed." << endl;
}

void remove_task(int n) {
    if (n <= 0 || n > tasks.size()) {
        cout << "No such task exists." << endl;
        return;
    }
    tasks.erase(tasks.begin() + n - 1);
    cout << "Task #" << n << " has been removed." << endl;
}

int main() {
    cout << "====================================================================================================" << endl;
    cout << "                                                To-Do-List                                          " << endl;
    cout << "====================================================================================================" << endl;
    cout << endl;
    cout << "Press 1 to add a new task" << endl;
    cout << "Press 2 to view all tasks" << endl;
    cout << "Press 3 to mark a task as completed" << endl;
    cout << "Press 4 to remove a task" << endl;
    cout << "Or any other key to end this program" << endl << endl;

    char ch;
    while (true) {
        cout << "Press: ";
        cin >> ch;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer

        if (ch == '1') {
            string name;
            cout << "Enter task: ";
            getline(cin, name);
            cout << endl;
            add_task(name);
        } else if (ch == '2') {
            view_tasks();
        } else if (ch == '3') {
            int n;
            cout << "Enter the task number you want to mark as completed: ";
            cin >> n;
            mark_completed(n);
        } else if (ch == '4') {
            int n;
            cout << "Enter the task number you want to remove: ";
            cin >> n;
            remove_task(n);
        } else {
            break;
        }

        cout << endl << "Press 1 to add a new task" << endl;
        cout << "Press 2 to view all tasks" << endl;
        cout << "Press 3 to mark a task as completed" << endl;
        cout << "Press 4 to remove a task" << endl;
        cout << "Or any other key to end this program" << endl << endl;
    }
    cout << "Program ended." << endl;
    return 0;
}