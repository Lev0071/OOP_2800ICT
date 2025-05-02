#include <iostream>
#include <string>
#include <vector>
#include <memory> // for smart pointers

using namespace std;

int main()
{
    vector<shared_ptr<StaffMember>> staffList;

    staffList.push_back(make_shared<Employee>("Paulie", "456 Off Line", "555-0101", "987-65-4321", 469.15));
    staffList.push_back(make_shared<Volunteer>("Adrianna", "987 Babe Blvd.", "555-8374"));

    auto hourly = make_shared<Hourly>("Michael", "678 Fifth Ave.", "555-0690", "958-47-3625", 10.55);
    hourly->addHours(25);
    staffList.push_back(hourly);

    auto commission = make_shared<Commission>("Michael", "678 Fifth Ave.", "555-0690", "958-47-3625", 10.55, 0.1);
    commission->addSales(225);
    staffList.push_back(commission);

    auto executive = make_shared<Executive>("Tony", "123 Main Line", "555-0469", "123-45-6789", 1023.07);
    executive->awardBonus(345);
    staffList.push_back(executive);

    for (const auto &person : staffList)
    {
        cout << *person << endl;
    }

    staffList.clear(); // shared_ptrs will automatically clean up memory!

    return 0;
}
