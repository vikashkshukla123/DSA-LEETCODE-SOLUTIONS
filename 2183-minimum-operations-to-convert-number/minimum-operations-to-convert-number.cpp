class Solution {
public:
int solve(vector<int>&nums, int start, int goal, unordered_set<int>&visited){
    int n = nums.size();
    queue<pair<int,int>>q;
    q.push({0,start});
    visited.insert(start); 
    while(!q.empty()){
        int size = q.size();
        for(int i = 0; i < size; i++){
        auto it = q.front();
        q.pop();
        int operations = it.first;
        int value = it.second;


        if(value == goal){
            return operations;
        }

            for(int newidx = 0; newidx < n; newidx++){
                int newvalue1 = value + nums[newidx];
                int newvalue2 = value - nums[newidx];
                int newvalue3 = value ^ nums[newidx];

                if((newvalue1 == goal || (newvalue1 >= 0 && newvalue1 <= 1000)) && !visited.count(newvalue1)){   
                    visited.insert(newvalue1);
                    q.push({operations + 1, newvalue1});
                }
                
                if((newvalue2 == goal || (newvalue2 >= 0 && newvalue2 <= 1000)) && !visited.count(newvalue2)){   
                    visited.insert(newvalue2);
                    q.push({operations + 1, newvalue2});
                }




               if((newvalue3 == goal || (newvalue3 >= 0 && newvalue3 <= 1000)) && !visited.count(newvalue3)){   
                    visited.insert(newvalue3);
                    q.push({operations + 1, newvalue3});
                }


        }
    }

    }
    return -1;
}
    int minimumOperations(vector<int>& nums, int start, int goal) {
        int n = nums.size();
        unordered_set<int>visited;
        return solve(nums,start,goal,visited);
        
    }
};