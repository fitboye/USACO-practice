//
//  main.cpp
//  lineup
//
//  Created by Jerry Cheng on 12/15/19.
//  Copyright © 2019 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;


int n;
int pairs[2][7];
int ans[8];
bool af = true;
void permutation(int a, int d, bool used[], int b[]){
    if (d == 8){
        /*
        for (int i = 0; i < 8; i++){
            cout << b[i] << ' ';
        }
        cout << endl;
         */
        
        bool works = true;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < 8; j++){
                if (b[j] == pairs[0][i]){
                    if (j == 0){
                        if (b[j + 1] != pairs[1][i]){
                            works = false;
                        }
                    }else if (j == 7){
                        if (b[j - 1] != pairs[1][i]){
                            works = false;
                        }
                    }else{
                        if ((b[j - 1] != pairs[1][i]) && (b[j + 1] != pairs[1][i])){
                            works = false;
                        }
                    }

                }
            }
        }
        
        if (works && af){
            for (int i = 0; i < 8; i++){
                ans[i] = b[i];
            }
            af = false;
        }
        
        return;
    }
    
    for (int i = 0; i < a; i++){
        if (!used[i]){
            used[i] = true;
            b[d] = i;
            permutation(a, d + 1, used, b);
            used[i] = false;
        }
    }
}


int main() {
    ifstream fin("lineup.in");
    ofstream fout("lineup.out");
    string cows[8] = {"Beatrice", "Belinda", "Bella",  "Bessie", "Betsy", "Blue", "Buttercup", "Sue"};
    fin >> n;
    for (int i = 0; i < n; i++){
        string a;
        int pos = 0;
        fin >> a;
        for (int i = 0; i < 8; i++){
            if (a == cows[i]){
                pos = i;
                break;
            }
        }
        pairs[0][i] = pos;
        fin >> a;
        fin >> a;
        fin >> a;
        fin >> a;
        fin >> a;
        for (int i = 0; i < 8; i++){
            if (a == cows[i]){
                pos = i;
                break;
            }
        }
        pairs[1][i] = pos;
    }
    
    bool used[8];
    for (int i = 0; i < 8; i++){
        used[i] = false;
    }
    int c[8];
    permutation(8, 0, used, c);
    for (int i = 0; i < 8; i++){
        fout << cows[ans[i]] << endl;
    }
    return 0;
}
