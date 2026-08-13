class Solution {
public:
unordered_map<string,bool>mp;
bool solve(string s1, string s2){
    int n = s1.length();
    int m = s2.length();
    if(s1 == s2){
        return true;
    }

    if(n != m){
        return false;
    }

    string key = s1 + "_" + s2;
    if(mp.find(key) != mp.end()){
        return mp[key];
    }


    for(int i = 1; i < s1.length(); i++){
        bool notswapped = solve(s1.substr(0,i), s2.substr(0,i)) && solve(s1.substr(i,n-i),s2.substr(i,n-i));

        if(notswapped){
            return mp[key] = true;
        }

        bool swapped = solve(s1.substr(0,i),s2.substr(n-i,i)) && solve(s1.substr(i,n-i),s2.substr(0,n-i));

        if(swapped){
            return mp[key] =  true;
        }

    }
    return mp[key] = false;
}
    bool isScramble(string s1, string s2) {
        int n1 = s1.length();
        int n2 = s2.length();

        if(n1 != n2){
           return false;
        }

    return solve(s1,s2);
    }
};