#define ll long long 
class Solution {
public:
    long long countCommas(long long n) {
        
        ll result=0;
        ll lower=1000;
        ll commas=1;
        while(lower<=n){
            ll upper=lower*1000-1;
            if(upper>n){
                upper=n;

            }
            ll count=upper-lower+1;
            result+=(count*commas) ;
            lower*=1000;
            commas++;
        }
        return result;
    }
};