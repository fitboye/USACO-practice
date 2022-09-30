//
//  main.cpp
//  hshoe
//
//  Created by Jerry Cheng on 4/25/20.
//  Copyright © 2020 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;
int n, ans = 0;
char a[7][7];
bool used[7][7];
void search(int b, int c, int l, int r){
    /*
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cout << a[i][j];
        }
        cout << endl;
    }
    cout << l << ' ' << r << endl;
    cout << endl;
     */
    cout << b << ' ' << c << endl << endl;
    
    if (l == r){
        if (l + r > ans){
            ans = l + r;
        }
        return;
    }
    
    int x[4] = {1, -1, 0, 0};
    int y[4] = {0, 0, 1, -1};
    for (int i = 0; i < 4; i++){
        cout << b << ' ' << c << endl;
        b = b + x[i];
        c = c + y[i];
        if (a[b][c] == '('){
            if (r == 0){
                a[b][c] = ' ';
                search(b, c, l + 1, r);
                a[b][c] = '(';
            }
        }else if (a[b][c] == ')'){
            a[b][c] = ' ';
            search(b, c, l, r + 1);
            a[b][c] = ')';
        }
        b = b - x[i];
        c = c - y[i];
    }
}

int main() {
    ifstream fin("hshoe.in");
    ofstream fout("hshoe.out");
    fin >> n;
    for (int i = 0; i < n; i++){
        a[0][i] = ' ';
        a[n + 1][i] = ' ';
        a[i][0] = ' ';
        a[i][n + 1] = ' ';
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            fin >> a[i][j];
        }
    }
    if (a[1][1] == '('){
        a[1][1] = ' ';
        search(1, 1, 1, 0);
    }
    fout << ans << endl;
    return 0;
}

/*
 if (a[b][c] == '('){
 a[b][c] = ' ';
 search(b, c, l++, r);
 a[b][c] = '(';
 }else if (a[b][c] == ')'){
 a[b][c] = ' ';
 search(b, c, l, r++);
 a[b][c] = '(';
 }
 
 (())
 ()((
 (()(
 ))))
 */
