class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n = word.length();
        unordered_set<char>st1;
        unordered_set<char>st2;

        unordered_map<char,int>firstOccurence;
        unordered_map<char,int>lastOccurence;
        for(int i = 0; i < n; i++){
            if(word[i] >= 'A' && word[i] <= 'Z'){
                if(firstOccurence.find(word[i]) == firstOccurence.end()){
                    firstOccurence[word[i]] = i;
                }
            }
        }

        for(int i = n-1; i >= 0; i--){
            if(word[i] >= 'a' && word[i] <= 'z'){
                if(lastOccurence.find(word[i]) == lastOccurence.end()){
                    lastOccurence[word[i]] = i;
                }
            }
        }




        for(int i = 0; i < n; i++){
            char ch = word[i];
            if(ch >= 'a' && ch <= 'z'){
                st1.insert(ch);
            }else{
                st2.insert(ch);
            }
        }

        int ans = 0;
        unordered_set<char>st3;
        for(int i = 0; i < n; i++){
            char ch = word[i];
            if(st1.find(ch) != st1.end()){
                if(st2.find(toupper(ch)) != st2.end()){
                    if(st3.find(ch) == st3.end() && st3.find(toupper(ch)) == st3.end()){

                    int idx = firstOccurence[toupper(ch)];
                    if(idx > lastOccurence[tolower(ch)]){
                    ans++;
                    st3.insert(ch);
                    st3.insert(toupper(ch));
                    
                    }
            
                    }
                    
                }
            }else{
                if(st1.find(tolower(ch)) != st1.end()){
                    if(st3.find(ch) == st3.end() && st3.find(tolower(ch)) == st3.end()){
                    int idx = lastOccurence[tolower(ch)];
                    if(idx <  firstOccurence[ch]){
                    ans++;
                    st3.insert(ch);
                    st3.insert(tolower(ch));

                    }
                    
                    
                    }

                }
            }
        }
        return ans;

        
    }
};