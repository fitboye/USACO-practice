//
//  main.cpp
//  Angry cows
//
//  Created by Jerry Cheng on 3/10/18.
//  Copyright © 2018 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;
int main() {
    ifstream fin ("angry.in");
    ofstream fout ("angry.out");
    int a[100], n, b[100], smallest, last_smallest = -1, amount = 0, x = -1, left, c[100], right;
    fin >> n;
    for (int i = 0; i < n; i = i + 1){
        fin >> a[i];
    }
    
    for (int i = 0; i < n; i = i + 1){
        smallest = 1000000000;
        for (int j = 0; j < n; j = j + 1){
            if ((a[j] <smallest) && (a[j] > last_smallest)){
                smallest = a[j];
            }
        }
        b[i] = smallest;
        last_smallest = smallest;
        //cout << last_smallest << endl;
    }
    
    for (int i = 0; i < n; i = i + 1){
        for (int j = 0; j < n; j = j + 1){
            c[j] = -1;
        }
        c[i] = 0;
        for (int t = 1; t < n; t = t + 1){
            for (int j = 0; j < n; j = j + 1){
                if (c[j] == t - 1){
                    for (int k = 0; k < n; k = k + 1){
                        if ((a[k] <= a[j] + t) && (a[k] >= a[j] - t)){
                            if (c[k] == -1){
                                c[k] = t;
                            }
                        }
                    }
                }
            }
        }
        for (int j = 0; j < n; j = j + 1){
            if (c[j] > -1){
                amount = amount + 1;
            }
            //cout << c[j] << endl;
        }
        //cout << endl;
        if (amount > x){
            x = amount;
        }
        amount = 0;
    }
    fout << x << endl;
    return 0;
}
