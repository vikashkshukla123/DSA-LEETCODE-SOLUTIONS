class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        if(n == 0){
            return {};
        }
        vector<int>temp = arr;
        sort(temp.begin(),temp.end());
        unordered_map<int,int>rank;
        rank[temp[0]] = 1;
        for(int i = 1; i < n; i++){
            if(temp[i] == temp[i-1]){
                continue;
            }else{
                rank[temp[i]] = 1 + rank[temp[i-1]];
            }

        }

        vector<int>ans(n,0);
        for(int i = 0; i < n; i++){
            ans[i] = rank[arr[i]];
        }
return ans;

        
    }
};