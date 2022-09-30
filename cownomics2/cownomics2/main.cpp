//
//  main.cpp
//  cownomics2
//
//  Created by Jerry Cheng on 9/1/18.
//  Copyright © 2018 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;
int main() {
    int n, m, total = 0;
    char a[1000][50];
    bool flag = true;
    cin >> n >> m;
    for (int i = 0; i < n * 2; i++){
        for (int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }
    
    for (int i = 0; i < m; i++){
        for (int j = i + 1; j < m; j++){
            for (int k = j + 1; k < m; k++){
                for (int l = 0; l < n; l++){
                    for (int h = n; h < n * 2; h++){
                        if (a[l][i] == a[h][i]){
                            if (a[l][j] == a[h][j]){
                                if (a[l][k] == a[h][k]){
                                    flag = false;
                                    cout << a[l][i] << ' ' << a[l][j] << ' ' << a[l][k] << ' ' << endl;
                                    cout << a[h][i] << ' ' << a[h][j] << ' ' << a[h][k] << endl << endl;
                                    h = n * 2;
                                    l = n;
                                }
                            }
                        }
                    }
                }
                cout << flag << endl;
                if (flag){
                    total++;
                }
                flag = true;
            }
        }
    }
    
    cout << total << endl;
    return 0;
}
