class Solution {
    public long calculateScore(String[] instructions, int[] values) {
        int n = instructions.length;
        boolean[] visited = new boolean[n];
        long totalScore = 0;
        int startIdx = 0;
        while(startIdx >= 0 && startIdx < n){
            if(instructions[startIdx].equals("add")  && visited[startIdx] == false){
                totalScore += values[startIdx];
                visited[startIdx] = true;
                startIdx++;
            }else if(instructions[startIdx].equals("jump") && visited[startIdx] == false){
                visited[startIdx] = true;
                startIdx = (startIdx + values[startIdx]);
            }else{
                break;
            }
        }

        return totalScore;
        
    }
}