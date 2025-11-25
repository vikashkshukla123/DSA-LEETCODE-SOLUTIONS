class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int n = arr.size();
        int sum = 0;
        for(int i = 0; i<n; i++){
            sum += arr[i];
        }
        if(sum % 3 != 0){
            return false;
        }
        int winSum = sum / 3;

        int s = 0;
        int i = 0;
        int cnt = 3;
        while(i < n){
            s += arr[i];

            if(s == winSum){
                cnt--;
                s = 0;
            }
            i++;

            
        }
        if(cnt <= 0){
            return true;
        }
        return false;
    }
};