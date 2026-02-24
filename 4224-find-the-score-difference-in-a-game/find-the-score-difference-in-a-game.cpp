class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        int n = nums.size();
        bool player1 =  true;
        bool player2 = false;

        int score1 = 0;
        int score2 = 0;
        for(int i = 0; i<n; i++){

            if(nums[i] % 2 == 1){
                player1 = !player1;
                player2 = !player2;
            }


            if((i+1) % 6 == 0){
                player1 = !player1;
                player2 = !player2;
            }


            


            if(player1){
                score1 += nums[i];
            }

            if(player2){
                score2 += nums[i];
            }

            
        
        }
        return score1 - score2;
    }
};