class Solution {
public:

// maintain sum of top x elements from main set
long long sum = 0;
int X;
// contains top x (freq,elements)
set<pair<int,int>>main;

// contains remaining {freq,elements}
set<pair<int,int>>sec;


void insertInSet(const pair<int,int>&p){
    if(main.size() < X || p > *main.begin()){
        sum += 1LL*p.first*p.second;

        main.insert(p);
        if(main.size() > X){
            auto smallest = *main.begin();
            sum -= 1LL*smallest.first*smallest.second;
            main.erase(smallest);
            sec.insert(smallest);


        }
    }else{
        sec.insert(p);
    }
}

void removeFromSet(const pair<int,int>&p){
    if(main.find(p) != main.end()){
        sum -= 1LL*p.first*p.second;
        main.erase(p);


        if(!sec.empty()){
            auto largest = *sec.rbegin();
            sec.erase(largest);
            main.insert(largest);
            sum += 1LL * largest.first * largest.second;
        }
    }else{
        sec.erase(p);
    }
}

    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        X = x;
        int n = nums.size();
        sum = 0;
        vector<long long>result;
        unordered_map<int,int>mp;
        int i = 0;
        int j = 0;
        while(j < n){
            if(mp[nums[j]] > 0){
                removeFromSet({mp[nums[j]],nums[j]});
            }
            // freq new
            mp[nums[j]]++;
            insertInSet({mp[nums[j]], nums[j]});


            if(j - i + 1 == k){
                result.push_back(sum);
                removeFromSet({mp[nums[i]], nums[i]});
                mp[nums[i]]--;
                if(mp[nums[i]] == 0){
                    mp.erase(nums[i]);
                }else{
                    insertInSet({mp[nums[i]], nums[i]});
                }
                i++;
            }
            j++;
        }
return result;
        
    }
};