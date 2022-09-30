//
//  main.cpp
//  relay
//
//  Created by Jerry Cheng on 9/30/19.
//  Copyright © 2019 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;
int main() {
    ifstream fin("relay.in");
    ofstream fout("relay.out");
    int n;
    fin >> n;
    int a[1000];
    for (int i = 0; i < n; i++){
        fin >> a[i];
    }
    
    int t = 0;
    for (int i = 0; i < n; i++){
        int current = i + 1, j = 0;
        while ((a[current - 1] != 0) && (j < n)){
            current = a[current - 1];
            j++;
        }
        //cout << current << endl;
        if (a[current - 1] == 0){
            t++;
        }
    }
    fout << t << endl;
    return 0;
}
