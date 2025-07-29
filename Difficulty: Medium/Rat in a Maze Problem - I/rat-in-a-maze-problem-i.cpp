class Solution {
  public:
  bool safe(int r, int c,vector<vector<int>> &visited,vector<vector<int>>& maze ){
      if(r<0 || c<0 || r>=maze.size() || c>=maze.size()) return false;
      if(visited[r][c]==1) return false;
      if(maze[r][c]==0) return false;
      return true;
  }
  void solve(vector<vector<int>>& maze,vector<string> &ans,string &temp,vector<vector<int>> &visited,int r, int c   ){
      if(r==maze.size()-1 && c==maze.size()-1){
          ans.push_back(temp);
          return;
      }
      visited[r][c]=1;
      // down
      int newr=r+1;
      int newc=c;
      if(safe(newr,newc,visited,maze)){
          temp.push_back('D');
          solve(maze,ans,temp,visited,newr,newc);
          temp.pop_back();
      }
       // left 
       newr=r;
      newc=c-1;
      if(safe(newr,newc,visited,maze)){
          temp.push_back('L');
          solve(maze,ans,temp,visited,newr,newc);
          temp.pop_back();
      }
      // right
       newr=r;
       newc=c+1;
      if(safe(newr,newc,visited,maze)){
          temp.push_back('R');
          solve(maze,ans,temp,visited,newr,newc);
          temp.pop_back();
      }
      // up
       newr=r-1;
       newc=c;
      if(safe(newr,newc,visited,maze)){
          temp.push_back('U');
          solve(maze,ans,temp,visited,newr,newc);
          temp.pop_back();
      }
      visited[r][c]=0;
      return;
       
      
      
      
      
      
      
      
  }
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
        if(maze[0][0]==0 ||maze[maze.size()-1][maze.size()-1]==0 ) return {};
        vector<string> ans;
        string temp;
        vector<vector<int>> visited(maze.size(),vector<int>(maze.size(),0));
        solve(maze,ans,temp,visited,0,0);
        return ans;
        
    }
};