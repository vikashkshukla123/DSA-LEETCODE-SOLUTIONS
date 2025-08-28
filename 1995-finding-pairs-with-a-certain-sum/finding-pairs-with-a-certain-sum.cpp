class FindSumPairs {
    vector<int>arr1,arr2;
    unordered_map<int,int>freq;
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        arr1 = nums1;
        arr2 = nums2;
        for(int ele : nums2){
            freq[ele]++;
        }
        
    }
    
    void add(int index, int val) {
        freq[arr2[index]]--;
        arr2[index]+=val;
        freq[arr2[index]]++;
        
    }
    
    int count(int tot) {
        int res = 0;
        for(int i = 0; i<arr1.size(); i++){
            int a = arr1[i];
            int b = tot - a;
            if(freq.find(b) != freq.end()){
                res += freq[b];
            }
        }
        return res;
        
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */