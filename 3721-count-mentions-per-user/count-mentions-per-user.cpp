class Solution {
public:
void applyMessageEvent(vector<string>event,vector<int>&mentionCount, vector<int>&offlineTime){
    int timeStamp = stoi(event[1]);

    vector<string>ids;

    stringstream ss(event[2]);

    string token;
    while(ss >> token){
        ids.push_back(token);
    }


    // process all ids;

    for(string id : ids){
        if(id == "ALL"){
            for(int i = 0; i<mentionCount.size(); i++){
                mentionCount[i]++;
            }
        }else if(id == "HERE"){
            for(int i = 0; i<mentionCount.size(); i++){
                if(offlineTime[i] == 0 || offlineTime[i] + 60 <= timeStamp){
                    mentionCount[i]++;
                }
            }
        }else{
            mentionCount[stoi(id.substr(2))]++;
        }
    }

}
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        vector<int>mentionCount(numberOfUsers);
        vector<int>offlineTime(numberOfUsers);
        auto lambda = [](vector<string>&v1, vector<string>&v2){
            int t1 = stoi(v1[1]);
            int t2 = stoi(v2[1]);

            if(t1 == t2){
                return v1[0][1] > v2[0][1];
                    // comparing 'o' pf offline with 'm'  message           
            }
            return t1 < t2;
        };
        sort(events.begin(),events.end(),lambda);
        for(vector<string>event : events){
            if(event[0] == "MESSAGE"){
                applyMessageEvent(event, mentionCount, offlineTime);
            }else if(event[0] == "OFFLINE"){
                int timeStamp = stoi(event[1]);
                int id = stoi(event[2]);
                offlineTime[id] = timeStamp;
            }
        }
        return mentionCount;
    }
};