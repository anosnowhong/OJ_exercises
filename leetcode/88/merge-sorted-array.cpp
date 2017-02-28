class Solution {
public:
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    for(int i=m-1,j=n-1, tar = m+n-1; j>=0; ){
      if(nums1[i]<nums2[j]||i<0){
        nums1[tar--] = nums2[j--];
      }
      else{
        nums1[tar--] = nums1[i--];
      }

    }
  }
};
