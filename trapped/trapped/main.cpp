//
//  main.cpp
//  trapped
//
//  Created by Jerry Cheng on 10/5/19.
//  Copyright © 2019 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <algorithm>
struct bale{
    int pos, size;
};

bool compare(bale a, bale b){
    return a.pos < b.pos;
}
using namespace std;
int main() {
    ifstream fin("trapped.in");
    ofstream fout("trapped.out");
    int n;
    fin >> n;
    bale a[4000];
    for (int i = 0; i < n; i++){
        fin >> a[i].size >> a[i].pos;
    }
    sort (a, a + n, compare);
    
    int total = 0;
    for (int i = 0; i < n - 1; i++){
        int jl = i, jr = i + 1;
        long long distance = 0;
        bool out = true;
        while ((jl >= 0) && (jr < n)){
            distance = a[jr].pos - a[jl].pos;
            //cout << i << ' ' << jl << ' ' << jr << ' ' << distance << endl;
            if (distance > a[jl].size){
                jl--;
            }else if (distance > a[jr].size){
                jr++;
            }else{
                out = false;
                break;
            }
        }
        if (!out){
            total = total + a[i + 1].pos - a[i].pos;
            //cout << total << ' ' << out1 << endl;
        }
    }
    fout << total << endl;
    return 0;
}

/*
 5
 99 1
 1 4
 1 8
 1 15
 18 20
*/
