//O(N^2)
//(n-1)+...+3+2+1=n(n-1)/2
class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> result;
    for(int i=0;i<nums.size();i++){
      for(int j=i+1;j<nums.size();j++){
        if(target-nums[i]==nums[j]){
          result.push_back(i);
          result.push_back(j);
          return result;
        }
      }
    }
    return result;
  }
};
