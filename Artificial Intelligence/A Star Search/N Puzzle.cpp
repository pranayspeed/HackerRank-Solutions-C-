#include <string>
#include <vector>
#include <queue>
#include <map>
#include <cstdio>
#include <iostream>
using namespace std;

void SolvePuzzle(vector<int> goal, int k)
{
    map<vector<int>,pair<int,int> >m;
	map<vector<int>,pair<vector<int>,string> >prev;
	queue<vector<int> >q;
	vector<int>v,next;
    int i,j;
	for(i=0;i<k*k;i++)v.push_back(i);
	m[v]=make_pair(0,0);
	prev[v]=make_pair(v,"");
	for(q.push(v);!q.empty();){
		v=q.front();q.pop();
		int indx=m[v].first,j=indx%k,i=indx/k;
		int depth=m[v].second;
		next=v;
        
        if(0<i)//UP
        {
			swap(v[indx],v[indx-k]);
			if(m.find(v)==m.end())
            {
                m[v]=make_pair(indx-k,depth+1);
                q.push(v);
                prev[v]=make_pair(next,"DOWN");
            }
			swap(v[indx],v[indx-k]);
		}
		if(i<k-1)//DOWN
        {
			swap(v[indx],v[indx+k]);
			if(m.find(v)==m.end())
            {
                m[v]=make_pair(indx+k,depth+1);
                q.push(v);
                prev[v]=make_pair(next,"UP");
            }
			swap(v[indx],v[indx+k]);
		}
        
		if(0<j)//LEFT
        {
			swap(v[indx],v[indx-1]);
			if(m.find(v)==m.end())
            {
                m[v]=make_pair(indx-1,depth+1);
                q.push(v);
                prev[v]=make_pair(next,"RIGHT");
            }
			swap(v[indx],v[indx-1]);
		}
		if(j<k-1)//RIGHT
        {
			swap(v[indx],v[indx+1]);
			if(m.find(v)==m.end())
            {
                m[v]=make_pair(indx+1,depth+1);
                q.push(v);
                prev[v]=make_pair(next,"LEFT");
            }
			swap(v[indx],v[indx+1]);
		}

		if(m.find(goal)!=m.end())break;
	}

	cout <<m[goal].second<< endl;
	for(;prev[goal].first!=goal;){
		cout << prev[goal].second<< endl;
		goal=prev[goal].first;
	}
}


int main(){
	int k,t;
	vector<int>grid;
	cin >>k;
    
	for(int i=0;i<k*k;i++)
    {
        cin>> t;
        grid.push_back(t);
    }

    SolvePuzzle(grid, k);
}