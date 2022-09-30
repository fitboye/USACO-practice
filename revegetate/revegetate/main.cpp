//
//  main.cpp
//  revegetate
//
//  Created by Jerry Cheng on 10/4/19.
//  Copyright © 2019 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;
int main() {
    ifstream fin("revegetate.in");
    ofstream fout("revegetate.out");
    int n, m;
    fin >> n >> m;
    int a[2][150];
    for (int i = 0; i < m; i++){
        fin >> a[0][i] >> a[1][i];
    }
    
    
    int b[100], type[4];
    for (int i = 0; i < 100; i++){
        b[i] = -1;
    }
    b[0] = 1;
    for (int i = 1; i < n; i++){
        for (int j = 0; j < 4; j++){
            type[j] = 0;
        }
        
        for (int j = 0; j < m; j++){
            if (a[0][j] == i + 1){
                if (b[a[1][j] - 1] != -1){
                    cout << i << ' ' << j << ' ' << a[1][j] << endl;
                    type[b[a[1][j] - 1] - 1] = 1;
                }
            }
            if (a[1][j] == i + 1){
                if (b[a[0][j] - 1] != -1){
                    type[b[a[0][j] - 1] - 1] = 1;
                }
            }
        }
        
        for (int j = 0; j < 4; j++){
            //cout << i << ' ' << type[j] << endl;
            if (type[j] == 0){
                b[i] = j + 1;
                break;
            }
        }
    }
    for (int i = 0; i < n; i++){
        fout << b[i];
    }
    fout << endl;
    return 0;
}
