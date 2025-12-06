class Solution {
public:
    bool canMakeEqual(vector<int>& nums, int k) {
        int n = nums.size();

        // keep original
        vector<int> orig = nums;

        // ---------- CASE 1 : make all +1 ----------
        int ope = 0;
        vector<int> a = orig;

        for(int i = 0; i < n - 1; i++){
            if(a[i] == 1) continue;

            // flip i and i+1
            a[i] = -a[i];
            a[i+1] = -a[i+1];
            ope++;

            if(ope > k) break;
        }

        // check if all became +1
        bool ok1 = true;
        for(int x : a) if(x != 1) ok1 = false;
        if(ok1 && ope <= k) return true;


        // ---------- CASE 2 : make all -1 ----------
        ope = 0;
        vector<int> b = orig;

        for(int i = 0; i < n - 1; i++){
            if(b[i] == -1) continue;

            // flip i and i+1
            b[i] = -b[i];
            b[i+1] = -b[i+1];
            ope++;

            if(ope > k) break;
        }

        // check if all became -1
        bool ok2 = true;
        for(int x : b) if(x != -1) ok2 = false;
        if(ok2 && ope <= k) return true;

        return false;
    }
};
