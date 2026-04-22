class Solution {
    public int destroyTargets(int[] nums, int space) {
        HashMap<Integer,Integer>mp = new HashMap<>();
        int n = nums.length;
        for(int i = 0; i<n; i++){
            int modulo = nums[i] % space;
            mp.put(modulo,mp.getOrDefault(modulo,0) + 1);
        }
        Arrays.sort(nums);
        int ans = -1;
        int freq = (int)-1e9;
        for(int i = 0; i<n; i++){
            if(mp.containsKey(nums[i] % space)){
                int value = mp.get(nums[i] % space);
                if(freq < value){
                    ans = nums[i];
                    freq = value;
                }

            }
        }
        return ans;
    }
}