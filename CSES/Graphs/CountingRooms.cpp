#include <bits/stdc++.h>

using namespace std;

void markRoom(int h, int w, vector<string>& map, int x, int y, vector<vector<int>>& visited){
    struct coords{
        int x, y;
    };
    queue<coords> que;
    que.push({x ,y});
    visited[y][x] = 1;
    coords dir[4] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    while(!que.empty()){
        coords q = que.front();
        que.pop();
        for(auto c : dir){
            if(q.x + c.x >= 0 && q.x + c.x < w && q.y + c.y >= 0 && q.y + c.y < h){
                if(map[q.y + c.y][q.x + c.x] == '.' && visited[q.y + c.y][q.x + c.x] == 0){
                    que.push({q.x + c.x, q.y + c.y});
                    visited[q.y + c.y][q.x + c.x] = 1;
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int h, w, roomCount = 0;
    cin>>h>>w;
    vector<string> map(h);
    for(int i=0; i < h; i++){
        cin>>map[i];
    }

    vector<vector<int>> visited(h, vector<int>(w, 0));
    for(int y = 0; y < map.size(); y++){
        for(int x = 0; x < map[y].size(); x++){
            if(map[y][x] == '.' && visited[y][x] == 0){
                markRoom(h, w, map, x, y, visited);
                roomCount++;
            }
        }
    }

    cout<<roomCount;

    return 0;
}