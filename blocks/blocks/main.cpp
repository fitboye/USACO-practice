//
//  main.cpp
//  blocks
//
//  Created by Jerry Cheng on 3/31/18.
//  Copyright © 2018 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;
int main() {
    ifstream fin ("blocks.in");
    ofstream fout ("blocks.out");
    string a[100], b[100];
    int n, c[26], flag, d[10];
    fin >> n;
    for (int i = 0; i < n; i++){
        fin >> a[i] >> b[i];
    }
    
    for (int i = 0; i < 26; i++){
        c[i] = 0;
    }
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < 10; j++){
            d[j] = 0;
        }
        
        for (int j = 0; j < a[i].length(); j++){
            c[int(a[i][j]) - 97]++;
        }
        
        for (int j = 0; j < b[i].length(); j++){
            flag = 0;
            for (int k = 0; k < a[i].length(); k++){
                if ((b[i][j] == a[i][k]) && (d[k] == 0)){
                    d[k] = 1;
                    flag = 1;
                }
            }
            if (flag == 0){
                c[int(b[i][j]) - 97]++;
            }
        }
    }
    
    for (int l = 0; l < 26; l++){
        fout << c[l] << endl;
    }
    return 0;
}

