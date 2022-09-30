//
//  main.cpp
//  moocryption
//
//  Created by Jerry Cheng on 12/8/18.
//  Copyright © 2018 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream fin("moocrypt.in");
    ofstream fout("moocrypt.out");
    int n, m;
    char c[50][50];
    fin >> n >> m;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            fin >> c[i][j];
        }
    }
    
    int max = -1;
    for (int k = 0; k < 26; k++){
        for (int l = 0; l < 26; l++){
            if ((l != k) && ((k + 'A' != 'M') && (l + 'A' != 'O'))){
                //cout << char(k + 'A') << ' ' << char(l + 'A') << endl;
                int count = 0;
                for (int i = 0; i < n; i++){
                    for (int j = 0; j < m; j++){
                        if (c[i][j] == k + 'A'){
                            if ((i < n - 2) && ((c[i + 1][j] == l + 'A') && (c[i + 2][j] == l + 'A'))){
                                //cout << i << ' ' << j << 'a' << endl;
                                count++;
                            }
                            if ((j < m - 2) && ((c[i][j + 1] == l + 'A') && (c[i][j + 2] == l + 'A'))){
                                //cout << i << ' ' << j << 'b' << endl;
                                count++;
                            }
                            if ((i >= 2) && ((c[i - 1][j] == l + 'A') && (c[i - 2][j] == l + 'A'))){
                                //cout << i << ' ' << j << 'c' << endl;
                                count ++;
                            }
                            if ((j >= 2) && ((c[i][j - 1] == l + 'A') && (c[i][j - 2] == l + 'A'))){
                                //cout << i << ' ' << j << 'd' << endl;
                                count ++;
                            }
                            if (((i < n - 2) && (j < m - 2)) && ((c[i + 1][j + 1] == l + 'A') && (c[i + 2][j + 2] == l + 'A'))){
                                //cout << i << ' ' << j << 'e' << endl;
                                count ++;
                            }
                            if (((i < n - 2) && (j >= 2)) && ((c[i + 1][j - 1] == l + 'A') && (c[i + 2][j - 2] == l + 'A'))){
                                //cout << i << ' ' << j << 'f' << endl;
                                count++;
                            }
                            if (((i >= 2) && (j >= 2)) && ((c[i - 1][j - 1] == l + 'A') && (c[i - 2][j - 2] == l + 'A'))){
                                //cout << i << ' ' << j << 'g' << endl;
                                count++;
                            }
                            if (((i >= 2) && (j < m - 2)) && ((c[i - 1][j + 1] == l + 'A') && (c[i - 2][j + 2] == l + 'A'))){
                                //cout << i << ' ' << j << 'h' << endl;
                                count++;
                            }
                        }
                    }
                }
                if (count > max){
                    max = count;
                }
            }
        }
    }
    fout << max << endl;
    return 0;
}
