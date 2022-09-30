//
//  main.cpp
//  reorder
//
//  Created by Jerry Cheng on 5/18/19.
//  Copyright © 2019 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;
int main() {
    ifstream fin("reorder.in");
    ofstream fout("reorder.out");
    int a[100], b[100], n;
    fin >> n;
    for (int i = 0; i < n; i++){
        fin >> a[i];
    }
    for (int i = 0; i < n; i++){
        fin >> b[i];
    }
    
    int num = 0, longest = 0;
    for (int i = 0; i < n; i++){
        int length = 0, displaced = a[i], loc = 0;
        bool c = true;
        while(c){
            for (int j = 0; j < n; j++){
                if (b[j] == displaced){
                    loc = j;
                    break;
                }
            }
            if (a[loc] == displaced){
                a[loc] = -1;
            }else{
                a[i] = 0;
            }
            //cout << i << ' ' << loc << endl;
            if (a[loc] == -1){
                c = false;
            }else if (a[loc] == 0){
                length++;
                break;
            }else{
                displaced = a[loc];
                a[loc] = 0;
                length++;
            }
        }
        a[i] = -1;
        if (c){
            if (length > longest){
                longest = length;
            }
            num++;
        }
    }
    fout << num << ' ';
    if (num == 0){
        fout << -1 << endl;
    }else{
        fout << longest << endl;
    }
    return 0;
}
/*
 5
 1 2 3 4 5
 1 5 4 3 2
*/
