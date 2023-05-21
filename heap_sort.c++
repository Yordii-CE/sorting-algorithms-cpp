#include <iostream>
#include <fstream>
#include <vector>

void heapify(std::vector<int>& numeros, int n, int i) {
    int mayor = i;
    int izquierda = 2 * i + 1;
    int derecha = 2 * i + 2;

    if (izquierda < n && numeros[izquierda] > numeros[mayor]) {
        mayor = izquierda;
    }

    if (derecha < n && numeros[derecha] > numeros[mayor]) {
        mayor = derecha;
    }

    if (mayor != i) {
        std::swap(numeros[i], numeros[mayor]);
        heapify(numeros, n, mayor);
    }
}

void heapSort(std::vector<int>& numeros) {
    int n = numeros.size();

    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(numeros, n, i);
    }

    for (int i = n - 1; i >= 0; i--) {
        std::swap(numeros[0], numeros[i]);
        heapify(numeros, i, 0);
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

    heapSort(numeros);

    std::ofstream archivo_escritura(ruta_archivo);
    for (int numero : numeros) {
        archivo_escritura << numero << std::endl;
    }
    archivo_escritura.close();
}

int main() {
    std::string ruta = "100.txt";
    ordenarNumerosEnArchivo(ruta);
    std::cout << "Los numeros han sido ordenados utilizando Heap Sort y guardados nuevamente en el archivo." << std::endl;
    return 0;
}
