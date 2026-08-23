class Solution {
public:
    bool sumGame(string num) {
        int n = num.length();
        int leftQuestionMark = 0;
        int rightQuestionMark = 0;
        int leftSum = 0;
        int rightSum = 0;
        for(int i = 0; i < n; i++){
            if(num[i] == '?'){
                if(i < n/2){
                    leftQuestionMark++;
                }else{
                    rightQuestionMark++;
                }
            }else{
                if(i < n/2){
                    leftSum += num[i] - '0';
                }else{
                    rightSum += num[i] - '0';
                }
            }
        }

        int totalQuestionMark = leftQuestionMark + rightQuestionMark;
        if(totalQuestionMark % 2 == 1){
            return true;
        }

        int Left = 2*leftSum + 9*leftQuestionMark;
        int Right = 2*rightSum + 9*rightQuestionMark;

        if(Left == Right){
            return false;
        }

        return true;
        
    }
};