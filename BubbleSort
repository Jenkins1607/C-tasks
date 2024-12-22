#include <iostream>
using namespace std;

void BubbleSort(int array[], int size) {
    for (int i = 0; i < size - 1; i++){
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {

                int temp = array[j+1];
                array[j + 1] = array[j];
                array[j] = temp;
            }
        }

    }       

}


int main() {
    int size;
    cout << "Введите размер массива: ";
    cin >> size;

    int array[size];
    
    cout << endl;
    cout << "Введите элементы массива через пробел: ";
    for (int i = 0; i < size; i++) {
        cin >> array[i];
    }

    cout << endl;//отступ для красивого вывода

    cout << "Non-Sorted: " << endl;
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }

    cout << endl;//отступ для красивого вывода

    BubbleSort(array,size); //вызов функции для сортировки массива
    
    cout << "Sorted: " << endl;
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }

    return 0;
}
