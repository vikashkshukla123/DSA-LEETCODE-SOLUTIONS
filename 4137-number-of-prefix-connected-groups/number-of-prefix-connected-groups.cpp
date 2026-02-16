class Solution {
public:
    int prefixConnected(vector<string>& words, int k) {
        int n = words.size();
        vector<string>quality;
        for(int i = 0; i<n; i++){
            if(words[i].length() >= k){
                quality.push_back(words[i]);
            }
        }


        int ans = 0;
        int m = quality.size();
        sort(quality.begin(),quality.end());
        int i = 0;
        while(i < m){
            string a = quality[i];
            int j = i;
            while((j < m) && (a.substr(0,k) == quality[j].substr(0,k))){
                j++;
            }

            if(j - i >= 2){
                ans++;
            }
            i = j;
        }

return ans;
        
    }
};