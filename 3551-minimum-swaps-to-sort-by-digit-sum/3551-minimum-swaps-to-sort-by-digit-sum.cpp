class Solution {
public:
    int digitsum(int num){
        int sum=0;
        while(num>0){
            sum+=(num%10);
            num=num/10;

        }
        return sum;
    }
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        
        
        auto lambda=[&](int num1,int num2){
            int dsum1=digitsum(num1);
            int dsum2=digitsum(num2);
            if(dsum1!=dsum2){
                
                return dsum1<dsum2;
            }
            return num1<num2;
        };
        vector<int>aftersorted(nums);
        
        sort(aftersorted.begin(),aftersorted.end(),lambda);
        unordered_map<int,int>valtoidx;
        for(int i=0;i<n;i++){
            valtoidx[nums[i]]=i;
        }
        int swapcount=0;
        for(int i=0;i<n;i++){
            int expectedval=aftersorted[i];
            int curr=nums[i];
            if(expectedval==curr) continue;
            int idx=valtoidx[expectedval];
            nums[i]=expectedval;
            nums[idx]=curr;
            valtoidx[expectedval]=i;
            valtoidx[curr]=idx;
            swapcount++;
        }
        return swapcount;
    }
};