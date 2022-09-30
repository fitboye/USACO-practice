//
//  main.cpp
//  maze tac toe
//
//  Created by Jerry Cheng on 4/5/21.
//  Copyright © 2021 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

string a[25][25];
vector<int> connections[625];
map<string, int> id;
vector<pair<int, int>> location;
int previous[25][25];
void gridsearch(int x, int y, int last){
    if (a[x][y] == "###" || previous[x][y] == 1){
        return;
    }
    previous[x][y] = 1;
    if (a[x][y] != "..." && id[a[x][y]] != last && a[x][y] != "BBB"){
        connections[last].push_back(id[a[x][y]]);
        return;
    }
    gridsearch(x + 1, y, last);
    gridsearch(x, y + 1, last);
    gridsearch(x - 1, y, last);
    gridsearch(x, y - 1, last);
}

int flag[625];
int bessie;
char generatedgrid[3][3];
char constructedgrid[3][3];
vector<string> points;
int ans = 0;
bool assess(){
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            cout << generatedgrid[i][j];
        }
        cout << endl;
    }
    cout << endl;
    
    bool win = false;
    for (int i = 0; i < 3; i++){
        if (generatedgrid[i][0] == 'M' && generatedgrid[i][1] == 'O' && generatedgrid[i][2] == 'O'){
            win = true;
        }
        if (generatedgrid[i][0] == 'O' && generatedgrid[i][1] == 'O' && generatedgrid[i][2] == 'M'){
            win = true;
        }
    }
    for (int i = 0; i < 3; i++){
        if (generatedgrid[0][i] == 'M' && generatedgrid[1][i] == 'O' && generatedgrid[2][i] == 'O'){
            win = true;
        }
        if (generatedgrid[0][i] == 'O' && generatedgrid[1][i] == 'O' && generatedgrid[2][i] == 'M'){
            win = true;
        }
    }
    
    if (generatedgrid[0][0] == 'M' && generatedgrid[1][1] == 'O' && generatedgrid[2][2] == 'O'){
        win = true;
    }
    if (generatedgrid[0][2] == 'M' && generatedgrid[1][1] == 'O' && generatedgrid[2][0] == 'O'){
        win = true;
    }
    if (generatedgrid[0][0] == 'O' && generatedgrid[1][1] == 'O' && generatedgrid[2][2] == 'M'){
        win = true;
    }
    if (generatedgrid[0][2] == 'O' && generatedgrid[1][1] == 'O' && generatedgrid[2][0] == 'M'){
        win = true;
    }
    
    if (win){
        return true;
    }
    return false;
}

void search(int current){
    //cout << current << endl;
    if (flag[current] == 1){
        return;
    }
    flag[current] = 1;
    
    
    if (assess()){
        ans++;
        return;
    }
    
    if (current != bessie){
        //cout << points[current][0] << endl;
        int x = int(points[current][1]) - int('1'), y = int(points[current][2]) - int('1');
        if (generatedgrid[x][y] == ' '){
            generatedgrid[x][y] = points[current][0];
        }
    }
    for (int i = 0; i < connections[current].size(); i++){
        search(connections[current][i]);
    }
    flag[current] = 0;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            string w = "   ";
            char x, y, z;
            cin >> x >> y >> z;
            w[0] = x;
            w[1] = y;
            w[2] = z;
            a[i][j] = w;
            if (x == 'B'){
                bessie = points.size();
            }
            if (x != '#' && x != '.'){
                id[w] = points.size();
                points.push_back(w);
                location.push_back({i, j});
            }
            //cout << w << endl;
        }
    }
    
    for (int i = 0; i < location.size(); i++){
        for (int j = 0; j < 25; j++){
            for (int k = 0; k < 25; k++){
                previous[j][k] = 0;
            }
        }
        gridsearch(location[i].first, location[i].second, i);
    }
    for (int i = 0; i < 10; i++){
        //cout << points[i] << ' ';
        for (int j = 0; j < connections[i].size(); j++){
            //cout << points[connections[i][j]] << ' ';
        }
        //cout << endl;
    }
    
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            generatedgrid[i][j] = ' ';
        }
    }
    search(bessie);
    cout << ans << endl;
    return 0;
}
