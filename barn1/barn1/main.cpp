/*
ID: jerry.c1
TASK: barn1
LANG: C++
*/

#include <iostream>
#include <fstream>
using namespace std;
int main() {
    ifstream fin("barn1.in");
    ofstream fout("barn1.out");
    int m, s, c, a[200], in;
    fin >> m >> s >> c;
    for (int i = 0; i < 200; i++){
        a[i] = 0;
    }
    for (int i = 0; i < c; i++){
        fin >> in;
        a[in - 1] = -1;
    }
    
    int b = 0;
    for (int i = 0; i < s - 1; i++){
        cout << i + 1 << ' ' << a[i] << endl;
        if ((a[i] == -1) && (a[i + 1] != -1)){
            b++;
        }
    }
    if ((a[s - 2] == 0) && (a[s - 1] == -1)){
        b++;
    }
    int startpos = 0;
    for (int i = 0; i < s; i++){
        if (a[i] == -1){
            startpos = i;
            break;
        }
    }
    cout << b << endl;
    if (b > m){
        while (b > m){
            int sgap = 10000, gaplen = 0, sgappos = 0;
            for (int i = startpos; i < s; i++){
                if (a[i] != -1){
                    gaplen++;
                }else{
                    if ((gaplen < sgap) && (gaplen != 0)){
                        sgap = gaplen;
                        sgappos = i;
                    }
                    gaplen = 0;
                }
            }
            cout << 'a' << sgappos << ' ' << sgap << endl;
            for (int i = sgappos - sgap; i < sgappos; i++){
                a[i] = -1;
            }
            b--;
        }
    }
    cout << " -------- " << endl;
    int len = 0;
    for (int i = 0; i < s; i++){
        cout << i + 1 << ' ' << a[i] << endl;
        if (a[i] == -1){
            len++;
        }
    }
    fout << len << endl;
    return 0;
}
