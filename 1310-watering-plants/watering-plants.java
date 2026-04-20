class Solution {
    public int wateringPlants(int[] plants, int capacity) {
        int n = plants.length;
        int originalCapacity = capacity;
        int totalSteps = 0;
        int canIndex = -1;
        int plantIndex = 0;
        while(true){
            if(capacity >= plants[plantIndex]){
                totalSteps++;
                capacity = capacity - plants[plantIndex];
                plantIndex++;
                canIndex = plantIndex;
            }else{
                totalSteps += (plantIndex);
                totalSteps += (plantIndex + 1);
                capacity = originalCapacity;
                capacity = capacity - plants[plantIndex];
                plantIndex++;
                canIndex = plantIndex;
                
            }

            if(plantIndex == n) break;



        }
return totalSteps;
        
    }
}