class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n = events.size();
        sort(events.begin(),events.end());
        int time = 1;
        int maxEvents = 0;
        priority_queue<int,vector<int>,greater<int>>minheap;
        int pos = 0;
        while(pos < n or !minheap.empty()){
            // time skip to cover only timeline covered by atleast one event;
            if(minheap.empty())
            time = max(time,events[pos][0]);

            // add events starting at currentTime
            while(pos < n && events[pos][0] == time){
                minheap.push(events[pos][1]);
                pos++;
            }

            // remove already ended unattented event;
            while(!minheap.empty() && minheap.top() < time){
                minheap.pop();
            }
            // complete 1 event at current time
            if(!minheap.empty()){
                minheap.pop();
                maxEvents++;
            }
            time++;
        }
        return maxEvents;
    }
};