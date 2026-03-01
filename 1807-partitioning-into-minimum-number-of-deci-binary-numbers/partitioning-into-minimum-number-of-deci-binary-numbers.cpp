class Solution {
public:
    int minPartitions(string n) {
        int m = n.length();
        sort(n.begin(),n.end());


        int a = n[m-1] - '0';

        return a;
        
    }
};