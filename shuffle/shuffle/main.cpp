//
//  main.cpp
//  shuffle
//
//  Created by Jerry Cheng on 1/30/21.
//  Copyright © 2021 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <set>
#include <fstream>
using namespace std;

int n, a[100001], b[100001];
void loop(int start, int pos){
    b[pos] = 2;
    if (pos != start){
        //cout << start << ' ' << pos << endl;
        loop(start, a[pos]);
    }
}

set<int> past;
void search(int pos){
    //cout << past.size() << endl;
    b[pos] = 1;
    past.insert(pos);
    //cout << b[a[pos]] << endl;
    if (past.count(a[pos])){
        b[pos] = 2;
        loop(pos, a[pos]);
    }else if(b[a[pos]] == 0){
        //cout << 'a' << a[pos] << endl;
        search(a[pos]);
    }
}

int main() {
    ifstream fin("shuffle.in");
    ofstream fout("shuffle.out");
    fin >> n;
    for (int i = 1; i <= n; i++){
        fin >> a[i];
    }
    for (int i = 0; i < 100001; i++){
        b[i] = 0;
    }
    for (int i = 1; i <= n; i++){
        if (b[i] == 0){
            past.clear();
            search(i);
            //cout << endl;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++){
        //cout << b[i] << ' ';
        if (b[i] == 2){
            ans++;
        }
    }
    //cout << endl;
    fout << ans << endl;
    return 0;
}
