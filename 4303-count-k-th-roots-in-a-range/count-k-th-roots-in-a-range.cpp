class Solution {
public:
    int countKthRoots(int l, int r, int k) {
        if(k == 1){
            return (r - l + 1);
        }

        vector<long long>perfectRoot;
        int num = 0;
        while(true){
            long long root = pow(num,k);
            if(root > r){
                break;
            }
            perfectRoot.push_back(root);
            num++;
        }


        int idx1 = lower_bound(perfectRoot.begin(),perfectRoot.end(),l) - perfectRoot.begin();

        if(idx1 < 0){
            idx1 = 0;
        }

        int idx2 = upper_bound(perfectRoot.begin(),perfectRoot.end(),r) - perfectRoot.begin();

        idx2 = idx2 - 1;

        return (idx2 - idx1 + 1);
        


    }
};