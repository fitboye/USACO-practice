//
//  main.cpp
//  whereami
//
//  Created by Jerry Cheng on 12/15/19.
//  Copyright © 2019 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream fin("whereami.in");
    ofstream fout("whereami.out");
    int n;
    char c[100];
    fin >> n;
    for (int i = 0; i < n; i++){
        fin >> c[i];
    }
    

    for (int k = 1; k < n; k++){
        bool works = true;
        for (int i = 0; i < n - k + 1; i++){//may be wrong
            for (int j = 0; j < n - k + 1; j++){//may be wrong
                if (i != j){
                    bool same = true;
                    for (int l = 0; l < k; l++){
                        if (c[i + l] != c[j + l]){
                            same = false;
                        }
                    }
                    if (same){
                        works = false;
                    }
                }
            }
        }
        if (works){
            fout << k << endl;
            break;
        }
    }
    return 0;
}
