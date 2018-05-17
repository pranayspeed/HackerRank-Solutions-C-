#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    int q;
    cin>>q;
    
    int x1,x2,y1,y2;
    
    int res[q][2];
    
    for(int i=0;i<q;i++)
    {
        cin>>x1>>y1>>x2>>y2;
        res[i][0]=2*x2-x1;
        res[i][1]=2*y2-y1;        
    }
    
       for(int i=0;i<q;i++)
       {
           cout<<res[i][0]<<" "<<res[i][1]<<endl;
       }
    return 0;
}
