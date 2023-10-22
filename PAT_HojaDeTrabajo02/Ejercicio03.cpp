#include "Ejercicio03.h"
#include <stack>
#include <string>


int Ejercicio03::calculate(string s)
{
    if (s.length() == 0) {
		return 0;
	}

	std::stack<int> pila;
	char op = '+';
	const char* ch = s.c_str(); //no permite modificar el contenido de la cadena

    for (int i = 0; i < strlen(ch); i++) { 
        
        if (isdigit(ch[i])) {
            int num = 0; //daba error si no era 0
            num = std::stoi(s.substr(i));
            while (isdigit(s[i])) {
                i++;
            }
            i--; // Retroceder el índice 

            if (op == '+') {
                pila.push(num);
            }
            else if (op == '-') {
                pila.push(-num);
            }
            else if (op == '*') {
                int temp = pila.top();
                pila.pop();
                pila.push(temp * num);
            }
            else if (op == '/') {
                int temp = pila.top();
                pila.pop();
                pila.push(temp / num);
            }
        }
        else if (ch[i] == '+' || ch[i] == '-' || ch[i] == '*' || ch[i] == '/') {
            op = ch[i];
        }
    }

    int resultado = 0;
    while (!pila.empty()) {
        resultado += pila.top();
        pila.pop();
    }

    return resultado;
    
}
