class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<vector<int>> detailing;

        for (int i = 0; i < n; i++) {
            detailing.push_back({
                positions[i],
                healths[i],
                directions[i] == 'R' ? 1 : 0,
                i
            });
        }

        sort(detailing.begin(), detailing.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });

        int left = 0;
        int right = n - 1;

        vector<int> ans(n, 0);

        // left moving at start
        while (left < n && detailing[left][2] == 0) {
            int idx = detailing[left][3];
            ans[idx] = detailing[left][1];
            left++;
        }

        // right moving at end
        while (right >= 0 && detailing[right][2] == 1) {
            int idx = detailing[right][3];
            ans[idx] = detailing[right][1];
            right--;
        }

        stack<int> st;

        for (int i = left; i <= right; i++) {

            while (!st.empty() && detailing[st.top()][2] == 1 && detailing[i][2] == 0 && detailing[i][1] > 0) {

                int &health1 = detailing[st.top()][1];
                int &health2 = detailing[i][1];

                if (health1 == health2) {
                    health1 = 0;
                    health2 = 0;
                    st.pop();
                    break;
                }
                else if (health1 > health2) {
                    health1--;
                    health2 = 0;
                    break;
                }
                else {
                    health2--;
                    health1 = 0;
                    st.pop();
                }
            }

            if (detailing[i][1] > 0) {
                st.push(i);
            }
        }

        // collect survivors
        for (int i = 0; i < n; i++) {
            if (detailing[i][1] > 0) {
                ans[detailing[i][3]] = detailing[i][1];
            }
        }

        vector<int> result;
        for (int x : ans) {
            if (x > 0) result.push_back(x);
        }

        return result;
    }
};