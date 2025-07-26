/*The structure of the class is
class SortedStack{
public:
    stack<int> s;
    void sort();
};
*/

/* The below method sorts the stack s
you are required to complete the below method */
void SortedStack ::sort() {
    // Your code here
    vector<int> temp;
    while(!s.empty()){
        temp.push_back(s.top());
        s.pop();
        
    }
     std::sort(temp.begin(), temp.end());
    for(int i=0;i<temp.size();i++){
        s.push(temp[i]);
    }
    
}