class SubrectangleQueries {
public:
vector<vector<int>>globalRec;
int n;
int m;
    SubrectangleQueries(vector<vector<int>>& rectangle) {
        n = rectangle.size();
        m = rectangle[0].size();
        globalRec.resize(n,vector<int>(m,0));
        globalRec = rectangle;
        
    }
    
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        for(int i = row1; i <= row2; i++){
            for(int j = col1; j <= col2; j++){
                globalRec[i][j] = newValue;
            }
        }
        
    }
    
    int getValue(int row, int col) {
        return globalRec[row][col];
        
    }
};

/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * SubrectangleQueries* obj = new SubrectangleQueries(rectangle);
 * obj->updateSubrectangle(row1,col1,row2,col2,newValue);
 * int param_2 = obj->getValue(row,col);
 */