class Solution {

    boolean isPossible(String tocheck, String fromcheck){
        if(tocheck.length() != fromcheck.length()){
            return false;
        }
        int n = tocheck.length();

        int cnt = 0;
        for(int i = 0; i<n; i++){
            if(tocheck.charAt(i) != fromcheck.charAt(i)){
                cnt++;
            }
        }

        return (cnt <= 2);
    }
    public List<String> twoEditWords(String[] queries, String[] dictionary) {
        int n = queries.length;
        int m = dictionary.length;

        Set<String>st = new HashSet<>();
        for(int i = 0; i<m; i++){
            st.add(dictionary[i]);
        }

        List<String> ans = new ArrayList<>();
        for(int i = 0; i<n; i++){
            String tocheck = queries[i];
            if(st.contains(tocheck)){
                ans.add(tocheck);
                    continue;
                
            }

            for(int j = 0; j<m; j++){
                if(isPossible(tocheck,dictionary[j])){
                    ans.add(tocheck);
                    break;
                }
            }
            
        }

        return ans;
        
    }
}