//
//  main.cpp
//  tracing
//
//  Created by Jerry Cheng on 2/19/21.
//  Copyright © 2021 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

struct interaction{
    int t, x, y;
};
bool compare(interaction a, interaction b){
    return a.t < b.t;
}

int main() {
    ifstream fin("tracing.in");
    ofstream fout("tracing.out");
    int n, t;
    fin >> n >> t;
    string s;
    int a[500];
    fin >> s;
    for (int i = 0; i < n; i++){
        a[i] = s[i] - int('0');
    }
    
    interaction b[500];
    for (int i = 0; i < t; i++){
        fin >> b[i].t >> b[i].x >> b[i].y;
        b[i].x--;
        b[i].y--;
    }
    sort(b, b + t, compare);
    
    int x = 0, y = 1000, z = 0, infected[500], shakes[500];
    for (int start = 0; start < n; start++){
        if (a[start] == 1){
            bool add = false;
            for (int k = 0; k <= t; k++){
                bool works = true;
                for (int i = 0; i < n; i++){
                    infected[i] = 0;
                    shakes[i] = 0;
                }
                infected[start] = 1;
                for (int i = 0; i < t; i++){
                    bool d = false;
                    if (shakes[b[i].x] < k && infected[b[i].x] == 1){
                        shakes[b[i].x]++;
                        d = true;
                    }
                    if (shakes[b[i].y] < k && infected[b[i].y] == 1){
                        shakes[b[i].y]++;
                        infected[b[i].x] = 1;
                    }
                    if (d){
                        infected[b[i].y] = 1;
                    }
                }
                for (int i = 0; i < n; i++){
                    //cout << infected[i] << ' ';
                    if (infected[i] != a[i]){
                        works = false;
                    }
                }
                //cout << endl;
                if (works){
                    y = min(k, y);
                    z = max(k, z);
                    add = true;
                }
            }
            if (add){
                x++;
            }
        }
    }
    if (z == t){
        fout << x << ' ' << y << ' ' << "Infinity" << endl;
    }else{
        fout << x << ' ' << y << ' ' << z << endl;
    }
    return 0;
}















