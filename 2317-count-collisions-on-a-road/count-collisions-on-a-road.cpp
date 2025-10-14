class Solution {
public:
    int countCollisions(string directions) {
        int n = directions.length();
        int left_car = 0;
        int right_car = n - 1;

        while(left_car <  n &&  directions[left_car] == 'L'){
            left_car ++;
        }
        while(right_car >= 0 && directions[right_car] == 'R'){
            right_car --;
        }
        int collision = 0;
        for(int i = left_car ; i<=right_car; i++){
            if(directions[i] != 'S'){
                collision++;
            }
        }
return collision;

        
    }
};