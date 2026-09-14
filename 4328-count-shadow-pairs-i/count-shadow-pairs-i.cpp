class Solution {
public:
    long long shadowPairs(vector<int>& nums) {
        int n = nums.size();
        stack<pair<int,long long>>st;
        long long current_bigger = 0;
        long long total_ans = 0;
        for(int i = 0; i < n; i++){
            if(st.empty()){
                current_bigger++;
                st.push({nums[i],1});
                continue;
            }

            while(!st.empty() && st.top().first > nums[i]){
                current_bigger -= st.top().second;
                st.pop();
            }

            if(st.empty()){
                current_bigger++;
                st.push({nums[i],1});
                continue;

            }



            if(!st.empty() && st.top().first < nums[i]){
                total_ans += current_bigger;
                st.push({nums[i],1});
                current_bigger++;

            }else if(!st.empty() && st.top().first == nums[i]){
                current_bigger -= st.top().second;
                total_ans += current_bigger;
                st.top().second++;
                current_bigger += st.top().second;
            }

        }

        return total_ans;
    }
};