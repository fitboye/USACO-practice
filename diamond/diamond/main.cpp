//
//  main.cpp
//  diamond
//
//  Created by Jerry Cheng on 10/12/19.
//  Copyright © 2019 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
int main() {
    ifstream fin("diamond.in");
    ofstream fout("diamond.out");
    int n, k;
    fin >> n >> k;
    int a[100000];
    for (int i = 0; i < n; i++){
        fin >> a[i];
    }
    sort(a, a + n);
    
    int j = 0, max = 0;
    for (int i = 0; i < n - 1; i++){
        while ((j < n) && (a[j] - a[i] <= k)){
            j++;
        }
        if (j - i > max){
            max = j - i;
        }
    }
    fout << max << endl;
    return 0;
}
