class Solution {
    public boolean checkAlmostEquivalent(String word1, String word2) {
        int n = word1.length();
        int m = word2.length();

        HashMap<Character,Integer>mp1 = new HashMap<>();
        HashMap<Character,Integer>mp2 = new HashMap<>();

        for(int i = 0; i<n; i++){
            char ch = word1.charAt(i);
            mp1.put(ch,mp1.getOrDefault(ch,0)+1);
            
        }


        for(int i = 0; i<m; i++){
            char ch = word2.charAt(i);
            mp2.put(ch,mp2.getOrDefault(ch,0)+1);
        }

        for(Map.Entry<Character,Integer> entry : mp1.entrySet()){
            char key = entry.getKey();
            int val1 = entry.getValue();

            int val2 = 0;
            if(mp2.containsKey(key)){
                val2 = mp2.get(key);
            }

            if (Math.abs(val1 - val2) > 3) return false;
        }


        for(Map.Entry<Character,Integer> entry : mp2.entrySet()){
            char key = entry.getKey();
            int val1 = entry.getValue();
            
            int val2 = 0;
            if(mp1.containsKey(key)){
                val2 = mp1.get(key);

            }

            if(Math.abs(val1-val2) > 3) return false;
        }

        return true;
    }
}