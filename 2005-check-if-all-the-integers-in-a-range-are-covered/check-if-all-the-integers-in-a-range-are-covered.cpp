class Solution {
public:
bool checking(vector<vector<int>>&ranges, int val){
    int n = ranges.size();
    for(int i = 0; i<n; i++){
        int left = ranges[i][0];
        int right = ranges[i][1];

        if(val >= left &&  val <= right){
            return true;
        }


    }
    return false;
}
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        int n = ranges.size();
        for(int i = left ; i<=right; i++){
            bool check = checking(ranges,i);

            if(!check){
                return false;
            }
        }
return true;
        
    }
};