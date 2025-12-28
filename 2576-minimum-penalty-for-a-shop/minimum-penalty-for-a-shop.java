class Solution {
    public int bestClosingTime(String customers) {
        int n = customers.length();

        int[] countN = new int[n + 1];
        int[] countY = new int[n + 1];

        // Prefix sums
        for (int i = 0; i < n; i++) {
            if (customers.charAt(i) == 'N') {
                countN[i + 1] = countN[i] + 1;
                countY[i + 1] = countY[i];
            } else {
                countY[i + 1] = countY[i] + 1;
                countN[i + 1] = countN[i];
            }
        }

        int ans = 0;
        int minPenalty = Integer.MAX_VALUE;

        for (int i = 0; i <= n; i++) {
            int openNoCustomer = countN[i];           
            int closedWithCustomer = countY[n] - countY[i];

            int penalty = openNoCustomer + closedWithCustomer;

            if (penalty < minPenalty) {
                minPenalty = penalty;
                ans = i;
            }
        }

        return ans;
    }
}
