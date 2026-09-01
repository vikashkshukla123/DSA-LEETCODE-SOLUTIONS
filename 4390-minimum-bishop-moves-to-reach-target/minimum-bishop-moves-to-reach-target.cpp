class Solution {
public:
    int minBishopMoves(vector<int>& source, vector<int>& target) {
        if(source == target){
            return 0;
        }

        string source_color = "";
        if((source[0] % 2 == 1 && source[1] % 2 == 1) || (source[0] % 2 == 0 && source[1] % 2 == 0)){
            source_color = "BLACK";
        }else{
            source_color = "WHITE";
        }

        string destination_color = "";
         if((target[0] % 2 == 1 && target[1] % 2 == 1) || (target[0] % 2 == 0 && target[1] % 2 == 0)){
            destination_color = "BLACK";
        }else{
            destination_color = "WHITE";
        }
       

if(source_color != destination_color){
    return -1;
}
    bool foundTopLeft = false;
    bool foundTopRight = false;
    bool foundBottomLeft = false;
    bool foundBottomRight = false;

    int x1 = source[0];
    int y1 = source[1];

    int x2 = target[0];
    int y2 = target[1];

    int i1 = x1;
    int j1 = y1;

    while(i1 >= 1 && j1 <= 8){
        i1 = i1 - 1;
        j1 = j1 + 1;

        if(i1 == x2 && j1 == y2){
            return 1;
        }

    }

    int i2 = x1;
    int j2 = y1;


    while(i2 <= 8 && j2 <= 8){
        i2 = i2 + 1;
        j2 = j2 + 1;

        if(i2 == x2 && j2 == y2){
            return 1;
        }
    }

   int i3 = x1;
   int j3 = y1;
    while(i3 <= 8 && j3 >= 1){
        i3 = i3 + 1;
        j3 = j3 - 1;

        if(i3 == x2 && j3 == y2){
            return 1;
        }
    }


    int i4 = x1;
    int j4 = y1;
    while(i4 >= 1 && j4 >= 1){
        i4 = i4 - 1;
        j4 = j4 - 1;

        if(i4 == x2 && j4 == y2){
            return 1;
        }
    }

return 2;


        
    }
};