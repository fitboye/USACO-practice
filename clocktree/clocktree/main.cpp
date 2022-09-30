//
//  main.cpp
//  clocktree
//
//  Created by Jerry Cheng on 2/23/20.
//  Copyright © 2020 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int n, a[2501], x = 0, xnum = 0, y = 0, ynum = 0;
vector<int> corridors[2501];

void search(int loc, int last, int d){
    if (d%2 == 0){
        x = x + a[loc];
        xnum++;
    }else{
        y = y + a[loc];
        ynum++;
    }
    
    for (int i = 0; i < corridors[loc].size(); i++){
        if (corridors[loc][i] != last){
            search(corridors[loc][i], loc, d + 1);
        }
    }
}

int main() {
    ifstream fin("clocktree.in");
    ofstream fout("clocktree.out");
    fin >> n;
    for (int i = 1; i <= n; i++){
        fin >> a[i];
    }
    for (int i = 0; i < n - 1; i++){
        int c, d;
        fin >> c >> d;
        corridors[c].push_back(d);
        corridors[d].push_back(c);
    }
    search(1, -1, 0);
    x = x % 12;
    y = y % 12;
    if (x == 0 && y == 11){
        x = 12;
    }else if (x == 11 && y == 0){
        y = 12;
    }
    
    if (x == y){
        fout << n << endl;
    }else if (x - y == 1){
        fout << xnum << endl;
    }else if (y - x == 1){
        fout << ynum << endl;
    }else{
        fout << 0 << endl;
    }
    return 0;
}
