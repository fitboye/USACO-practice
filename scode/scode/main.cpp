//
//  main.cpp
//  scode
//
//  Created by Jerry Cheng on 7/18/20.
//  Copyright © 2020 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;

int counter = 0;
void search(string s){
    //cout << s << endl;
    if (s.length() % 2 == 0 || s.length() < 2){
        return;
    }
    if (s.length() > 2){
        int mid = s.length() / 2;
        string a = "", b = "";
        for (int i = 0; i < mid; i++){
            a += s[i];
        }
        for (int i = mid + 1; i < s.length(); i++){
            b += s[i];
        }
        //cout << a << ' ' << b << endl;
        string atemp = a + s[mid];
        string btemp = s[mid] + b;
        bool same = true;
        for (int i = 0; i < b.length(); i++){
            if (atemp[i] != b[i]){
                same = false;
            }
        }
        if (same){
            counter++;
            search(atemp);
        }
        same = true;
        for (int i = 0; i < b.length(); i++){
            if (atemp[i + 1] != b[i]){
                same = false;
            }
        }
        if (same){
            counter++;
            search(atemp);
        }
        same = true;
        for (int i = 0; i < a.length(); i++){
            if (a[i] != btemp[i]){
                same = false;
            }
        }
        if (same){
            counter++;
            search(btemp);
        }
        same = true;
        for (int i = 0; i < a.length(); i++){
            if (a[i] != btemp[i + 1]){
                same = false;
            }
        }
        if (same){
            counter++;
            search(btemp);
        }
    }
}

int main() {
    ifstream fin("scode.in");
    ofstream fout("scode.out");
    string s;
    fin >> s;
    search(s);
    fout << counter << endl;
    return 0;
}
