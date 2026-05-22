class Solution {
public:
int solve(vector<int>&people, int k){
    int idx = 0;
    
    while(people.size() > 1){
        int deleted_index = (idx + k - 1) % people.size();
        people.erase(people.begin() + deleted_index);
        idx = deleted_index;
        


    }
    return people[0];
}

    int findTheWinner(int n, int k) {
        vector<int>people(n);
        int peopleCnt = 1;
        for(int i = 0; i < n; i++){
            people[i] = peopleCnt;
            peopleCnt++;

        }

        return solve(people, k);
        
    }
};