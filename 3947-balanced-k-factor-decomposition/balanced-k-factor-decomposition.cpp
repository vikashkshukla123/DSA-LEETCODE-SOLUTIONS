class Solution {
public:
    int N, K;
    int difference = 1e9;
    vector<int> best;

    void solve(int idx, int product, vector<int>& ans, vector<int>& cases) {
        if (product == 1 && ans.size() == K) {
            int diff = ans.back() - ans[0];
            if (diff < difference) {
                difference = diff;
                best = ans;
            }
            return;
        }

        if (ans.size() > K) return;

        for (int i = idx; i < cases.size(); i++) {
            if (product % cases[i] == 0) {
                ans.push_back(cases[i]);

                solve(i, product / cases[i], ans, cases);

                ans.pop_back();
            }
        }
    }

    vector<int> minDifference(int n, int k) {
        N = n;
        K = k;

        vector<int> cases;
        for (int i = 1; i <= n; i++) {
            if (n % i == 0) {
                cases.push_back(i);
            }
        }

        sort(cases.begin(), cases.end());

        vector<int> ans;
        solve(0, n, ans, cases);

        return best;
    }
};