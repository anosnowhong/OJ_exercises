class Solution {
public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    //rearrange
    vector<int> tmp;
    double result;
    tmp.insert(tmp.end(), nums1.begin(), nums1.end());
    tmp.insert(tmp.end(), nums2.begin(), nums2.end());

    sort(tmp.begin(),tmp.end());

    if(tmp.size()%2 != 0){
      result = tmp[tmp.size()/2];
    }else{
      result = (tmp[tmp.size()/2] + tmp[tmp.size()/2 - 1])/2.0;
    }
    return result;
  }
};
