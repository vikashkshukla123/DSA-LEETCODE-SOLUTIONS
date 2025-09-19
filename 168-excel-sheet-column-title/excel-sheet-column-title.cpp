class Solution {
public:

    string convertToTitle(int columnNumber) {


        string ans = "";
        while(columnNumber > 0){
            columnNumber--;
            int remainder = columnNumber % 26;
            ans += remainder + 'A';
            columnNumber = columnNumber/26;

        }
        int n = ans.length();
        int i = 0;
        int j = n-1;
        while(i <= j){
            swap(ans[i],ans[j]);
            i++;
            j--;
        }
        return ans;
        
        
    }
};