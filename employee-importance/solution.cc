/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        map<int, Employee*> idToEmployee;
        stack<int> employeeStack;
        for (Employee *staff : employees) {
            idToEmployee.insert(std::pair<int, Employee*>(staff->id, staff));
        }
        employeeStack.push(id);
        int totalImportance = 0;
        while(!employeeStack.empty()) {
            Employee *staff = idToEmployee[employeeStack.top()];
            employeeStack.pop();
            totalImportance+=staff->importance;
            for (int sub : staff->subordinates) {
                employeeStack.push(sub);
            }
        }
        return totalImportance;
    }
};
