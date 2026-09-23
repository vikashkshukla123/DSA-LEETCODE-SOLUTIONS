class OrderedStream {
    Map<Integer,String>mp;
    int ptr;
    int maxPtrValue;

    public OrderedStream(int n) {
        mp = new HashMap<>(n);
        ptr = 1;
        maxPtrValue = 1;
        
    }
    
    public List<String> insert(int idKey, String value) {
        maxPtrValue = Math.max(maxPtrValue,idKey);
        mp.put(idKey,value);
        List<String>ans = new ArrayList<>();
        if(idKey == ptr){
            ans.add(value);
            ptr++;
            for(int nxt_ptr = ptr; nxt_ptr <= maxPtrValue; nxt_ptr++){
                if(!mp.containsKey(nxt_ptr)) break;
                if(mp.containsKey(nxt_ptr)){
                    ans.add(mp.get(nxt_ptr));
                    ptr++;
                }
        
            }
            
           
            
            

        }else{
            ans = List.of();
        }
        return ans;
    }
}

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream obj = new OrderedStream(n);
 * List<String> param_1 = obj.insert(idKey,value);
 */