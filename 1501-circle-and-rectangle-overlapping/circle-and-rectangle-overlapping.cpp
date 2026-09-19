class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int x3 = x2;
        int y3 = y1;

        int x4 = x1;
        int y4 = y2;

        for(int x = x1; x <= x3; x++){
            int dist = sqrt(pow(x - xCenter,2) + pow(y1 - yCenter,2));
            if(dist <= radius){
                return true;
            }
        }

        for(int y = y1; y <= y4; y++){
            int dist = sqrt(pow(x1 - xCenter,2) + pow(y - yCenter,2));
            if(dist <= radius){
                return true;
            }
        }


        for(int x = x3; x <= x2; x++){
            int dist = sqrt(pow(x - xCenter,2) + pow(y4 - yCenter,2));
            if(dist <= radius){
                return true;
            }
        }

        for(int y = y3 ; y <= y4; y++){
            int dist = sqrt(pow(x3 - xCenter,2) + pow(y - yCenter,2));
            if(dist <= radius){
                return true;
            }
        }


        if(xCenter > x1  && yCenter > y1 && xCenter < x2 && yCenter < y2){
            return true;
        }

        return false;
    }
};