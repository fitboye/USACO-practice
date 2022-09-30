//
//  main.cpp
//  crosswords
//
//  Created by Jerry Cheng on 12/8/18.
//  Copyright © 2018 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream fin("crosswords.in");
    ofstream fout("crosswords.out");
    int n, m;
    char c[50][50];
    fin >> n >> m;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            fin >> c[i][j];
        }
    }
    
    int count = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            bool x = false;
            if (c[i][j] == '.'){
                if ((i < n - 2) && ((i == 0) || (c[i - 1][j] == '#'))){
                    if ((c[i + 1][j] == '.') && (c[i + 2][j] == '.')){
                        x = true;
                    }
                }
                if ((j < m - 2) && ((j == 0) || (c[i][j - 1] == '#'))){
                    if ((c[i][j + 1] == '.') && (c[i][j + 2] == '.')){
                        x = true;
                    }
                }
            }
            if (x){
                c[i][j] = 'a';
                count++;
            }
        }
    }
    
    /*
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cout << c[i][j];
        }
        cout << endl;
    }
    */
    
    fout << count << endl;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (c[i][j] == 'a'){
                fout << i + 1 << ' ' << j + 1 << endl;
            }
        }
    }
    return 0;
}
