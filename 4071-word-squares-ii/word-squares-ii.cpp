class Solution {
public:

bool isPossible(int i, int j, int k, int l, vector<string>&words){
    string top = words[i];
    string left = words[j];
    string right = words[k];
    string bottom = words[l];

    if(top[0] == left[0] && top[3] == right[0] &&
bottom[0] == left[3] && bottom[3] == right[3]){
    return true;
}

   return false;
    
}
    vector<vector<string>> wordSquares(vector<string>& words) {
        int n = words.size();
        vector<vector<string>>ans;
        sort(words.begin(),words.end());
        for(int i = 0; i<n; i++){
            vector<string>a;
            for(int j = 0; j<n; j++){
                for(int k = 0; k<n; k++){
                    for(int l = 0; l<n; l++){
                        if((i != j && i != k && i != l && j != k && j != l && k != l) &&(isPossible(i,j,k,l,words))){
                           ans.push_back({words[i],words[j],words[k], words[l]});
                            

                           
                        }
                    }
                }
            }
            
        }

return ans;

        
    }
};