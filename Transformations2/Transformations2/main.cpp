/*
 ID: jerry.c1
 TASK: transform
 LANG: C++
 */

int n;

void reflect(char x[][10]){
    char y[10][10];
    for (int i = 0; i < n; i = i + 1){
        for (int j = 0; j < n; j = j + 1){
            y[i][j] = x[i][n - 1 - j];
        }
    }
    for (int i = 0; i < n; i = i + 1){
        for (int j = 0; j < n; j = j + 1){
            x[i][j] = y[i][j];
        }
    }
}

void rotate(char x[][10]){
    char y[10][10];
    for (int i = 0; i < n; i = i + 1){
        for (int j = 0; j < n; j = j + 1){
            y[i][j] = x[n - 1 - j][i];
        }
    }
    for (int i = 0; i < n; i = i + 1){
        for (int j = 0; j < n; j = j + 1){
            x[i][j] = y[i][j];
        }
    }
}

bool compare(char a[][10], char b[][10]){
    for (int i = 0; i < n; i = i + 1){
        for (int j = 0; j < n; j = j + 1){
            if (a[i][j] != b[i][j]){
                return false;
            }
        }
    }
    return true;
}
    
#include <iostream>
#include <fstream>
using namespace std;
int main() {
    ifstream fin("transform.in");
    ofstream fout("transform.out");
    char a[10][10], b[10][10], c[10][10], d[10][10];
    int flag = 0, flag1 = 0;
    fin >> n;
    for (int i = 0; i < n; i = i + 1){
        for (int j = 0; j < n; j = j + 1){
            fin >> a[i][j];
        }
    }
    for (int i = 0; i < n; i = i + 1){
        for (int j = 0; j < n; j = j + 1){
            fin >> b[i][j];
        }
    }
    
    rotate(a);
    if (compare(a, b)){
        fout << 1 << endl;
    }else{
        rotate(a);
        if (compare(a, b)){
            fout << 2 << endl;
        }else{
            rotate(a);
            if (compare(a, b)){
                fout << 3 << endl;
            }else{
                rotate(a);
                reflect(a);
                if (compare(a, b)){
                    fout << 4 << endl;
                }else{
                    rotate(a);
                    if (compare(a, b)){
                        fout << 5 << endl;
                    }else{
                        rotate(a);
                        if (compare(a, b)){
                            fout << 5 << endl;
                        }else{
                            rotate(a);
                            if (compare(a, b)){
                                fout << 5 << endl;
                            }else{
                                rotate(a);
                                reflect(a);
                                if(compare(a, b)){
                                    fout << 6 << endl;
                                }else{
                                    fout << 7 << endl;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}










