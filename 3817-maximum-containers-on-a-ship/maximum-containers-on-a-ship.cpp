class Solution {
public:
    int maxContainers(int n, int w, int maxWeight) {
        int total_grid = n*n;
        int maxi_weight = total_grid * w;
        if(maxi_weight <= maxWeight){
            return total_grid;
        }else{
            return floor(maxWeight/w);
        }

        
    }
};