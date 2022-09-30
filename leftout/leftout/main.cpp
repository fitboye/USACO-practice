//
//  main.cpp
//  leftout
//
//  Created by Jerry Cheng on 7/31/20.
//  Copyright © 2020 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream fin("leftout.in");
    ofstream fout("leftout.out");
    int n, a[1000][1000];
    fin >> n;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            char x;
            fin >> x;
            if (x == 'L'){
                a[i][j] = -1;
            }else{
                a[i][j] = 1;
            }
        }
    }
    
    for (int i = 0; i < n; i++){
        if (a[0][i] == -1){
            for (int j = 0; j < n; j++){
                a[j][i] = a[j][i] * -1;
            }
        }
    }
    
    for (int i = 1; i < n; i++){
        int count1 = 0, count2 = 0;
        for (int j = 0; j < n; j++){
            if (a[i][j] == -1){
                count1++;
            }else{
                count2++;
            }
        }
        if (count1 > count2){
            for (int j = 0; j < n; j++){
                a[i][j] = a[i][j] * -1;
            }
        }
    }
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cout << a[i][j];
        }
        cout << endl;
    }
    
    int x = -1, y = -1;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (a[i][j] == -1){
                if (x == -1){
                    x = i + 1;
                    y = j + 1;
                }else{
                    x = -2;
                    break;
                }
            }
        }
    }
    
    if (x == -1){
        fout << -1 << endl;
    }else if (x >= 0){
        fout << x << ' ' << y << endl;
    }else{
        for (int i = 0; i < n; i++){
            if (a[n - 1][i] == -1){
                for (int j = 0; j < n; j++){
                    a[j][i] = a[j][i] * -1;
                }
            }
        }
        
        for (int i = 0; i < n - 1; i++){
            int count1 = 0, count2 = 0;
            for (int j = 0; j < n; j++){
                if (a[i][j] == -1){
                    count1++;
                }else{
                    count2++;
                }
            }
            if (count1 > count2){
                for (int j = 0; j < n; j++){
                    a[i][j] = a[i][j] * -1;
                }
            }
        }
        
        int x = -1, y = -1;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (a[i][j] == -1){
                    if (x == -1){
                        x = i + 1;
                        y = j + 1;
                    }else{
                        x = -2;
                        break;
                    }
                }
            }
        }
        if (x < 0){
            fout << -1 << endl;
        }else{
            fout << x << ' ' << y << endl;
        }
    }
    
    
    
    return 0;
}
