//
//  main.cpp
//  hoofball
//
//  Created by Jerry Cheng on 2/24/18.
//  Copyright © 2018 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;
int main() {
    ifstream fin ("hoofball.in");
    ofstream fout ("hoofball.out");
    int n, a[100], x = 0, b[100], lastsmallest = 0, smallest, c[100];
    fin >> n;
    for (int i = 0; i < n; i = i + 1){
        fin >> a[i];
    }
    
    for (int i = 0; i < n; i = i + 1){
        smallest = 100000;
        for (int j = 0; j < n; j = j + 1){
            if ((a[j] < smallest) && (a[j] > lastsmallest)){
                smallest = a[j];
            }
        }
        lastsmallest = smallest;
        b[i] = smallest;
        //cout << b[i] << ' ';
    }
    //cout << endl;
    
    c[0] = 1;
    c[n - 1] = 0;
    for (int i = 1; i < n - 1; i = i + 1){
        if (b[i + 1] - b[i] < b[i] - b[i - 1]){
            c[i] = 1;
        }else{
            c[i] = 0;
        }
    }
    
    for (int i = 0; i < n; i = i + 1){
        //cout << c[i] << ' ';
    }
    //cout << endl;
    
    for (int i = 0; i < n; i = i + 1){
        if (i == 0){
            if (c[i + 1] == 1){
                x = x + 1;
                //cout << "a" << i << endl;
            }
            if (c[i + 1] == 0){
                if (c[i + 2] == 1){
                    x = x + 1;
                    //cout << "b" << i << endl;
                }
            }
        }else if (i == n - 1){
            if (c[i - 1] == 0){
                x = x + 1;
                //cout << "c" << i << endl;
            }
        }else{
            if ((c[i - 1] == 0) && (c[i + 1] == 1)){
                x = x + 1;
                //cout << "d" << i << endl;
            }
            if ((c[i] == 1) && (c[i + 1] == 0)){
                if (i == n - 2){
                    if (c[i - 1] == 0){
                        x = x + 1;
                        //cout << "e" << i << endl;
                    }
                }
                if ((c[i - 1] == 0) && (c[i + 2] == 1)){
                    x = x + 1;
                    //cout << "f" << i << endl;
                }
            }
        }
    }

    fout << x << endl;
    
    return 0;
}
