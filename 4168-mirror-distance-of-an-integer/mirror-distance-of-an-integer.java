class Solution {
    public int mirrorDistance(int n) {
        int val  = 0;
        int original =  n;
        while(n != 0){
            int num = n % 10;
            val = val * 10 + num;
            n = n / 10;
        }


        return Math.abs(original - val);
    }
}