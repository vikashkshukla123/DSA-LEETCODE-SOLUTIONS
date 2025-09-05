class Solution {
public:
struct cmp {
    bool operator()(pair<int,int> &a, pair<int,int> &b) {
        return a.second < b.second; // max heap by second value
    }
};
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        int n = barcodes.size();
        unordered_map<int,int>mp;
        priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;

        for(int i = 0; i<n; i++){
            mp[barcodes[i]]++;
        }
        for(auto i : mp){
            pq.push({i.first,i.second});
        }
        vector<int>ans;
        while(!pq.empty()){
            auto p = pq.top();
            ans.push_back(p.first);
            p.second = p.second - 1;
            pq.pop();
            if(pq.empty()) {
                break;
            }
            auto q = pq.top();
            ans.push_back(q.first);
             q.second = q.second - 1;
             pq.pop();

            if(p.second != 0) pq.push({p.first,p.second});
            if(q.second != 0) pq.push({q.first,q.second});

            
            
        



            
        }
        return ans;

    }
}; 