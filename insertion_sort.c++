#include <iostream>
#include <fstream>
#include <vector>

void insertionSort(std::vector<int>& numeros) {
    int n = numeros.size();
    for (int i = 1; i < n; i++) {
        int clave = numeros[i];
        int j = i - 1;

        while (j >= 0 && numeros[j] > clave) {
            numeros[j + 1] = numeros[j];
            j = j - 1;
        }
        
        numeros[j + 1] = clave;
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

    insertionSort(numeros);

    std::ofstream archivo_escritura(ruta_archivo);
    for (int numero : numeros) {
        archivo_escritura << numero << std::endl;
    }
    archivo_escritura.close();
}

int main() {
    std::string ruta = "100.txt";
    ordenarNumerosEnArchivo(ruta);
    std::cout << "Los numeros han sido ordenados utilizando Insertion Sort y guardados nuevamente en el archivo." << std::endl;
    return 0;
}
