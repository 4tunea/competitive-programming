#include<bits/stdc++.h>

using namespace std;

struct MOVIE{
    int start, end;
};

bool sorter(const MOVIE &a, const MOVIE &b){
    if(a.end == b.end){
        return a.start < b.start;
    }
    return a.end < b.end;
}

int main(){
    int n, ats = 0; cin >> n;
    vector<MOVIE> movies;
    for(int i = 0; i < n; i++){
        int start, end;
        cin>>start>>end;
        movies.push_back({start, end});
    }
    
    sort(movies.begin(), movies.end(), sorter);
    int StartHour = 0;
    for(auto i : movies){
        if(StartHour == 0){
            StartHour = i.end;
            ats++;
            continue;
        }
        if(StartHour <= i.start){
            StartHour = i.end;
            ats++;
        }
    }
    
    cout<<ats;

    return 0;
}