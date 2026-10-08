class Solution {
public:
    string removeOuterParentheses(string s) {
        string result="";
        int n=s.length();
        int count=0;
        for(char&ch:s){
            if(ch=='('){
                if(count!=0){
                    result.push_back(ch);
                }
                count++;
            }


            else{
                count--;
                if(count!=0){
                    result.push_back(ch);
                }
            }
        }
        return result;
        
    }
};