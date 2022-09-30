//
//  main.cpp
//  crazy
//
//  Created by Jerry Cheng on 3/13/21.
//  Copyright © 2021 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct pos{
    int val, type, og, fencepoint;
};

bool compare(pos a, pos b){
    return a.val < b.val;
}

int field[3100][3100], cowcount;
void fill (int x, int y){
    queue<pair<int, int>> a;
    a.push({x, y});
    while(a.size() > 0){
        x = a.front().first;
        y = a.front().second;
        //cout << 'a' << endl;
        if (field[x][y] != 1 && field[x][y] != 3){
            if (field[x][y] == 0){
                field[x][y] = 3;
            }else if (field[x][y] == 2){
                //cout << 'a' << endl;
                cowcount++;
                field[x][y] = 3;
            }
            a.push({x + 1, y});
            a.push({x - 1, y});
            a.push({x, y + 1});
            a.push({x, y - 1});
        }
        a.pop();
    }
    /*
    //cout << x << ' ' << y << endl;
    if (field[x][y] == 0){
        field[x][y] = 3;
    }else if (field[x][y] == 2){
        //cout << 'a' << endl;
        cowcount++;
        field[x][y] = 3;
    }else{
        return;
    }
    //cout << 'a' << endl;
    fill (x + 1, y);
    fill (x - 1, y);
    fill (x, y + 1);
    fill (x, y - 1);
     */
}

int main() {
    ifstream fin("crazy.in");
    ofstream fout("crazy.out");
    int n, c, fences[4][500], cows[2][500];
    fin >> n >> c;
    vector<pos> x;
    vector<pos> y;
    for (int i = 0; i < n; i++){
        pos z;
        z.type = 0;
        z.og = i;
        fin >> fences[0][i] >> fences[1][i] >> fences[2][i] >> fences[3][i];
        z.fencepoint = 0;
        z.val = fences[0][i];
        x.push_back(z);
        z.fencepoint = 1;
        z.val = fences[1][i];
        y.push_back(z);
        z.fencepoint = 2;
        z.val = fences[2][i];
        x.push_back(z);
        z.fencepoint = 3;
        z.val = fences[3][i];
        y.push_back(z);
    }
    for (int i = 0; i < c; i++){
        pos z;
        z.type = 1;
        z.og = i;
        fin >> cows[0][i] >> cows[1][i];
        z.val = cows[0][i];
        x.push_back(z);
        z.val = cows[1][i];
        y.push_back(z);
    }
    sort(x.begin(), x.end(), compare);
    sort(y.begin(), y.end(), compare);
    
    int num = 2;
    for (int i = 0; i < x.size(); i++){
        if (i > 0 && x[i].val != x[i - 1].val){
            num+=2;
        }
        if (x[i].type == 0){
            fences[x[i].fencepoint][x[i].og] = num;
            fences[x[i].fencepoint][x[i].og] = num;
        }else{
            cows[0][x[i].og] = num;
        }
    }
    num = 2;
    for (int i = 0; i < y.size(); i++){
        if (i > 0 && y[i].val != y[i - 1].val){
            num+=2;
        }
        if (y[i].type == 0){
            fences[y[i].fencepoint][y[i].og] = num;
            fences[y[i].fencepoint][y[i].og] = num;
        }else{
            cows[1][y[i].og] = num;
        }
    }
    
    for (int i = 0; i < 3100; i++){
        for (int j = 0; j < 3100; j++){
            field[i][j] = 0;
        }
    }
    int area = max(x.size(), y.size()) * 2 + 10;
    //int area = 2 * n + 2 * c + 10;
    for (int i = 0; i < area; i++){
        field[0][i] = 1;
        field[area-1][i] = 1;
        field[i][0] = 1;
        field[i][area-1] = 1;
    }
    for (int i = 0; i < n; i++){
        if (fences[0][i] == fences[2][i]){
            int smaller = min(fences[1][i], fences[3][i]), larger = max(fences[1][i], fences[3][i]);
            for (int j = smaller; j < larger; j++){
                field[fences[0][i]][j] = 1;
            }
        }else{
            int smaller = min(fences[0][i], fences[2][i]), larger = max(fences[0][i], fences[2][i]);
            for (int j = smaller; j < larger; j++){
                field[j][fences[1][i]] = 1;
            }
        }
    }
    
    for (int i = 0; i < c; i++){
        field[cows[0][i]][cows[1][i]] = 2;
    }
    /*
    for (int i = 0; i < area; i++){
        for (int j = 0; j < area; j++){
            cout << field[i][j];
        }
        cout << endl;
    }
     */
    
    int ans = 0;
    for (int i = 1; i < area; i++){
        for (int j = 1; j < area; j++){
            if (field[i][j] == 0){
                cowcount = 0;
                fill(i, j);
                ans = max(cowcount, ans);
            }
        }
    }
    fout << ans << endl;
    return 0;
}
