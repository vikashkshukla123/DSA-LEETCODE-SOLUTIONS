class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        unordered_map<char,int>mp2;
        for(int i = 0; i<5; i++){
            mp2[suits[i]]++;
        }
        if(mp2.size() == 1) return "Flush";
        int maxi = -1e9;
        for(int i = 0; i<5; i++){
            int cnt = 0;
            for(int j = 0; j<5; j++){
                if(ranks[i] == ranks[j]){
                    cnt++;
                }
            }
            maxi = max(maxi,cnt);
        }
        if(maxi >= 3) return "Three of a Kind";
        else if(maxi >= 2) return "Pair";
        else return "High Card";
       
    }
};