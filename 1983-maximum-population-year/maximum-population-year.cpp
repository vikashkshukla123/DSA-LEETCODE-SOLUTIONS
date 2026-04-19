class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        int n = logs.size();
        vector<int>birth_rate(102,0);
        for(int i = 0; i<n; i++){
            int birth = logs[i][0];
            int death = logs[i][1];

            int idx1 = birth - 1950;
            int idx2 = death - 1950;

            birth_rate[idx1] += 1;
            birth_rate[idx2] -= 1;
            
        }
        vector<int>prefixBirth(102,0);
        prefixBirth[0] = birth_rate[0];
        int ans = prefixBirth[0];
        int year = 1950;
        for(int i = 1; i<birth_rate.size(); i++){
            prefixBirth[i] = birth_rate[i] + prefixBirth[i-1];
            if(prefixBirth[i] > ans){
                ans = prefixBirth[i];
                year = i + 1950;

            }
        }
        return year;
    }
};