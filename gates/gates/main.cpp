//
//  main.cpp
//  gates
//
//  Created by Jerry Cheng on 4/18/20.
//  Copyright © 2020 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int n;
vector< vector<int> > a;

void search(int b, int c, int fill){
    if (a[b][c] == 0){
        a[b][c] = fill;
        //cout << b << ' ' << c << endl;
    }else{
        return;
    }
    
    search(b + 1, c, fill);
    search(b - 1, c, fill);
    search(b, c + 1, fill);
    search(b, c - 1, fill);
}

int main() {
    ifstream fin("gates.in");
    ofstream fout("gates.out");
    string s;
    fin >> n >> s;
    int x = 0, y = 0, d[4];
    d[0] = 0;
    d[1] = 0;
    d[2] = 0;
    d[3] = 0;
    for (int i = 0; i < s.length(); i++){
        if (s[i] == 'N'){
            x = x - 2;
        }else if (s[i] == 'S'){
            x = x + 2;
        }else if (s[i] == 'E'){
            y = y + 2;
        }else{
            y = y - 2;
        }
        //cout << x << ' ' << y << endl;
        if (x > d[0]){
            d[0] = x;
        }
        if (x < d[1]){
            d[1] = x;
        }
        if (y > d[2]){
            d[2] = y;
        }
        if (y < d[3]){
            d[3] = y;
        }
    }
    int h = d[0] - d[1] + 8;
    int w = d[2] - d[3] + 8;
    vector<int> insert;
    insert.push_back(1);
    for (int i = 0; i < w - 2; i++){
        insert.push_back(0);
    }
    insert.push_back(1);
    for (int i = 0; i < h; i++){
        a.push_back(insert);
    }
    
    for (int i = 0; i < w; i++){
        a[0][i] = 1;
        a[h - 1][i] = 1;
    }
    
    //cout << h << ' ' << w << endl;
    int b = d[1] * -1 + 4, c = d[3] * -1 + 4;
    //cout << b << ' ' << c << endl;
    a[b][c] = 1;
    for (int i = 0; i < s.length(); i++){
        if (s[i] == 'N'){
            b--;
        }else if (s[i] == 'S'){
            b++;
        }else if (s[i] == 'E'){
            c++;
        }else{
            c--;
        }
        a[b][c] = 1;
        
        if (s[i] == 'N'){
            b--;
        }else if (s[i] == 'S'){
            b++;
        }else if (s[i] == 'E'){
            c++;
        }else{
            c--;
        }
        a[b][c] = 1;
    }
    
    int fill = 2;
    for (int i = 1; i < h; i++){
        for (int j = 1; j < w; j++){
            if (a[i][j] == 0){
                search(i, j, fill);
                fill++;
            }
        }
    }
    /*
    a[100][100] = 5;
    for (int i = 75; i < 125; i++){
        for (int j = 75; j < 125; j++){
            if (a[i][j] == 2){
                cout << ' ';
            }else{
                cout << a[i][j];
            }
        }
        cout << endl;
    }
     */
    fout << fill - 3 << endl;
    return 0;
}
