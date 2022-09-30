//
//  main.cpp
//  High Card
//
//  Created by Jerry Cheng on 8/11/18.
//  Copyright © 2018 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;
int main() {
    ifstream fin("highcard.in");
    ofstream fout("highcard.out");
    int n, a[50000], elsie[50000], bessie[50000], elsiecount, bessiecount, start, total = 0;
    bool b[100000];
    fin >> n;
    for (int i = 0; i < n; i++){
        fin >> a[i];
    }
    
    for (int i = 0; i < n; i++){
        b[a[i] - 1] = true;
    }
    
    elsiecount = 0;
    bessiecount = 0;
    for (int i = 0; i < 2 * n; i++){
        if (b[i] == false){
            bessie[bessiecount] = i + 1;
            bessiecount++;
        }else if(b[i] == true){
            elsie[elsiecount] = i + 1;
            elsiecount++;
        }
    }
    
    start = 0;
    for (int i = 0; i < n; i++){
        for (int j = start; j < n; j++){
            if (bessie[j] > elsie[i]){
                start = j + 1;
                total++;
                break;
            }
        }
    }
    
    fout << total << endl;
    return 0;
}
