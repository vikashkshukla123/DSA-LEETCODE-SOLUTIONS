class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int>a;
        int i = 0;
        int j = 0;
        double median;
        while(i < n && j < m){
            if(nums1[i]  < nums2[j]){
                a.push_back(nums1[i]);
                i++;
            }else if(nums1[i] > nums2[j]){
                a.push_back(nums2[j]);
                j++;
            }else{
                a.push_back(nums1[i]);
                a.push_back(nums2[j]);
                i++;
                j++;
            }
        }
        if(i < n){
            while(i < n){
                a.push_back(nums1[i]);
                i++;
            }
        }else{
            while(j < m){
                a.push_back(nums2[j]);
                j++;
            }
        }

        int s = a.size();

        if (s % 2 == 1) {
        median = a[s / 2];  // odd
    } else {
        median = (a[s / 2 - 1] + a[s / 2]) / 2.0; // even
    }
    return median;
        
    }
};