#include <iostream>
#include <fstream>
#include <vector>

void bubbleSort(std::vector<int>& numeros) {
    int n = numeros.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (numeros[j] > numeros[j + 1]) {
                std::swap(numeros[j], numeros[j + 1]);
            }
        }
    }
}

void ordenarNumerosEnArchivo(const std::string& ruta_archivo) {
    std::vector<int> numeros;
    std::ifstream archivo_lectura(ruta_archivo);
    int numero;
    while (archivo_lectura >> numero) {
        numeros.push_back(numero);
    }
    archivo_lectura.close();

    bubbleSort(numeros);

    std::ofstream archivo_escritura(ruta_archivo);
    for (int numero : numeros) {
        archivo_escritura << numero << std::endl;
    }
    archivo_escritura.close();
}

int main() {
    std::string ruta = "100.txt";
    ordenarNumerosEnArchivo(ruta);
    std::cout << "Los numeros han sido ordenados y guardados nuevamente en el archivo." << std::endl;
    return 0;
}
