//
//  main.cpp
//  sort
//
//  Created by Jerry Cheng on 9/5/20.
//  Copyright © 2020 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

struct num{
    int startpos;
    int input;
};

bool compare(num a, num b){
    if (a.input == b.input){
        return a.startpos < b.startpos;
    }
    return a.input < b.input;
}

int main() {
    ifstream fin("sort.in");
    ofstream fout("sort.out");
    int n;
    fin >> n;
    num a[100000];
    for (int i = 0; i< n; i++) {
        int x;
        fin >> x;
        a[i].input = x;
        a[i].startpos = i;
    }
    sort(a, a + n, compare);
    
    int ans = 0;
    for (int i = 0; i< n; i++) {
        ans = max(ans, a[i].startpos - i);
    }
    fout << ans + 1 << endl;
    return 0;
}
