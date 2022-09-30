//
//  main.cpp
//  decorate
//
//  Created by Jerry Cheng on 6/6/20.
//  Copyright © 2020 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


int n, m, all[50002], count1, count2;
bool works = true;
vector<int> a[50001];

void search(int last, int current){
    if (all[current] == 0){
        all[current] = all[last] * -1;
        if (all[current] > 0){
            count1++;
        }else{
            count2++;
        }
    }else{
        if (all[last] == all[current]){
            works = false;
        }
        return;
    }
    
    for (int i = 0; i < a[current].size(); i++){
        search(current, a[current][i]);
    }
}

int main() {
    ifstream fin("decorate.in");
    ofstream fout("decorate.out");
    fin >> n >> m;
    for (int i = 0; i < m; i++){
        int b, c;
        fin >> b >> c;
        a[b].push_back(c);
        a[c].push_back(b);
    }
    for (int i = 0; i <= n; i++){
        all[i] = 0;
    }
    
    all[n + 1] = 1;
    int total = 0;
    for (int i = 1; i <= n; i++){
        if (all[i] == 0){
            count1 = 0;
            count2 = 0;
            //cout << i << endl;
            search(n + 1, i);
            if (count1 > count2){
                total = total + count1;
            }else{
                total = total + count2;
            }
        }
    }
    if (works){
        fout << total << endl;
    }else{
        fout << -1 << endl;
    }
    return 0;
}
