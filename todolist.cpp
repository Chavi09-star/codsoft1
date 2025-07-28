#include <iostream>
#include <vector>
using namespace std;

void show_menu() {
    cout << "\n--- TO-DO LIST MENU ---\n";
    cout << "1. Add a Task\n";
    cout << "2. View Tasks\n";
    cout << "3. Mark Task as Completed\n";
    cout << "4. Remove a Task\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
}

void add_task(vector<string>& task_list, vector<bool>& task_done) {
    string task;
    cout << "Enter task: ";
    cin.ignore();
    getline(cin, task);

    task_list.push_back(task);
    task_done.push_back(false); 
    cout << "Task added!\n";
}

void view_tasks(const vector<string>& task_list, const vector<bool>& task_done) {
    if (task_list.empty()) {
        cout << "No tasks yet.\n";
        return;
    }

    for (int i = 0; i < task_list.size(); i++) {
        cout << i + 1 << ". " << task_list[i];
        if (task_done[i]) {
            cout << " [Done]";
        } else {
            cout << " [Pending]";
        }
        cout << "\n";
    }
}

void mark_task_done(vector<bool>& task_done) {
    int num;
    cout << "Enter task number to mark as done: ";
    cin >> num;

    if (num < 1 || num > task_done.size()) {
        cout << "Invalid task number.\n";
    } else {
        task_done[num - 1] = true;
        cout << "Task marked as done.\n";
    }
}

void remove_task(vector<string>& task_list, vector<bool>& task_done) {
    int num;
    cout << "Enter task number to remove: ";
    cin >> num;

    if (num < 1 || num > task_list.size()) {
        cout << "Invalid task number.\n";
    } else {
        task_list.erase(task_list.begin() + (num - 1));
        task_done.erase(task_done.begin() + (num - 1));
        cout << "Task removed.\n";
    }
}

int main() {
    vector<string> task_list;  
    vector<bool> task_done;    
    int choice;

    do {
        show_menu();
        cin >> choice;

        if (choice == 1) {
            add_task(task_list, task_done);
        } else if (choice == 2) {
            view_tasks(task_list, task_done);
        } else if (choice == 3) {
            mark_task_done(task_done);
        } else if (choice == 4) {
            remove_task(task_list, task_done);
        } else if (choice == 5) {
            cout << "Thank you! Goodbye.\n";
        } else {
            cout << "Please enter a valid option (1-5).\n";
        }

    } while (choice != 5);

    return 0;
}