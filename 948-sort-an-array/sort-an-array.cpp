class Solution {
public:
int find(int low, int high, vector<int>&nums){
    int pivot = nums[low];
    int i = low;
    int j = high;

    while(i < j){
        while(nums[i] <= pivot && i <= high - 1){
            i++;
        }

        while(nums[j] > pivot  && j >= low + 1){
            j--;
        }

        if(i < j){
            swap(nums[i],nums[j]);
        }
    }
    swap(nums[low], nums[j]);
    

    return j;
}
void quickSort(vector<int>&nums, int low, int high){
    if(low < high){
    int pivotCorrect = find(low,high,nums);
    quickSort(nums, low, pivotCorrect - 1);
    quickSort(nums, pivotCorrect + 1, high);
    }
}
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n-1;

        quickSort(nums, low, high);
        return nums;
        
    }
};