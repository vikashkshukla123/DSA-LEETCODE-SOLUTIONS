class Solution {
    public String evaluate(String s, List<List<String>> knowledge) {
        int n = knowledge.size();
        Map<String,String>mp = new HashMap<>();
        for(int i = 0; i < n; i++){
            List<String>ls = knowledge.get(i);
            String key = ls.get(0);
            String value = ls.get(1);
            mp.putIfAbsent(key,value);
        }

        StringBuilder ans = new StringBuilder();
        int m = s.length();
        int idx = 0;
        while(idx < m){
            if(s.charAt(idx) == '('){
                int j = idx + 1;
                StringBuilder valuePart = new StringBuilder();
                while(j < m && s.charAt(j) != ')'){
                    valuePart.append(s.charAt(j));
                    j++;
                }

                String key = valuePart.toString();

                if(mp.containsKey(key)){
                    ans.append(mp.get(key));
                }else{
                    ans.append("?");
                }

                idx = j+1;

            }else{
                ans.append(s.charAt(idx));
                idx++;
            }
        }

        return ans.toString();
    }
}