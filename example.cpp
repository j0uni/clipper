#include "clipper.hpp"

using namespace ClipperLib;

Paths subj;
Paths clip;
Paths solution;

void addPoint(int x, int y, Path *path)
{
    IntPoint ip;
    ip.X = x;
    ip.Y = y;
    path->push_back(ip);
}

int main()
{
    Paths subj;
    
    Path p;
    addPoint(100,100, &p);
    addPoint(200,100, &p);
    addPoint(200,200, &p);
    addPoint(100,200, &p);
    subj.push_back(p);
    
    Path p2;
    addPoint(150,50, &p2);
    addPoint(175,50, &p2);
    addPoint(175,250, &p2);
    addPoint(150,250, &p2);
    clip.push_back(p2);
    
    Clipper c;
    
    c.AddPaths(subj, ptSubject, true);
    c.AddPaths(clip, ptClip, true);
    c.Execute(ctIntersection, solution, pftNonZero, pftNonZero);
    
    printf("solution size = %d\n",(int)solution.size());
    for (unsigned i=0; i<solution.size(); i++)
    {
        Path p3 = solution.at(i);
        
        for (unsigned j=0; j<p3.size(); j++)
        {
            IntPoint ip = p3.at(j);
            printf("%d = %lld, %lld\n",j, ip.X,ip.Y);
        }
        
    }
    
    return 0;
}
