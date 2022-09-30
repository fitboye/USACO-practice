//
//  main.cpp
//  reduce2
//
//  Created by Jerry Cheng on 1/18/20.
//  Copyright © 2020 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
struct cow{
    int x, y, loc;
};

bool comparex(cow a, cow b){
    return a.x < b.x;
}

bool comparey(cow a , cow b){
    return a.y < b.y;
}

int smallest = 2000000000;
cow e[50000], b[50000];
void select(int a[], int d, int x[], int x1[], int y[], int y1[], int n){
    if (d == 4){
        int points = 0;
        for (int i = 0; i < n; i++){
            if ((e[i].x <= x1[a[0]]) && (e[i].x >= x[a[1]])){
                if ((e[i].y <= y1[a[2]]) && (e[i].y >= y[a[3]])){
                    points++;
                }
            }
        }
        if (n - points <= 3){
            /*
            for (int i = 0; i < 4; i++){
                cout << a[i] << ' ';
            }
            cout << endl;
            cout << x1[a[0]] << ' ' << x[a[1]] << ' ' << y1[a[2]] << ' ' << y[a[3]] << endl;
             */
            int area = (x1[a[0]] - x[a[1]]) * (y1[a[2]] - y[a[3]]);
            //cout << area << endl;
            //cout << endl;
            if (area < smallest){
                smallest = area;
            }
        }
        return;
    }
    
    for (int i = 0; i < 4; i++){
        a[d] = i;
        select(a, d + 1, x, x1, y, y1, n);
    }
}

int main() {
    ifstream fin("reduce.in");
    ofstream fout("reduce.out");
    int n;
    fin >> n;
    for (int i = 0; i < n; i++){
        fin >> e[i].x >> e[i].y;
        b[i] = e[i];
    }
    sort(e, e + n, comparex);
    sort(b, b + n, comparey);
    int x[4], x1[4], y[4], y1[4];
    for (int i = 0; i < 4; i++){
        x[i] = e[i].x;
        x1[i] = e[n - i - 1].x;
        y[i] = b[i].y;
        y1[i] = b[n - i - 1].y;
    }
    int c[4] = {0, 0, 0, 0};
    select(c, 0, x, x1, y, y1, n);
    fout << smallest << endl;
    return 0;
}
