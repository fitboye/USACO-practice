//
//  main.cpp
//  cowrace
//
//  Created by Jerry Cheng on 10/12/19.
//  Copyright © 2019 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;
int main() {
    ifstream fin("cowrace.in");
    ofstream fout("cowrace.out");
    int n, m;
    fin >> n >> m;
    int b[3][100000], e[3][100000];
    int time = 0;
    b[2][0] = 0;
    for (int i = 1; i <= n; i++){
        fin >> b[0][i] >> b[1][i];
        time = time + b[1][i];
        b[2][i] = time;
    }
    time = 0;
    e[2][0] = 0;
    for (int i = 1; i <= m; i++){
        fin >> e[0][i] >> e[1][i];
        time = time + e[1][i];
        e[2][i] = time;
    }
    
    int j = 1, k = 1, total = 0, last = 0;
    char first = 'a';
    long long bdist = 0, edist = 0;
    if (b[0][1] > e[0][1]){
        first = 'b';
    }else if (b[0][1] < e[0][1]){
        first = 'e';
    }
    while ((j <= n) || (k <= m)){
        if (e[2][j] > b[2][k]){
            bdist = bdist + b[0][k] * (b[2][k] - last);
            edist = edist + e[0][j] * (b[2][k] - last);
            last = b[2][k];
            k++;
        }else if (e[2][j] < b[2][k]){
            bdist = bdist + b[0][k] * (e[2][j] - last);
            edist = edist + e[0][j] * (e[2][j] - last);
            last = e[2][j];
            j++;
        }else{
            bdist = bdist + b[0][k] * (b[2][k] - last);
            edist = edist + e[0][j] * (e[2][j] - last);
            last = e[2][j];
            j++;
            k++;
        }
        if ((bdist > edist) && (first != 'b')){
            total++;
            first = 'b';
        }else if ((bdist < edist) && (first != 'e')){
            total++;
            first = 'e';
        }
        cout << first << ' ' << total << endl;
    }
    fout << total << endl;
    return 0;
}
