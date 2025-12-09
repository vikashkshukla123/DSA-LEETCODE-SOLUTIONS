class Solution {
public:
    string generateTag(string caption) {
        stringstream ss(caption);
        string word;
        vector<string> words;

        while (ss >> word) {
            for (char &c : word) c = tolower(c);
             words.push_back(word);

           
        }

        string ans = "#";
        int cnt = 1;
        for(int i = 0; i<words.size(); i++){
            int n = words[i].length();
            string s = words[i];
            if(i == 0){
                ans += s;
            }else{
                s[0] = toupper(s[0]);
                ans += s;
            }
            cnt += n;

            if(cnt > 100){
                break;
            }

        }

        if(cnt <= 100){
            return ans;
        }

        int m = ans.length();
        while(cnt != 100){
            ans.pop_back();
            cnt--;
        }
        return ans;
    }
};