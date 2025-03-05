//бинарный поиск
#include <iostream>
using namespace std;

struct Calculate
{   
    int index;
    int iterations;
};





Calculate binarySearch(int array[], int x, int size) {    
    Calculate result;
    result.index = -1;
    result.iterations = 0;

    int L = 0; //левая граница
    int R = size - 1; //правая граница
    int mid;

    while (L <= R) {

    mid = (L + R) / 2; //середина
    result.iterations++;
    if (array[mid] < x) {
    
        L = mid + 1;
        
    
    } else if (array[mid] > x){
        
        R = mid - 1;
        
    
    } else {
        result.index = mid;
        return result;
        
    }




    } return result; //если индекс равен -1 (число не найдено)

}


int main() {
    
    int size;
    cout << "Введите размер массива: ";
    cin >> size;

    int array [size];

    cout << "Введите элементы массива один за другим через пробел: ";
    for (int i = 0; i < size; i++) {
        cin >> array[i];
    }

    cout << endl;

    cout << "Ваш массив: ";
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }

    cout << endl;
    int x;//искомое число
    cout << "Введите число которое хотите найти: ";
    cin >> x;

    Calculate result = binarySearch(array, x, size);

    if (result.index == -1) {
        cout << "Искомое число не существует в заданном массиве!"<< endl;
    } else {
        cout << "Число " << x << " найдено в заданном массиве за " << result.iterations << " итераций"<< endl;
    }


   return 0; 
}
