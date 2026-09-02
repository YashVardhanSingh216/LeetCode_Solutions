// 58. Length of Last Word

class Solution {
public:
    int lengthOfLastWord(string s) {
        
        bool space = 1;
        int size = 0;

        reverse(s.begin(),s.end());

        for(int i=0; i<s.size(); i++){

            if(s[i] == ' ' && space == 1){
                continue;
            }
            if(s[i] == ' ' && space == 0){
                break;
            }
            else{
                size++;
                space = 0;
            }
        }
        return size;
    }
};
