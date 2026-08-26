class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.length();
        int left = 0;
        int right = 0;
        string ans = "";
        int cntOne = 0;
        int maxi = 1e9;
        while(right < n){
            if(s[right] == '1'){
                cntOne++;
            }

            while(left < n && cntOne > k){
                if(s[left] == '1'){
                    cntOne--;
                }
                left++;
            }
           
            if(cntOne == k){
                while(left < right && s[left] == '0'){
                    left++;
                }
                string str = s.substr(left, right - left + 1);
                if(right - left + 1 < maxi){
                    ans = str;
                    maxi = right - left + 1;
                }else if(right - left + 1 == maxi){
                    if(ans.empty() || ans > str){
                        ans = str;
                    }
                }

            }

            right++;
        }



        return ans;
    }
};