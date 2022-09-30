/*
 ID: jerry.c1
 TASK: namenum
 LANG: C++
 */

#include <iostream>
#include <fstream>
using namespace std;
int main() {
    ifstream fin("namenum.in");
    ofstream fout("namenum.out");
    ifstream din("dict.txt");
    string d[5000];
    char letters[24] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y'};
    for (int i = 0; i < 4616; i++){
        din >> d[i];
    }
    long long a;
    fin >> a;
    long long a1 = a;
    int digits = 0;
    long long c = 1;
    while (a1 > 0){
        a1 = a1 / 10;
        digits++;
        c = c * 10;
    }
    long long c1 = c;
    bool none = true;
    for (int i = 0; i < 4616; i++){
        if (d[i].length() == digits){
            a1 = a;
            c1 = c;
            bool possible;
            for (int j = 0; j < digits; j++){
                c1 = c1 / 10;
                int b;
                if (c1 == 0){
                    b = a1 % 10;
                }else{
                    b = a1 / c1;
                }
                cout << b << ' ' << a1 << ' ' << c1 << endl;
                possible = false;
                for (int k = (b - 2) * 3; k < (b - 2) * 3 + 3; k++){
                    cout << letters[k] << ' ' << d[i][j] << endl;
                    if (letters[k] == d[i][j]){
                        possible = true;
                    }
                }
                if (!possible){
                    break;
                }
                if (c1 > 0){
                    a1 = a1 % c1;
                }
            }
            if (possible){
                none = false;
                fout << d[i] << endl;
            }
        }
    }
    if (none){
        fout << "NONE" << endl;
    }
    return 0;
}
