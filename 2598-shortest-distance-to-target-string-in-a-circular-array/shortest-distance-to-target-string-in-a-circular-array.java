class Solution {
    public int closestTarget(String[] words, String target, int startIndex) {
        int n = words.length;
        // firsty trying forward;
        int case1 = 0;
        int i = 0;
        HashSet<String>st = new HashSet<>();
        for(int k = 0; k<n; k++){
            st.add(words[k]);
        }

        if(!st.contains(target)) return -1;
        while(true){
            int idx = (startIndex + i) % n;
            if(words[idx].equals(target)){
                break;
            }
            i++;
            case1++;
            
            
        }


        // trying backward
        int case2 = 0;
        int j = 0;
        while(true){
            int idx = (startIndex - j + n) % n;
            if(words[idx].equals(target)){
                break;
                
            }
            case2++;
            j++;
        }
return Math.min(case1,case2);

        
    }
}