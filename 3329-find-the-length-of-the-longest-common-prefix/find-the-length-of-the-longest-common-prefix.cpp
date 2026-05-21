class Solution {
public:
int max(int a, int b){
    if(a < b) return b;
    return a;
}
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        unordered_set<string>st;
        for(int i = 0; i < n; i++){
            int num = arr1[i];
            string s = to_string(num);
            int j = s.length();

            string prefix = "";
            int idx = 0;
            while(idx < j){
                prefix += s[idx];
                if(st.find(prefix) == st.end()){
                    st.insert(prefix);
                }
                idx++;
            }
        }

        int ans = 0;
        for(int i = 0; i < arr2.size(); i++){
            int num = arr2[i];
            string s = to_string(num);
            int j = s.length();

            string prefix = "";
            int idx = 0;
            while(idx < j){
                prefix += s[idx];

                if(st.find(prefix) != st.end()){
                    ans = max(ans, prefix.length());
                }
                idx++;
            }
        }
        return ans;
        
    }
};