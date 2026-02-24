class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.length();
        unordered_set<string>st;
        int i = 0;
        int j = 0;
        string str = "";
        while(i < n){
            str += s[i];

            while(j < n && i - j  + 1 > k){
                if(!str.empty()){
                    str.erase(0,1);
                    j++;
                }
            }

            if(i - j  + 1 == k  && st.find(str) == st.end()){
                st.insert(str);
            }

            i++;
        }

        int unique_string = pow(2,k);

        if(st.size() == unique_string){
            return true;
        }
        return false;
    }
};