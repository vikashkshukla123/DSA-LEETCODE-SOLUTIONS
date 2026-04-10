class Solution {
    public boolean sumOfNumberAndReverse(int num) {
        if(num  == 0) return true;
        for(int i = 1; i<num; i++){
            int num1 =  i;
            String to_reverse = num1 + "";
            String reversed = new StringBuilder(to_reverse).reverse().toString();

            int num2 = Integer.parseInt(reversed);

            if(num1 + num2 == num){
                return true;
            }
        }
        return false;
    }
}