class Solution {
public:
void buildSegementTree(int idx, int left, int right, int segementTree[], int arr[]){
    if(left == right){
        segementTree[idx] = arr[left];
        return;
    }
    int mid = left + (right - left)/2;
    buildSegementTree(2*idx + 1, left, mid, segementTree, arr);
    buildSegementTree(2*idx + 2,mid + 1, right, segementTree,arr);

    segementTree[idx] = max(segementTree[2*idx + 1],segementTree[2*idx + 2]);
}
int *constructST(int arr[], int n){
    int *segementTree = new int[4*n];
    buildSegementTree(0,0,n-1,segementTree,arr);
    return segementTree;
}
int querySegmentTree(int start, int end, int i, int l, int r, int segmentTree[]) {
    if (l > end || r < start) {
        return INT_MIN;
    }

    if (l >= start && r <= end) {
        return segmentTree[i];
    }

    int mid = l + (r - l) / 2;
    return max(querySegmentTree(start, end, 2 * i + 1, l, mid, segmentTree),
               querySegmentTree(start, end, 2 * i + 2, mid + 1, r, segmentTree));
}
int RMQ(int st[], int n, int a, int b){
    return querySegmentTree(a,b,0,0,n-1,st);
}
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int activeSection = count(begin(s),end(s),'1');
        vector<int>startBlock;
        vector<int>endBlock;

        int idx = 0;
        while(idx < s.length()){
            if(s[idx] == '0'){
                int start = idx;
                while(idx < s.length() && s[idx] == '0'){
                    idx++;
                }
                startBlock.push_back(start);
                endBlock.push_back(idx - 1);
            }else{
                idx++;
            }
        }
        int m = startBlock.size();
        if(m < 2){
            return vector<int>(queries.size(), activeSection);
        }

        vector<int>blockSize(m);
        for(int i = 0; i < m; i++){
            blockSize[i] = endBlock[i] - startBlock[i] + 1;
        }

        int N = blockSize.size() - 1;
        vector<int>pairSum(N);
        for(int i = 0; i < N; i++){
            pairSum[i] = blockSize[i] + blockSize[i+1];

        }

        int *st = constructST(pairSum.data(), N);
        vector<int>result;
        for(auto &q : queries){
            int l = q[0];
            int r = q[1];


            int low = lower_bound(begin(endBlock),end(endBlock),l) - begin(endBlock);
            int high = upper_bound(begin(startBlock),end(startBlock),r) - begin(startBlock) - 1;

            int maxPairSum = 0;
            if(low < high){
                int firstLen = endBlock[low] - max(startBlock[low],l) + 1;
                int lastLen = min(endBlock[high],r) - startBlock[high] + 1;

                if(high - low == 1){
                    maxPairSum = firstLen + lastLen;
                }else{
                    int pair1 = firstLen + blockSize[low + 1];
                    int pair2 = blockSize[high-1] + lastLen;

                    int RMQMaxPairSum = RMQ(st,N,low + 1, high - 2);
                    maxPairSum = max({pair1,pair2,RMQMaxPairSum});
                }

            }
            result.push_back(maxPairSum + activeSection);
        }



return result;
        
    }
};