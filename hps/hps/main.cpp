//
//  main.cpp
//  hps
//
//  Created by Jerry Cheng on 06/01/2018.
//  Copyright © 2018 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;
int main() {
    ifstream fin("hps.in");
    ofstream fout("hps.out");
    int n, a[100], b[100], x = 0, y = 0;
    fin >> n;
    for (int i = 0; i < n; i = i + 1){
        fin >> a[i] >> b[i];
    }
    
    // 1, 2, 3
    x = 0;
    for (int i = 0; i < n; i = i + 1){
        if ((a[i] == 1) && (b[i] == 2)){
            x = x + 1;
        }else if ((a[i] == 2) && (b[i] == 3)){
            x = x + 1;
        }else if ((a[i] == 3) && (b[i] == 1)){
            x = x + 1;
        }
    }
    if (x > y){
        y = x;
    }
    
    // 1, 3, 2
    x = 0;
    for (int i = 0; i < n; i = i + 1){
        if ((a[i] == 1) && (b[i] == 3)){
            x = x + 1;
        }else if ((a[i] == 3) && (b[i] == 2)){
            x = x + 1;
        }else if ((a[i] == 2) && (b[i] == 1)){
            x = x + 1;
        }
    }
    if (x > y){
        y = x;
    }
    
    // 2, 1, 3
    x = 0;
    for (int i = 0; i < n; i = i + 1){
        if ((a[i] == 2) && (b[i] == 1)){
            x = x + 1;
        }else if ((a[i] == 1) && (b[i] == 3)){
            x = x + 1;
        }else if ((a[i] == 3) && (b[i] == 2)){
            x = x + 1;
        }
    }
    if (x > y){
        y = x;
    }
    
    //2, 3, 1
    x = 0;
    for (int i = 0; i < n; i = i + 1){
        if ((a[i] == 2) && (b[i] == 3)){
            x = x + 1;
        }else if ((a[i] == 3) && (b[i] == 1)){
            x = x + 1;
        }else if ((a[i] == 1) && (b[i] == 2)){
            x = x + 1;
        }
    }
    if (x > y){
        y = x;
    }
    
    // 3, 2, 1
    x = 0;
    for (int i = 0; i < n; i = i + 1){
        if ((a[i] == 3) && (b[i] == 2)){
            x = x + 1;
        }else if ((a[i] == 2) && (b[i] == 1)){
            x = x + 1;
        }else if ((a[i] == 1) && (b[i] == 3)){
            x = x + 1;
        }
    }
    if (x > y){
        y = x;
    }
    
    // 3, 1, 2
    x = 0;
    for (int i = 0; i < n; i = i + 1){
        if ((a[i] == 3) && (b[i] == 1)){
            x = x + 1;
        }else if ((a[i] == 1) && (b[i] == 2)){
            x = x + 1;
        }else if ((a[i] == 2) && (b[i] == 3)){
            x = x + 1;
        }
    }
    if (x > y){
        y = x;
    }
    fout << y << endl;
    return 0;
}
