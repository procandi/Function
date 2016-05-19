#ifndef _PCTIME_H_
#define _PCTIME_H_
#ifndef _TIME_H_
	#include <time.h>
	#define _TIME_H_
#endif

class TimerTest{
public:
	void setTime();
	double getTime();
private:
	double str_t;
};
void TimerTest::setTime(){
	str_t=time(NULL);
}
double TimerTest::getTime(){
	return time(NULL)-str_t;
}

void Delay(double t){
	double str_t=time(NULL);
	while(time(NULL)-str_t<t)
		;
}
#endif //_PCTIME_H_