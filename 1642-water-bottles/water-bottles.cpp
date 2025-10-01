class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = numBottles;
        int empty = numBottles;

        while(empty / numExchange != 0){
            int newBottle = floor(empty / numExchange);
            ans += newBottle;
            empty = newBottle + floor(empty % numExchange);
            


        }
        return ans;
        

    }
};