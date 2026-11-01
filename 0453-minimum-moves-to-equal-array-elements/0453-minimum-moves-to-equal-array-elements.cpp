class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n=nums.size();
        
        int minel=INT_MAX;
        int moves=0;
        int sum=0;
        for(int i=0;i<n;i++){
            minel=min(nums[i],minel);
            sum+=nums[i];
            
        }
        
        return sum-n*minel;        
    }
};