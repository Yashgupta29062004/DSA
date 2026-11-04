class Solution {
public:
    int n,x,k;
    long long cost[100001];


    long long memo[16][100001];
    long long solve(int count ,int i){
        if(count==k){
            return 0;
        }
        int subarrayneeded= k-count;
        int element_needed= subarrayneeded*x;
        int lastindex  =i+element_needed-1;
        if(lastindex>=n){
            return 1e16;
        }
        if(memo[count][i]!=-1) return memo[count][i];
        long long result=cost[i]+solve(count+1,i+x);
        result=min(result,solve(count,i+1));
        return memo[count][i]=result;

    }

    long long minOperations(vector<int>& nums, int x, int k)
     {
        this->n=nums.size();
        this->x=x;
        this->k=k;
        memset(memo,-1,sizeof(memo));
        multiset<int>left,right;
        long long leftsum=0, rightsum=0;
        int i=0;
        int j=0;
        while(j<n){
            if(left.size()<=right.size()){
                left.insert(nums[j]);
                leftsum+=nums[j];
            }else{
                right.insert(nums[j]);
                rightsum+=nums[j];

            }
            if(!left.empty()&& !right.empty()){
                int maxleft=*left.rbegin();
                int minright=*right.begin();

                if(maxleft>minright){
                    left.erase(left.find(maxleft));
                    right.erase(right.find(minright));

                    left.insert(minright);
                    right.insert(maxleft);

                    leftsum+=minright-maxleft;
                    rightsum+=maxleft-minright;
                }
            }
            if(j-i+1==x){
                long long median=*left.rbegin();
                long long leftsize=left.size();
                long long rightsize=right.size();
                cost[i]=(leftsize*median-leftsum)+(rightsum-rightsize*median);

                if(left.find(nums[i])!=left.end()){
                    left.erase(left.find(nums[i]));
                    leftsum-=nums[i];
                }
                else{
                    right.erase(right.find(nums[i]));
                    rightsum-=nums[i];
                }
                i++;
            }
            j++;
        }
        return solve(0,0);
        
    }
};