class Solution {
    public int[] rearrangeArray(int[] nums) {
        Map<Integer,Integer> mp = new TreeMap<>();
        int n = nums.length;
        for(int i = 0; i < n; i++){
            mp.put(nums[i],mp.getOrDefault(nums[i],0) + 1);
        }

        int []ans = new int[n];
        int idx = 0;
        while(!mp.isEmpty()){
            Iterator<Map.Entry<Integer,Integer>> it = mp.entrySet().iterator();
            while(it.hasNext()){
                Map.Entry<Integer,Integer> e = it.next();
                int key = e.getKey();
                if(e.getValue() == 0){
                    it.remove();
                    continue;
                }
                ans[idx] = key;
                idx++;
                e.setValue(e.getValue() - 1);

            }
        }
return ans;
        
    }
}