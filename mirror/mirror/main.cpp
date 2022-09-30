//
//  main.cpp
//  mirror
//
//  Created by Jerry Cheng on 5/30/20.
//  Copyright © 2020 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;

int n, m;
char a[1000][1000];
int l[4] = {3, 2, 1, 0};
int r[4] = {1, 0, 3, 2};
int b[4] = {1, 0, -1, 0};
int c[4] = {0, -1, 0, 1};
int reflect (int loc1, int loc2, int direction){
    int bounces = 0;
    while (loc1 >= 0 && loc1 < n && loc2 >= 0 && loc2 < m){
        if (a[loc1][loc2] == '/'){
            direction = r[direction];
        }else{
            direction = l[direction];
        }
        loc1 = loc1 + b[direction];
        loc2 = loc2 + c[direction];
        bounces++;
    }
    return bounces;
}

int main() {
    ifstream fin("mirror.in");
    ofstream fout("mirror.out");
    fin >> n >> m;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            fin >> a[i][j];
        }
    }
    
    int max = 0;
    for (int i = 0; i < n; i++){
        int bounces = reflect(i, 0, 3);
        if (bounces > max){
            max = bounces;
        }
        
        bounces = reflect(i, m - 1, 1);
        if (bounces > max){
            max = bounces;
        }
    }
    
    for (int i = 0; i < m; i++){
        int bounces = reflect(0, i, 0);
        if (bounces > max){
            max = bounces;
        }
        
        bounces = reflect(n - 1, i, 2);
        if (bounces > max){
            max = bounces;
        }
    }
    fout << max << endl;
    return 0;
}
