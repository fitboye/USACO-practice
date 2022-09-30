//
//  main.cpp
//  perimeter
//
//  Created by Jerry Cheng on 3/14/20.
//  Copyright © 2020 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;

int a[102][102];
int length;
bool holes[10003];
void fill(int fillnum, int x, int y){
    a[x][y] = fillnum;
    
    if (a[x + 1][y] == 0){
        fill(fillnum, x + 1, y);
    }else if (a[x + 1][y] == 2){
        holes[fillnum] = false;
    }
    if (a[x - 1][y] == 0){
        fill(fillnum, x - 1, y);
    }else if (a[x - 1][y] == 2){
        holes[fillnum] = false;
    }
    if (a[x][y + 1] == 0){
        fill(fillnum, x, y + 1);
    }else if (a[x][y + 1] == 2){
        holes[fillnum] = false;
    }
    if (a[x][y - 1] == 0){
        fill(fillnum, x, y - 1);
    }else if (a[x][y - 1] == 2){
        holes[fillnum] = false;
    }
}

int main() {
    ifstream fin("perimeter.in");
    ofstream fout("perimeter.out");
    int n;
    for (int i = 0; i < 102; i++){
        for (int j = 0; j < 102; j++){
            a[i][j] = 0;
        }
    }
    for (int i = 0; i < 102; i++){
        a[i][0] = 2;
        a[i][101] = 2;
        a[0][i] = 2;
        a[101][i] = 2;
    }
    for (int i = 0; i < 10000; i++){
        holes[i] = true;
    }
    holes[2] = false;
    fin >> n;
    for (int i = 0; i < n; i++){
        int x, y;
        fin >> x >> y;
        a[x][y] = 1;
    }
    
    int fillnum = 3;
    for (int i = 0; i < 102; i++){
        for (int j = 0; j < 102; j++){
            if (a[i][j] == 0){
                fill(fillnum,i , j);
                fillnum++;
            }
        }
    }
    /*
    for (int i = 0; i < 102; i++){
        for (int j = 0; j < 102; j++){
            cout << a[i][j];
        }
        cout << endl;
    }
     */
    
    for (int i = 0; i < fillnum; i++){
        //cout << holes[i] << endl;
    }
    int p = 0;
    for (int i = 1; i < 101; i++){
        for (int j = 1; j < 101; j++){
            if (a[i][j] == 1){
                if (!holes[a[i + 1][j]]){
                    p++;
                }
                //cout << a[i + 1][j] << ' ' << holes[a[i + 1][j]] << endl;
                if (!holes[a[i - 1][j]]){
                    p++;
                }
                //cout << a[i - 1][j] << ' ' << holes[a[i - 1][j]] << endl;
                if (!holes[a[i][j + 1]]){
                    p++;
                }
                //cout << a[i][j - 1] << ' ' << holes[a[i][j - 1]] << endl;
                if (!holes[a[i][j - 1]]){
                    p++;
                }
                //cout << a[i][j - 1] << ' ' << holes[a[i][j - 1]] << endl << endl;
            }
        }
    }
    fout << p << endl;
    return 0;
}
