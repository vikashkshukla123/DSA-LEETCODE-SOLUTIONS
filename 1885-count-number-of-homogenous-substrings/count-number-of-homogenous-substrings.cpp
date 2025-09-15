class Solution {
    int m = 1e9+7;
public:
    int countHomogenous(string s) {
        long long ans = 0;
        int n = s.length();
        for(int i =  0; i<n;){
            long long count = 0;
            char ch = s[i];
            while(i < n && s[i] == ch){
                count++;
                i++;
            }

            ans += ((count * (count+1))/2)%m;
        }
        return (int)ans%m;
    }
};