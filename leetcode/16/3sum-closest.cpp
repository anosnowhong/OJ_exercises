class Solution {
public:
  int threeSumClosest(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int sum, min=abs(nums[0]+nums[1]+nums[2]-target), min_sum=nums[0]+nums[1]+nums[2];
    for(unsigned i = 0;i<nums.size();i++){
      for(unsigned j = i+1;j<nums.size();j++){
        for(unsigned k = j+1;k<nums.size();k++){
          sum = nums[i]+nums[j]+nums[k];
          if(min>abs(sum-target)){
            min=abs(sum-target);
            min_sum = sum;
          }
        }
      }
    }
    return min_sum;
  }
};
