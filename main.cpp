//Arkhilaev MM IU8-13 на "Удовлетворительно"
#include <iostream>
#include <stack>
#include <cmath>
struct define{
    char type;
    double value;
};
int priority( char deistv){
    if (deistv == '+' or deistv == '-') return 0;
    if (deistv == '*' or deistv == '/') return 1;

}
void calculate(std::stack <define>& stek1, std::stack <define>& stek2,define& elem){
    double number1  = stek1.top().value;
    stek1.pop();
    double result;
    switch (stek2.top().type) {
        case '+':
        {double number2  = stek1.top().value;
            stek1.pop();
            result = number1+number2;
            elem.type='0';
            elem.value=result;
            stek1.push(elem);
            stek2.pop();
            break;}
        case '-':{
            double number2  = stek1.top().value;
            stek1.pop();
            result = number2-number1;
            elem.type='0';
            elem.value=result;
            stek1.push(elem);
            stek2.pop();
            break;}
       case '*':{
           double number2  = stek1.top().value;
           stek1.pop();
           result = number1*number2;
           elem.type='0';
           elem.value=result;
           stek1.push(elem);
           stek2.pop();
           break;}
        case '/':
            double number2  = stek1.top().value;
            stek1.pop();
            if (number2 == 0){
                std::cout << "err: division by 0";
            }
            result = number2/number1;
            elem.type='0';
            elem.value=result;
            stek1.push(elem);
            stek2.pop();
            break;
//        case '^': result = pow( number2 , number1 );
    }
}
int main(){
    std::stack<define> stek1;
    std::stack<define> stek2;
    define otric;
    otric.value=0;
    otric.type='+';
    stek1.push(otric);
    define elem;
    char ch;
    while (1>0) {
        ch = std::cin.peek();
        if (ch == '\n'){
            break;
        }
        if (ch >= '0' && ch <= '9') {
            std::cin >> elem.value;
            elem.type = 0;
            stek1.push(elem);
            continue;
        }
        if (ch == '*' or ch == '-' or ch == '/' or ch == '+') {
            if (stek2.size() == 0) {
                elem.type = ch;
                elem.value = 0;
                stek2.push(elem);
                std::cin.ignore();
                continue;
            }
            if (stek2.size() != 0 and priority(ch) > priority(stek2.top().type)){
                elem.type = ch;
                elem.value = 0;
                stek2.push(elem);
                std::cin.ignore();
                continue;
            }
            if (stek2.size() != 0 and priority(ch) <= priority(stek2.top().type)){
                calculate( stek1, stek2, elem);
                continue;
            }
        }
    }
    while (stek2.size() != 0) calculate( stek1, stek2, elem);
    std::cout << "result: " << stek1.top().value << std ::endl;
}