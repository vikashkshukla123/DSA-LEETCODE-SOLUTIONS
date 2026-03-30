class Solution {
public:
int M = 1e9 + 7;
    int countPartitions(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>dp(n+1,0);
        vector<int>prefix(n+1,0);

        dp[0] = 1;
        prefix[0] = 1;
        
        deque<int>trackMin;
        deque<int>trackMax;

        int i = 0;
        int j = 0;
        while(j < n){
            while(!trackMax.empty() && nums[trackMax.back()]  < nums[j]){
                trackMax.pop_back();

            }

            trackMax.push_back(j);


            while(!trackMin.empty()  && nums[trackMin.back()] > nums[j]){
                trackMin.pop_back();

            }
            trackMin.push_back(j);


            // invalid window;

            while(i <= j  && (nums[trackMax.front()] - nums[trackMin.front()]) > k){
                i++;

                if(!trackMax.empty()  && trackMax.front() < i){
                    trackMax.pop_front();
                }


                if(!trackMin.empty()  && trackMin.front() < i){
                    trackMin.pop_front();
                }
            }

            dp[j+1] = (prefix[j] - (i > 0 ? prefix[i-1] : 0) + M) % M;
            prefix[j+1] = (prefix[j] + dp[j+1]) % M;

            j++;
        }


        return dp[n];

    }
};