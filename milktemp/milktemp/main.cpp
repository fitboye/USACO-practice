//
//  main.cpp
//  milktemp
//
//  Created by Jerry Cheng on 6/15/19.
//  Copyright © 2019 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
int main() {
    ifstream fin("milktemp.in");
    ofstream fout("milktemp.out");
    int n, x, y, z;
    int cold[20000], hot[20000];
    fin >> n >> x >> y >> z;
    for (int i = 0; i < n; i++){
        fin >> cold[i] >> hot[i];
        hot[i] = hot[i] + 1;
    }
    sort(cold, cold + n);
    sort(hot, hot + n);
    
    int temp = -1, nc = 0, nh = 0, milk = n * x, max = milk;
    while ((temp <= hot[n - 1]) && ((nc < n) && (nh < n))){
        if (cold[nc] < hot[nh]){
            temp = cold[nc];
            while (cold[nc] == temp){
                milk = milk - x + y;
                nc++;
            }
        }else{
            temp = hot[nh];
            while (hot[nh] == temp){
                milk = milk - y + z;
                nh++;
            }
        }
        if (milk > max){
            max = milk;
        }
    }
    fout << max << endl;
    return 0;
}

/*
 4 7 9 6
 5 8
 3 7
 13 20
 7 10
*/
