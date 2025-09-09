class Solution {
public:
int count(long long  spell, vector<int>&potions, long long success){
    int n = potions.size();
    int low = 0;
    int high = n - 1;
    int mid;
    int ans = -1;
    while(low <= high){
        mid = low + (high - low)/2;
        long long a =  potions[mid]*spell;
        if(a >= success){
            ans = mid;
            high = mid - 1;
        }
        else if(potions[mid]*spell < success){
            low = mid + 1;
        }else {
            high = mid - 1;
        }

    }
    return ans;
}
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int>ans;
        int n = spells.size();
        int m = potions.size();
        sort(potions.begin(),potions.end());
        for(int i = 0; i<n; i++){
            long long  spell = spells[i];
            int idx = count(spell ,potions, success);
            if(idx != -1){
                ans.push_back(m-idx);
            }else{
                ans.push_back(0);
            }
        }
        return ans;
    }
};