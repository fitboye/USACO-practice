//
//  main.cpp
//  Tic Tac Toe
//
//  Created by Jerry Cheng on 3/26/18.
//  Copyright © 2018 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;
int main() {
    ifstream fin ("tttt.in");
    ofstream fout ("tttt.out");
    int x = 0, y = 0, flag = 0, bnumber = 0, cnumber = 0;
    char a[3][3], b[9], c[2][9];
    for (int i = 0; i < 3; i = i + 1){
        for (int j = 0; j < 3; j = j + 1){
            fin >> a[i][j];
        }
    }
    
    for (int i = 0; i < 3; i = i + 1){
        if ((a[i][0] == a[i][1]) && (a[i][1] == a[i][2])){
            flag = 0;
            for (int j = 0; j < bnumber; j = j + 1){
                if (a[i][0] == b[j]){
                    flag = 1;
                }
            }
            if (flag == 0){
                x = x + 1;
                b[bnumber] = a[i][0];
                bnumber++;
            }
        }else{
            if (a[i][0] == a[i][1]){
                flag = 0;
                for (int j = 0; j < cnumber; j = j + 1){
                    if ((a[i][0] == c[0][j]) && (a[i][2] == c[1][j])){
                        flag = 1;
                    }else if ((a[i][0] == c[1][j]) && (a[i][2] == c[0][j])){
                        flag = 1;
                    }
                }
                if (flag == 0){
                    y = y + 1;
                    c[0][cnumber] = a[i][0];
                    c[1][cnumber] = a[i][2];
                    cnumber++;
                }
            }else if (a[i][1] == a[i][2]){
                    flag = 0;
                    for (int j = 0; j < cnumber; j = j + 1){
                        if ((a[i][0] == c[0][j]) && (a[i][2] == c[1][j])){
                            flag = 1;
                        }else if ((a[i][0] == c[1][j]) && (a[i][2] == c[0][j])){
                            flag = 1;
                        }
                    }
                    if (flag == 0){
                        y = y + 1;
                        c[0][cnumber] = a[i][0];
                        c[1][cnumber] = a[i][2];
                        cnumber++;
                    }
            }else if (a[i][0] == a[i][2]){
                flag = 0;
                for (int j = 0; j < cnumber; j = j + 1){
                    if ((a[i][0] == c[0][j]) && (a[i][1] == c[1][j])){
                        flag = 1;
                    }else if ((a[i][0] == c[1][j]) && (a[i][1] == c[0][j])){
                        flag = 1;
                    }
                }
                if (flag == 0){
                    y = y + 1;
                    c[0][cnumber] = a[i][0];
                    c[1][cnumber] = a[i][1];
                    cnumber++;
                }
            }
        }
        
        if ((a[0][i] == a[1][i]) && (a[1][i] == a[2][i])){
            flag = 0;
            for (int j = 0; j < bnumber; j = j + 1){
                if (a[0][i] == b[j]){
                    flag = 1;
                }
            }
            if (flag == 0){
                x = x + 1;
                b[bnumber] = a[0][i];
                bnumber++;
            }
        }else{
            if (a[0][i] == a[1][i]){
                flag = 0;
                for (int j = 0; j < cnumber; j = j + 1){
                    if ((a[0][i] == c[0][j]) && (a[2][i] == c[1][j])){
                        flag = 1;
                    }else if ((a[0][i] == c[1][j]) && (a[2][i] == c[0][j])){
                        flag = 1;
                    }
                }
                if (flag == 0){
                    y = y + 1;
                    c[0][cnumber] = a[0][i];
                    c[1][cnumber] = a[2][i];
                    cnumber++;
                }
            }else if (a[1][i] == a[2][i]){
                flag = 0;
                for (int j = 0; j < cnumber; j = j + 1){
                    if ((a[1][i] == c[0][j]) && (a[0][i] == c[1][j])){
                        flag = 1;
                    }else if ((a[1][i] == c[1][j]) && (a[0][i] == c[0][j])){
                        flag = 1;
                    }
                }
                if (flag == 0){
                    y = y + 1;
                    c[0][cnumber] = a[0][i];
                    c[1][cnumber] = a[2][i];
                    cnumber++;
                }
            }else if (a[0][i] == a[2][i]){
                flag = 0;
                for (int j = 0; j < cnumber; j = j + 1){
                    if ((a[0][i] == c[0][j]) && (a[1][i] == c[1][j])){
                        flag = 1;
                    }else if ((a[0][i] == c[1][j]) && (a[1][i] == c[0][j])){
                        flag = 1;
                    }
                }
                if (flag == 0){
                    y = y + 1;
                    c[0][cnumber] = a[0][i];
                    c[1][cnumber] = a[1][i];
                    cnumber++;
                }
            }
        }
    }
    
    if ((a[0][0] == a[1][1]) && (a[1][1] == a[2][2])){
        flag = 0;
        for (int j = 0; j < bnumber; j = j + 1){
            if (a[0][0] == b[j]){
                flag = 1;
            }
        }
        if (flag == 0){
            x = x + 1;
            b[bnumber] = a[0][0];
            bnumber++;
        }
    }else{
        if (a[0][0] == a[1][1]){
            flag = 0;
            for (int j = 0; j < cnumber; j = j + 1){
                if ((a[0][0] == c[0][j]) && (a[2][2] == c[1][j])){
                    flag = 1;
                }else if ((a[0][0] == c[1][j]) && (a[2][2] == c[0][j])){
                    flag = 1;
                }
            }
            if (flag == 0){
                y = y + 1;
                c[0][cnumber] = a[0][0];
                c[1][cnumber] = a[2][2];
                cnumber++;
            }
        }else if (a[1][1] == a[2][2]){
            flag = 0;
            for (int j = 0; j < cnumber; j = j + 1){
                if ((a[0][0] == c[0][j]) && (a[2][2] == c[1][j])){
                    flag = 1;
                }else if ((a[0][0] == c[1][j]) && (a[2][2] == c[0][j])){
                    flag = 1;
                }
            }
            if (flag == 0){
                y = y + 1;
                c[0][cnumber] = a[0][0];
                c[1][cnumber] = a[2][2];
                cnumber++;
            }
        }else if (a[0][0] == a[2][2]){
            flag = 0;
            for (int j = 0; j < cnumber; j = j + 1){
                if ((a[0][0] == c[0][j]) && (a[1][1] == c[1][j])){
                    flag = 1;
                }else if ((a[0][0] == c[1][j]) && (a[1][1] == c[0][j])){
                    flag = 1;
                }
            }
            if (flag == 0){
                y = y + 1;
                c[0][cnumber] = a[0][0];
                c[1][cnumber] = a[1][1];
                cnumber++;
            }
        }
    }
    
    
    if ((a[0][2] == a[1][1]) && (a[1][1] == a[2][0])){
        flag = 0;
        for (int j = 0; j < bnumber; j = j + 1){
            if (a[0][2] == b[j]){
                flag = 1;
            }
        }
        if (flag == 0){
            x = x + 1;
            b[bnumber] = a[0][2];
            bnumber++;
        }
    }else{
        if (a[0][2] == a[1][1]){
            flag = 0;
            for (int j = 0; j < cnumber; j = j + 1){
                if ((a[0][2] == c[0][j]) && (a[2][0] == c[1][j])){
                    flag = 1;
                }else if ((a[0][2] == c[1][j]) && (a[2][0] == c[0][j])){
                    flag = 1;
                }
            }
            if (flag == 0){
                y = y + 1;
                c[0][cnumber] = a[0][2];
                c[1][cnumber] = a[2][0];
                cnumber++;
            }
        }else if (a[1][1] == a[2][0]){
            flag = 0;
            for (int j = 0; j < cnumber; j = j + 1){
                if ((a[0][2] == c[0][j]) && (a[2][0] == c[1][j])){
                    flag = 1;
                }else if ((a[0][2] == c[1][j]) && (a[2][0] == c[0][j])){
                    flag = 1;
                }
            }
            if (flag == 0){
                y = y + 1;
                c[0][cnumber] = a[0][2];
                c[1][cnumber] = a[2][0];
                cnumber++;
            }
        }else if (a[0][2] == a[2][0]){
            flag = 0;
            for (int j = 0; j < cnumber; j = j + 1){
                if ((a[0][2] == c[0][j]) && (a[1][1] == c[1][j])){
                    flag = 1;
                }else if ((a[0][2] == c[1][j]) && (a[1][1] == c[0][j])){
                    flag = 1;
                }
            }
            if (flag == 0){
                y = y + 1;
                c[0][cnumber] = a[0][2];
                c[1][cnumber] = a[1][1];
                cnumber++;
            }
        }
    }
    
    fout << x << endl << y << endl;
    return 0;
}








