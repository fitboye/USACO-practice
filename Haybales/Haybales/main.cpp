//
//  main.cpp
//  Haybales
//
//  Created by Jerry Cheng on 7/8/18.
//  Copyright © 2018 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
int main(){
    ifstream fin("haybales.in");
    ofstream fout("haybales.out");
    int n, q;
    fin >> n >> q;
    int a[100000], b[100000], c[100000];
    for (int i = 0; i < n; i++){
        fin >> a[i];
    }
    for (int i = 0; i < q; i++){
        fin >> b[i] >> c[i];
    }
    sort(a, a + n);
    
    for (int i = 0; i < q; i++){
        int l = -1, r = n;
        while(r - l > 1){
            int m = (l + r)/2;
            if (a[m] < b[i]){
                l = m;
            }else{
                r = m;
            }
        }
        int x = -1, y = n;
        while(y - x > 1){
            int m = (x + y)/2;
            if (a[m] <= c[i]){
                x = m;
            }else{
                y = m;
            }
        }
        fout << x - r + 1 << endl;
    }
    return 0;
}
