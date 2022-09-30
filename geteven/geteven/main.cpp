//
//  main.cpp
//  geteven
//
//  Created by Jerry Cheng on 1/16/21.
//  Copyright © 2021 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <map>
using namespace std;

int ans = 0, p[7];
int a[2][7];
void search(int parity, int d){
    if (d == 7){
        if ((p[0]+p[1]+p[2]*2+p[3]+p[1])*(p[4]+p[5]+p[1]+p[2])*(p[6]+p[5]+p[5]) % 2 == 0){
            int x = 1;
            for (int i = 0; i < 7; i++){
                //cout << a[p[i]][i] << endl;
                x = x * a[p[i]][i];
            }
            ans = ans + x;
        }
        return;
    }
    
    p[d] = 0;
    search(0, d + 1);
    p[d] = 1;
    search(1, d + 1);
}

int main() {
    ifstream fin("geteven.in");
    ofstream fout("geteven.out");
    int n;
    map<char, int> b;
    b['B'] = 0;
    b['E'] = 1;
    b['S'] = 2;
    b['I'] = 3;
    b['G'] = 4;
    b['O'] = 5;
    b['M'] = 6;
    for (int i = 0; i < 7; i++){
        a[0][i] = 0;
        a[1][i] = 0;
    }
    
    fin >> n;
    for (int i = 0; i < n; i++){
        char x;
        int y;
        fin >> x >> y;
        if (y % 2 == 0){
            a[0][b[x]]++;
        }else{
            a[1][b[x]]++;
        }
    }
    
    p[0] = 0;
    search(0, 1);
    p[0] = 1;
    search(1, 1);
    fout << ans << endl;
    return 0;
}
