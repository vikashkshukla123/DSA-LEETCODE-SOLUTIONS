class Solution {
public:
void generate(string s, int l, vector<string>&ans){
    if(s.length() == l){
        ans.push_back(s);
        return;
    }


    generate(s + "0", l, ans);
    generate(s + "1", l, ans);
}
    string findDifferentBinaryString(vector<string>& nums) {
        vector<string>ans;
        int n = nums[0].length();
        generate("",n,ans);

        unordered_set<string>st;
        for(int i = 0; i<n; i++){
            st.insert(nums[i]);

        }

        string result;
        for(int i = 0; i<ans.size(); i++){
            if(st.find(ans[i]) == st.end()){
                result = ans[i];
                break;
            }
        }
        return result;
    }
};