//
//  main.cpp
//  citystate
//
//  Created by Jerry Cheng on 8/18/18.
//  Copyright © 2018 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;
string a[200000], b[200000];
int main() {
    ifstream fin ("citystate.in");
    ofstream fout ("citystate.out");
    int n, c[456976], total = 0;
    for(int i = 0; i < 456976; i++){
        c[i] = 0;
    }
    fin >> n;
    for (int i = 0; i < n; i++){
        fin >> a[i] >> b[i];
    }
    
    for (int i = 0; i < n; i++){
        c[int(a[i][0] - 'A') * 26 * 26 * 26 + int(a[i][1] - 'A') * 26 * 26 + int(b[i][0] - 'A') * 26 + int(b[i][1] - 'A')]++;
    }
    
    for (int i = 0; i < n; i++){
        if (int(b[i][0] - 'A') * 26 + int(b[i][1] - 'A') == int(a[i][0] - 'A') * 26 + int(a[i][1] - 'A')) continue;
        total = total + c[int(b[i][0] - 'A') * 26 * 26 * 26 + int(b[i][1] - 'A') * 26 * 26 + int(a[i][0] - 'A') * 26 + int(a[i][1] - 'A')];
    }
    fout << total / 2 << endl;
    return 0;
}
