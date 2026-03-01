class Solution {
public:
    int minCost(int n) {
        if(n == 1){
            return 0;
        }



        int a = 1;
        int b = n - a;
        long long  cost = 0;

        while(true){
            long long  curr_cost = a * b;
            cost += curr_cost;
            a = 1;

            b = curr_cost - 1;

            if(a == 1 && b == 1){
                break;
            }

            if(a == 0 || b == 0){
                return cost;
            }
            
        }

        cost += a * b;

        return (int) cost;
        

        
    }
};