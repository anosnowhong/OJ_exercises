/*
three pattern
[ - 0 +]
[ - - +]
[ - + +]
each member can only be used once in one solution
here [-1, 0, 1, 2, -1, -4] has two '-1', so you can
have solution [-1, -1, 2], use '-1' twice.
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        vector<vector<int> > result;
        int k, sum;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                for(int k=j+1;k<nums.size();k++){
                sum = nums[i]+nums[j]+nums[k];
                if(sum==0) result.push_back({nums[i],nums[j],nums[k]});
                }
            }
        }
        //auto repeate = unique(result.begin(), result.end());
        //result.erase(repeate, result.end());
        set<vector<int>> final;
        unsigned size = result.size();
        for( unsigned i = 0; i < size; ++i ) final.insert( result[i] );
        result.assign(final.begin(), final.end());
        return result;
    }
};
