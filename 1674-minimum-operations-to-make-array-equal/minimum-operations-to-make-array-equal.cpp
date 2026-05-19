class Solution {
public:
    int minOperations(int n) {
        vector<int>arr(n,0);
        for(int i = 0; i < n; i++){
            arr[i] = (2 * i) + 1;
        }

        int ans = 0;
        int increase = 0;
        int decrease = 0;
        for(int i = 0; i < n; i++){
            if(arr[i] == n){
                continue;
            }else if(arr[i] < n){
                increase += (n - arr[i]) / 1;
            }else{
                decrease += (arr[i] - n) / 1;
            }

        }

        return (increase + decrease)/2;


    }
};