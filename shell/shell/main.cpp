//
//  main.cpp
//  shell
//
//  Created by Jerry Cheng on 8/31/19.
//  Copyright © 2019 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;
int main() {
    ifstream fin("shell.in");
    ofstream fout("shell.out");
    int a[100000], b[100000], g[100000], n, c[100000], counts[100000];
    fin >> n;
    for (int i = 0; i < n; i++){
        fin >> a[i] >> b[i] >> g[i];
        c[i] = i;
        counts[i] = 0;
    }
    for (int i = 0; i < n; i++){
        int swap = c[a[i]];
        c[a[i]] = c[b[i]];
        c[b[i]] = swap;
        counts[c[g[i]] - 1]++;
    }
    
    int max = 0;
    for (int i = 0; i < n; i++){
        cout << counts[i] << endl;
        if (counts[i] > max){
            max = counts[i];
        }
    }
    fout << max << endl;
    return 0;
}
