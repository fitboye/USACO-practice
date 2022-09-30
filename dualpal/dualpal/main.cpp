/*
 ID: jerry.c1
 TASK: dualpal
 LANG: C++
 */

#include <iostream>
#include <fstream>
using namespace std;

string base10tobasek(int n, int k){
    int y = 1;
    string x;
    while (n / y > 0){
        if (n / y % k < 10){
            x = char(n / y % k + '0') + x;
        }else{
            x = char(n / y % k + 'A' - 10) + x;
        }
        y = y * k;
    }
    return x;
}
int main() {
    ifstream fin("dualpal.in");
    ofstream fout("dualpal.out");
    int n, s;
    fin >> n >> s;
    int found = 0;
    s++;
    while (found < n){
        int p = 0;
        for (int i = 2; i <= 10; i++){
            string a = base10tobasek(s, i);
            //cout << a << endl;
            int l = 0, r = a.length() - 1;
            bool palindrome = true;
            while (r - l > 0){
                //cout << l << ' ' << r << endl;
                if (a[l] != a[r]){
                    palindrome = false;
                }
                l++;
                r--;
            }
            if (palindrome){
                //cout << a << endl;
                p++;
            }
        }
        if (p >= 2){
            fout << s << endl;
            found++;
        }
        s++;
    }
    return 0;
}
