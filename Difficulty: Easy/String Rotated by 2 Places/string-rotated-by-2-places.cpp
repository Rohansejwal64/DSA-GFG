class Solution {
  public:
    bool isRotated(string& s1, string& s2) {
        // code here
        bool check1=true;
        int n=s1.size();
        for(int i=0;i<s1.size();i++){
            int cwc=(i+2)%n;
            if(s2[cwc] !=s1[i]){
                check1=false;
                break;
                
            }
            
        }
        bool check2=true;
        for(int i=0;i<s1.size();i++){
            int acwc=(i-2+n)%n;
            if(s2[acwc] !=s1[i]){
                check2=false;
                break;
                
            }
            
        }
        if(check1 || check2) return true;
        else{
            return false;
        }
        
    }
};
