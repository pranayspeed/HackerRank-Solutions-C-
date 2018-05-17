#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    int N,Q;
    cin >>N>>Q;
    
    vector<vector<long long int>> seqList;
    seqList.resize(N);
    
    long long int la=0;
    long long int x,y;
    int qn;
    vector<long long int> ans;
    for(int i=0;i<Q;i++)
    {        
        cin>>qn>>x>>y;
        int indx = (x^la)%N;
        if(qn==1)
        {
            seqList[indx].push_back(y);
        }
        else
        {
            la=seqList[indx][y% seqList[indx].size()];
            ans.push_back(la);
        }
    }
    
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<endl;
    } 
    
    
    return 0;
}
