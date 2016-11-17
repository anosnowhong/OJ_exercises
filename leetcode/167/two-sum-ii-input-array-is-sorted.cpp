//Use question 1 brute force solution will exceed limit time.
//It's OK to use hash table, but you are not using the ascending order feature
//This solution using tow pointers, one point to lower position and another point to higher position
//O(N)


class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
    int low=0, high=nums.size()-1;
    int sum;
    while(true){
      sum = nums[low]+nums[high];
      if(sum==target) return vector<int>({low+1, high+1});
      if(target>sum) low++;
      else high--;
    }
    return vector<int>();
  }
};
