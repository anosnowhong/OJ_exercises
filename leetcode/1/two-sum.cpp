class Solution {
	public:
		vector<int> twoSum(vector<int>& nums, int target) {
			unordered_map<int, int> sumtable;
			vector<int> result;
			for(int i=0;i<nums.size();i++){
				//find the match integer
				auto it = sumtable.find(target - nums[i]);
				if(it != sumtable.end()){
					result.push_back(sumtable[target - nums[i]]);
					result.push_back(i);
					return result;
				}
				else{
					//insert the integer and its index in the vector
					sumtable.insert({nums[i],i});
				}
			}
			return result;
		}
};