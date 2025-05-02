#include "TimeDuration.hpp"
#include <iostream>

TimeDuration::TimeDuration(){hours=-1,minutes=-1,seconds=-1;}
TimeDuration::TimeDuration(int h,int m,int s):hours(h),minutes(m),seconds(s){}

TimeDuration::~TimeDuration(){ cout << "Destructor called for \n"<< "TimeDuration(" << this->hours << "h" << this->minutes << "m" << this->seconds << "s" << ")" << endl;}

//getters
int TimeDuration::getHours() const {return hours;}
int TimeDuration::getMinutes() const {return minutes;}
int TimeDuration::getSeconds() const {return seconds;}
int TimeDuration::totalSeconds() const {return ((hours*3600)+(minutes*60)+seconds);}

//setters
void TimeDuration::setHours(int hours){this->hours=hours;}
void TimeDuration::setMinutes(int minutes){this->minutes=minutes;}
void TimeDuration::setSeconds(int seconds){this->seconds=seconds;}

//operators
bool TimeDuration::operator==(const TimeDuration &other) const {return totalSeconds()==other.totalSeconds();}
bool TimeDuration::operator>(const TimeDuration &other) const {return totalSeconds()>other.totalSeconds();}
bool TimeDuration::operator<(const TimeDuration &other) const {return totalSeconds()<other.totalSeconds();}

int TimeDuration::operator+(const TimeDuration &other) const {return totalSeconds()+other.totalSeconds();}
int TimeDuration::operator-(const TimeDuration &other) const {return totalSeconds()-other.totalSeconds();}
ostream &operator<<(ostream &out,const TimeDuration &InputTD){
	out 	<< "TimeDuration(hours= " << InputTD.getHours()
			<< ", minutes: " << InputTD.getMinutes()
			<< ", seconds: " << InputTD.getSeconds()
			<< ")";
	return out;

}
