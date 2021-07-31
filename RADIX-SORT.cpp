
#include <iostream>
using namespace std;

// Una función de utilidad para obtener el valor máximo en arr []
int getMax(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

// Una función para contar una especie de arr [] según
// el dígito representado por exp.
void countSort(int arr[], int n, int exp)
{
    int output[n]; // matriz de salida
    int i, count[10] = { 0 };

    // Almacenar el recuento de ocurrencias en el recuento []
    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    // Cambie el recuento [i] para que el recuento [i] ahora contenga datos reales
    // posición de este dígito en la salida []
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Construye la matriz de salida
    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copia la matriz de salida en arr [], de modo que arr [] ahora
    // contiene números ordenados según el dígito actual
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}

// La función principal que ordena arr [] de tamaño n usando
// Ordenar por radix
void radixsort(int arr[], int n)
{
    // Encuentra el número máximo para saber el número de dígitos
    int m = getMax(arr, n);

    // Ordenar contando para cada dígito. Tenga en cuenta que en su lugar
    // del número de dígito que pasa, se pasa exp. exp es 10 ^ i
    // donde i es el número de dígito actual
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}

// Una función de utilidad para imprimir una matriz
void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

// Código del conductor
int main()
{
    int arr[] = { 129, 34, 55, 96, 82, 240, 2, 62, 100, 9 };
    int n = sizeof(arr) / sizeof(arr[0]);

// Llamada de función
      radixsort(arr, n);
    print(arr, n);
    return 0;
}

