class Solution {
public:
    string largestMerge(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();

        string merge = "";
        int i = 0;
        int j = 0;
        while(i < n && j < m){
            string s1 = word1.substr(i, n);
            string s2 = word2.substr(j,m);

            if(s1 > s2){
                merge += word1[i];
                i++;
            }else if(s1 < s2){
                merge += word2[j];
                j++;
            }else{
                merge += word1[i];
                i++;
            }


        }

        if(i <  n){
            for(int k = i; k < n; k++){
                merge += word1[k];
            }
        }

        if(j < m){
            for(int k = j; k < m; k++){
                merge += word2[k];
            }
        }

        return merge;
    }
};