/*
 ID: jerr.c1
 TASK: milk3
 LANG: C++
 */
//  main.cpp
//  milk3
//
//  Created by Jerry Cheng on 3/7/20.
//  Copyright © 2020 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <set>
using namespace std;

int a, b, c, used[3][10000], total = 0;
void search(int a1, int b1, int c1){
    bool u = false;
    for (int i = 0; i < total; i++){
        if (used[0][i] == a1){
            if (used[1][i] == b1){
                if (used[2][i] == c1){
                    u = true;
                }
            }
        }
    }
    if (!u){
        used[0][total] = a1;
        used[1][total] = b1;
        used[2][total] = c1;
        total++;
    }else{
        return;
    }
    
    //a to b
    if (a1 + b1 > b){
        search(a1 - (b - b1), b, c1);
    }else{
        search(0, b1 + a1, c1);
    }
    //a to c
    if (a1 + c1 > c){
        search(a1 - (c - c1), b1, c);
    }else{
        search(0, b1, a1 + c1);
    }
    
    //b to c
    if (b1 + c1 > c){
        search(a1, b1 - (c - c1), c);
    }else{
        search(a1, 0, c1 + b1);
    }
    //b to a
    if (b1 + a1 > a){
        search(a, b1 - (a - a1), c1);
    }else{
        search(a1 + b1, 0, c1);
    }
    
    //c to b
    if (b1 + c1 > b){
        search(a1, b, c1 - (b - b1));
    }else{
        search(a1, b1 + c1, 0);
    }
    //c to a
    if (a1 + c1 > a){
        search(a, b1, c1 - (a - a1));
    }else{
        search(a1 + c1, b1, 0);
    }
}

int main() {
    ifstream fin("milk3.in");
    ofstream fout("milk3.out");
    fin >> a >> b >> c;
    search(0, 0, c);
    
    set<int> all;
    int length = 0;
    for (int i = 0; i < total; i++){
        if (used[0][i] == 0){
            all.insert(used[2][i]);
        }
    }
    int j = 0;
    for (int i : all){
        if (j != 0){
            fout << ' ';
        }
        j++;
        fout << i;
    }
    fout << endl;
    return 0;
}
