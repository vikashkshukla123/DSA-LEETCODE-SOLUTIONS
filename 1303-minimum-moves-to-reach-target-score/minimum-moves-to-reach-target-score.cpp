class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        long long operations = 0;
        if(maxDoubles == 0){
            return target - 1;
        }

        while(target != 1){
            if(target % 2 == 0 && maxDoubles > 0){
                target = target/2;
                maxDoubles--;
                operations++;
            }else if(target % 2 == 1 && maxDoubles > 0){
                operations++;
                target--;
            }else if(maxDoubles == 0){
                operations += target-1;
                target = 1;
            }
        }
        return (int) operations;
    }
};