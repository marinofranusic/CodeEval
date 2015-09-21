/*
GRID WALK
SPONSORING COMPANY:
AVANOO
CHALLENGE DESCRIPTION:

There is a monkey which can walk around on a planar grid. The monkey 
can move one space at a time left, right, up or down. That is, from 
x, y) the monkey can go to (x+1, y), (x-1, y), (x, y+1), and (x, y-1).

Points where the sum of the digits of the absolute value of the x 
coordinate plus the sum of the digits of the absolute value of the y
 coordinate are lesser than or equal to 19 are accessible to the monkey.
 For example, the point (59, 79) is inaccessible because 5 + 9 + 7 + 9 = 30,
 which is greater than 19. Another example: the point (-5, -7) is 
 accessible because abs(-5) + abs(-7) = 5 + 7 = 12, which is less than 19.
 How many points can the monkey access if it starts at (0, 0), including 
 (0, 0) itself?

INPUT SAMPLE:

There is no input for this program.

OUTPUT SAMPLE:

Print the number of points the monkey can access. It should be printed 
as an integer — for example, if the number of points is 10, print "10",
 not "10.0" or "10.00", etc.
*/
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
using namespace std;

struct point_t
{
       int x;
       int y;
};

struct find_point
{
       point_t p;
       find_point(point_t p): p(p) {}
       bool operator () ( const point_t& pt) const
       {
            if(p.x==pt.x && p.y==pt.y)
               return true;
            else
               return false;
       }
};

int abs(int num)
{
    if(num<0)
       return num*(-1);
    else
       return num;
}

int SumOfDigits(point_t *p)
{
    int sum=0;

    int num = abs(p->x);
    while ( num > 0 ) 
    {
        sum += num % 10;
        num /= 10;
    }
    num = abs(p->y);
    while ( num > 0 ) 
    {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

bool CanWalk(point_t *p)
{
     if(SumOfDigits(p)<=19)
        return true;
     else
         return false;
}

bool IsInPastPoints(point_t *p, vector<point_t> *v)
{
     bool retVal=false;
     if(find_if((*v).begin(),(*v).end(),find_point(*p))!=(*v).end())
     {retVal=true;}
     else
     {retVal=false;}
     return retVal;
}

int main(int arg, char* args[])
{
    point_t p;
    p.x=0;
    p.y=0;
    
    vector<point_t> PastPoints;
    vector<point_t> ToProcess;
    PastPoints.push_back(p);
    ToProcess.push_back(p);

    //Count duplicates from quarter solution
    while(ToProcess.size()>0)
    {
        point_t tempPoint;
        tempPoint=ToProcess.back();
        ToProcess.pop_back();
        tempPoint.x--;
        if(CanWalk(&tempPoint)==true && IsInPastPoints(&tempPoint,&PastPoints)==false)
        {
             PastPoints.push_back(tempPoint);
             ToProcess.push_back(tempPoint);
        }
        tempPoint.x++;
        
    }
    int duplicates=PastPoints.size();
    PastPoints.clear();
    ToProcess.clear();
    p.x=0;
    p.y=0;
    PastPoints.push_back(p);
    ToProcess.push_back(p);
    //Count quarter solution
     while(ToProcess.size()>0)
    {
        point_t tempPoint;
        tempPoint=ToProcess.back();
        ToProcess.pop_back();
        tempPoint.x--;
        if(CanWalk(&tempPoint)==true && IsInPastPoints(&tempPoint,&PastPoints)==false)
        {
             PastPoints.push_back(tempPoint);
             ToProcess.push_back(tempPoint);
        }
        tempPoint.x++;
        //up
        tempPoint.y--;
        if(CanWalk(&tempPoint)==true && IsInPastPoints(&tempPoint,&PastPoints)==false)
        {
             PastPoints.push_back(tempPoint);
             ToProcess.push_back(tempPoint);
        }
        tempPoint.y++;
    }
    int quarter=PastPoints.size();
    cout<<(quarter-duplicates)*4+1<<endl;
	return 0;
}
