//
//  main.cpp
//  balancing
//
//  Created by Jerry Cheng on 8/24/19.
//  Copyright © 2019 Jerry Cheng. All rights reserved.
//

struct c{
    int x, y;
};

bool comparex (c a, c b){
    return a.x < b.x;
}

bool comparey (c a, c b){
    return a.y < b.y;
}

#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
int main() {
    ifstream fin("balancing.in");
    ofstream fout("balancing.out");
    int n, b;
    fin >> n >> b;
    c locsx[100], locsy[100];
    for (int i = 0; i < n; i++){
        fin >> locsx[i].x >> locsx[i].y;
        locsy[i] = locsx[i];
    }
    sort (locsx, locsx + n, comparex);
    sort (locsy, locsy + n, comparey);
    
    int c, d, max = 100000;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            int a[4];
            for (int i = 0; i < 4; i++){
                a[i] = 0;
            }
            c = locsx[i].x + 1;
            d = locsy[i].y + 1;
            for (int i = 0; i < n; i++){
                if (locsx[i].x > c){
                    if(locsx[i].y < d){
                        a[0]++;
                    }else{
                        a[1]++;
                    }
                }else{
                    if(locsx[i].y < d){
                        a[2]++;
                    }else{
                        a[3]++;
                    }
                }
            }
            sort(a, a + 4);
            if (a[3] < max){
                max = a[3];
            }
        }
    }
    fout << max << endl;
    return 0;
}

/*
 7 10
 5 3
 5 5
 9 7
 3 1
 7 7
 5 3
 9 1
*/


