//Класс-шаблон "Очередь"

#include <iostream>
#include <stdexcept>
#include <vector>
#include <locale>
#include <codecvt>
#include <windows.h>
using namespace std;



template <typename T>
class Queue {

    private:
        vector<T> data; //вектор для хранения элементов
        size_t front; //индекс первого элемента очереди
        size_t back; //индекс последнего элемента
        size_t count; //количество эл-тов в очереди

    public:
        Queue() : front(0), back(0), count(0) {
            data.resize(1);
        }

    //Добавление элемента в очередь
    void enqueue(const T& value) {
        if (count == data.size()) {
            vector<T> newData(data.size() * 2);//увеличиваем размер вектора

            for (size_t i = 0; i < count; ++i) {
                newData[i] = data[(front + i) % data.size()];
            }
            data = move(newData);
            front = 0;
            back = count;
        }

        data[back] = value;
        back = (back + 1) % data.size(); //циклический переход

        count++;
    }




    //Извлечение элемента из очереди
    T dequeue() {
        if (isEmpty()) {
            throw out_of_range("Очередь пуста.");
        }

        T value = data[front];
        front = (front + 1) % data.size();
        count--;

        return value;
    }

    //Проверка на пустоту
    bool isEmpty() const {
        return count == 0; //если count равень нулю - очередь пуста
    }

    //получение размера очереди
    size_t size() const {
        return count;
    }

    //Получение переднего элемента без удаления
    T peek() const {
        if (isEmpty()) {
            throw out_of_range("Очередь пуста");
        }
        return data[front];
    }

};


int main() {
    //установка локали
    setlocale(LC_ALL, "Russian");

    //установка кодировки консоли на UTF-8
    SetConsoleOutputCP(CP_UTF8);


    Queue<int> q;

    q.enqueue(123);
    q.enqueue(5235);
    q.enqueue(123123);

    cout << "Передний элемент: " << q.peek() << endl;
    cout << "Размер очереди: " << q.size() << endl;

    while (!q.isEmpty())
    {
        cout << "Извлечённый элемент: " << q.dequeue() << endl;
    }


    return 0;
}
