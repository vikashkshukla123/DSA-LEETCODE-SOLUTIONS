class TaskManager {
    // set for priority, taskId
        set<pair<int,int>>st;
        // map for taskId , user_id;
        map<int,int>mp1;
        // map for taskId, priority;
        map<int,int>mp2;
public:
    TaskManager(vector<vector<int>>& tasks) {
        int n = tasks.size();
        for(int i = 0; i<n; i++){
            int userId = tasks[i][0];
            int taskId = tasks[i][1];
            int priority = tasks[i][2]; 

            st.insert({priority, taskId});
            mp1[taskId] = userId;
            mp2[taskId] = priority;
        }
    
        
    }
    
    void add(int userId, int taskId, int priority) {
        st.insert({priority, taskId});
        mp1[taskId] = userId;
        mp2[taskId] = priority;
        
    }
    
    void edit(int taskId, int newPriority) {
        int oldPriority = mp2[taskId];
        st.erase({oldPriority, taskId});
        mp2[taskId] = newPriority;
        st.insert({newPriority,taskId});
        
    }
    
    void rmv(int taskId) {
        int oldPriority = mp2[taskId];
        st.erase({oldPriority,taskId});
        mp1.erase(taskId);
        mp2.erase(taskId);

        
    }
    
    int execTop() {

        if(st.size() == 0) {
            return -1;
        }
        
        int taskId = st.rbegin()->second;

        int userId = mp1[taskId];
        rmv(taskId);
        return userId;

        
        
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */