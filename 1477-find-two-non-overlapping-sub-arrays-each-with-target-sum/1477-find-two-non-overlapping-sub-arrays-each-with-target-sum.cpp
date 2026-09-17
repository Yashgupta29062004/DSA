class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n=arr.size();
        int i=0;
        int j=0;
        int currsum=0;
        vector<int>minbest(n,INT_MAX);
        int bestmin=INT_MAX;
        int result=INT_MAX;
        while(j<n){
            currsum+=arr[j];
            while(currsum>target && i <= j){
                currsum-=arr[i];
                i++;
            }
            if(currsum==target){
                int len=j-i+1;
                if(i>0 && minbest[i-1]!=INT_MAX){
                    result=min(result,len+minbest[i-1]);
                }
                bestmin=min(bestmin,len);
            }
            minbest[j]=bestmin;
            j++;
        }
        return result == INT_MAX ? -1 : result;
        
    }
};