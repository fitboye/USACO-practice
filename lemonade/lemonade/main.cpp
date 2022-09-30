//
//  main.cpp
//  lemonade
//
//  Created by Jerry Cheng on 12/22/18.
//  Copyright © 2018 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

bool c(int a, int b){
    return a > b;
}

int main() {
    ifstream fin("lemonade.in");
    ofstream fout("lemonade.out");
    int n, a[100000];
    fin >> n;
    for (int i = 0; i < n; i++){
        fin >> a[i];
    }
    sort(a, a + n, c);
    
    int pos = n;
    for (int i = 0; i < n; i++){
        if (a[i] < i){
            pos = i;
            break;
        }
    }
    fout << pos << endl;
    return 0;
}
