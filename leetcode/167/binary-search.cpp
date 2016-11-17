//O(Nlog(N))
class Solution {
public:

  vector<int> twoSum(vector<int>& nums, int target) {
    for(int i=0;i<nums.size();i++){
      int index = bs(target-nums[i],i+1,nums.size()-1,nums);
      if(index!=-1)
        return vector<int>({i+1, index+1});
    }
    return vector<int>();
  }

  int bs(int part, int left, int right, vector<int>& nums){
    int index;
    while(left<=right){
      index=(left+right)/2;
      if(nums[index]>part)
        right=index-1;
      else if(nums[index]<part)
        left = index+1;
      else return index;
    }
    return -1;
  }

};
