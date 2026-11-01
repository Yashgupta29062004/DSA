class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n=nums.size();
        
        int minel=INT_MAX;
        int moves=0;
        for(int i=0;i<n;i++){
            minel=min(nums[i],minel);
        }
        for(int i=0;i<n;i++){
            moves+=nums[i]-minel;
        }
        return moves;        
    }
};