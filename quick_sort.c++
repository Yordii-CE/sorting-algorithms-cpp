#include <iostream>
#include <fstream>
#include <vector>

int partition(std::vector<int>& numeros, int inicio, int fin) {
    int pivot = numeros[fin];
    int i = inicio - 1;

    for (int j = inicio; j <= fin - 1; j++) {
        if (numeros[j] <= pivot) {
            i++;
            std::swap(numeros[i], numeros[j]);
        }
    }

    std::swap(numeros[i + 1], numeros[fin]);
    return i + 1;
}

void quickSort(std::vector<int>& numeros, int inicio, int fin) {
    if (inicio < fin) {
        int pivot_index = partition(numeros, inicio, fin);
        quickSort(numeros, inicio, pivot_index - 1);
        quickSort(numeros, pivot_index + 1, fin);
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

    quickSort(numeros, 0, numeros.size() - 1);

    std::ofstream archivo_escritura(ruta_archivo);
    for (int numero : numeros) {
        archivo_escritura << numero << std::endl;
    }
    archivo_escritura.close();
}

int main() {
    std::string ruta = "100.txt";
    ordenarNumerosEnArchivo(ruta);
    std::cout << "Los numeros han sido ordenados utilizando Quick Sort y guardados nuevamente en el archivo." << std::endl;
    return 0;
}
