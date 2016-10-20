/*
  Half of merge sort
  Watch out blank input
  
*/
class Solution {
public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    //rearrange
    vector<int> tmp;
    double result;

    int len_total = nums1.size()+nums2.size();
    int half_search = len_total/2 + 1;
    int j = 0, k = 0;
   
    while(half_search>0){
      if(nums1.size()<nums2.size()){
          
        if(j<nums1.size()){
          if(nums1[j]<nums2[k]){
            tmp.push_back(nums1[j]);
            j++;
            half_search--;
          }
          else{
            tmp.push_back(nums2[k]);
            k++;
            half_search--;
          }
        }
        else{
            tmp.push_back(nums2[k]);
            k++;
            half_search--;
        }
        
      }
      else{
          if(j<nums2.size()){
            if(k==nums1.size()){
              tmp.push_back(nums2[j]);
              j++;
              half_search--;
            }
            else{
                if(nums2[j]<nums1[k]){
              tmp.push_back(nums2[j]);
              j++;
              half_search--;
            }
            else{
              tmp.push_back(nums1[k]);
              k++;
              half_search--;
            }
            }
            
          }
           else{
            tmp.push_back(nums1[k]);
            k++;
            half_search--;
        }
  
        }
      
    }

      if(len_total%2 != 0){
        result = tmp[tmp.size()-1];
      }else{
        result = (tmp[tmp.size()-2] + tmp[tmp.size()-1])/2.0;
      }
      cout<<tmp[0]<<endl;
      cout<< tmp[1]<<endl;
      cout<< tmp[2]<<endl;
      
      return result;
    }
  };
