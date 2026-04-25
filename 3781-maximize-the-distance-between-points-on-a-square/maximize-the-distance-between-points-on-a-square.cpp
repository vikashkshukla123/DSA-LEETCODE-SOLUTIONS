class Solution {
public:
    bool isPossible(long long mid, int k, vector<long long>& flatten, int side) {
        int n = flatten.size();
        long long L = 4LL * side;

        vector<long long> extended(2 * n);
        for (int i = 0; i < n; i++) {
            extended[i] = flatten[i];
            extended[i + n] = flatten[i] + L;
        }

    
        for (int i = 0; i < n; i++) {
            int count = 1;
            long long pos = extended[i];
            int idx = i;

        
            for (int cnt = 1; cnt < k; cnt++) {
                long long target = pos + mid;

                auto it = lower_bound(
                    extended.begin() + idx + 1,
                    extended.begin() + i + n,
                    target
                );

                if (it == extended.begin() + i + n) {
                    break;
                }

                idx = it - extended.begin();
                pos = extended[idx];
                count++;
            }


            if (count == k && (extended[i] + L - pos) >= mid) {
                return true;
            }
        }

        return false;
    }

    int maxDistance(int side, vector<vector<int>>& points, int k) {
        vector<long long> flattenDist;

        
        for (auto &p : points) {
            int x = p[0], y = p[1];

            if (y == 0) {
                flattenDist.push_back(x);
            } 
            else if (x == side) {
                flattenDist.push_back(side + y);
            } 
            else if (y == side) {
                flattenDist.push_back(2LL * side + (side - x));
            } 
            else if (x == 0) {
                flattenDist.push_back(3LL * side + (side - y));
            }
        }

        sort(flattenDist.begin(), flattenDist.end());

        long long low = 0;
        long long high = (4LL * side) / k; 
        long long ans = 0;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            if (isPossible(mid, k, flattenDist, side)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return (int)ans;
    }
};