//
//  main.cpp
//  greetings
//
//  Created by Jerry Cheng on 8/24/19.
//  Copyright © 2019 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;
int main() {
    ifstream fin("greetings.in");
    ofstream fout("greetings.out");
    int b, e;
    fin >> b >> e;
    int a[50000], c[50000];
    char x[50000], y[50000];
    for (int i = 0; i < b; i++){
        fin >> a[i] >> x[i];
    }
    for (int i = 0; i < e; i++){
        fin >> c[i] >> y[i];
    }
    
    int n, tb = 0, te = 0;
    for (int i = 0; i < b; i++){
        tb = tb + a[i];
    }
    for (int i = 0; i < e; i++){
        te = te + c[i];
    }
    if (tb > te){
        n = tb;
    }else{
        n = te;
    }
    
    int bloc = 0, eloc = 0, m = 0, b0 = b, e0 = e, apart = 0;
    b = 0;
    e = 0;
    for (int i = 0; i < n; i++){
        if (b < b0){
            if (x[b] == 'L'){
                bloc--;
            }else{
                bloc++;
            }
            a[b] = a[b] - 1;
            if (a[b] == 0){
                b++;
            }
        }
        
        if (e < e0){
            if (y[e] == 'L'){
                eloc--;
            }else{
                eloc++;
            }
            c[e] = c[e] - 1;
            if (c[e] == 0){
                e++;
            }
        }
        
        //cout << bloc << ' ' << eloc << endl;
        if ((bloc == eloc) && (apart == 1)){
            m++;
            apart = 0;
            //cout << 'a' << endl;
        }else if (bloc != eloc){
            apart = 1;
        }
    }
    fout << m << endl;
    return 0;
}
