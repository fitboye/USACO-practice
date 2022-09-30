//
//  main.cpp
//  66
//
//  Created by Jerry Cheng on 8/22/20.
//  Copyright © 2020 Jerry Cheng. All rights reserved.
//

#include <iostream>
#include <stack>
using namespace std;

stack<char> operators;
stack<int> operands;

void operation (char newOperator){
    int a;
    if (operators.top() != '('){
        if (newOperator == '+' || newOperator == '-' || newOperator == 'a'){
            if (operators.top() == '+'){
                a = operands.top();
                operands.pop();
                a = a + operands.top();
                operands.pop();
                operators.pop();
                operands.push(a);
            }else if (operators.top() == '-'){
                a = operands.top();
                operands.pop();
                a = operands.top() - a;
                operands.pop();
                operators.pop();
                operands.push(a);
            }else{
                a = operands.top();
                operands.pop();
                a = a * operands.top();
                operands.pop();
                operators.pop();
                operands.push(a);
            }
        }else if (operators.top() == '*'){
            a = operands.top();
            operands.pop();
            a = a * operands.top();
            operands.pop();
            operators.pop();
            operands.push(a);
        }
    }
    operators.push(newOperator);
}

int main() {
    string s;
    cin >> s;
    
    int left = 0;
    for (int i = 0; i < s.length(); i++){
        if (int(s[i]) >= int('0') && int(s[i]) <= int('9')){
            char x[10];
            int j = 0;
            while (i < s.length() && int(s[i]) >= int('0') && int(s[i]) <= int('9')){
                x[j] = s[i];
                i++;
                j++;
            }
            i--;
            
            int z = 0, multiplier = 1;
            for (int k = j - 1; k >= 0; k--){
                z = z + multiplier * (int(x[k]) - int('0'));
                multiplier = multiplier * 10;
            }
            operands.push(z);
        }else{
            char y = s[i];
            if (y == '('){
                operators.push('(');
                left++;
            }else if (y == ')'){
                char y = 'a';
                while(operators.top() != '('){
                    operation(y);
                    y = operators.top();
                    operators.pop();
                }
                operators.pop();
                left--;
            }else{
                if (!operators.empty()){
                    //operation(y);
                    if (y == '+'){
                        while(!operators.empty() && operators.top() != '('){
                            operation(y);
                            y = operators.top();
                            operators.pop();
                        }
                    }else{
                        while(!operators.empty() && operators.top() == '*'){
                            operation(y);
                            y = operators.top();
                            operators.pop();
                        }
                    }
                }else{
                    operators.push(y);
                }
            }
        }
    }
    cout << 'a' << endl;
    while(!operators.empty()){
        cout << operators.top() << ' ';
        operators.pop();
    }
    cout << endl;
    while(!operands.empty()){
        cout << operands.top() << ' ';
        operands.pop();
    }
    cout << endl;

    char y = 'a';
    while(!operators.empty()){
        operation(y);
        y = operators.top();
        operators.pop();
    }
    cout << operands.top() << endl;
    return 0;
}
//(30-1)*(2+5)*2
// 12+(30-1)*(2+5)*2-9*(3+11)
