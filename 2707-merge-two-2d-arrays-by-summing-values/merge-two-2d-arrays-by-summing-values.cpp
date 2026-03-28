class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        vector<vector<int>>result;
        unordered_map<int,int>mp1;
        unordered_map<int,int>mp2;
        for(int i = 0; i<n; i++){
            int id1 = nums1[i][0];
            int val1 = nums1[i][1];
            mp1[id1] = val1;
        }

        for(int i = 0; i<m; i++){
            int id2 = nums2[i][0];
            int val2 = nums2[i][1];

            mp2[id2] = val2;

        }

        for(auto it = mp1.begin(); it != mp1.end(); it++){
            int val = it->first;
            int f1 = it->second;
            vector<int>ans;
            if(mp2.find(val) != mp2.end()){
                int val2 = mp2[val];
                ans.push_back(val);
                ans.push_back(f1 + val2);
                mp2.erase(val);

                
            }else{
                ans.push_back(val);
                ans.push_back(f1);
            }

            result.push_back(ans);


        }

    

        if(mp2.empty()){
            sort(result.begin(),result.end());
            return result;
        }

        for(auto it = mp2.begin(); it != mp2.end(); it++){
            int val = it->first;
            int freq = it->second;

            vector<int>ans;
            ans.push_back(val);
            ans.push_back(freq);


            result.push_back(ans);

        }
        sort(result.begin(),result.end());
return result;



        
    }
};