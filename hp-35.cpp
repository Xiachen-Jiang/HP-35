/**
 * Computer Programming 2 (COMP2711, COMP8801)
 * Practical 3: HP-35
 */

#include <iostream>
#include <sstream>
#include <string>
#include <math.h>
#define pi acos(-1)

using namespace std;

class HPStack {
public:
    double pop();
    void push(double);
    double peek();
    void CLR();
    void STO(double x);
    double RCL();
    void CLX();
    void swap();
    void roll();
    void enter();

private:
    double arr[4] = {0,0,0,0};
    double memoryX;
};

double HPStack::pop() {
    double temp = arr[0];
    for(int i = 0; i < 3; i++)
    {
        arr[i] = arr[i+1];
    }
    return temp;
}

void HPStack::push(double x) {
    for(int i = 3; i > 0 ; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[0] = x;
}

double HPStack::peek() {
    return arr[0];
}
//level 3
void HPStack::CLR() {
    for(int i = 0; i < 4; i++)
    {
        arr[i] = 0;
    }
}

void HPStack::STO(double x) {
    memoryX = x;
}
double HPStack::RCL() {
    for(int i = 3; i > 0 ; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[0] = memoryX;
    return arr[0];
}

void HPStack::CLX() {
    for(int i = 0; i < 3; i++)
    {
        arr[i] = arr[i + 1];
    }
}

// level 4
void HPStack::roll() {
    double temp = arr[0];
    for(int i = 0; i < 3; i++)
    {
        arr[i] = arr[i + 1];
    }
    arr[3] = temp;
}

void HPStack::swap() {
    double temp = arr[0];
    arr[0] = arr[1];
    arr[1] = temp;
}

void HPStack::enter() {
    for(int i = 2; i >= 0; i--)
    {
        arr[i + 1] = arr[i];
    };
}

int main(int argc, char* argv[]) {
    HPStack stack;
    string line;
    while (getline(cin, line)) {
        stringstream expression(line);
        string token;
        while (expression >> token) {
            //level 1
            if (isdigit(token[0])) {
                stack.push(atof(token.data()));
            } else if (token == "pi" || token == "PI") {
                stack.push(pi);
            } else if (token == "+") { // similar for other arithmetic ops
                double x = stack.pop();
                double y = stack.pop();
                stack.push(y + x);
            } else if (token == "-") { // similar for other arithmetic ops
                double x = stack.pop();
                double y = stack.pop();
                stack.push(y - x);
            } else if (token == "/") { // similar for other arithmetic ops
                double x = stack.pop();
                double y = stack.pop();
                stack.push(y / x);
            } else if (token == "*") { // similar for other arithmetic ops
                double x = stack.pop();
                double y = stack.pop();
                stack.push(y * x);
            }

                //level 2
            else if (token == "sqrt") { // similar for other arithmetic ops
                double x = stack.pop();
                stack.push(sqrt(x));
            } else if (token == "log" || token == "LOG") { // similar for other arithmetic ops
                double x = stack.pop();
                stack.push(log10(x));
            } else if (token == "ln" || token == "LN") { // similar for other arithmetic ops
                double x = stack.pop();
                stack.push(log(x));
            } else if (token == "chs" || token == "CHS") { // similar for other arithmetic ops
                double x = stack.pop();
                stack.push(x * (-1));
            } else if (token == "recip" || token == "RECIP") { // similar for other arithmetic ops
                double x = stack.pop();
                stack.push(1 / x);
            } else if (token == "sin" || token == "SIN") { // similar for other arithmetic ops
                double x = stack.pop();
                stack.push(sin(x));
            } else if (token == "cos" || token == "COS") { // similar for other arithmetic ops
                double x = stack.pop();
                stack.push(cos(x));
            } else if (token == "tan" || token == "TAN") { // similar for other arithmetic ops
                double x = stack.pop();
                stack.push(tan(x));
            } else if (token == "arcsin" || token == "ARCSIN") { // similar for other arithmetic ops
                double x = stack.pop();
                stack.push(asin(x));
            } else if (token == "arccos" || token == "ARCCOS") { // similar for other arithmetic ops
                double x = stack.pop();
                stack.push(acos(x));
            } else if (token == "arctan" || token == "ARCTAN") { // similar for other arithmetic ops
                double x = stack.pop();
                stack.push(atan(x));
            } else if (token == "pow" || token == "POW") { // similar for other arithmetic ops
                double x = stack.pop();
                double y = stack.pop();
                stack.push(pow(x, y));
            } else if (token == "exp" || token == "EXP") { // similar for other arithmetic ops
                double x = stack.pop();
                stack.push(exp(x));
            }

                //level 3
            else if (token == "sto" || token == "STO") { // similar for other arithmetic ops
                double x = stack.peek();
                stack.STO(x);
            } else if (token == "rcl" || token == "RCL") { // similar for other arithmetic ops
                stack.RCL();
            } else if (token == "clr" || token == "CLR") { // similar for other arithmetic ops
                stack.CLR();
            } else if (token == "clx" || token == "CLX") { // similar for other arithmetic ops
                stack.CLX();
            }

                //level 4
            else if (token == "swap" || token == "SWAP") { // similar for other arithmetic ops
                stack.swap();
            } else if (token == "roll" || token == "ROLL") { // similar for other arithmetic ops
                stack.roll();
            } else if (token == "enter" || token == "ENTER") { // similar for other arithmetic ops
                stack.enter();
            }
        }
            cout << stack.peek() << endl;
        }
        return 0;
    }

