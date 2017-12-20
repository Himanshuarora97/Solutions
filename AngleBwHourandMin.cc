#include "temp.h"

// Find angle between hour and minute hand (Clock Angle Problem)
int angleBwHourandMin(int hour, int min){
	if(min == 60){
		hour += 1;
		min = 0;
	}
	hour = (hour == 12) ? 0:hour;
	int angleH, angleM, angle;
	angleH = hour * (30) + min / 2;
	angleM = min * 6;
	angle = abs(angleM - angleH);
	return (angle < 360 - angle) ? angle : 360 - angle;

}
int main(){
	int hour, min;
	cin>>hour>>min;
	PRINT(angleBwHourandMin(hour, min));
}