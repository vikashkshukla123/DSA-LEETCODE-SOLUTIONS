class Solution {
public:

struct Node{
    long long score = -1;
    vector<int>idxs;
};
vector<int>nextIdx;
vector<vector<Node>>t;

Node solve(int idx, vector<vector<int>>&intervals, int k){
    int n = intervals.size();
    if(idx >= n || k <= 0){
        return Node{};
    }
    if(t[idx][k].score != -1){
        return t[idx][k];
    }
    Node skip = solve(idx + 1, intervals, k);
    int weight = intervals[idx][2];
    int next = nextIdx[idx];
    int originalIdx = intervals[idx][3];
    Node temp = solve(next, intervals, k - 1); 

    Node take;
    take.score = weight + temp.score;
    take.idxs = temp.idxs;
    take.idxs.push_back(originalIdx);
    sort(begin(take.idxs),end(take.idxs));

    Node result;
    if(skip.score > take.score){
        result = skip;
    }else if(take.score > skip.score){
        result = take;
    }else{
        result = (skip.idxs < take.idxs) ? skip : take;
    }

    return t[idx][k] =  result;
}
int find(vector<vector<int>>&intervals,int endTime){
    int n = intervals.size();
    int low = 0;
    int high = n-1;
    int ans = n;
    while(low <= high){
        int mid = low + (high - low)/2;
        int start = intervals[mid][0];

        if(start > endTime){
            ans = mid;
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    return ans;
}
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        for(int i = 0; i < n; i++){
            intervals[i].push_back(i);
        }
        sort(intervals.begin(),intervals.end());
        nextIdx.resize(n);
        for(int i = 0; i < n; i++){
            int endTime = intervals[i][1];
            int nextStart = find(intervals,endTime);
            nextIdx[i] = nextStart;
        }
        vector<int>ans;
        t.assign(n+1,vector<Node>(4+1));
        return solve(0,intervals,4).idxs;
    
        
    }
};