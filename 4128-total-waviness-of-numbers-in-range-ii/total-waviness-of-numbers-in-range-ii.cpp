class Solution {
public:
typedef long long ll;
string s;
int n;
ll dpTotalNumbers[16][10][10];
ll dpTotalWaviness[16][10][10];
pair<ll, ll>solve(int curr, int prevprev, int prev, bool isLimitedWithActualNumber, bool isLeadingZero){
    if(curr == n){
        return {1,0};
    }

    if(!isLimitedWithActualNumber && !isLeadingZero && prevprev >= 0 && prev >= 0){
        if(dpTotalNumbers[curr][prevprev][prev] != -1){
           return {dpTotalNumbers[curr][prevprev][prev],dpTotalWaviness[curr][prevprev][prev]};
        }

    }

    long long totalNumbers = 0;
    long long totalWaiveScore = 0;

    int limitDigit = isLimitedWithActualNumber ? (s[curr] - '0') : 9;
    for(int digit = 0; digit <= limitDigit; digit++){
        bool newIsLeadingZero = isLeadingZero && (digit == 0);
        int newPrevPrev = prev;
        int newPrev = newIsLeadingZero ? -1 : digit;


        auto [remainTotalNumber, remainTotalWaiveScore] = solve(curr + 1, newPrevPrev, newPrev,isLimitedWithActualNumber && (digit == limitDigit), newIsLeadingZero);

        if(!newIsLeadingZero && prevprev >= 0 && prev >= 0){
            bool isPeak = (prevprev <  prev && prev > digit);
            bool isValley = (prevprev > prev && prev < digit);

            if(isPeak || isValley){
                totalWaiveScore += remainTotalNumber;
            }
        }
        totalNumbers += remainTotalNumber;
        totalWaiveScore += remainTotalWaiveScore;


    }
    if(!isLimitedWithActualNumber && !isLeadingZero && prevprev >= 0 && prev >= 0){
         dpTotalNumbers[curr][prevprev][prev] = totalNumbers;
         dpTotalWaviness[curr][prevprev][prev] = totalWaiveScore;

    }

    return {totalNumbers, totalWaiveScore};
}
long long func(ll num){
    if(num < 100){
        return 0;
    }
    memset(dpTotalNumbers, -1,sizeof(dpTotalNumbers));
    memset(dpTotalWaviness, -1,sizeof(dpTotalWaviness));
    s = to_string(num);
    n = s.length();

    auto [totalNumber,totalWaiveScore] = solve(0,-1,-1, true, true);
    return totalWaiveScore;



}
    long long totalWaviness(long long num1, long long num2) {
        return func(num2) - func(num1 - 1);
        
    }
};