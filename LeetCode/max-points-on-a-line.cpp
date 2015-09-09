/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
    int getCantor(int x, int y) {
        return (x + y) * (x + y + 1) / 2 + x;
    }
    
    int getGCD(int x, int y) {
        while (y != 0) {
            int r = x % y;
            x = y;
            y = r;
        }
        return x;
    }
    
public:
    int maxPoints(vector<Point>& points) {
        if (points.size() <= 2) {
            return points.size();
        }
        
        int ret = 2;
        for (int i=0; i<points.size(); i++) {
            int samePoint = 1,
                verticalLine = 0,
                bestSlopeCount = 0;
                
            unordered_map<int, int> h;
            
            for (int j=i+1; j<points.size(); j++) {
                if (points[i].x == points[j].x &&
                    points[i].y == points[j].y) {
                        samePoint++;
                } else if (points[i].x == points[j].x) {
                    verticalLine++;
                } else {
                    int yDiff = points[i].y - points[j].y,
                        xDiff = points[i].x - points[j].x;
                    
                    int gcd = getGCD(yDiff, xDiff);
                    
                    int yNew = yDiff / gcd,
                        xNew = xDiff / gcd;
                        
                    int cantor = getCantor(yNew, xNew);
                    h[cantor]++;
                    bestSlopeCount=max(h[cantor], bestSlopeCount);
                }
            }
            
            ret = max(ret, max(bestSlopeCount + samePoint, 
                               verticalLine + samePoint));
        }
        
        return ret;
    }
};
