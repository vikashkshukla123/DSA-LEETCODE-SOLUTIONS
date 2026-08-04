class Solution {
public:
string generate(vector<int>vowelCnt){
    string s = "";
    for(int i = 0; i < 5; i++){
        s += to_string(vowelCnt[i]);
    }

    return s;
}
    int findTheLongestSubstring(string s) {
        int n = s.length();
        int ans = 0;
        vector<int>vowelCnt(5,0);
        unordered_map<string,int>mp;
        mp["00000"] = -1;
        for(int i = 0; i < n; i++){
            if(s[i] == 'a'){
                vowelCnt[0] = ((vowelCnt[0] + 1) % 2); 
                
            }else if(s[i] == 'e'){
                vowelCnt[1] = ((vowelCnt[1] + 1) % 2); 

            }else if(s[i] == 'i'){
                vowelCnt[2] = ((vowelCnt[2] + 1) % 2); 
            }else if(s[i] == 'o'){
                vowelCnt[3] = ((vowelCnt[3] + 1) % 2); 
            }else if(s[i] == 'u'){
                vowelCnt[4] = ((vowelCnt[4] + 1) % 2); 
            }


            string str = generate(vowelCnt);
            if(mp.find(str) != mp.end()){
                ans = max(ans, i - mp[str]);
            }else{
            mp[str] = i;
            }
        }

        return ans;
        
    }
};