//
//  main.cpp
//  mowing
//
//  Created by Jerry Cheng on 3/10/18.
//  Copyright © 2018 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;
int a[2001][2001];
int main(){
    ifstream fin ("mowing.in");
    ofstream fout ("mowing.out");
    int n, c[100], x = 1000, y = 1000, last = 0, smallest = 100000, time = 0;
    char b[100];
    fin >> n;
    for (int i = 0; i < n; i = i + 1){
        fin >> b[i] >> c[i];
    }
    
    for (int i = 0; i < 2001; i = i + 1){
        for (int j = 0; j < 2001; j = j + 1){
            a[i][j] = -1;
        }
    }
    
    a[x][y] = 0;
    for (int i = 0; i < n; i = i + 1){
        if (b[i] == 'N'){
            for (int j = 1; j <= c[i]; j = j + 1){
                time = time + 1;
                if (a[x][y + j] != -1){
                    if (time - a[x][y + j] < smallest){
                        smallest = time - a[x][y + j];
                        //cout << x << ' ' << y + j << ' ' << time << ' ' << smallest << endl;
                    }
                }
                last = time;
                a[x][y + j] = time;
            }
            y = y + c[i];
        }else if (b[i] == 'S'){
            for (int j = 1; j <= c[i]; j = j + 1){
                time = time + 1;
                if (a[x][y - j] != -1){
                    if (time - a[x][y - j] < smallest){
                        smallest = time - a[x][y - j];
                        //cout << x << ' ' << y - j << ' ' << time << ' ' << smallest << endl;
                    }
                }
                last = time;
                a[x][y - j] = time;
            }
            y = y - c[i];
        }else if (b[i] == 'E'){
            for (int j = 1; j <= c[i]; j = j + 1){
                time = time + 1;
                if (a[x + j][y] != -1){
                    if (time - a[x + j][y] < smallest){
                        smallest = time - a[x + j][y];
                        //cout << x + j << ' ' << y << ' ' << time << ' ' << smallest << endl;
                    }
                }
                last = time;
                a[x + j][y] = time;
            }
            x = x + c[i];
        }else if (b[i] == 'W'){
            for (int j = 1; j <= c[i]; j = j + 1){
                time = time + 1;
                if (a[x - j][y] != -1){
                    if (time - a[x - j][y] < smallest){
                        smallest = time - a[x - j][y];
                        //cout << x - j << ' ' << y << ' ' << time << ' ' << smallest << endl;
                    }
                }
                last = time;
                a[x - j][y] = time;
            }
            x = x - c[i];
        }
    }
    if (smallest == 100000){
        fout << -1 << endl;
    }else{
        fout << smallest << endl;
    }
    return 0;
}
    
    
    
    
    
    
    
    
    
    
    
    
    
    
