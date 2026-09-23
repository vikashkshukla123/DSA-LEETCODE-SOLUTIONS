class Solution {
    Map<String,Integer>mp = new HashMap<>();
    int solve(int idx, int jump,boolean canUse, int k){
        if(idx > k + 1){
            return 0;
        }
        int ways = 0;
        if(idx == k){
            ways++;
        }

        StringBuilder sb = new StringBuilder();
        sb.append(idx);
        sb.append(jump);
        sb.append(canUse);

        String res = sb.toString();
        if(mp.containsKey(res)){
            return mp.get(res);
        }
        if(canUse & idx > 0){
            ways += solve(idx - 1, jump,false, k);

        }

        ways += solve(idx + (1 << jump),jump + 1,true, k);
        mp.put(res,ways);
        return mp.get(res);

    }
    public int waysToReachStair(int k) {
        return solve(1,0,true,k);


        
    }
}