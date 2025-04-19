#include <iostream>
#include <vector>
#include <map>
using namespace std;



int main(){
    map<int,string> employees = {
        {101, "Alice"},
        {102, "Bob"},
        {103, "Charlie"},
        {104, "Diana"},
        {105, "Ethan"},
        {106, "Fiona"},
        {107, "George"},
        {108, "Hannah"},
        {109, "Ian"},
        {110, "Jasmine"}
    };
    cout << "First Employee: " << employees.at(101) << endl;
    cout << "Last Employee: " << employees.at(110) << endl;

    int index{105};
    if (employees.count(index)){
        cout << "Employee #"<< index <<" is in the system: " << employees.at(index) << endl;
    }else{
        cout << "Employee #"<< index <<" is NOT in the system: " << endl;
    }

    int id{};string name{};
    cout << "enter the number of employees to add to the system: ";
    cin >> id;

    if(id<0){
        cout << "No new employees added" << endl;
    }else{
        int count = id;
        for (int i = 0; i < count; i++) {
            cout << "Please enter the new employee id: ";
            cin >> id;
            cout << "Please enter the new employee name: ";
            cin >> name;
            employees.insert(make_pair(id,name));
          }
    }

    cout << "Employee Records" << endl;
    for(auto it= employees.begin(); it != employees.end();++it){
        cout << "ID: " << it->first << "\nName: " << it->second << "\n---------" << endl;
    }

    char ans{};
    cout << "Do you want to delete any employee ? (y/n): ";
    cin >> ans;

    if(ans == 'y'){
        cout << "which empolyee id ?: ";
        cin >> id;
        employees.erase(id);
        cout << "Employee Records" << endl;
        for(auto it= employees.begin(); it != employees.end();++it){
            cout << "ID: " << it->first << "\tName: " << it->second << endl;
            cout << "ID: " << (*it).first << "\tName: " << (*it).second << "\n---------" << endl;
        }

    }
    // employees[id] = name;

    // if (employees.count(id)){
    //     cout << "Employee #"<< id <<" has been added to the the system: " << employees.at(id) << endl;
    // }else{
    //     cout << "Employee #"<< id <<" has NOT been added to the system: " << endl;
    // }


    return 0;
} 