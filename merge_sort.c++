#include <iostream>
#include <fstream>
#include <vector>

void merge(std::vector<int>& numeros, int inicio, int medio, int fin) {
    int n1 = medio - inicio + 1;
    int n2 = fin - medio;

    std::vector<int> izquierda(n1);
    std::vector<int> derecha(n2);

    for (int i = 0; i < n1; i++) {
        izquierda[i] = numeros[inicio + i];
    }

    for (int j = 0; j < n2; j++) {
        derecha[j] = numeros[medio + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = inicio;

    while (i < n1 && j < n2) {
        if (izquierda[i] <= derecha[j]) {
            numeros[k] = izquierda[i];
            i++;
        } else {
            numeros[k] = derecha[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        numeros[k] = izquierda[i];
        i++;
        k++;
    }

    while (j < n2) {
        numeros[k] = derecha[j];
        j++;
        k++;
    }
}

void mergeSort(std::vector<int>& numeros, int inicio, int fin) {
    if (inicio < fin) {
        int medio = inicio + (fin - inicio) / 2;
        mergeSort(numeros, inicio, medio);
        mergeSort(numeros, medio + 1, fin);
        merge(numeros, inicio, medio, fin);
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

    mergeSort(numeros, 0, numeros.size() - 1);

    std::ofstream archivo_escritura(ruta_archivo);
    for (int numero : numeros) {
        archivo_escritura << numero << std::endl;
    }
    archivo_escritura.close();
}

int main() {
    std::string ruta = "100.txt";
    ordenarNumerosEnArchivo(ruta);
    std::cout << "Los numeros han sido ordenados utilizando Merge Sort y guardados nuevamente en el archivo." << std::endl;
    return 0;
}
