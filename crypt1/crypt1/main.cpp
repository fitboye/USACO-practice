/*
ID: jerry.c1
TASK: crypt1
LANG: C++
*/

#include <iostream>
#include <fstream>
using namespace std;
int main() {
    ifstream fin("crypt1.in");
    ofstream fout("crypt1.out");
    int n, a[10];
    fin >> n;
    int b[10];
    for (int i = 0; i < 10; i++){
        b[i] = false;
    }
    for (int i = 0; i < n; i++){
        fin >> a[i];
        b[a[i]] = true;
    }
    
    int count = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            for (int k = 0; k < n; k++){
                for (int l = 0; l < n; l++){
                    for (int m = 0; m < n; m++){
                        
                        bool works = true;
                        int c = (a[i] * 100 + a[j] * 10 + a[k]) * a[l];
                        int d;
                        if (c / 1000 > 0){
                            works = false;
                        }else{
                            d = 100;
                            for (int i = 0; i < 3; i++){
                                if (!b[c / d]){
                                    works = false;
                                    break;
                                }
                                c = c % d;
                                d = d / 10;
                            }
                        }
                        
                        c = (a[i] * 100 + a[j] * 10 + a[k]) * a[m];
                        if (c / 1000 > 0){
                            works = false;
                        }else{
                            d = 100;
                            for (int i = 0; i < 3; i++){
                                if (!b[c / d]){
                                    works = false;
                                    break;
                                }
                                c = c % d;
                                d = d / 10;
                            }
                        }
                        
                        c = (a[i] * 100 + a[j] * 10 + a[k]) * (a[l] * 10 + a[m]);
                        if (c / 10000 > 0){
                            works = false;
                        }else{
                            d = 1000;
                            for (int i = 0; i < 4; i++){
                                if (!b[c / d]){
                                    works = false;
                                    break;
                                }
                                c = c % d;
                                d = d / 10;
                            }
                        }
                        if (works){
                            //cout << a[i] << ' ' << a[j] << ' ' << a[k] << ' ' << a[l] << ' ' << a[m] << endl;
                            count++;
                        }
                        
                    }
                }
            }
        }
    }
    fout << count << endl;
    return 0;
}


