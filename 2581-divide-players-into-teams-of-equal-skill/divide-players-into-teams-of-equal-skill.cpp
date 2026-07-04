class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();
        if(n % 2 == 1) return -1;

    sort(skill.begin(),skill.end());
    int i = 0;
    int j = n-1;
    long long sumTotal = 0;
    long long sumNeeded = skill[0] + skill[n-1];
    while(i < j){
        long long prod = skill[i] * skill[j];
        if(skill[i] + skill[j] != sumNeeded) return -1;
        i++;
        j--;

        sumTotal += prod;

    }

return sumTotal;

    }
};