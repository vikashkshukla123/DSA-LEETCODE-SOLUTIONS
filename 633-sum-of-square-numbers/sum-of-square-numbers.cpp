class Solution {
public:
    bool judgeSquareSum(int c) {
        vector<int>v;
        for(long long i = 0; i<=c; i++){
            long long a = i*i;
            if(a <= c) {v.push_back(i);
            }
            else {
                break;
            }
        }
        long long n = v.size();
        long long  left = 0;
        long long right = n-1;
        while(left <= right){
            long long a = v[left] * v[left];
            long long  b = v[right]*v[right];

            if(a + b == c) return true;
            else if(a + b  < c) left ++;
            else right --;
        }

    
        return false;
    }
};