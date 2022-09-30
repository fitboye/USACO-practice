/*
 ID: jerry.c1
 TASK: palsquare
 LANG: C++
 */

#include <iostream>
#include <fstream>
using namespace std;

int b;
string base10tobaseb(int n){
    int y = 1;
    string x;
    while (n / y > 0){
        if (n / y % b < 10){
            x = char(n / y % b + '0') + x;
        }else{
            x = char(n / y % b + 'A' - 10) + x;
        }
        y = y * b;
    }
    return x;
}

int main() {
    ifstream fin("palsquare.in");
    ofstream fout("palsquare.out");
    fin >> b;
    int a;
    string c;
    for (int i = 1; i < 300; i++){
        a = i * i;
        c = base10tobaseb(a);
        bool x = true;
        for (int i = 0; i < c.length(); i++){
            if (c[i] != c[c.length() - i - 1]){
                x = false;
                break;
            }
        }
        if(x){
            fout << base10tobaseb(i) << ' ' << c << endl;
        }
     }
    return 0;
}
