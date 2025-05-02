#include "TimeDuration.hpp"
using namespace std;

int main() {
    cout<<boolalpha;
    TimeDuration t1;
    cout << "Output1 >> t1 : " << t1 << endl;

    t1.setHours(1);
    t1.setMinutes(30);
    t1.setSeconds(30);
    cout << "        >> t1 : " << t1 << endl;


    TimeDuration t2(0, 29, 30);

    cout << "Output2 >> t1 = t2 : " << (t1 == t2) << endl;
    cout << "           t1 > t2 : " << (t1 > t2 ) << endl;
    cout << "           t1 < t2 : " << (t1 < t2 ) << endl;

    int sumSeconds = t1 + t2;
    int diffSeconds = t1 - t2;

    cout << "Output3 >> t1 + t2 : " << sumSeconds << " s" <<endl;
    cout << "           t1 - t2 : " << diffSeconds << " s" << endl;

    cout << "Output4 >> "<<endl;
    return 0;
}

// g++ -std=c++2b run_time.cpp TimeDuration.cpp -o WA4