class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(),arr2.end());
        int count =0;
        int n=arr2.size();
        for(int i=0;i<arr1.size();i++){
            int j=lower_bound(begin(arr2),end(arr2),arr1[i])-begin(arr2);
            if(j==0){
                count+=abs(arr2[0]-arr1[i])>d;
            }
            else if(j>=n){
                count+=abs(arr1[i]-arr2[n-1])>d;

            }
            else{
                count+=(abs(arr1[i]-arr2[j])>d)&&(abs(arr1[i]-arr2[j-1])>d);

            }
        }
        return count ;
        
    }
};