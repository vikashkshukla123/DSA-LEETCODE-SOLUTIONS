class RangeFreqQuery {
public:
unordered_map<int,vector<int>>mp;
int lower(vector<int>&toFindIn, int val){
    int n = toFindIn.size();
    int left = 0;
    int right = n-1;
    int ans = toFindIn.size();
    int mid;
    while(left <= right){
        mid = left + (right - left)/2;

        if(toFindIn[mid] >= val){
            ans = mid;
            right = mid - 1;
        }else{
            left = mid + 1;
        }
    }
    return ans;
}

int upper(vector<int>&toFindIn, int val){
    int n = toFindIn.size();
    int left = 0;
    int right = n-1;
    int ans = toFindIn.size();
    int mid = 0;
    while(left <= right){
        mid = left+ (right - left)/2;

        if(toFindIn[mid] > val){
            ans = mid;
            right  = mid - 1;
        }else{
            left = mid + 1;
        }
    }
    return ans;
}
    RangeFreqQuery(vector<int>& arr) {
        int n = arr.size();
        for(int i = 0; i<n; i++){
            mp[arr[i]].push_back(i);
        }
        
    }
    
    int query(int left, int right, int value) {

        if(mp.find(value) == mp.end()) return 0;
         vector<int>&toFindIn = mp[value];
        int n = toFindIn.size();
        

        int idx1 = lower(toFindIn, left);
        int idx2 = upper(toFindIn, right);


        return (idx2 - idx1);

        
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */