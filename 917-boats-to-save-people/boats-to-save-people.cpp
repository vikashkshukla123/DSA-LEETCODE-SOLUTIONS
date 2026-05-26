class Solution {
public:
bool isPossible(int boats, vector<int>&people, int limit){
    int n = people.size();
    int boatCnt = 0;
    int i = 0;
    int j = n-1;
    while(i <= j){
        int w1 = people[i];
        int w2 = people[j];

        if(w1 + w2 <= limit){
            boatCnt++;
            i++;
            j--;
        }else{
            boatCnt++;
            j--;
        }
    }





    return (boatCnt <= boats);
}
    int numRescueBoats(vector<int>& people, int limit){
        int n = people.size();
        int low = 1;
        int high = n;
        int mid;
        int ans = 0;
        sort(people.begin(),people.end());
        while(low <= high){
            mid = low + (high - low)/2;
            if(isPossible(mid, people, limit)){
                ans = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }

        }
        return ans;
    }
};