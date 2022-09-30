//
//  main.cpp
//  cowcode
//
//  Created by Jerry Cheng on 2/19/21.
//  Copyright © 2021 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream fin("cowcode.in");
    ofstream fout("cowcode.out");
    string s;
    long long n;
    fin >> s >> n;
    long long stringlen = s.length();
    while (stringlen < n){
        stringlen = stringlen * 2;
    }
    
    while (n > s.length()){
        if (n == stringlen / 2 + 1){
            n--;
        }else if (n > stringlen / 2){
            n = n - stringlen / 2 - 1;
        }
        stringlen = stringlen / 2;
    }
    fout << s[n - 1] << endl;
    return 0;
}
