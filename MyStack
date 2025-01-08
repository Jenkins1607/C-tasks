//6.6.Реализовать собственный класс - шаблон контейнер :
//стек. Класс
//должен содержать функционал близкий к STL.


#include <iostream>
#include <locale>
#include <codecvt>
#include <windows.h>
using namespace std;


// Так называемая ячейка стека
template <typename T>
class comp {
public:
    T Data; // Данные элемента
    comp* next; // Указатель на следующий элемент

    comp(T data) : Data(data), next(nullptr) {} // Конструктор узла
};

// Класс для стека
template <typename T>
class Stack {
private:
    comp<T>* top; // Указатель на вершину стека

public:
    // Конструктор
    Stack() : top(nullptr) {}

    // Деструктор
    ~Stack() {
        while (top) {
            s_delete(); // Удаляем все элементы при уничтожении стека
        }
    }

    // Функция добавления элемента в стек
    void s_push(T D) {
        comp<T>* q = new comp<T>(D); // Новый элемент
        q->next = top; // Новый элемент указывает на текущую вершину
        top = q; // Вершиной стека будет новый элемент
    }

    // Функция удаления верхнего элемента из стека
    void s_delete() {
        if (top) {
            comp<T>* temp = top; // Сохраняем указатель на верхний элемент
            top = top->next; // Обновляем вершину стека
            delete temp; // Очищаем память
        }
    }

    // Функция удаления элемента из стека по значению
    void s_delete_key(T N) {
        comp<T>* q = top; // Ставим указатель q на верх стека
        comp<T>* prev = nullptr; // Указатель на предыдущий элемент
        while (q != nullptr) {
            if (q->Data == N) {
                if (q == top) {
                    top = q->next; // Обновляем вершину стека
                }
                else {
                    prev->next = q->next; // Пропускаем элемент q, удаляя его
                }
                delete q; // Очищаем ячейку
                return; // Завершаем выполнение после удаления
            }
            prev = q; // Запоминаем текущую ячейку как предыдущую
            q = q->next; // Перемещаем указатель q на следующий элемент
        }
    }

    // Метод для печати элементов стека
    void s_print() const {
        comp<T>* q = top;
        while (q) {
            printf("%d ", q->Data);
            q = q->next;
        }
        printf("\n");
    }
};

int main() {

    //установка локали
    setlocale(LC_ALL, "Russian");

    //установка кодировки консоли на UTF-8
    SetConsoleOutputCP(CP_UTF8);

    Stack<int> stack; // Создаем стек для хранения целых чисел
    stack.s_push(1);
    stack.s_push(2);
    stack.s_push(3);
    stack.s_push(4);
    stack.s_push(5);

    cout << "Стек: ";
    stack.s_print(); // Печатаем стек

    cout << "удаление элемента 4: ";
    stack.s_delete_key(4); // Удаляем элемент со значением 4
    stack.s_print();
    cout << endl;

    cout << "удаление элемента 2: ";
    stack.s_delete_key(2);
    stack.s_print();

    cout << endl;

    cout << "добавление элемента 123: ";
    stack.s_push(123);
    stack.s_print();

    cout << endl;

    cout << "Стек после проведенных операций: ";
    stack.s_print(); // Печатаем стек после удаления

    return 0; // Возвращаем значение
}
