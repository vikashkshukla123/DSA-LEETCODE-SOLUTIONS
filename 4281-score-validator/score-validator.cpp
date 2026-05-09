class Solution {
public:
bool isNum(string &s){
    return (s == "0" || s == "1" || s == "2" || s == "3" || s == "4" || s == "6");
}
    vector<int> scoreValidator(vector<string>& events) {
        int n = events.size();
        int score = 0;
        int counter = 0;
        vector<int>ans;
        int i = 0;
        for(int i = 0; i < n; i++){
            if(isNum(events[i])){
                score += stoi(events[i]);
            }else if(events[i] == "W"){
                counter += 1;
            }else if(events[i] == "WD"){
                score += 1;
            }else if(events[i] == "NB"){
                score += 1;
            }

            if(counter == 10){
                break;
            }
            
                
            }
        ans.push_back(score);
        ans.push_back(counter);

        return ans;

    }
};