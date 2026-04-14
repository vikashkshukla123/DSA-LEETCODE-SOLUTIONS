class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();

        if (2 * candidates >= n) {
            sort(costs.begin(), costs.end());
            long long ans = 0;
            for (int i = 0; i < k; i++) ans += costs[i];
            return ans;
        }

        priority_queue<int, vector<int>, greater<int>> pq1, pq2;

        int left = 0, right = n - 1;

        // Fill initial heaps
        for (int i = 0; i < candidates; i++) {
            pq1.push(costs[left++]);
            pq2.push(costs[right--]);
        }

        long long total_cost = 0;

        for (int hired = 0; hired < k; hired++) {

            if (pq1.empty()) {
                total_cost += pq2.top();
                pq2.pop();

                if (left <= right) pq2.push(costs[right--]);
            }
            else if (pq2.empty()) {
                total_cost += pq1.top();
                pq1.pop();

                if (left <= right) pq1.push(costs[left++]);
            }
            else {
                if (pq1.top() <= pq2.top()) {
                    total_cost += pq1.top();
                    pq1.pop();

                    if (left <= right) pq1.push(costs[left++]);
                } else {
                    total_cost += pq2.top();
                    pq2.pop();

                    if (left <= right) pq2.push(costs[right--]);
                }
            }
        }

        return total_cost;
    }
};