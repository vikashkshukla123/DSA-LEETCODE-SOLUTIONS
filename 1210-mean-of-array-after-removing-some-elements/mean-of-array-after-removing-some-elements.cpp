class Solution {
public:
    double trimMean(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(),arr.end());
        double sum = 0.0;
        double remove = 0.05 * n;
        for(int i = remove; i < n-remove; i++){
            sum += arr[i];
        }

        return sum / (n - 2 * remove);



     


        
    }
};