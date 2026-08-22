class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end());
        priority_queue<int,vector<int>,greater<int>>pq;
        pq.push(intervals[0][1]);
        for(int i = 1; i < n; i++){
            int start = intervals[i][0];
            while(!pq.empty()){
                int end = pq.top();
                if(start > end){
                    pq.pop();
                    pq.push(intervals[i][1]);
                    break;
                }else{
                    pq.push(intervals[i][1]);
                    break;
                }
            }
        }
        return pq.size();
    }
};