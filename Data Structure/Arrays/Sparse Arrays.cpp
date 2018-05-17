#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int N;
    cin>>N;
    vector<string> strList;
    for(int i=0;i<N;i++)
    {
        string s;
        cin>>s;
        strList.push_back(s);        
    }
    int Q;
    cin>>Q;
    vector<int> cnts;
    for(int i=0;i<Q;i++)
    {
        string s;
        cin>>s;
        int c=0;
        for(int i=0;i<strList.size();i++)
        {
            if(s.compare(strList[i])==0)
                c++;
        }
        cnts.push_back(c);
    }
    
    for(int i=0;i<cnts.size();i++)
    {
        cout << cnts[i]<<endl;
    }
    return 0;
}
