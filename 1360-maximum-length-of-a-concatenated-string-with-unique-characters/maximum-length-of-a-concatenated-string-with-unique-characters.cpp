class Solution {
public:
bool hasDuplicate(string &s1, string &s2){
    vector<int>freq(26,0);
    for(int i = 0; i < s1.length(); i++){
        int idx = s1[i] - 'a';
        if(freq[idx] > 0){
            return true;
        }

        freq[idx]++;
    }

    for(int i = 0; i < s2.length(); i++){
        int idx = s2[i] - 'a';
        if(freq[idx] >= 1){
            return true;
        }
        freq[idx]++;
    }
    
   
    

    return false;
}
int solve(int idx, string temp, vector<string>&arr){
    int n = arr.size();
    if(idx == n){
        return temp.length();
    }
    int take = 0;
    int nottake = 0;
    if(!hasDuplicate(temp,arr[idx])){
        take = solve(idx + 1 , temp + arr[idx], arr);
        nottake = solve(idx + 1, temp, arr);

    }else{
        nottake = solve(idx + 1, temp,arr);

    }

    return max({take,nottake});

}
    int maxLength(vector<string>& arr) {
        string temp = "";
        return solve(0,temp,arr);
        
    }
};