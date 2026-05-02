class Solution {
public:
bool isMirror(int num, unordered_map<int,int>&mp){
    int original = num;
    int numStart = 0;
    string original_num = to_string(num);
    for(int i = 0; i<original_num.length(); i++){
        int val = original_num[i] - '0';
        if(mp.find(val) == mp.end()) return false;
        numStart = numStart * 10 + mp[val];
    }
    return (original != numStart);
}
    int rotatedDigits(int n) {
        unordered_map<int,int>mirror;
        mirror[0] = 0;
        mirror[1] = 1;
        mirror[8] = 8;
        mirror[2] = 5;
        mirror[5] = 2;
        mirror[6] = 9;
        mirror[9] = 6;

        int ans = 0;
        for(int i = 1; i <= n; i++){
            if(isMirror(i,mirror)){
                ans++;
            }
        }
        return ans;
    }
};