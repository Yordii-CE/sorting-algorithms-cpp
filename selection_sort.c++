#include <iostream>
#include <fstream>
#include <vector>

void selectionSort(std::vector<int>& numeros) {
    int n = numeros.size();

    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;

        for (int j = i + 1; j < n; j++) {
            if (numeros[j] < numeros[min_idx]) {
                min_idx = j;
            }
        }

        std::swap(numeros[min_idx], numeros[i]);
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

    selectionSort(numeros);

    std::ofstream archivo_escritura(ruta_archivo);
    for (int numero : numeros) {
        archivo_escritura << numero << std::endl;
    }
    archivo_escritura.close();
}

int main() {
    std::string ruta = "../numbers/100.txt";
    ordenarNumerosEnArchivo(ruta);
    std::cout << "Los numeros han sido ordenados utilizando Selection Sort y guardados nuevamente en el archivo." << std::endl;
    return 0;
}
