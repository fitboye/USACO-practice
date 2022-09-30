//
//  main.cpp
//  speeding
//
//  Created by Jerry Cheng on 3/31/18.
//  Copyright © 2018 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;
int main() {
    ifstream fin ("speeding.in");
    ofstream fout ("speeding.out");
    int a[100], b[100], c[100], d[100], n, m, e[100], f[100], last, x, largest = -1;
    fin >> n >> m;
    for (int i = 0; i < n; i = i + 1){
        fin >> a[i] >> b[i];
    }
    
    for (int i = 0; i < m; i = i + 1){
        fin >> c[i] >> d[i];
    }
    
    for (int i = 0; i < 100; i = i + 1){
        e[i] = 0;
        f[i] = 0;
    }

    
    last = 0;
    for (int i = 0; i < n; i = i + 1){
        for (int j = last; j < last + a[i]; j = j + 1){
            e[j] = b[i];
            //cout << e[j] << endl;
        }
        last = last + a[i];
    }
    //cout << endl << endl;
    
    last = 0;
    for (int i = 0; i < m; i = i + 1){
        for (int j = last; j < last + c[i]; j = j + 1){
            f[j] = d[i];
            //cout << f[j] << endl;
        }
        last = last + c[i];
    }
    
    //cout << endl << endl;
    for (int i = 0; i < 100; i = i + 1){
        //cout << e[i] << ' ' << f[i] << endl;
    }
    
    
    for (int i = 0; i < 100; i = i + 1){
        if (e[i] < f[i]){
            x = f[i] - e[i];
            if (x > largest){
                largest = x;
                //cout << largest << endl;
            }
        }
    }
    
    if (largest == -1){
        fout << 0 << endl;
    }else{
        fout << largest << endl;
    }
    return 0;
}






