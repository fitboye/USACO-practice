//
//  main.cpp
//  cowart
//
//  Created by Jerry Cheng on 12/28/19.
//  Copyright © 2019 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;

char a[102][102];
bool b[102][102];

void search(int b, int d, char c){
    if (a[b + 1][d] == c){
        a[b + 1][d] = 'A';
        search(b + 1, d, c);
    }
    if (a[b - 1][d] == c){
        a[b - 1][d] = 'A';
        search(b - 1, d, c);
    }
    if (a[b][d + 1] == c){
        a[b][d + 1] = 'A';
        search(b, d + 1, c);
    }
    if (a[b][d - 1] == c){
        a[b][d - 1] = 'A';
        search(b, d - 1, c);
    }
}

void search2(int b, int d, char c){
    if ((c == 'R') || (c == 'G')){
        if ((a[b + 1][d] == 'R') || (a[b + 1][d] == 'G')){
            a[b + 1][d] = 'A';
            search2(b + 1, d, c);
        }
        if ((a[b - 1][d] == 'R') || (a[b - 1][d] == 'G')){
            a[b - 1][d] = 'A';
            search2(b - 1, d, c);
        }
        if ((a[b][d + 1] == 'R') || (a[b][d + 1] == 'G')){
            a[b][d + 1] = 'A';
            search2(b, d + 1, c);
        }
        if ((a[b][d - 1] == 'R') || (a[b][d - 1] == 'G')){
            a[b][d - 1] = 'A';
            search2(b, d - 1, c);
        }
    }else{
        if (a[b + 1][d] == c){
            a[b + 1][d] = 'A';
            search2(b + 1, d, c);
        }
        if (a[b - 1][d] == c){
            a[b - 1][d] = 'A';
            search2(b - 1, d, c);
        }
        if (a[b][d + 1] == c){
            a[b][d + 1] = 'A';
            search2(b, d + 1, c);
        }
        if (a[b][d - 1] == c){
            a[b][d - 1] = 'A';
            search2(b, d - 1, c);
        }
    }
}

int main() {
    ifstream fin("cowart.in");
    ofstream fout("cowart.out");
    int n;
    fin >> n;
    
    for (int i = 0; i <= n; i++){
        a[0][i] = 'A';
        a[n + 1][i] = 'A';
    }
    for (int i = 0; i <= n; i++){
        a[i][0] = 'A';
        a[i][n + 1] = 'A';
    }
    for (int i = 0; i <= n + 1; i++){
        for (int j = 0; j <= n + 1; j++){
            b[i][j] = false;
        }
    }
    
    char c[102][102];
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            fin >> a[i][j];
        }
    }
    for (int i = 0; i <= n + 1; i++){
        for (int j = 0; j <= n + 1; j++){
            c[i][j] = a[i][j];
        }
    }
    
    int human = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (a[i][j] != 'A'){
                human++;
                search(i, j, a[i][j]);
            }
        }
    }
    fout << human << ' ';
    
    
    for (int i = 0; i <= n + 1; i++){
        for (int j = 0; j <= n + 1; j++){
            a[i][j] = c[i][j];
        }
    }
    
    int cow = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (a[i][j] != 'A'){
                cow++;
                search2(i, j, a[i][j]);
            }
        }
    }
    fout << cow << endl;
    return 0;
}
