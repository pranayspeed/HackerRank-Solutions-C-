#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    long L, s1,s2;
    cin >>L>>s1>>s2;
    
    long q_count=0;
    cin >> q_count;
    
    vector<long> q(q_count,0);

    for(long i=0;i < q_count; i++)
    {
        cin >> q[i];
    }
    
    for(long i=0;i < q_count; i++)
    {
        
        double l = sqrt(q[i]);
        double D = (double)sqrt(2)*(L-l);
        
        double t= D/(double)abs(s1-s2);
        cout<<fixed;
        cout<< t<<endl;
        
    }
    return 0;
}
