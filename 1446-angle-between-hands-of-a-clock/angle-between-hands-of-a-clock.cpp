class Solution {
public:
    double angleClock(int hour, int minutes) {
        double initialAngle = 0.0;
        double minuteAngle = 0.0;
        double hourAngle = 0.0;

        if(hour == 12){
            initialAngle = 0.0;
        }else{
            initialAngle = hour * 30.0;
        }

        minuteAngle = minutes * 6.0;
        hourAngle = minutes * 0.5;


        double angle1 = abs(minuteAngle - initialAngle - hourAngle);
        double angle2 = abs(360.0 - angle1);

        return min(angle1,angle2);
        
    }
};