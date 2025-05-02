// TimeDuration.hpp

#ifndef TIME_DURATION_H 
#define TIME_DURATION_H 

#include <string>
#include <iostream> 
using namespace std; 


class TimeDuration{
	private:
		int hours;
		int minutes;
		int seconds;

	public:
		~TimeDuration();
		TimeDuration(int h,int m,int s);
		TimeDuration();
		//getters
		int getHours() const;
		int getMinutes() const;
		int getSeconds() const;
		int totalSeconds() const;
		//setters
		void setHours(int hours);
		void setMinutes(int minutes);
		void setSeconds(int seconds);

		//operators
		bool operator==(const TimeDuration &other) const;
		bool operator>(const TimeDuration &other) const;
		bool operator<(const TimeDuration &other) const;

		int operator+(const TimeDuration &other) const;
		int operator-(const TimeDuration &other) const;

		friend ostream &operator<<(ostream &out,const TimeDuration &td);
		
};

#endif // TIME_DURATION_H 