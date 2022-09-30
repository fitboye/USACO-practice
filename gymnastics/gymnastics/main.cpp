//
//  main.cpp
//  gymnastics
//
//  Created by Jerry Cheng on 12/15/19.
//  Copyright © 2019 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;
int main() {
    ifstream fin("gymnastics.in");
    ofstream fout("gymnastics.out");
    int k, n, a[10][100];
    fin >> k >> n;
    for (int i = 0; i < k; i++){
        for (int j = 0; j < n; j++){
            fin >> a[i][j];
        }
    }
    
    int total = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (i != j){
                int ipos = 0, jpos = 0;
                bool ifirst, works = true;
                for (int l = 0; l < k; l++){
                    for (int m = 0; m < n; m++){
                        if (a[l][m] == i){
                            ipos = m;
                        }
                        if (a[l][m] == j){
                            jpos = m;
                        }
                    }
                    if (l == 0){
                        if (ipos < jpos){
                            ifirst = true;
                        }else{
                            ifirst = false;
                        }
                    }else{
                        cout << ipos << ' ' << jpos << ' ' << ifirst << endl;
                        if ((ipos < jpos) && !ifirst){
                            cout << 'a' << endl;
                            works = false;
                            break;
                        }else if ((ipos > jpos) && ifirst){
                            cout << 'b' << endl;
                            works = false;
                            break;
                        }
                    }
                }
                if (works){
                    //cout << i << ' ' << j << endl;
                    total++;
                }
            }
        }
    }
    fout << total / 2 << endl;
    return 0;
}

/*
 3 4
 1 2 3 4
 1 2 3 4
 1 2 4 3
*/
