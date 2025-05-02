#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

template<typename T>
void printVector(const vector<T>& elements);

int main()
{
    vector<int> scores{95,51,3,84,76,49,80,-1,97,98,79,69,55,80,-1,18,22,65,59,77,36,91,-1,4,76,7,39,40,50,16,92,70,69};
    
    cout << "###################### TASK_1 ######################" << endl;
     vector<int> greaterScores {};
     int greater = count_if(scores.begin(), scores.end(), [](int score){
        if(score>85)cout<<score<<" ";
        return score > 85;
     });
     cout<<endl;
     cout <<  greater << " integeres greater than 85 found" << endl;

     cout << "###################### TASK_2 ######################" << endl;

     cout<< "scores vector before sorting:"<<endl;
     printVector(scores);
     cout<<endl;

     sort(scores.begin(),scores.end());
     
     cout<< "scores vector after sorting:"<<endl;
     printVector(scores);
     cout<<endl;

     bool found = std::binary_search(scores.begin(), scores.end(), -1);
     int howmany = 0;
    if (found)
        howmany = count_if(scores.begin(), scores.end(), [](int n) { return n == -1; });

    cout << "The value -1 was " << (found ? "found" : "not found");
    if (found)
        cout << " " << howmany << " times";
    cout << endl;

    cout << "###################### TASK_3 ######################" << endl;
    auto newEnd = remove_if(scores.begin(),scores.end(),[](int n) { return n == -1; });
    scores.erase(newEnd,scores.end()); // Erase the "removed elements";

    cout<< "scores vector after erase:"<<endl;
    printVector(scores);
    cout<<endl;

    tuple<int, int,double> avg(0,0,0);//  get<0> = count, get<1> = sum, get<2> = aerage =  get<1>/get<0>
    for_each(scores.begin(),scores.end(),[&](int &n) { 
        ++get<0>(avg);
        get<1>(avg)+=n;
    });
    get<2>(avg) = static_cast<double>(get<1>(avg)) / get<0>(avg);
    cout<< "Average Grade:"<< get<2>(avg) <<endl;
    avg = {0, 0, 0.0}; // reset for reuse

    cout << "###################### TASK_4 ######################" << endl;
    cout<< "scores vector before GPA substitutuion:"<<endl;
    printVector(scores);
    cout<<endl;
    for_each(scores.begin(),scores.end(),[](int &n) { 
        if(n >= 85)n=7;
        else if(n >= 75)n=6;
        else if(n >= 65)n=5;
        else if(n >= 50)n=4;
        else n=3;
    });

    cout<< "scores vector after GPA substitutuion:"<<endl;
    printVector(scores);
    cout<<endl;

    for_each(scores.begin(),scores.end(),[&](int &n) { 
        ++get<0>(avg);
        get<1>(avg)+=n;
    });
    get<2>(avg) = static_cast<double>(get<1>(avg)) / get<0>(avg);
    cout<< "Average GPA:"<< get<2>(avg) <<endl;


    return 0;
}


template<typename T>
void printVector(const vector<T>& elements){
    for (const T& elems : elements) {
        cout << elems << " ";
    }
}
// g++ -std=c++2b WA3.cpp -o WA3