class Solution {
    int n;
    int min_rounds = 1e9;
    int max_rounds = -1e9;

    void allPossibleMatchUps(int mask, int left, int right,int& p1, int&p2, int rounds){
        if(left >= right){
            // you are done with the current round goto next round
            allPossibleMatchUps(mask, 0,n-1, p1,p2,rounds+1);
        }
        // skip the defeated left player
        else if((mask & (1 << left)) == 0){
            allPossibleMatchUps(mask, left +1, right, p1,p2,rounds);
        }
        // skip the defeated right player
        else if((mask & (1<<right)) == 0){
            allPossibleMatchUps(mask,left,right-1, p1,p2,rounds);
        }
        else if(left == p1 && right == p2){
            min_rounds = min(min_rounds, rounds);
            max_rounds = max(max_rounds, rounds);
        }
        else{
            if(left != p1 && left != p2)
                // make right win
                allPossibleMatchUps(mask ^ (1 << left), left + 1, right - 1, p1,p2,rounds);

            if(right != p1 && right != p2)
                // make left win
                allPossibleMatchUps(mask ^ ( 1 << right), left + 1, right - 1 ,p1,p2, rounds);
        }
    }
public:
    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        this->n = n;
        int mask = (1<<n) - 1;
        firstPlayer -=1;
        secondPlayer -=1;
        allPossibleMatchUps(mask,0,n-1,firstPlayer, secondPlayer,1);
        return {min_rounds,max_rounds};
    }
};