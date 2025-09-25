class Solution {
public:
vector<string>splitString(string &preorder, char delimeter){
    vector<string>tokens;
    string token ;
    std::istringstream tokenStream(preorder); // Create a stringstream from the input string

    // Read tokens from the stream until the end, delimited by 'delimiter'
    while (std::getline(tokenStream, token, delimeter)) {
        tokens.push_back(token);
    }
    return tokens;

}
    bool isValidSerialization(string preorder) {
        vector<string>s = splitString(preorder,',');
        int vacancy = 1;
        for(int i = 0; i<s.size(); i++){
            vacancy --;
            if(vacancy < 0){
                return false;
            }
            if(s[i] != "#"){
                vacancy += 2;
            }

        }
        return vacancy == 0;

        
    }
};