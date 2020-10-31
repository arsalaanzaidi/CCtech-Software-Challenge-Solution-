/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;


struct Point {
   float x, y;
};

struct Building {
   Point p1, p2,p3,p4;
};
float Dist(Point p1,Point p2)
{
    return(sqrt(pow(p2.x - p1.x, 2) +  pow(p2.y - p1.y, 2) * 1.0));
}
Point intersect(Point s,Point p4,Point p1,Point p2)
{
    float slope=(p4.y-s.y)/(p4.x-s.x);
    
    Point a;
    float m = slope;
    float l=50;
    // slope is 0
    if (m == 0) {
        a.x = p4.x + l;
        a.y = p4.y;
    }
 
    // if slope is infinte
    else if (m == std::numeric_limits<float>
                                 ::max()) {
        a.x = p4.x;
        a.y = p4.y + l;
 
    } 
    else {
        float dx = (l / sqrt(1 + (m * m)));
        float dy = m * dx;
        a.x = p4.x + dx;
        a.y = p4.y + dy;
    }
    
    double a =  - A.second;
   double b = A.first - B.first;
   double c = a*(A.first) + b*(A.second);
   // Line CD represented as a2x + b2y = c2
   double a1 = D.second - C.second;
   double b1 = C.first - D.first;
   double c1 = a1*(C.first)+ b1*(C.second);
   double det = a*b1 - a1*b;
   if (det == 0) {
      return make_pair(FLT_MAX, FLT_MAX);
   } else {
      double x = (b1*c - b*c1)/det;
      double y = (a*c1 - a1*c)/det;
      return make_pair(x, y);
   }
    
    
}
float caluclateLength(Building b1[],int n, Point p)
{
    float a,b;
    a=Dist(b1[0].p1,b1[0].p2);
    b=Dist(b1[0].p1,b1[0].p4);
    float distance =a+b;//main distance
    if(n>1)
    {
       Point p1= intersect(p,b1[0].p4,b1[1].p1,b1[1].p1);
    }
    
    
    return distance;
}


int main()
{
    cout<<"Enter no. of Buildings";
   int n;
   cin>>n;
   Building b1[n];
   int count=0;
   while(count<n){
       
       float a, b,c,d,e,f,g,h;
   cout<<"Enter Points of building";
       cin>>a>>b>>c>>d>>e>>f>>g>>h;
       Point p1={a,b};
       Point p2={c,d};
       Point p3={e,f};
       Point p4={g,h};
       b1[count]={p1,p2,p3,p4};
       count++;
   }
   cout<<"Enter Source Point";
   float a, b;
   cin>>a>>b; 
   Point s={a,b};
   float k = caluclateLength(b1,n,s);
   cout<<k;
    return 0;
}
