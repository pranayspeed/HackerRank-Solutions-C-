#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    int m;
    cin >> n >> m;
    int mi=1,mj=n;
    vector<long long int> list(n,0);
    long long int max=0;
    for(int a0 = 0; a0 < m; a0++){
        int a;
        int b;
        int k;
        cin >> a >> b >> k;
        
        list[a-1]+=k;
        if(b<=n) list[b]-=k;
     
    }
        
    long long sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=list[i];
        if(max<sum)
           max=sum;
    }   

    cout << max;
    return 0;
}
