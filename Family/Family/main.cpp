//
//  main.cpp
//  Family
//
//  Created by Jerry Cheng on 5/1/18.
//  Copyright © 2018 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;

int n, layer = 0, depth = 0, tempdepth;
string a[2][100], start;

void search(string current, string target, int d, int currentlayer){
    if (d > currentlayer){
        return;
    }
    if (current == target){
        //fout << current << endl;
        tempdepth = d;
        return;
    }
    
    for (int i = 0; i < n; i++){
        if (a[0][i] == current && a[1][i] != start){
            search(a[1][i], target, d + 1, currentlayer);
        }
    }
    return;
}

void direct_search(string current, string target, int d){
    tempdepth = 0;
    start = current;
    search(current, target, 0, d);
    if (current == target){
        layer = d;
        return;
    }else if (tempdepth > 0){
        //fout << current << ' ' << target << ' ' << d << endl;
        layer = d;
        depth = tempdepth;
        return;
    }
    
    for (int i = 0; i < n; i++){
        if (a[1][i] == current){
            direct_search(a[0][i], target, d + 1);
        }
    }
}

int main(){
    ifstream fin("family.in");
    ofstream fout("family.out");
    fin >> n;
    string cowa, cowb;
    fin >> cowa >> cowb;
    for (int i = 0; i < n; i++){
        fin >> a[0][i] >> a[1][i];
    }
    
    bool found = false;
    layer = 0;
    depth = 0;
    direct_search(cowa, cowb, 0);
    if (layer != 0){
        found = true;
        if (depth == 0){
            fout << cowb << " is the ";
            if (layer == 1){
                fout << "mother of " << cowa;
            }else{
                while (layer >= 3){
                    layer--;
                    fout << "great-";
                }
                fout << "grand-mother of " << cowa;
            }
        }else if (depth == 1){
            if (layer == 1){
                fout << "SIBLINGS";
            }else{
                fout << cowb << " is the ";
                while (layer >= 3){
                    layer--;
                    fout << "great-";
                }
                fout << "aunt of " << cowa;
            }
        }else{
            fout << "COUSINS";
        }
    }
    
    layer = 0;
    depth = 0;
    direct_search(cowb, cowa, 0);
    //fout << layer << endl;
    if (!found){
        if (layer != 0){
            found = true;
            if (depth == 0){
                fout << cowa << " is the ";
                if (layer == 1){
                    fout << "mother of " << cowb;
                }else{
                    while (layer >= 3){
                        layer--;
                        fout << "great-";
                    }
                    fout << "grand-mother of " << cowb;
                }
            }else if (depth == 1){
                if (layer == 1){
                    fout << "SIBLINGS";
                }else{
                    fout << cowa << " is the ";
                    while (layer >= 3){
                        layer--;
                        fout << "great-";
                    }
                    fout << "aunt of " << cowb;
                }
            }else{
                fout << "COUSINS";
            }
        }
    }
    if (found){
        fout << endl;
    }else{
        fout << "NOT RELATED" << endl;
    }
    return 0;
}
/*
 6 AA BB
 MOTHER AA
 MOTHER SISTER
 GMOTHER MOTHER
 GMOTHER AUNT
 AUNT COUSIN
 BB GMOTHER
*/






