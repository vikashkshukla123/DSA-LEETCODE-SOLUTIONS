class Solution {
    public int garbageCollection(String[] garbage, int[] travel) {
        int n = travel.length;
        int[] prefixDist = new int[n+1];
        prefixDist[0] = 0;
        for(int i = 0; i<n; i++){
            prefixDist[i+1] = travel[i] + prefixDist[i];
        }

        int metal = 0;
        int plastic = 0;
        int glass = 0;
        

        int metal_max = (int)-1e9;
        int plastic_max = (int)-1e9;
        int glass_max = (int)-1e9;

        int m = garbage.length;
        for(int i = 0; i<m; i++){
            String garbages = garbage[i];

            int k = garbages.length();

            for(int j = 0; j<k; j++){
                if(garbages.charAt(j) == 'M'){
                    metal++;
                    metal_max = Math.max(metal_max, i);
                }else if(garbages.charAt(j) == 'P'){
                    plastic++;
                    plastic_max = Math.max(plastic_max,i);
                }else if(garbages.charAt(j) == 'G'){
                    glass++;
                    glass_max = Math.max(glass_max, i);
                }
            }
        }


        int ans = 0;
        if(metal_max != (int)-1e9){
            ans += prefixDist[metal_max] + metal;
        }

        if(plastic_max != (int)-1e9){
            ans += prefixDist[plastic_max] + plastic;
        }

        if(glass_max != (int)-1e9){
            ans += prefixDist[glass_max] + glass;
        }


        return ans;
    }
}