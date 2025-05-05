// run_wa6.cpp
#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;

#include "MediaItem.hpp"
#include "Book.hpp"
#include "Movie.hpp"
#include "MusicAlbum.hpp"

// g++ -std=c++2b run_wa6.cpp -o WA6

// =============Don't modify the code below==============
int main()
{
    vector<shared_ptr<MediaItem>> items;

    items.push_back(make_shared<Book>("CODE", 2000, "Charles Petzold", 400));
    items.push_back(make_shared<Movie>("Inception", 2010, "Christopher Nolan", 148, 1000));
    items.push_back(make_shared<MusicAlbum>("Thriller", 1982, "Michael Jackson", 9, 20));

    int idx = 1;
    for (const auto& item : items)
    {
        cout << "Output " << idx++ << ": "
             << *item << endl;
    }

    cout << endl;
    return 0;
}
// =============Don't modify the code above==============
