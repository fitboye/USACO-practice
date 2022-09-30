//
//  main.cpp
//  taming2
//
//  Created by Jerry Cheng on 3/3/18.
//  Copyright © 2018 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;
int main() {
    ifstream fin ("taming.in");
    ofstream fout ("taming.out");
    int n, a[100], max = 0, min = 0, b, flag = 0, c[100];
    fin >> n;
    for (int i = 0; i < n; i = i + 1){
        fin >> a[i];
    }
    
    for (int i = 0; i < n; i = i + 1){
        c[i] = a[i];
    }
    
    a[0] = 0;
    for (int i = 0; i < n; i = i + 1){
        if (a[i] > 0){
            b = a[i];
            for (int j = i - 1; j > i - a[i] - 1; j = j - 1){
                b = b - 1;
                a[j] = b;
            }
        }
    }
    
    /*
    for (int i = 0; i < n; i = i + 1){
        cout << a[i] << endl;
    }
     */
    
    for (int i = 0; i < n; i = i + 1){
        if (a[i] == 0){
            min = min + 1;
            max = max + 1;
        }else if (a[i] == -1){
            max = max + 1;
        }
    }
    
    for (int i = 0; i < n; i = i + 1){
        if (c[i] != -1){
            if (c[i] != a[i]){
                flag = 1;
            }
        }
    }
    
    if (flag == 1){
        fout << -1 << endl;
    }else{
       fout << min << ' ' << max << endl;
    }
    return 0;
}




