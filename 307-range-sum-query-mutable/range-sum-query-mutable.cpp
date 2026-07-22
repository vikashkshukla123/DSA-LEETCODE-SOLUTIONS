class NumArray {
public:
int n;
vector<int>segementTree;
void buildSegementTree(int idx, int left, int right, vector<int>&nums){
    if(left == right){
        segementTree[idx] = nums[left];
        return;
    }
    int mid = left + (right - left)/2;
    buildSegementTree(2*idx + 1, left, mid,nums);
    buildSegementTree(2*idx + 2, mid + 1, right, nums);

    segementTree[idx] = segementTree[2*idx + 1] + segementTree[2*idx + 2];

}
void updateSegementTree(int index, int val, int idx, int left, int right){
    if(left == right){
        segementTree[idx] = val;
        return;
    }

    int mid = left + (right - left)/2;
    if(index <= mid){
        updateSegementTree(index, val, 2*idx + 1, left, mid);
    }else{
        updateSegementTree(index,val,2*idx + 2, mid + 1, right);
    }

    segementTree[idx] = segementTree[2*idx + 1] + segementTree[2*idx + 2];
}
int query(int start, int end, int idx, int left, int right){
    if(start > right || end < left){
        return 0;
    }

    if(left >= start && right <= end){
        return segementTree[idx];
    }

    int mid = left + (right - left)/2;
    int queryLeft = query(start, end, 2*idx + 1, left, mid);
    int queryRight = query(start,end, 2*idx + 2, mid + 1, right);

    return (queryLeft + queryRight);
}
    NumArray(vector<int>& nums) {
        n = nums.size();
        segementTree.resize(4*n,0);
        buildSegementTree(0,0,n-1,nums);
        
    }
    
    void update(int index, int val) {
        updateSegementTree(index,val,0,0,n-1);
        
    }
    
    int sumRange(int left, int right) {
        return query(left,right, 0, 0,n-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */