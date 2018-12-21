#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct point{
 int x,y;

    bool operator=(const point &p) const{
        return x == p.x && y == p.y;
    }
    bool operator<(const point &o) const {
        return x < o.x || (x == o.x && y < o.y);
    }
};
vector<point> GetPoints( )
{
    // filestream variable file

    ifstream read("exercice.txt");
    int x,y;
    vector<point> points;
    point p;

    while(read>>x>>y){
    p.x = 2*x;
    p.y = 2*y;
points.push_back(p);
}
    return points;
}
int main()
{

    vector<point> points;
    map<point,int> MapPoints;
    points = GetPoints();
    int numberOfSquare = 0;
    for( int i = 0 ; i < points.size()-1 ; i++)
    {
        point p = points[i];
        MapPoints[p] = 1;
    }
    for( int i = 0 ; i<points.size()-1 ; i++)
    {

        for( int j = i ; j<points.size()-1 ; j++)
        {
            point p3, p4;
            p3.x = (points[i].x + points[j].x + points[j].y - points[i].y)/2;
            p3.y = (points[i].y + points[j].y + points[i].x - points[j].x)/2;
            p4.x = (points[i].x + points[j].x + points[i].y - points[j].y)/2;
            p4.x = (points[i].x + points[j].x + points[j].x - points[i].x)/2;
            if(MapPoints[p3] == 1 && MapPoints[p4] == 1)
            {
            numberOfSquare++;
            }

        }

    }
    cout<<numberOfSquare / 2;
}
