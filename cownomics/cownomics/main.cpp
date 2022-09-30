//
//  main.cpp
//  cownomics
//
//  Created by Jerry Cheng on 4/3/18.
//  Copyright © 2018 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;
int main() {
    ifstream fin("cownomics.in");
    ofstream fout("cownomics.out");
    int n, m, x = 0, c[100], flag = 0, f = 0, A, C, T, G, A1, C1, T1, G1, all[4], all0[4];
    char a[100][100], b[100][100];
    fin >> n >> m;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            fin >> a[i][j];
        }
    }
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            fin >> b[i][j];
        }
    }
    
    for (int i = 0; i < m; i++){
        c[i] = 0;
    }
    
    for (int i = 0; i < 3; i++){
        
    }
    
    for (int i = 0; i < m; i++){
        for (int j = 0; j < 4; j++){
            all[j] = 0;
        }
        for (int j = 0; j < n; j++){
            if (a[j][i] == 'A'){
                all[0] = all[0] + 1;
            }else if (a[j][i] == 'C'){
                all[1] = all[1] + 1;
            }else if (a[j][i] == 'G'){
                all[2] = all[2] + 1;
            }else if (a[j][i] == 'T'){
                all[3] = all[3] + 1;
            }
        }
        
        for (int j = 0; j < 4; j++){
            all0[j] = 0;
        }
        for (int j = 0; j < n; j++){
            if (b[j][i] == 'A'){
                all0[0] = all0[0] + 1;
            }else if (b[j][i] == 'C'){
                all0[1] = all0[1] + 1;
            }else if (b[j][i] == 'G'){
                all0[2] = all0[2] + 1;
            }else if (b[j][i] == 'T'){
                all0[3] = all0[3] + 1;
            }
        }
        
        /*
        for (int j = 0; j < 4; j++){
            cout << all[j] << ' ' << all0[j] << endl;
        }
        cout << endl;
        */
        
        for (int j = 0; j < 4; j++){
            if ((all[j] > 0) && (all0[j] > 0)){
                flag = 1;
            }
        }
        if (flag == 0){
            x = x + 1;
        }
        flag = 0;
    }
    
    fout << x << endl;
    return 0;
}
