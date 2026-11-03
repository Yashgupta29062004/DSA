class Solution {
public:
    int minMoves(vector<int>& nums) {
        int moves=0;
        int n=nums.size();
        int min_no=INT_MIN;
        for(int i=0;i<n;i++){
            min_no=max(nums[i],min_no);
        }
        for(int i=0;i<n;i++){
            moves+=min_no-nums[i];
        }
        return moves;
        
    }
};