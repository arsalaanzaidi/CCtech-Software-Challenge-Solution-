#include<iostream>
using namespace std;

struct Point {
   float x, y;
};

struct line {
   Point p1, p2;
};

bool checkonLine(line l, Point p) {      
   if(p.x <= max(l.p1.x, l.p2.x) && p.x <= min(l.p1.x, l.p2.x) &&
      (p.y <= max(l.p1.y, l.p2.y) && p.y <= min(l.p1.y, l.p2.y)))
         return true;

   return false;
}

int direction(Point a, Point b, Point c) {
   int val = (b.y-a.y)*(c.x-b.x)-(b.x-a.x)*(c.y-b.y);
   if (val == 0)
      return 0;         
   else if(val < 0)
      return 2;          
      return 1;         
}

bool intersect(line l1, line l2) {

   int dir1 = direction(l1.p1, l1.p2, l2.p1);
   int dir2 = direction(l1.p1, l1.p2, l2.p2);
   int dir3 = direction(l2.p1, l2.p2, l1.p1);
   int dir4 = direction(l2.p1, l2.p2, l1.p2);

   if(dir1 != dir2 && dir3 != dir4)
      return true;           //they are intersecting
   if(dir1==0 && checkonLine(l1, l2.p1))        
      return true;
   if(dir2==0 && checkonLine(l1, l2.p2))       
      return true;
   if(dir3==0 && checkonLine(l2, l1.p1))      
      return true;
   if(dir4==0 && checkonLine(l2, l1.p2))
      return true;
   return false;
}

bool checkInside(Point poly[], int n, Point p) {
   if(n < 3)
      return false;                 
   line infinity = {p, {9999, p.y}};  
   int count = 0;
   int i = 0;
   do {
      line side = {poly[i], poly[(i+1)%n]};    
      if(intersect(side, infinity)) {        
         if(direction(side.p1, p, side.p2) == 0)
            return checkonLine(side, p);
         count++;
      }
      i = (i+1)%n;
   } while(i != 0);
    if(count%2!=0)
        return true;
    else
    return false;
}

int main() {
   cout<<"Enter no. of Points";
   int n;
   cin>>n;
   Point polygon[n];
   cout<<"Enter Points";
   for(int i=0;i<n;i++)
   {
       float a, b;
       cin>>a>>b;
       polygon[i]={a,b};
   }
   cout<<"Enter Point to be checked";
   float a, b;
   cin>>a>>b; 
   Point x={a,b};
   if(checkInside(polygon,n,x))
   cout<<"true";
   else
   cout<<"False";
}

