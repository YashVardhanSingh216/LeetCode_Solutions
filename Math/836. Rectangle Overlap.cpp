// 836. Rectangle Overlap

class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        
        bool x_overlap = rec2[0] < rec1[2] && rec1[0] < rec2[2];
        bool y_overlap = rec2[1] < rec1[3] && rec1[1]< rec2[3];
        return x_overlap && y_overlap;

        // int rec1_x1 = rec1[0], rec1_x2 = rec1[2], rec1_y1 = rec1[1], rec1_y2 = rec1[3];

        // int rec2_x1 = rec2[0], rec2_x2 = rec2[2], rec2_y1 = rec2[1], rec2_y2 = rec2[3];

        // bool x_overlap = false;
        // // unordered_map<int,int> mpx;
        // unordered_set<int> mpx;
        // for(int i=rec1_x1; i<rec1_x2; i++){
        //     mpx.insert(i);
        // }
        // for(int i=rec2_x1; i<rec2_x2; i++){
        //     // mpx.insert(i);

        //     if(mpx.count(i)){
        //         x_overlap = true;
        //         break;
        //     }
        // }

        // bool y_overlap = false;
        // // unordered_map<int,int> mpy;
        // unordered_set<int> mpy;
        // for(int j=rec1_y1; j<rec1_y2; j++){
        //     mpy.insert(j);
        // }
        // for(int j=rec2_y1; j<rec2_y2; j++){
        //     // mpy.insert(j);

        //     if(mpy.count(j)){
        //         y_overlap = true;
        //         break;
        //     }
        // }

        // return x_overlap && y_overlap;
    }
};
