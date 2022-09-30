//
//  main.cpp
//  learning
//
//  Created by Jerry Cheng on 12/14/19.
//  Copyright © 2019 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

struct cow{
    int weight;
    bool spotted;
};

bool compare (cow a, cow b){
    return a.weight < b.weight;
}

int main() {
    ifstream fin("learning.in");
    ofstream fout("learning.out");
    int n, a, b;
    fin >> n >> a >> b;
    cow c[50000];
    for (int i = 0; i < n; i++){
        string s;
        fin >> s;
        if (s == "S"){
            c[i].spotted = true;
        }else{
            c[i].spotted = false;
        }
        fin >> c[i].weight;
    }
    sort(c, c + n, compare);
    
    int start = 0, end = 0;
    for (int i = 0; i < n; i++){
        if (c[i].weight <= a){
            start = i;
        }
        if (c[i].weight >= b){
            end = i;
            break;
        }
    }
    
    // 1 2 3 4
    // 1 2 3 4 5 6 7 8 9
    // a   s   l   r   s + 1
    int midl, midr, total = 0;
    if ((c[start + 1].weight - c[start].weight) % 2 == 1){
        midl = (c[start].weight + c[start + 1].weight) / 2;
        midr = midl + 1;
    }else{
        midl = (c[start].weight + c[start + 1].weight) / 2 - 1;
        midr = midl + 2;
    }
    if (a < midl){
        if (c[start].spotted){
            total = total + midl - a + 1;
        }
        if (c[start + 1].spotted){
            total = total + c[start + 1].weight - midr;
        }
        if (midr - midl == 2){
            if (c[start].spotted || c[start + 1].spotted){
                total++;
            }
        }
    }else if (a > midl && a < midr){
        if (c[start + 1].spotted){
            total = total + c[start + 1].weight - midr;
        }
        if (c[start].spotted || c[start + 1].spotted){
            total++;
        }
    }else{
        if (c[start + 1].spotted){
            total = total + c[start + 1].weight - a;
        }
    }
    for (int i = start + 1; i < end - 1; i++){
        if ((c[i + 1].weight - c[i].weight) % 2 == 1){
            midl = (c[i].weight + c[i + 1].weight) / 2;
            midr = midl + 1;
        }else{
            midl = (c[i].weight + c[i + 1].weight) / 2 - 1;
            midr = midl + 2;
        }
        if (c[i].spotted){
            total = total + midl - c[i].weight + 1;
        }
        if (c[i + 1].spotted){
            total = total + c[i + 1].weight - midr;
        }
        if (midr - midl == 2){
            if (c[i].spotted || c[i + 1].spotted){
                total++;
            }
        }
    }
    if ((c[end].weight - c[end - 1].weight) % 2 == 1){
        midl = (c[end].weight + c[end - 1].weight) / 2;
        midr = midl + 1;
    }else{
        midl = (c[end].weight + c[end - 1].weight) / 2 - 1;
        midr = midl + 2;
    }
    if (b < midl){
        if (c[end - 1].spotted){
            total = total + b - c[end - 1].weight + 1;
        }
    }else if (b > midl && b < midr){
        if (c[end - 1].spotted){
            total = total + midl - c[end - 1].weight + 1;
        }
        if (c[end].spotted || c[end - 1].spotted){
            total++;
        }
    }else{
        if (c[end - 1].spotted){
            total = total + midl - c[end - 1].weight + 1;
        }
        if (midr - midl == 2){
            if (c[end].spotted || c[end - 1].spotted){
                total++;
            }
        }
        if (c[end].spotted){
            total = total + b - midr + 1;
        }
    }
    fout << total << endl;
    return 0;
}
// 1 2 3 4
// 1 2 3 4 5 6 7

/*
2 11 100
S 4
S 10
 
 2 1 100
 S 10
 S 15
 */




