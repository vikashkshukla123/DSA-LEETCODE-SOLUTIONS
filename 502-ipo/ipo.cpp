class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int,int>>p;
        for(int i = 0; i<n; i++){
            p.push_back({capital[i], profits[i]});
        }
        priority_queue<int>pq;

        sort(p.begin(), p.end());
        int i = 0;
        while(k > 0 ){
            while(i < n && p[i].first <= w){
                pq.push(p[i].second);
                i++;
            }

            if(!pq.empty()){

            w += pq.top();
            pq.pop();
            k--;
            }else{
                break;
            }

        }
        return w;

    }
};