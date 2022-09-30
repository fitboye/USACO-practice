//
//  main.cpp
//  cowjump
//
//  Created by Jerry Cheng on 3/30/19.
//  Copyright © 2019 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

struct hurdle{
    int x1, x2, y1, y2, count, index;
};

bool x(hurdle x, hurdle y){
    return x.x1 < y.x1;
}

int main() {
    ifstream fin("cowjump.in");
    ofstream fout("cowjump.out");
    int n;
    hurdle a[100000];
    fin >> n;
    for (int i = 0; i < n; i++){
        fin >> a[i].x1 >> a[i].y1 >> a[i].x2 >> a[i].y2;
        a[i].index = i + 1;
    }
    
    int b;
    for (int i = 0; i < n; i++){
        if (a[i].x1 > a[i].x2){
            b = a[i].x1;
            a[i].x1 = a[i].x2;
            a[i].x2 = b;
        }
        if (a[i].y1 > a[i].y2){
            b = a[i].y1;
            a[i].y1 = a[i].y2;
            a[i].y2 = b;
        }
    }
    sort(a, a + n, x);
    
    int overlaps[2][100000], o = 0;
    for (int i = 0; i < n; i++){
        int j = i;
        while ((j < n) && (a[j].x1 < a[i].x2)){
            if ((a[i].x2 >= a[j].x1) && (a[i].y2 >= a[j].y1)){
                if (i != j){
                    overlaps[0][o] = a[i].index;
                    overlaps[1][o] = a[j].index;
                    o++;
                }
            }
            j++;
        }
    }
    
    
    return 0;
}
