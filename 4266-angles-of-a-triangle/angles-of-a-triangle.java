class Solution {
    public double[] internalAngles(int[] sides) {
        int n = sides.length;
        Arrays.sort(sides);
        int sum2 = sides[0] + sides[1];
        int sum3 = sides[2];

        if(sum2 <= sum3){
            return new double[0];
        }
        double a = sides[0];
        double b = sides[1];
        double c = sides[2];

        double value1 = ((Math.pow(a,2) + Math.pow(c,2) - Math.pow(b,2))/(2*c*a));

        double angle_radian1 = Math.acos(value1);
        double angle_degree1 = Math.toDegrees(angle_radian1);



        double value2 = ((Math.pow(b,2) + Math.pow(c,2) - Math.pow(a,2))/(2*b*c));
        double angle_radian2 = Math.acos(value2);
        double angle_degree2 = Math.toDegrees(angle_radian2);


        double angle_degree3 = 180 - (angle_degree1 + angle_degree2);

        double[] ans = new double[3];
        ans[0] = angle_degree1;
        ans[1] = angle_degree2;
        ans[2] = angle_degree3;


        Arrays.sort(ans);

        return ans;








    }
}