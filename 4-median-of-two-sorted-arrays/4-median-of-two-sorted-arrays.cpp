class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        int m = nums1.size();
        if(m>n){
            return findMedianSortedArrays(nums2,nums1);
        }
        int s = 0;
        int e = m;
        double median;
        while(s<=e){
            
            int partitionX = (s+e)/2;
            int partitionY = (m+n+1)/2 - partitionX;
            
            double maxArrayX = (partitionX==0)?INT_MIN:nums1[partitionX-1];
            double minArrayX = (partitionX==m)?INT_MAX:nums1[partitionX];
            double maxArrayY = (partitionY==0)?INT_MIN:nums2[partitionY-1];
            double minArrayY = (partitionY==n)?INT_MAX:nums2[partitionY];
            
            if(maxArrayX<=minArrayY && maxArrayY<=minArrayX){
                if((m+n)%2==0){
                    median = double((max(maxArrayX,maxArrayY)+min(minArrayX,minArrayY)))/2;
                }
                else{
                    median = double(max(maxArrayX,maxArrayY));
                }
                break;
            }
            else if(maxArrayX>minArrayY){
                e = partitionX-1;
            }
            else if(maxArrayY>minArrayX){
                s = partitionX+1;
            }
            
        }
        return median;
    }
};