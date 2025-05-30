class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int> > &mat) {
        // code here
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        int r=0;
        int c=0;
        vector<int>dr={0,1,0,-1};
        vector<int>dc={1,0,-1,0};
        vector<int> ans;
        int index=0;
        for(int i=0;i<n*m;i++){
            ans.push_back(mat[r][c]);
            visited[r][c]=true;
            int nr=r+dr[index];
            int nc=c+dc[index];
            if(nr>=0 && nr<n && nc>=0 && nc<m && !visited[nr][nc]){
                r=nr;
                c=nc;
            }
            else{
                index=(index+1)%4;
                r=r+dr[index];
                c=c+dc[index];
            }
            
        }
        return ans;
    }
};