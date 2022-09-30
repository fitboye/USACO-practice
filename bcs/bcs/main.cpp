//
//  main.cpp
//  bcs
//
//  Created by Jerry Cheng on 4/21/18.
//  Copyright © 2018 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;
int main() {
    int n, k, a[8][8], b[10][8][8], flag = 0, w[10], x[10], y[10], z[10];
    cin >> n >> k;
    for (int i = 0; i < n; i = i + 1){
        for (int j = 0; j < n; j = j + 1){
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < k; i = i + 1){
        for (int j = 0; j < n; j = j + 1){
            for (int l = 0; l < n; l = l + 1){
                cin >> b[i][j][l];
            }
        }
    }
    //------------------------------------------------------
    for (int i = 0; i < k; i = i + 1){
        for (int l = n; l > 0; l = l - 1){
            for (int j = 0; j < n; j = j + 1){
                if (b[i][j][l] == '#'){
                    flag = 1;
                }
            }
            if (flag == 1){
                x[i] = n - l;
            }
        }
        //-----------------------------------
        flag = 0;
        for (int l = 0; l < n; l = l + 1){
            for (int j = 0; j < n; j = j + 1){
                if (b[i][j][l] == '#'){
                    flag = 1;
                }
            }
            if (flag == 1){
                w[i] = l;
            }
        }
        //-----------------------------------
        flag = 0;
        for (int j = 0; j < n; j = j + 1){
            for (int l = 0; l < n; l = l + 1){
                if (b[i][j][l] == '#'){
                    flag = 1;
                }
            }
            if (flag == 1){
                y[i] = j;
            }
        }
        //-----------------------------------
        flag = 0;
        for (int j = n; j > 0; j = j - 1){
            for (int l = 0; l < n; l = l + 1){
                if (b[i][j][l] == '#'){
                    flag = 1;
                }
            }
            if (flag == 1){
                y[i] = n - j;
            }
        }
    }
    
    for (int i = 0; i < k; i = i + 1){
        
    }
    
    
    
    return 0;
}

/*
 llll
 j####
 j####
 j####
 j####
 
 y
 w x
 z
 */

