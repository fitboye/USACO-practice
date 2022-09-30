//
//  main.cpp
//  Mountains
//
//  Created by Jerry Cheng on 1/19/19.
//  Copyright © 2019 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

struct mt{
    int a, b;
};

bool compare (mt x, mt y){
    if (x.a == y.a){
        return x.b > y.b;
    }else{
        return x.a < y.a;
    }
}

int main() {
    ifstream fin("mountains.in");
    ofstream fout("mountains.out");
    int n, x, y;
    mt m[100000];
    fin >> n;
    for (int i = 0; i < n; i++){
        fin >> x >> y;
        m[i].a = x - y;
        m[i].b = x + y;
    }
    sort(m, m + n, compare);
    
    int biggest = m[0].b, total = 1;
    for (int i = 1; i < n; i++){
        if (m[i].b > biggest){
            biggest = m[i].b;
            total++;
        }
    }
    
    fout << total << endl;
    return 0;
}
