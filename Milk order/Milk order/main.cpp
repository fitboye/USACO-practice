//
//  main.cpp
//  Milk order
//
//  Created by Jerry Cheng on 4/21/18.
//  Copyright © 2018 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;
int main() {
    ifstream fin("milkorder.in");
    ofstream fout("milkorder.out");
    int m, n, k, a[100], b[100], c[100], x[100], d, mnumber = 0, flag, y = 0, flag2 = 0, z[100],e = 0;
    fin >> n >> m >> k;
    for (int i = 0; i < m; i ++){
        fin >> a[i];
    }
    for (int i = 0; i < k; i ++){
        fin >> b[i] >> c[i];
    }
    
    for (int i = 0; i < n; i ++){
        x[i] = 0;
        z[i] = 0;
    }
    
    for (int i = 0; i < n; i ++){
        for (int j = 0; j < k; j ++){
            if (i == c[j] - 1){
                z[i] = b[j];
            }
        }
    }
    
    for (int i = 0; i < n; i ++){
        if (z[i] == 1){
            flag2 = 1;
            y = i + 1;
        }
    }
    
    if (flag2 == 0){
        for (int i = 0; i < n; i ++){
            d = 0;
            flag = 0;
            mnumber = 0;
            for (int j = 0; j < n; j ++){
                x[j] = z[j];
            }
            if (x[i] == 0){
                x[i] = 1;
                for (int j = 0; j < n; j++){
                    if (x[j] == 0){
                        if (j > 0){
                            for (int l = 0; l < n; l = l + 1){
                                if (a[mnumber] == x[l]){
                                    mnumber++;
                                    for (int o = l; o < n; o++){
                                        if (x[o] == 0){
                                            e = o;
                                            o = n;
                                        }
                                    }
                                    j = e;
                                    cout << mnumber << ' ' << j << endl;
                                }
                            }
                        }
                        if ((mnumber < m) && (x[j] == 0)){
                            x[j] = a[mnumber];
                        }
                        mnumber++;
                    }
                }
                
                
                for (int j = 0; j < n; j++){
                    cout << x[j] << endl;
                }
                cout << endl;
                
                
                for (int j = 0; j < m; j++){
                    for (int l = 0; l < n; l++){
                        if (x[l] == a[j]){
                            d = l;
                            l = n;
                        }
                    }
                    for (int l = d; l >= 0; l = l - 1){
                        for (int o = j + 1; o < m; o++){
                            if (x[l] == a[o]){
                                flag = 1;
                            }
                        }
                    }
                }
                
                if (flag == 0){
                    y = i + 1;
                    i = n;
                }
            }
        }
    }
    
    fout << y << endl;
    return 0;
}
