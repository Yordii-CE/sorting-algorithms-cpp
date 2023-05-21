#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>


void countingSort(std::vector<int>& numeros) {
    int maximo = *std::max_element(numeros.begin(), numeros.end());
    int minimo = *std::min_element(numeros.begin(), numeros.end());
    int rango = maximo - minimo + 1;

    std::vector<int> contador(rango, 0);
    std::vector<int> resultado(numeros.size());

    for (int i = 0; i < numeros.size(); i++) {
        contador[numeros[i] - minimo]++;
    }

    for (int i = 1; i < rango; i++) {
        contador[i] += contador[i - 1];
    }

    for (int i = numeros.size() - 1; i >= 0; i--) {
        resultado[contador[numeros[i] - minimo] - 1] = numeros[i];
        contador[numeros[i] - minimo]--;
    }

    numeros = resultado;
}

void ordenarNumerosEnArchivo(const std::string& ruta_archivo) {
    std::vector<int> numeros;
    std::ifstream archivo_lectura(ruta_archivo);
    int numero;
    while (archivo_lectura >> numero) {
        numeros.push_back(numero);
    }
    archivo_lectura.close();

    countingSort(numeros);

    std::ofstream archivo_escritura(ruta_archivo);
    for (int numero : numeros) {
        archivo_escritura << numero << std::endl;
    }
    archivo_escritura.close();
}

int main() {
    std::string ruta = "100.txt";
    ordenarNumerosEnArchivo(ruta);
    std::cout << "Los numeros han sido ordenados utilizando Counting Sort y guardados nuevamente en el archivo." << std::endl;
    return 0;
}
