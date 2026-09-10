class Solution {
public:
vector<int>result;
int totalSkills;
unordered_map<string,int>dp;
void solve(int idx, vector<int>&temp, vector<int>&peopleSkills, int mask){
    int n = peopleSkills.size();
    if(idx == n){
        if(mask == totalSkills){
            if(result.size() == 0 || temp.size() <= result.size()){
                result = temp;
            }
        }
        return;
    }
    string key = to_string(idx) + "_" + to_string(mask);
    if(dp.find(key) != dp.end()){
        if(dp[key] <= temp.size()){
            return;
        }
    }
    if(result.size() != 0 && result.size() <= temp.size()){
        return;
    }

    solve(idx + 1, temp,peopleSkills, mask);
    if((mask | peopleSkills[idx]) != mask){
    temp.push_back(idx);
    solve(idx + 1, temp,peopleSkills, mask | peopleSkills[idx]);
    temp.pop_back();

    dp[key] = (temp.size() != 0) ? temp.size() : -1;
    }
}
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        unordered_map<string,int>mp;
        int n = req_skills.size();
        for(int i = 0; i < n; i++){
            mp[req_skills[i]] = i;
        }
        totalSkills = pow(2,n) - 1;
        int m = people.size();
        vector<int>peopleSkills(m,0);
        for(int i = 0; i < m; i++){
            vector<string>&skill = people[i];
            int skill_set = 0;
            for(int j = 0; j < skill.size(); j++){
                skill_set =  skill_set | 1 << mp[skill[j]];

            }
            peopleSkills[i] = skill_set;
        }

        vector<int>temp;

         solve(0,temp,peopleSkills,0);
         return result;
        
    }
};