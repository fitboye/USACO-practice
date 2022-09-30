/*
 ID: jerry.c1
 TASK: combo
 LANG: C++
 */
//  main.cpp
//  combo2
//
//  Created by Jerry Cheng on 9/15/18.
//  Copyright © 2018 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;

int n;
int difference(int a, int b){
    if ((a <= 2) && (b >= a - 2 + n)){
        return a - b + n;
    }else if ((b <= 2) && (a >= b - 2 + n)){
        return b - a + n;
    }else{
        if (a > b){
            return a - b;
        }else
            return b - a;
    }
}

int main() {
    ifstream fin("combo.in");
    ofstream fout("combo.out");
    int a[3], b[3], total = 0;
    fin >> n;
    for (int i = 0; i < 3; i++){
        fin >> a[i];
    }
    for (int i = 0; i < 3; i++){
        fin >> b[i];
    }
    
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            for (int k = 1; k <= n; k++){
                if (((difference(a[0], i) <= 2) && (difference(a[1], j) <= 2)) && (difference(a[2], k) <= 2)){
                    total++;
                }else if (((difference(b[0], i) <= 2) && (difference(b[1], j) <= 2)) && (difference(b[2], k) <= 2)){
                    total++;
                }
            }
        }
    }
    
    //cout << difference(2, 1) << endl;
    fout << total << endl;
    return 0;
}



/*
50
1 2 3
5 6 7

3
1 1 1
1 1 1
*/
