#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Task 
{
private:
    string description;
    bool completed;

public:
    Task(string desc) 
    {
        description = desc;
        completed = false;
    }

    void markDone() 
    {
        completed = true;
    }

    bool isDone() const {
        return completed;
    }

    string getDescription() const {
        return description;
    }

    void display(int index) const {
        cout << index + 1 << ". [" << (completed ? 'x' : ' ') << "] " << description << endl;
    }
};

class ToDoList 
{
private:
    vector<Task> tasks;

public:
    void addTask() 
    {
        cout << "Enter task description: ";
        string desc;
        cin.ignore();
        getline(cin, desc);
        tasks.emplace_back(desc);
        cout << "Task added.\n";
    }

    void listTasks() const 
    {
        if (tasks.empty()) 
        {
            cout << "No tasks to show.\n";
            return;
        }

        cout << "\nYour Tasks:\n";
        for (size_t i = 0; i < tasks.size(); ++i) 
        {
            tasks[i].display(i);
        }
    }

    void markTaskDone() 
    {
        listTasks();
        
        if (tasks.empty()) return;

        cout << "Enter task number to mark as done: ";
        int index;
        cin >> index;

        if (index > 0 && index <= tasks.size()) 
        {
            tasks[index - 1].markDone();
            cout << "Task marked as done.\n";
        }
        else 
        {
            cout << "Invalid task number.\n";
        }
    }

    void deleteTask() 
    
    {
        listTasks();
        
        if (tasks.empty()) return;

        cout << "Enter task number to delete: ";
        int index;
        cin >> index;

        if (index > 0 && index <= tasks.size()) 
        {
            tasks.erase(tasks.begin() + index - 1);
            cout << "Task deleted.\n";
        } else 
        {
            cout << "Invalid task number.\n";
        }
    }

    void menu() 
    {
        int choice;
        do {
            cout << "\n--- To-Do List Menu ---\n";
            cout << "1. Add Task\n";
            cout << "2. View Tasks\n";
            cout << "3. Mark Task as Done\n";
            cout << "4. Delete Task\n";
            cout << "0. Exit\n";
            cout << "Enter choice: ";
            cin >> choice;

            switch (choice) 
            {
                case 1: addTask(); break;
                
                case 2: listTasks(); break;
                
                case 3: markTaskDone(); break;
                
                case 4: deleteTask(); break;
                
                case 0: cout << "Goodbye!\n"; break;
                
                default: cout << "Invalid choice.\n";
            }
            
        } while (choice != 0);
    }
};

int main() 
{
    ToDoList app;
    
    app.menu();
    
    return 0;
    }
"
