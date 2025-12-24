class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int n = capacity.size();

        sort(capacity.begin(),capacity.end());

        int appleCnt = 0;
        for(int i = 0; i<apple.size(); i++){
            appleCnt += apple[i];
        }

        int cnt = 0;
        int i = n-1;
        while(appleCnt > 0){
            appleCnt -= capacity[i];
            cnt ++;
            i--;
        }
        return cnt;
    }
};