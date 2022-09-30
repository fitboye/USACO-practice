//
//  main.cpp
//  fairphoto
//
//  Created by Jerry Cheng on 9/5/20.
//  Copyright © 2020 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;

struct cow{
    int pos;
    int breed;
};

bool compare(cow a, cow b){
    return a.pos < b.pos;
}

int main() {
    ifstream fin("fairphoto.in");
    ofstream fout("fairphoto.out");
    int n;
    fin >> n;
    cow input[100000];
    for (int i = 0; i < n; i++){
        fin >> input[i].pos;
        char x;
        fin >> x;
        if (x == 'G'){
            input[i].breed = -1;
        }else{
            input[i].breed = 1;
        }
    }
    sort(input, input + n, compare);
    
    int ans = 0, b = -1, c = -1;
    for (int i = 0; i < n; i++){
        if (input[i].breed == -1 && b == -1){
            b = i;
        }
        if (input[i].breed == 1 && b != -1){
            if (input[i - 1].pos - input[b].pos > ans){
                ans = input[i - 1].pos - input[b].pos;
            }
            b = -1;
        }
        
        if (input[i].breed == 1 && c == -1){
            c = i;
        }
        if (input[i].breed == -1 && c != -1){
            if (input[i - 1].pos - input[c].pos > ans){
                ans = input[i - 1].pos - input[c].pos;
            }
            c = -1;
        }
    }
    
    int pos[100001], a[100001];
    a[0] = 0;
    pos[0] = 0;
    for (int i = 0; i < n; i++){
        pos[i + 1] = input[i].pos;
        a[i + 1] = a[i] + input[i].breed;
    }
    
    int seen[200002];
    for (int i = 0; i <= 200002; i++){
        seen[i] = -1;
    }
    for (int i = 0; i <= n; i++){
        if (seen[a[i]+100000] == -1){
            seen[a[i]+100000] = i;
        }else{
            if (pos[i] - pos[seen[a[i]+100000] + 1] > ans){
                ans = pos[i] - pos[seen[a[i]+100000] + 1];
            }
        }
    }
    
    fout << ans << endl;
    return 0;
}

/*
 6
 4 G
 10 H
 7 G
 16 H
 1 G
 3 H
 
 map<int, int> seen;
 seen.count()
 seen[a[i]]
 
 for (pair<int, int> p : seen){
    cout << p.first << p.second
 }
*/
