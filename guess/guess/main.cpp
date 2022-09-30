//
//  main.cpp
//  guess
//
//  Created by Jerry Cheng on 11/9/19.
//  Copyright © 2019 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream fin("guess.in");
    ofstream fout("guess.out");
    int n;
    fin >> n;
    string animal, a[100][100];
    int k[100];
    for (int i = 0; i < n; i++){
        fin >> animal >> k[i];
        for (int j = 0; j < k[i]; j++){
            fin >> a[i][j];
        }
    }

    int count, max = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            count = 0;
            if (i != j){
                for (int l = 0; l < k[i]; l++){
                    for (int m = 0; m < k[j]; m++){
                        if (a[i][l] == a[j][m]){
                            count++;
                        }
                    }
                }
            }
            if (count > max){
                max = count;
            }
        }
    }
    
    fout << max + 1 << endl;
    return 0;
}
