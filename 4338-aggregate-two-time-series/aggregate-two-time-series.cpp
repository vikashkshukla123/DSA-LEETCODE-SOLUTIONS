class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1, vector<vector<int>>& series2) {
        unordered_set<int>st;
        int n = series1.size();
        int m = series2.size();
        for(int i = 0; i < n; i++){
            st.insert(series1[i][0]);
        }
        for(int j = 0; j < m; j++){
            st.insert(series2[j][0]);
        }
        vector<int>times;
        for(auto it = st.begin(); it != st.end(); it++){
            times.push_back(*it);
        }
        sort(times.begin(),times.end());
        int i = 0;
        int j = 0;

        int start = 0;
        vector<vector<int>>ans;
        for(int k = 0; k < times.size(); k++){
            int timestamp = times[k];

            int sum_series1 = 0;
            while(i < n && series1[i][0] == timestamp){
                sum_series1 += series1[i][1];
                i++;
            }
            if(i < n && sum_series1 == 0){
                sum_series1 += series1[i][1];
            }

            int sum_series2 = 0;
            
            while(j < m && series2[j][0] == timestamp){
                sum_series2 += series2[j][1];
                j++;
            }
            if(j < m  && sum_series2 == 0){
                sum_series2 += series2[j][1];
            }


            ans.push_back({timestamp,sum_series1 + sum_series2});




        }
        

        
    return ans;    
        
    }
};