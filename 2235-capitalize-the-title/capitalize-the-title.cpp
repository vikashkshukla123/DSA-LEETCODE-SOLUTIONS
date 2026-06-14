class Solution {
public:
    string capitalizeTitle(string title) {
        for(int i = 0; i < title.length(); i++){
            if(title[i] == ' ') continue;
            title[i] = tolower(title[i]);
        }
        stringstream ss(title);
        vector<string>words;
        string word;
        while(ss >> word){
            words.push_back(word);
        }

        string ans = "";
        for(int i = 0; i < words.size(); i++){
            string s = words[i];
            if(s.length() == 1 || s.length() == 2){
                ans += s;
                ans += " ";
                
            }else{

                s[0] = toupper(s[0]);
                ans += s;
                ans += " ";
               

            }
        }
        ans.pop_back();
        return ans;
    }
};