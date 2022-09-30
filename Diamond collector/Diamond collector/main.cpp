//
//  main.cpp
//  Diamond collector
//
//  Created by Jerry Cheng on 4/1/18.
//  Copyright © 2018 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;
int main() {
    ifstream fin ("diamond.in");
    ofstream fout ("diamond.out");
    int n, a[1000], k, smallest = 10000000, smallest_location = 0, b[1000], x, y = 0;
    fin >> n >> k;
    for (int i = 0; i < n; i++){
        fin >> a[i];
    }
    
    for (int i = 0; i < n; i++){
        smallest = 10000000;
        for (int j = 0; j < n; j++){
            if ((a[j] < smallest) && (a[j] > -1)){
                smallest_location = j;
                smallest = a[j];
            }
        }
        b[i] = a[smallest_location];
        a[smallest_location] = -1;
    }
    
    /*
    for (int i = 0; i < n; i++){
        cout << b[i] << endl;
    }
    cout << endl;
    */
    
    for (int i = 0; i < n; i++){
        x = 0;
        for (int j = i; b[j] - b[i] <= k && j < n; j = j + 1){
            x = x + 1;
            //cout << i << ' ' << j << endl;
        }
        
        if (x > y){
            y = x;
        }
        //cout << x << endl;
    }
    fout << y << endl;
    return 0;
}
