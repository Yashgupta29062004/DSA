class Solution {
public:
    vector<bool>is_prime;
    void buildsieve(int maxEl){
        is_prime.resize(maxEl+1,true);
        is_prime[0]=false;
        is_prime[1]=false;
        for(int i=2;i*i<=maxEl;i++){
            if(is_prime[i]){
                for(int mul=i*i;mul<=maxEl;mul+=i){
                    is_prime[mul]=false;
                }

            }
        }

        
    }
    int minJumps(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,vector<int>>mp;
        int maxEl=0;
        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
            maxEl=max(maxEl,nums[i]);
        }
        buildsieve(maxEl);
        queue<int>que;
        vector<bool>visited(n,false);
        que.push(0);
        visited[0]=true;
        unordered_set<int>seen;
        int steps=-0;
        while(!que.empty()){
            int size=que.size();
                while(size--){
                    int i=que.front();
                    que.pop();
                    if(i==n-1){
                        return steps;

                    }
                    if(i-1>=0&&!visited[i-1]){
                        que.push(i-1);
                        visited[i-1]=true;
                    }
                    if(i+1<=n&&!visited[i+1]){
                        que.push(i+1);
                        visited[i+1]=true;
                    }
                    if(is_prime[nums[i]]==false){
                        continue;

                    }
                    if(seen.count(nums[i])){
                        continue;
                    }
                    for(int mul=nums[i];mul<=maxEl;mul+=nums[i]){
                        if(!mp.contains(mul)){
                            continue;

                        }
                        for(int&j:mp[mul]){
                            if(!visited[j]){
                                que.push(j);
                                visited[j]=true;

                            }
                            
                        }
                    }
                    seen.insert(nums[i]);
                }

            
            steps++;
        }
        return steps;

        
    }
};