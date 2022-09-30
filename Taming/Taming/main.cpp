//
//  main.cpp
//  hoofball
//
//  Created by Jerry Cheng on 2/24/18.
//  Copyright © 2018 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;
int main() {
    ifstream fin ("taming.in");
    ofstream fout ("taming.out");
    int n, a[100], max = 1, min = 1, b = 1000, flag = 0, flag1 = 0, c[100];
    fin >> n;
    for (int i = 0; i < n; i = i + 1){
        fin >> a[i];
    }
    
    for (int i = 0; i < 100; i = i + 1){
        c[i] = 0;
    }
    
    for (int i = 1; i < n; i = i + 1){
        if (a[i] == 0){
            max = max + 1;
            min = min + 1;
        }
    }
    
    
    for (int i = 0; i < n; i = i + 1){
        if ((b == 1000) && (a[i] != -1)){
            b = i;
            flag = 1;
        }
        if (flag == 1){
            if ((a[i + 1] == -1) && (a[i] > 0)){
                b = i;
            }
            if ((a[i - 1] == -1) && (a[i] > 0)){
                b = i;
                if ((a[i] < a[b]) || (i == n - 1)){
                    if (a[i - a[i]] == -1){
                        min = min + 1;
                    }else if (a[i - a[i]] > 0){
                        flag1 = 1;
                    }
                }
            }
        }
    }
    
    
    for (int i = 0; i < n; i = i + 1){
        if (a[i] > -1){
            c[i] = 1;
            if (a[i] > 0){
                for (int j = i; j >= i - a[i]; j = j - 1){
                    c[j] = 1;
                }
            }
        }
    }
    
    max = min;
    for (int i = 1; i < n; i = i + 1){
        if (c[i] == 0){
            max = max + 1;
        }
    }
    
    if ((a[0] > 0) || (flag1 == 1)){
        fout << -1 << endl;
    }else{
        fout << min << ' ' << max << endl;
    }
    return 0;
}
