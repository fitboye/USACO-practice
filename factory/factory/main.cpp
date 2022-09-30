//
//  main.cpp
//  factory
//
//  Created by Jerry Cheng on 4/1/19.
//  Copyright © 2019 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream fin("factory.in");
    ofstream fout("factory.out");
    int n, all[100], a[2][100];
    fin >> n;
    for (int i = 0; i < n - 1; i++){
        fin >> a[0][i] >> a[1][i];
    }
    for (int i = 0; i < n; i++){
        all[i] = -1;
    }
    
    int s = 0;
    for (int i = 1; i < n + 1; i++){
        bool c = false;
        for (int j = 1; j < n + 1; j++){
            bool x = true, connects = false;
            int current = j;
            if (j != i){
                while (x){
                    bool found = false;
                    for (int k = 0; k < n - 1; k++){
                        if (a[0][k] == current){
                            current = a[1][k];
                            found = true;
                            break;
                        }
                    }
                    //cout << i << ' ' << j << ' ' << found << endl;
                    if (found == false){
                        x = false;
                    }else if (current == i){
                        connects = true;
                        x = false;
                    }
                }
                
                if (connects == false){
                    c = true;
                    break;
                }
            }
        }
        if (!c){
            s = i;
            break;
        }
    }
    fout << s << endl;
    return 0;
}
