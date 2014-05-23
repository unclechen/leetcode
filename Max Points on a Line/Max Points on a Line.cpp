#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
//Definition for a point.
struct Point {
     int x;
     int y;
     Point() : x(0), y(0) {}
     Point(int a, int b) : x(a), y(b) {}
};
 
int maxPoints(vector<Point> &points) 
{
    if (points.size() == 0)
       return 0; 
    const double INF = 1E9;
    int i, j, max_result = 1;
    int len = points.size(); 
    for (i = 0; i < len; i++ )
    {
        double k = 0.0;
        int samepoint = 0, result = 1;
        map<double, int> map;
        //cout << "x:" << points[i].x << ", y:" << points[i].y << endl;
        for (j = 0; j < len; j++)
        {
            if (j == i )  continue;
            if(points[i].x == points[j].x  && points[i].y == points[j].y)
            {
                samepoint += 1;
                continue;
            }
            if (points[i].x == points[j].x)
            {
                if (map.find(INF) == map.end() )
                {
                    map[INF] = 2;
                }
                else
                {
                    map[INF] += 1;
                }
                result = max(result, map[INF]);
            }
            else
            {
                k = (points[i].y - points[j].y)*1.0/(points[i].x - points[j].x);
                if (map.find(k) == map.end() )
                {
                    map[k] = 2;
                }
                else
                {
                    map[k] += 1;
                }
                result = max(result, map[k]);
            }
        }
        max_result = max(max_result, result + samepoint);   
    }
    return max_result;     
}

int main()
{
    vector<Point> points;
    int result;
    //Point p = Point(1, 1);
    points.push_back(Point(0, 1));
    points.push_back(Point(1, 1));
    points.push_back(Point(2, 2));
    points.push_back(Point(3, 3));
    cout << maxPoints(points) << endl;
    
    system("pause");
    return 0; 
}
