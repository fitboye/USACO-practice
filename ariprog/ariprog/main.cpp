/*
 ID: jerry.c1
 TASK: ariprog
 LANG: C++
 */

#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream fin("ariprog.in");
    ofstream fout("ariprog.out");
    int n, m;
    fin >> n >> m;
    
    bool bq[125001];
    int allbq[62500], length = 0;
    for (int i = 0; i < 125001; i++){
        bq[i] = false;
    }
    for (int i = 0; i <= m; i++){
        for (int j = 0; j <= m; j++){
            bq[i * i + j * j] = true;
        }
    }
    for (int i = 0; i <= 2 * m * m; i++){
        if (bq[i]){
            allbq[length] = i;
            length++;
        }
    }
    
    int ans = 0;
    for (int b = 1; b * (n - 1) <= 2 * m * m; b++){
        for (int i = 0; i < length; i++){
            if (allbq[i] + (n-1) * b <= 2 * m * m){
                int a = allbq[i];
                bool works = true;
                for (int j = 1; j < n; j++){
                    if (!bq[a + j * b]){
                        works = false;
                        break;
                    }
                }
                if (works){
                    ans++;
                    fout << a << ' ' << b << endl;
                }
            }
        }
    }
    if (ans == 0){
        fout << "NONE" << endl;
    }
    return 0;
}
// 22 250
