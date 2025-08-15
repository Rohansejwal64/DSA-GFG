// User function Template for C++

class Solution {
  public:
  int MOD=1e5;
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        queue<pair<int,int>> q;
        vector<int> result(MOD,INT_MAX);
        result[start]=0;
        q.push({0,start});
        while(!q.empty()){
            auto [st,prv]=q.front();
            q.pop();
            if(prv==end) return st;
            for(int &i:arr){
                int curr=(prv*i)%MOD;
                if(result[curr] > st+1){
                    q.push({st+1,curr});
                    result[curr]=st+1;
                    
                }
                
            }
        }
        return -1;
    }
};
