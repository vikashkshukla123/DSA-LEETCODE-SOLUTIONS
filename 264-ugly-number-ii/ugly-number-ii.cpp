class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int>ans(n+1);
        ans[1] = 1;
        int i2 = 1;
        int i3 = 1;
        int i5 = 1;
        for(int i = 2; i<=n; i++){
            int i2UglyNum = ans[i2] * 2;
            int i3UglyNum = ans[i3] * 3;
            int i5UglyNum = ans[i5] * 5;


            int min_ugly = min({i2UglyNum,i3UglyNum,i5UglyNum});

            ans[i] = min_ugly;
            if(min_ugly == i2UglyNum){
                i2++;
            }
            if(min_ugly == i3UglyNum){
                i3++;
            }
            if(min_ugly == i5UglyNum){
                i5++;
            }


        }
        return ans[n];
    }
};