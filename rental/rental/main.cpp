//
//  main.cpp
//  rental
//
//  Created by Jerry Cheng on 8/4/20.
//  Copyright © 2020 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

struct store{
    int price, amt;
};

bool compare(store a, store b){
    return a.price > b.price;
}

bool c(int a, int b){
    return a > b;
}

int main() {
    ifstream fin("rental.in");
    ofstream fout("rental.out");
    int n, m, r;
    fin >> n >> m >> r;
    int cows[100000], farmers[100000];
    store stores[100000];
    for (int i = 0; i < n; i++){
        fin >> cows[i];
    }
    sort(cows, cows + n);
    for (int i = 0; i < m; i++){
        fin >> stores[i].amt >> stores[i].price;
    }
    sort(stores, stores + m, compare);
    for (int i = 0; i < r; i++){
        fin >> farmers[i];
    }
    sort(farmers, farmers + r, c);
    
    int milkProduced = 0, cowsRented;
    if (r > n){
        cowsRented = n;
        milkProduced = 0;
    }else{
        cowsRented = r;
        for (int i = cowsRented; i < n; i++){
            milkProduced = milkProduced + cows[i];
        }
    }
    long long money = 0, largest;
    for (int i = 0; i < n && i < r; i++){
        money = money + farmers[i];
    }
    int j = 0, excess;
    while (j < m && milkProduced - stores[j].amt > 0){
        money = money + stores[j].price * stores[j].amt;
        milkProduced = milkProduced - stores[j].amt;
        j++;
    }
    money = money + milkProduced * stores[j].price;
    excess = stores[j].amt - milkProduced;
    largest = money;

    //cout << money << endl;
    for (int i = cowsRented - 1; i >= 0; i--){
        money = money - farmers[i];
        milkProduced = cows[i];
        if (milkProduced > excess){
            money = money + excess * stores[j].price;
            milkProduced = milkProduced - excess;
            j++;
        }else{
            money = money + milkProduced * stores[j].price;
            milkProduced = 0;
        }
        //cout << money << endl;
        while (j < m && milkProduced - stores[j].amt > 0){
            money = money + stores[j].price * stores[j].amt;
            milkProduced = milkProduced - stores[j].amt;
            j++;
        }
        money = money + milkProduced * stores[j].price;
        excess = stores[j].amt - milkProduced;
        //cout << money << endl;
        if (money > largest){
            largest = money;
        }
        if (j >= m){
            break;
        }
    }
    fout << largest << endl;
    return 0;
}
