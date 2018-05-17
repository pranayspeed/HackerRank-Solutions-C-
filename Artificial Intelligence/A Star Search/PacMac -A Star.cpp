#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;

map < pair<int, int>, vector<pair<int, int>>> adj;
vector<pair<int, int>> shortestpath, visitedPath;


void AddEdge(pair<int, int> u, pair<int, int> v)
{
	adj[u].push_back(v);
}




// utility function for printing
// the found path in graph
void printpath(vector<pair<int, int>> & path)
{
    int size = path.size();
    for (int i = 0; i < size; i++) 
        cout << path[i].first <<" "<< path[i].second << endl;    
    //cout << endl;
}
 
// utility function to check if current
// vertex is already present in path
int isNotVisited(pair<int, int> x, vector<pair<int, int>> & path)
{
    int size = path.size();
    for (int i = 0; i < size; i++) 
        if (path[i] == x) 
            return 0; 
    return 1;
}
 
// utility function for finding paths in graph
// from source to destination
void findpaths(map < pair<int, int>, vector<pair<int, int>>>&g, pair<int, int> src, 
                                 pair<int, int> dst, pair<int, int> v)
{
    // create a queue which stores
    // the paths
    queue<vector<pair<int, int>> > q;
 
    // path vector to store the current path
    vector<pair<int, int>> path;
    path.push_back(src);
    q.push(path);
    while (!q.empty()) {
        path = q.front();
        q.pop();
        pair<int, int> last = path[path.size() - 1];
        if(find(visitedPath.begin(),visitedPath.end(),last)==visitedPath.end())
             visitedPath.push_back(last);
        // if last vertex is the desired destination
        // then print the path
        if (last == dst) 
        {
           // printpath(path);
            shortestpath.assign(path.begin(), path.end());
            return;
        }         
 
        // traverse to all the nodes connected to 
        // current vertex and push new path to queue
        
        vector<pair<int, int>> tmpNodes;
       
        for (int i = 0; i < g[last].size(); i++) {
            if (isNotVisited(g[last][i], path)) {
               // vector<pair<int, int>> newpath(path);
               // newpath.push_back(g[last][i]);
               // q.push(newpath);
              int lenNew = abs(g[last][i].first - dst.first) + abs(g[last][i].second - dst.second);
                int insertIndex=0;
               for (insertIndex = 0; insertIndex < tmpNodes.size(); insertIndex++)
               {
                   int len =abs(tmpNodes[insertIndex].first - dst.first) + abs(tmpNodes[insertIndex].second - dst.second);          
                   if(len> lenNew)
                   {
                       break;
                   }
               }
               tmpNodes.insert(tmpNodes.begin()+insertIndex, g[last][i]);
            }
        }
        
        for (int i = 0; i < tmpNodes.size(); i++)
        {
                vector<pair<int, int>> newpath(path);
                newpath.push_back(tmpNodes[i]);
                q.push(newpath);                
        }
        
    }
}
 




void nextMove( int r, int c, int pacman_r, int pacman_c, int food_r, int food_c, vector <string> grid){
    //your logic here
   
	for (int i = 1; i<r-1; i++)
	{
		for (int j = 1; j<c-1; j++)
		{
			
			char up = grid[i - 1][j];
			char left = grid[i][j - 1];
			char right = grid[i][j + 1];
			char down = grid[i + 1][j];


			if (up == '-' || up == '.' || up == 'P')
			{
				AddEdge(pair<int, int>(i, j), pair<int, int>(i - 1, j));
			}
			if (left == '-' || left == '.' || left == 'P')
			{
				AddEdge(pair<int, int>(i, j), pair<int, int>(i, j - 1));
			}
			if (right == '-' || right == '.' || right == 'P')
			{
				AddEdge(pair<int, int>(i, j), pair<int, int>(i, j+1));
			}
			if (down == '-' || down == '.' || down == 'P')
			{
				AddEdge(pair<int, int>(i, j), pair<int, int>(i + 1, j));
			}
		}
	}

	findpaths(adj, pair<int, int>(pacman_r, pacman_c), pair<int, int>(food_r, food_c), pair<int, int>(pacman_r, pacman_c));
    
    cout<< shortestpath.size()-1<<endl;    
    printpath(shortestpath);

}
int main(void) {

    int r,c, pacman_r, pacman_c, food_r, food_c;
    
    cin >> pacman_r >> pacman_c;
    cin >> food_r >> food_c;
    cin >> r >> c;
    vector <string> grid;

    for(int i=0; i<r; i++) {
        string s; cin >> s;
        grid.push_back(s);
    }

    nextMove( r, c, pacman_r, pacman_c, food_r, food_c, grid);

    return 0;
}
