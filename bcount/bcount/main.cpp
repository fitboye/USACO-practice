//
//  main.cpp
//  bcount
//
//  Created by Jerry Cheng on 8/11/18.
//  Copyright © 2018 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;
int main() {
    ifstream fin("bcount.in");
    ofstream fout("bcount.out");
    int n, q, a[100000], b[100000], c[100000], all1[100001], all2[100001], all3[100001];
    fin >> n >> q;
    for (int i = 0; i < n; i++){
        fin >> a[i];
    }
    for (int i = 0; i < q; i++){
        fin >> b[i] >> c[i];
    }
    
    all1[0] = 0;
    all2[0] = 0;
    all3[0] = 0;
    
    for (int i = 0; i < n; i++){
        if (a[i] == 1){
            all1[i + 1] = all1[i]+ 1;
            all2[i + 1] = all2[i];
            all3[i + 1] = all3[i];
        }else if (a[i] == 2){
            all1[i + 1] = all1[i];
            all2[i + 1] = all2[i]+ 1;
            all3[i + 1] = all3[i];
        }else{
            all1[i + 1] = all1[i];
            all2[i + 1] = all2[i];
            all3[i + 1] = all3[i]+ 1;
        }
    }
    
    /*
    for (int i = 0; i < n + 1; i++){
        cout << all1[i] << ' ' << all2[i] << ' ' << all3[i] << endl;
    }
    cout << endl;
     */
    
    for (int i = 0; i < q; i++){
        fout << all1[c[i]] - all1[b[i] - 1] << ' ';
        fout << all2[c[i]] - all2[b[i] - 1] << ' ';
        fout << all3[c[i]] - all3[b[i] - 1] << endl;
    }
    return 0;
}





