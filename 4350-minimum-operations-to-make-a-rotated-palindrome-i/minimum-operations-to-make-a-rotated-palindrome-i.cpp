class Solution {
public:
bool isPallindrome(string s){
    int n = s.length();
    int i = 0;
    int j = n-1;
    while(i <= j){
        if(s[i] != s[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}
int solve(string naya){
    int n = naya.length();
    int i = 0;
    int j = n-1;
    int cost = 0;
    while(i <= j){
        if(naya[i] == naya[j]){
            i++;
            j--;
            continue;
        }

        cost += min(abs(naya[i] - naya[j]),26 - abs(naya[i] - naya[j]));
        i++;
        j--;
    }
    return cost;
}
    int minOperations(string s) {
        string original = s;
        int n = s.length();
        int ans = INT_MAX;
        if(isPallindrome(s)){
            return 0;
        }
        int operation = 0;
        for(int rotation = 0; rotation < n; rotation++){
            int operation = rotation+1;
            string naya = "";
            naya += s.substr(1,n-1);
            naya += s.substr(0,1);

            int countOp = solve(naya);
            operation += countOp;
            s = naya;


            ans = min(ans,operation);

        }

        int case2 = solve(original);

return min(ans,case2);
        
    }
};