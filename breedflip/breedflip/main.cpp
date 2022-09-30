//
//  main.cpp
//  breedflip
//
//  Created by Jerry Cheng on 4/25/20.
//  Copyright © 2020 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <fstream>
using  namespace std;
int main() {
    ifstream fin("breedflip.in");
    ofstream fout("breedflip.out");
    int n;
    string a, b;
    fin >> n;
    fin >> a >> b;
    int ans = 0;
    if (a[0] != b[0]){
        ans++;
    }
    for (int i = 1; i < n; i++){
        if (a[i] != b[i]){
            if (a[i - 1] == b[i - 1]){
                ans++;
            }
        }
    }
    fout << ans << endl;
    return 0;
}
