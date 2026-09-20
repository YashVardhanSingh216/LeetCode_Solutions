// 1401. Circle and Rectangle Overlapping

class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {

        int min_x = 0, min_y = 0;

        if(x2 < xCenter)
        min_x = x2;
        else if(x1 > xCenter)
        min_x = x1;
        else
        min_x = xCenter;

        if(y2 < yCenter)
        min_y = y2;
        else if(y1 > yCenter)
        min_y = y1;
        else
        min_y = yCenter;

        int d = sqrt((xCenter - min_x)*(xCenter - min_x) + (yCenter - min_y)*(yCenter - min_y));

        if(d <= radius)
        return true;
        else
        return false;
        

        
    }
};
