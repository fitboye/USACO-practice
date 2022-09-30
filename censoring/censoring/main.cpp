//
//  main.cpp
//  censoring
//
//  Created by Jerry Cheng on 8/29/20.
//  Copyright © 2020 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main() {
    ifstream fin("censor.in");
    ofstream fout("censor.out");
    string s, t;
    fin >> s >> t;
    string a;
    for (int i = 0; i < s.length(); i++){
        a += s[i];
        
        if (a.length() >= t.length()){
            bool same = true;
            int k = 0;
            for (int j = a.length() - t.length(); j < a.length(); j++){
                //cout << a[j];
                if (a[j] != t[k]){
                    same = false;
                }
                k++;
            }
            //cout << endl;
            //cout << same << endl;
            if (same){
                a.erase(a.length() - t.length());
            }
        }
    }
    fout << a << endl;
    return 0;
}
