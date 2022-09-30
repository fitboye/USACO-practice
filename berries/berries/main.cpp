//
//  main.cpp
//  berries
//
//  Created by Jerry Cheng on 1/20/20.
//  Copyright © 2020 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

bool compare (int a, int b){
    return a > b;
}

int main() {
    ifstream fin("berries.in");
    ofstream fout("berries.out");
    int n, k, a[1000];
    fin >> n >> k;
    int biggest = 0;
    for (int i = 0; i < n; i++){
        fin >> a[i];
        if (a[i] > biggest){
            biggest = a[i];
        }
    }
    sort(a, a + n, compare);
    /*
    for (int i = 0; i < n; i++){
        cout << a[i] << ' ';
    }
    cout << endl;
     */
    
    int ans = 0;
    for (int i = 1; i < biggest; i++){
        int baskets = 0;
        for (int j = 0; j < n; j++){
            baskets = baskets + a[j] / i;
        }
        int remaining[1000];
        if (baskets < k){
            for (int j = 0; j < n; j++){
                remaining[j] = a[j] % i;
            }
            sort(remaining, remaining + n, compare);
        }
        int current = 0;
        if (baskets > k / 2){
            if (baskets >= k){
                current = current + k/2 * i;
            }else{
                current = current + (baskets - k/2) * i;
                for (int j = 0; (j < k - baskets && j < n); j++){
                    current = current + remaining[j];
                    //cout << current << endl;
                }
            }
        }
        if (current > ans){
            //cout << baskets << ' ' << i << endl;
            ans = current;
        }
    }
    fout << ans << endl;
    return 0;
}



/*
505 293
 
91058
*/
