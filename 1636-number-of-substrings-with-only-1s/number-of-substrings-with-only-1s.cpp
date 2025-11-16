class Solution {
public:
    int numSub(string s) {
        int n = s.length();
        long long ans = 0;
        int i = 0;

        while (i < n) {
            if (s[i] == '1') {
                long long cnt = 0;  // <-- make cnt long long
                int j = i;

                while (j < n && s[j] == '1') {
                    cnt++;
                    j++;
                }

                long long a = cnt * (cnt + 1) / 2;  // safe now
                ans += a;

                i = j;
            } else {
                i++;
            }
        }

        return ans % 1000000007; // LeetCode requirement
    }
};
