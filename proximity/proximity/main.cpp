//
//  main.cpp
//  proximity
//
//  Created by Jerry Cheng on 8/31/19.
//  Copyright © 2019 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream fin("proximity.in");
    ofstream fout("proximity.out");
    int n, k, a[50000], ids[1000000];
    fin >> n >> k;
    for (int i = 0; i < n; i++){
        fin >> a[i];
    }
    for (int i = 0; i < 1000000; i++){
        ids[i] = 0;
    }
    
    int max = -1;
    for (int i = 0; i < n; i++){
        ids[a[i] - 1]++;
        if (i > k){
            //cout << 'a' << a[i - k - 1] << endl;
            ids[a[i - k - 1] - 1]--;
        }
        for (int j = 0; j < 7; j++){
            cout << ids[j] << endl;
        }
        cout << endl;
        if (ids[a[i] - 1] >= 2){
            if (a[i] > max){
                max = a[i];
            }
        }
    }
    fout << max << endl;
    return 0;
}
