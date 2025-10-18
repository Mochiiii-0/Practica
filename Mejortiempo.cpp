#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& precios) {
        int precioMinimo = precios[0];
        int gananciaMaxima = 0;

        for (int i = 1; i < precios.size(); i++) {
            // si encontamos un precio menor, actualizamos el minimo
            if (precios[i] < precioMinimo)
                precioMinimo = precios[i];
            // si no calculamos la ganancia posible y la compramos con la maxima
            else
                gananciaMaxima = max(gananciaMaxima, precios[i] - precioMinimo);
        }

        return gananciaMaxima;
    }
};
