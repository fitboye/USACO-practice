//
//  main.cpp
//  planting
//
//  Created by Jerry Cheng on 1/19/19.
//  Copyright © 2019 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream fin("planting.in");
    ofstream fout("planting.out");
    int n;
    int a, b, c[100000];
    fin >> n;
    for (int i = 0; i < n; i++){
        c[i] = 0;
    }
    for (int i = 0; i < n - 1; i++){
        fin >> a >> b;
        c[a - 1]++;
        c[b - 1]++;
    }
    
    int ans = 0;
    for (int i = 0; i < n; i++){
        if (c[i] + 1 > ans){
            ans = c[i] + 1;
        }
    }
    fout << ans << endl;
    return 0;
}
