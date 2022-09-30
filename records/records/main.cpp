//
//  main.cpp
//  records
//
//  Created by Jerry Cheng on 4/27/19.
//  Copyright © 2019 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int main() {
    ifstream fin("records.in");
    ofstream fout("records.out");
    int n;
    string a[3][1000], b[3];
    fin >> n;
    for (int i = 0; i < n; i++){
        fin >> b[0] >> b[1] >> b[2];
        sort (b, b + 3);
        a[0][i] = b[0];
        a[1][i] = b[1];
        a[2][i] = b[2];
    }
    
    int x = 0, max = -1;
    for (int i = 0; i < n; i++){
        x = 0;
        for (int j = 0; j < n; j++){
            if (((a[0][i] == a[0][j]) && (a[1][i] == a[1][j])) && (a[2][i] == a[2][j])){
                x++;
            }
        }
        if (x > max){
            max = x;
        }
    }
    fout << max << endl;
    return 0;
}
