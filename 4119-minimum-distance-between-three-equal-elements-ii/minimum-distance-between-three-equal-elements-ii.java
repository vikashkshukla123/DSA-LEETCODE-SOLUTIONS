class Solution {
    public int minimumDistance(int[] nums) {
        int n = nums.length;
        int ans = (int)1e9;
        Map<Integer,List<Integer>>map = new HashMap<>();
        for(int i = 0; i<n; i++){
            if (!map.containsKey(nums[i])) {
                  map.put(nums[i], new ArrayList<>());
            }
            map.get(nums[i]).add(i);
            List<Integer> list = map.get(nums[i]);
            int m = list.size();
            if(m < 3) continue;

            int k = list.get(m-1);
            int j = list.get(m-3);

            ans = Math.min(ans, 2*(k-j));

            
        }
return ans == (int)1e9 ? -1 : ans;
        
        
    }
}