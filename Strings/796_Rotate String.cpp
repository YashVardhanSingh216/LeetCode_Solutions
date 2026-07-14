// 796. Rotate String

class Solution {
public:
    bool rotateString(string s, string goal) {

        if(s.size() != goal.size()) return false;

        string ns = s+s;
        int n = ns.size();
       
        for(int i=0; i<n-goal.size(); i++){

            if(ns[i] == goal[0]){
                if(ns.substr(i,goal.size()) == goal) return true;
            }

            else{
                continue;
            }
        }

        return false;
    }
};
