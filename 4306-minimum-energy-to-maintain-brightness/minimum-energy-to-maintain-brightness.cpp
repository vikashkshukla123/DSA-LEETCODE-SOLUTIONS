class Solution {
public:
    long long minEnergy(int n, int brightness, vector<vector<int>>& intervals) {
        int m = intervals.size();
        int bulb_required = ceil((double)brightness/3);
        sort(intervals.begin(),intervals.end());

        int t1 = intervals[0][0];
        int t2 = intervals[0][1];


        vector<vector<int>>correct;
        for(int i = 0; i < m ; i++){
            if(correct.empty() || intervals[i][0] > correct.back()[1]){
                correct.push_back(intervals[i]);
            }else{
                correct.back()[1] = max(correct.back()[1], intervals[i][1]);
            }
        }
        
        

        long long energy = 0;
        for(int i = 0; i < correct.size(); i++){
            int a = correct[i][0];
            int b = correct[i][1];

            energy += (1LL * (b - a + 1)) * bulb_required;

        }
        return energy;
    }
};