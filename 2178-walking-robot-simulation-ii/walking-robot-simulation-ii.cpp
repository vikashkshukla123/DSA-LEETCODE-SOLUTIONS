class Robot {
public:
vector<vector<int>>result;
int idx = 0;
int w;
int h;
bool moved;
    Robot(int width, int height) {
        w = width;
        h = height;
        moved = false;
        // filling all the values
        // 1. filling left to right starting from 1;
        for(int x = 0; x < w; x++){
            result.push_back({x,0,0});
        }

        // 2. filling down to up
        for(int y = 1; y < h; y++){
            result.push_back({w-1,y,1});
        }

        // filling right to left;
        for(int x = w-2; x >= 0; x--){
            result.push_back({x,h-1,2});
        }

        for(int y = h-2; y > 0; y--){
            result.push_back({0,y,3});
        }
       
    //    handling corner case when it comes to [0][0];
        result[0][2] = 3;

        
    }
    
    void step(int num) {
        moved = true;
        idx = (idx + num) % result.size();

        return;
        

        
    }
    
    vector<int> getPos() {
        vector<int>ans;
        int x = result[idx][0];
        int y = result[idx][1];

        ans.push_back(x);
        ans.push_back(y);

        return ans;
        
    }
    
    string getDir() {
    int val = result[idx][2];
    if (!moved) return "East";

    if (val == 0) return "East";
    if (val == 1) return "North";
    if (val == 2) return "West";
    return "South"; 
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */