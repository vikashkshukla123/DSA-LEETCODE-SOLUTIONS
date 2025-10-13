class Solution {
public:

    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>>p;
        for(int i = 0; i<position.size(); i++){
            p.push_back({position[i],speed[i]});
        }
        sort(p.begin(),p.end(),greater<pair<int,int>>());
        stack<double>st;
        for(auto &car : p){
            int pos = car.first;
            int spd = car.second;
            double timeTaken = (double)(target-pos)/spd;

            if(st.empty() || timeTaken > st.top()) st.push(timeTaken);
        }
        return st.size();
        
    }
};