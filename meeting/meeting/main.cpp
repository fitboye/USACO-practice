//
//  main.cpp
//  meeting
//
//  Created by Jerry Cheng on 4/3/21.
//  Copyright © 2021 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <set>
#include <vector>
#include <queue>
using namespace std;

struct path{
    int end, b, e;
};

vector<path> paths[17];
set<int> bessie[17];
set<int> elsie[17];

int main() {
    ifstream fin("meeting.in");
    ofstream fout("meeting.out");
    int n, m;
    fin >> n >> m;
    for (int i = 0; i < m; i++){
        int x, y;
        fin >> x >> y;
        path z;
        z.end = max(x, y);
        fin >> z.b >> z.e;
        paths[min(x, y)].push_back(z);
    }
    
    bessie[1].insert(0);
    elsie[1].insert(0);
    for (int loc = 1; loc < 16; loc++){
        for (int i = 0; i < paths[loc].size(); i++){
            for (int j: bessie[loc]){
                bessie[paths[loc][i].end].insert(paths[loc][i].b + j);
            }
            for (int j: elsie[loc]){
                elsie[paths[loc][i].end].insert(paths[loc][i].e + j);
            }
        }
    }
    
    vector<int> b, e;
    for (int j: bessie[n]){
        b.push_back(j);
    }
    for (int j: elsie[n]){
        e.push_back(j);
    }
    
    int j = 0, ans = -1;
    for (int i = 0; i < b.size(); i++){
        while(j < e.size() && b[i] > e[j]){
            j++;
        }
        if (b[i] == e[j]){
            ans = b[i];
            break;
        }
    }
    if (ans == -1){
        fout << "IMPOSSIBLE" << endl;
    }else{
        fout << ans << endl;
    }
    return 0;
}
