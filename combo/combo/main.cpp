/*
 ID: jerry.c1
 TASK: wormhole
 LANG: C++
 */
//  main.cpp
//  combo
//
//  Created by Jerry Cheng on 9/15/18.
//  Copyright © 2018 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;

int n;
int difference(int a, int b){
    if ((a <= 2) && (b >= n - a)){
        return a - b + n;
    }else if ((b <= 2) && (a >= n - b)){
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
    int a[3], b[3], x;
    fin >> n;
    for (int i = 0; i < 3; i++){
        fin >> a[i];
    }
    for (int i = 0; i < 3; i++){
        fin >> b[i];
    }
    if (((difference(a[0], b[0]) <= 4) && (difference(a[1], b[1]) <= 4)) && (difference(a[2], b[2]) <= 4)){
        if (((a[0] == a[1]) && (b[0] == b[1])) && (b[0] == b[2])){
            x = 250 - (5 - difference(a[0], b[0]));
        }else if ((a[0] == a[1]) && (b[0] == b[1])){
            x = 250 - (5 - difference(a[0], b[0])) * (5 - difference(a[1], b[1]));
        }else if ((a[1] == a[2]) && (b[1] == b[2])){
            x = 250 - (5 - difference(a[1], b[1])) * (5 - difference(a[2], b[2]));
        }else if ((a[0] == a[2]) && (b[0] == b[2])){
            x = 250 - (5 - difference(a[0], b[0])) * (5 - difference(a[2], b[2]));
        }else{
            x = 250 - (5 - difference(a[0], b[0])) * (5 - difference(a[1], b[1])) * (5 - difference(a[2], b[2]));
        }
        fout << x << endl;
    }else{
        fout << 250 << endl;
    }
    return 0;
}


/*
10
9 9 9
1 1 1
*/
