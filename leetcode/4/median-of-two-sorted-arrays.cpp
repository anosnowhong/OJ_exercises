/*
 */
class Solution {
public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    double result;
    int len_total = nums1.size() + nums2.size();
    int half_search = len_total/2 + 1;
    int j = 0, k = 0;
    vector<int> tmp;
    vector<int> *swap1;
    vector<int> *swap2;
    swap1 = &nums1;
    swap2 = &nums2;
    vector<int> *swapn;
    if(nums1.size()>nums2.size()){
      swapn = swap1;
      swap1 = swap2;
      swap2 = swapn;
    }

    while(half_search>0){
      if(j<swap1->size()){
        if(k<swap2->size()){
          if(swap1->at(j)<swap2->at(k)){
            tmp.push_back(swap1->at(j));
            j++;
            half_search--;
          }
          else{
            tmp.push_back(swap2->at(k));
            k++;
            half_search--;
          }
        }
        else{
          tmp.push_back(swap1->at(j));
          j++;
          half_search--;
        }
      }
      else{
        tmp.push_back(swap2->at(k));
        k++;
        half_search--;
      }
    }

    if(len_total%2 != 0){
      result = tmp[tmp.size()-1];
    }else{
      result = (tmp[tmp.size()-2] + tmp[tmp.size()-1])/2.0;
    }
    return result;
  }
};
