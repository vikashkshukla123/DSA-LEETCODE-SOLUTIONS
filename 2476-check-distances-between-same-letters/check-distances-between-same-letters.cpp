class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        vector<pair<int,int>> v(26, {-1, -1});
        for(int i = 0; i<s.length(); i++){
            char ch = s[i];
            int idx = ch - 'a';
            if(v[idx].first == -1){
                v[idx].first = i;
            }else{
                v[idx].second = i;
            }
        }
        int n = distance.size();
        for(int i = 0; i<n; i++){
            if(v[i].first != -1 && v[i].second != -1){
                int actual_dis = v[i].second - v[i].first - 1;
                if(actual_dis != distance[i]) return false;
            }
        }
        return true;



        
        

        
    }
};