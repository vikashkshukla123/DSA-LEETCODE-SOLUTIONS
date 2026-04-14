class Solution {
    public int[] applyOperations(int[] nums) {
        int n = nums.length;
        for(int i = 0; i<n-1; i++){
            if(nums[i] == nums[i+1]){
                nums[i] = nums[i] * 2;
                nums[i+1] = 0;


            }
        }
        int cnt0 = 0;
        for(int i = 0; i<n; i++){
            if(nums[i] == 0) cnt0++;
        }


        List<Integer> list = new ArrayList<>();
        for(int i = 0; i<n; i++){
            if(nums[i] != 0){
                list.add(nums[i]);
            }else{
                continue;
            }
        }

        while(cnt0 != 0){
            list.add(0);
            cnt0--;
        }

        int m = list.size();
        int ans[] = new int[m];
        for(int i = 0; i<m; i++){
            ans[i] = list.get(i);
        }

return ans;
        
    }
}