class Solution {
public:

bool isCheck(string &s){
    if(s.empty()) return false;
    for(char &ch : s){
        if(!(isalnum(ch) || ch == '_')){
            return false;
    }
}
return true;
}
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        int n = code.size();
        vector<pair<int,string>>v;
        unordered_map<string,int>mp;
        mp["electronics"] = 1;
        mp["grocery"] = 2;
        mp["pharmacy"] = 3;
        mp["restaurant"] = 4;

        for(int i = 0; i<n; i++){
            string coded = code[i];
            string line = businessLine[i];
            bool active = isActive[i];


            if(active == false || !isCheck(coded)){
                continue;
            }

            if(mp.find(line) != mp.end()){
                int order = mp[line];
                v.push_back({order, coded});

            }
        }

        sort(v.begin(),v.end());
        vector<string>ans;
        for(int i = 0; i<v.size(); i++){
            ans.push_back(v[i].second);
        }
return ans;
        
    }
};