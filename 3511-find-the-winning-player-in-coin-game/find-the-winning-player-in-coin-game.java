class Solution {
    public String winningPlayer(int x, int y) {
        if(x < 1 || y < 4) return "Bob";
        boolean alice = true;
        String ans = "";
        while(true){
        if(alice){
            if(x >= 1 && y >= 4){
                x -= 1;
                y -= 4;
            }
            if(x < 1 || y < 4){
                return "Alice";
                
            }
            alice = false;
        }
        else{
            if(x >= 1 && y >= 4){
                x -= 1;
                y -= 4;

                if(x < 1 || y < 4){
                    return "Bob";
                }
            }
            alice = true;
            
        }
        }




        
    }
}