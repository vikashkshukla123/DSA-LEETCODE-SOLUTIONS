class EventManager {
public:
priority_queue<pair<int,int>>pq;
unordered_map<int,int>mp;
    EventManager(vector<vector<int>>& events) {
        int n = events.size();
        for(int i = 0; i<n; i++){
            pq.push({events[i][1], -events[i][0]});
            mp[events[i][0]] = events[i][1];
        }

        
    }
    
    void updatePriority(int eventId, int newPriority) {
    
          mp[eventId] = newPriority;

          pq.push({newPriority,-eventId});


    }
    int pollHighest() {
       while(!pq.empty()){
        int priority = pq.top().first;
        int id = pq.top().second;

        if(mp.find(-id) != mp.end()  && mp[-id] == priority){
            pq.pop();
            mp.erase(-id);
            return -id;

        }
        pq.pop();
       }

       return -1;

        
    }
};

/**
 * Your EventManager object will be instantiated and called as such:
 * EventManager* obj = new EventManager(events);
 * obj->updatePriority(eventId,newPriority);
 * int param_2 = obj->pollHighest();
 */