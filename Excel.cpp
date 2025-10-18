#include <string>
using namespace std;

class Solution {
public:
    int titleToNumber(string titulo) {
        int numero = 0;

        for (char letra : titulo) {
            int valor = letra - 'A' + 1; 
            numero = numero * 26 + valor;
        }

        return numero;
    }
};

