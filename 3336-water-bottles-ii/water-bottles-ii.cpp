class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int ans = numBottles;
        int empty = numBottles;

        int newBottle = 0;
        while(empty >= numExchange){
            newBottle++;
            empty = empty - numExchange;
            numExchange++;


            if(empty < numExchange && newBottle + empty / numExchange >= 1){
                ans += newBottle;
                empty = newBottle + empty;
                newBottle = 0;
                

            }
                ans += newBottle;
                empty = empty + newBottle;
                newBottle = 0;
            
            


            

        }
        return ans;
        
    }
};