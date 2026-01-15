class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        int x = hBars.size();
        int y = vBars.size();


        sort(hBars.begin(),hBars.end());
        sort(vBars.begin(),vBars.end());



        int length = 1;
        int currMaxlen = 1;
        for(int i = 1; i<x; i++){
            if(hBars[i] == hBars[i-1] + 1){
                length++;
            }else{
                length = 1;
            }

            currMaxlen = max(currMaxlen,length);

        }
        

        int width = 1;
        int currMaxWidth = 1;
        for(int i = 1; i<y; i++){
            if(vBars[i] == vBars[i-1] + 1){
                width++;
            }else{
                width = 1;
            }

            currMaxWidth = max(currMaxWidth,width);
        }


    int req_side = min(currMaxWidth + 1, currMaxlen + 1);


    return req_side * req_side;
        


    }
};