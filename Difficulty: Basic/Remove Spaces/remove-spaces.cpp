class Solution {
  public:
    string modify(string& s) {
        // code here.
        int temp=0;
        for(int i=0;i<s.size();i++){
            if(s[i]!=' '){
                s[temp]=s[i];
                temp++;
            }
            
        }
       int c=s.size()-temp;
       for(int i=1;i<=c;i++){
           s.pop_back();
       }
        return s;
        
    }
};