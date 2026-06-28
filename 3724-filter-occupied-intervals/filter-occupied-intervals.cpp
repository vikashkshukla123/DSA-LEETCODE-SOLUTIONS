class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals, int freeStart, int freeEnd) {
        int n = occupiedIntervals.size();
        sort(occupiedIntervals.begin(),occupiedIntervals.end());
        vector<vector<int>>merged;
        for(int i = 0; i < n; i++){
            int start = occupiedIntervals[i][0];
            int end = occupiedIntervals[i][1];

            if(merged.empty()){
                merged.push_back({start,end});
                continue;
            }

            if(merged.back()[1] < start && merged.back()[1] + 1 != start){
                merged.push_back({start,end});
            }else if(merged.back()[1] < start && merged.back()[1] + 1 == start){
                merged.back()[1] = end;

            }else{
                merged.back()[1] = max(end, merged.back()[1]);
            }

           
        }

        vector<vector<int>>result;
        for(int i = 0; i < merged.size(); i++){
            int start1 = merged[i][0];
            int end1 = merged[i][1];

            if(start1 > freeEnd || end1 < freeStart){
                result.push_back(merged[i]);
                continue;
            }

            if(start1 < freeStart && end1 == freeEnd){
                result.push_back({start1, freeStart-1});
                continue;
            }

            if(start1 == freeStart && end1 > freeEnd){
                result.push_back({freeEnd + 1, end1});
                continue;
            }

        

            if(freeStart > start1 && freeEnd > end1){
                result.push_back({start1, freeStart - 1});
            }else if(freeStart < start1 && freeEnd < end1){
                result.push_back({freeEnd + 1, end1});
            }else if(freeStart > start1 && freeEnd < end1){
                result.push_back({start1, freeStart-1});
                result.push_back({freeEnd + 1, end1});
            }else{
                continue;
            }
        }

        sort(result.begin(),result.end());
        return result;
        
    }
};