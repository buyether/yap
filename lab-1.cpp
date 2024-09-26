#include <iostream>
#include <string>
#include <clocale> // Для функции setlocale()
#include <cstdlib> // Для функции rand()
#include <ctime>   // Для функции time()
#include <limits> // Для функции numeric_limits

using namespace std;

// Функции для безопасного ввода
double safeDoubleInput(const string& message) {
    double value;
    while (true) {
        cout << message;
        cin >> value;
        if (!cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Ошибка ввода! Пожалуйста, попробуйте снова." << endl;
    }
}

int safeIntInput(const string& message) {
    int value;
    while (true) {
        cout << message;
        cin >> value;
        if (!cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Ошибка ввода! Пожалуйста, попробуйте снова." << endl;
    }
}

char safeCharInput(const string& message) {
    char value;
    while (true) {
        cout << message;
        cin >> value;
        if (!cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Ошибка ввода! Пожалуйста, попробуйте снова." << endl;
    }
}

long safeLongInput(const string& message) {
    long input;
    while (true) {
        cout << message;
        if (cin >> input) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return input;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Ошибка! Пожалуйста, попробуйте снова." << endl;
    }
}

void inputArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = safeIntInput("Введите элемент массива: ");
    }
}

// Функции для задач

double fraction(double x) {
    return x - (int)x;
}

int sumLastNums(int x) {
    x = abs(x);
    int lastDigit = x % 10;
    x /= 10;
    int secondLastDigit = x % 10;

    return lastDigit + secondLastDigit;
}

int charToNum(char x) {
    // Проверяем, является ли символ цифрой от '0' до '9'
    if (x >= '0' && x <= '9') {
        return x - '0'; // Преобразуем символ в число
    }
    else {
        // Если x не является цифрой, выводим сообщение об ошибке
        cout << "Ошибка: символ '" << x << "' не является цифрой!" << endl;
        return -1; // Возвращаем -1 для обозначения ошибки
    }
}

bool isPositive(int x) {
    return x > 0; // Возвращает true, если x положительное, иначе false
}

bool is2Digits(int x) {
    // Проверяем, находится ли число в диапазоне от 10 до 99 или от -99 до -10
    return (x >= 10 && x <= 99) || (x <= -10 && x >= -99);
}

// Блок 2

bool is35(int x) {
    // Проверяем делимость на 3 или 5, но не на оба сразу
    return (x % 3 == 0 || x % 5 == 0) && !(x % 3 == 0 && x % 5 == 0);
}

string makeDecision(int x, int y) {
    // Формируем строку в зависимости от сравнения
    if (x > y) {
        return to_string(x) + " > " + to_string(y);
    }
    else if (x < y) {
        return to_string(x) + " < " + to_string(y);
    }
    else {
        return to_string(x) + " == " + to_string(y);
    }
}

int max3(int x, int y, int z) {
    // Находим максимальное число, используя всего две инструкции if
    int maxXY = (x > y) ? x : y; // Сравниваем x и y
    return (maxXY > z) ? maxXY : z; // Сравниваем результат с z
}

bool sum3(int x, int y, int z) {
    return (x + y == z) || (x + z == y) || (y + z == x);
}

string age(int x) {
    string suffix;

    // Определяем правильное окончание
    if (x % 10 == 1 && x % 100 != 11) {
        suffix = "год";
    }
    else if ((x % 10 == 2 || x % 10 == 3 || x % 10 == 4) && (x % 100 != 12 && x % 100 != 13 && x % 100 != 14)) {
        suffix = "года";
    }
    else {
        suffix = "лет";
    }

    // Формируем результат
    return to_string(x) + " " + suffix;
}

void checkAge() {
    while (true) {
        int x = safeIntInput("Введите возраст: ");
        string result = age(x);
        cout << result << endl;
        break; // Успех, выходим из цикла
    }
}

// блок 3

string reverseListNums(int x) {
    string result;
    for (int i = x; i >= 0; --i) {
        result += to_string(i) + (i > 0 ? " " : ""); // Добавляем пробел между числами
    }
    return result;
}

string chet(int x) {
    string result;
    for (int i = 0; i <= x; i += 2) {
        result += to_string(i) + " ";
    }
    return result;
}

int numLen(long x) {
    int length = 0;
    do {
        length++; // Увеличиваем длину на 1 за каждую итерацию
        x /= 10; // Убираем последнюю цифру
    } while (x > 0);
    return length;
}

bool equalNum(int x) {
    int lastDigit = x % 10; // Получаем последнюю цифру
    while (x > 0) {
        if (x % 10 != lastDigit) { // Сравниваем с последней цифрой
            return false; // Если не совпадает, возвращаем false
        }
        x /= 10; // Убираем последнюю цифру
    }
    return true; // Все цифры совпадают
}

void guessGame() {
    srand(static_cast<unsigned int>(time(0))); // Инициализация генератора случайных чисел
    int target = rand() % 10; // Генерация случайного числа от 0 до 9
    int guess;
    int attempts = 0;

    do {
        guess = safeIntInput("Введите число от 0 до 9: "); // Чтение введенного числа
        attempts++;

        if (guess == target) {
            cout << "Вы угадали!" << endl;
        }
        else {
            cout << "Вы не угадали, введите число от 0 до 9: " << endl;
        }
    } while (guess != target); // Продолжаем, пока число не угадано

    cout << "Вы отгадали число за " << attempts << " попытки(ок)." << endl;
}

// блок 4

int* add(int arr[], int size, int x, int pos) {
    // Создаем новый массив размером на 1 больше
    int* newArr = new int[size + 1];

    // Копируем элементы до позиции вставки
    for (int i = 0; i < pos; i++) {
        newArr[i] = arr[i];
    }

    // Вставляем новый элемент
    newArr[pos] = x;

    // Копируем оставшиеся элементы
    for (int i = pos; i < size; i++) {
        newArr[i + 1] = arr[i];
    }

    return newArr; // Возвращаем новый массив
}

int* add(int arr[], int arrSize, int ins[], int insSize, int pos) {
    // Создаем новый массив размером, который равен сумме исходного массива и вставляемого
    int* newArr = new int[arrSize + insSize];

    // Копируем элементы из первого массива до позиции вставки
    for (int i = 0; i < pos; i++) {
        newArr[i] = arr[i];
    }

    // Копируем элементы из второго массива
    for (int i = 0; i < insSize; i++) {
        newArr[pos + i] = ins[i];
    }

    // Копируем оставшиеся элементы из первого массива
    for (int i = pos; i < arrSize; i++) {
        newArr[i + insSize] = arr[i];
    }

    return newArr; // Возвращаем новый массив
}

void reverse(int arr[], int size) {
    int left = 0;                // Индекс с начала массива
    int right = size - 1;       // Индекс с конца массива

    // Перемещаем элементы к центру, меняя местами элементы
    while (left < right) {
        // Меняем местами элементы
        swap(arr[left], arr[right]);
        left++;                  // Увеличиваем индекс с начала
        right--;                 // Уменьшаем индекс с конца
    }
}

int* reverseBack(int arr[], int size) {
    // Создаем новый массив того же размера
    int* reversedArr = new int[size];

    // Заполняем новый массив элементами в обратном порядке
    for (int i = 0; i < size; i++) {
        reversedArr[i] = arr[size - 1 - i];
    }

    return reversedArr; // Возвращаем указатель на новый массив
}

int* concat(int arr1[], int size1, int arr2[], int size2) {
    // Создаем новый массив размером size1 + size2
    int* concatenatedArr = new int[size1 + size2];

    // Копируем элементы первого массива
    for (int i = 0; i < size1; i++) {
        concatenatedArr[i] = arr1[i];
    }

    // Копируем элементы второго массива
    for (int i = 0; i < size2; i++) {
        concatenatedArr[size1 + i] = arr2[i];
    }

    return concatenatedArr; // Возвращаем указатель на новый массив
}



// Основное меню
void mainMenu() {
    while (true) {
        cout << "--- Блок 1: Методы ---" << endl;
        cout << "[1] Рассчитать дробную часть" << endl;
        cout << "[2] Сумма последних двух цифр" << endl;
        cout << "[3] Перевод символа в число" << endl;
        cout << "[4] Является ли число положительным" << endl;
        cout << "[5] Двузначное ли число" << endl;
        cout << "--- Блок 2: Условия ---" << endl;
        cout << "[6] Делится ли число на 3 или 5" << endl;
        cout << "[7] Сравнение двух чисел" << endl;
        cout << "[8] Тройной максимум" << endl;
        cout << "[9] Тройная сумма" << endl;
        cout << "[10] Возраст" << endl;
        cout << "--- Блок 3: Циклы ---" << endl;
        cout << "[11] Числа наоборот" << endl;
        cout << "[12] Четные числа" << endl;
        cout << "[13] Длина числа" << endl;
        cout << "[14] Одинаковость цифр числа" << endl;
        cout << "[15] Угадайка" << endl;
        cout << "--- Блок 4: Массивы ---" << endl;
        cout << "[16] Добавление элемента в массив" << endl;
        cout << "[17] Добавление массива в массив" << endl;
        cout << "[18] Реверс массива" << endl;
        cout << "[19] Возвратный реверс массива" << endl;
        cout << "[20] Объединение массивов" << endl;
        cout << "--- Остальное ---" << endl;
        cout << "[0] Выход из программы" << endl;
        cout << "" << endl;

        int choice;
        cin >> choice;

        switch (choice) {
        case 1: {
            double x = safeDoubleInput("Введите дробное число: ");
            cout << "Дробная часть: " << fraction(x) << endl;
            break;
        }
        case 2: {
            int x = safeIntInput("Введите целое число (не менее двух знаков): ");
            if (x < 10 && x > -10) { // Проверяем, что число действительно двухзначное
                cout << "Ошибка: число должно содержать не менее двух цифр." << endl;
                break;
            }
            int result = sumLastNums(x);
            cout << "Сумма последних двух цифр: " << result << endl;
            break;
        }
        case 3: {
            char inputChar = safeCharInput("Введите символ (0-9): ");

            int result = charToNum(inputChar);

            // Проверяем, была ли ошибка при преобразовании
            if (result != -1) {
                cout << "Преобразованное число: " << result << endl;
            }
            break;
        }
        case 4: {
            int inputNumber = safeIntInput("Введите целое число: ");

            // Вызов функции isPositive
            if (isPositive(inputNumber)) {
                cout << "Результат: true" << endl; // Если число положительное
            }
            else {
                cout << "Результат: false" << endl; // Если число неположительное
            }
            break;
        }
        case 5: {
            int inputNumber = safeIntInput("Введите целое число: ");

            // Вызов функции is2Digits
            if (is2Digits(inputNumber)) {
                cout << "Результат: true" << endl; // Если число двузначное
            }
            else {
                cout << "Результат: false" << endl; // Если число не двузначное
            }
            break;
        }
        case 6: {
            int inputNumber = safeIntInput("Введите целое число: ");

            // Вызов функции is35
            if (is35(inputNumber)) {
                cout << "Результат: true" << endl; // Если число делится на 3 или 5, но не на оба
            }
            else {
                cout << "Результат: false" << endl; // Если число не удовлетворяет условиям
            }
            break;
        }
        case 7: {
            int x = safeIntInput("Введите первое целое число (x): ");
            int y = safeIntInput("Введите второе целое число (y): ");

            // Вызов функции makeDecision
            string result = makeDecision(x, y);
            cout << "Результат: " << result << endl;

            break;
        }
        case 8: {
            int x = safeIntInput("Введите первое целое число (x): ");
            int y = safeIntInput("Введите второе целое число (y): ");
            int z = safeIntInput("Введите третье целое число (z): ");

            // Вызов функции max3
            int result = max3(x, y, z);
            cout << "Максимальное число: " << result << endl;

            break;
        }
        case 9: {
            int x = safeIntInput("Введите первое целое число (x): ");
            int y = safeIntInput("Введите второе целое число (y): ");
            int z = safeIntInput("Введите третье целое число (z): ");

            // Вызов функции sum3
            bool result = sum3(x, y, z);
            cout << "Результат: " << (result ? "true" : "false") << endl;

            break;
        }
        case 10: {
            int x = safeIntInput("Введите возраст: ");

            // Вызов функции age
            string result = age(x);
            cout << result << endl;

            break;
        }
        case 11: {
            int x = safeIntInput("Введите число x: ");
            string result = reverseListNums(x);
            cout << result << endl;

            break;
        }
        case 12: {
            int x = safeIntInput("Введите число x: ");
            string result = chet(x);
            cout << result << endl;

            break;
        }
        case 13: {
            long x = safeLongInput("Введите число x: ");
            int length = numLen(x);
            cout << "Длина числа: " << length << endl;

            break;
        }
        case 14: {
            int x = safeIntInput("Введите число x: ");
            bool result = equalNum(x);
            cout << (result ? "Результат: true" : "Результат: false") << endl;

            break;
        }
        case 15: guessGame(); break;
        case 16: {
            int size = safeIntInput("Введите размер массива: "); // Запрашиваем размер массива
            int* arr = new int[size]; // Динамически выделяем память для массива

            cout << "Введите элементы массива:\n";
            inputArray(arr, size); // Ввод элементов массива

            int x = safeIntInput("Введите значение для вставки: "); // Запрашиваем значение для вставки
            int pos = safeIntInput("Введите позицию для вставки: "); // Позиция для вставки

            int* newArr = add(arr, size, x, pos);

            // Вывод нового массива
            cout << "Новый массив: [";
            for (int i = 0; i < size + 1; i++) {
                cout << newArr[i];
                if (i < size) {
                    cout << ", ";
                }
            }
            cout << "]" << endl;

            delete[] arr; // Освобождение памяти первого массива
            delete[] newArr; // Освобождение памяти нового массива
            break;
        }

        case 17: {
            int arrSize = safeIntInput("Введите размер первого массива: "); // Размер первого массива
            int insSize = safeIntInput("Введите размер второго массива: "); // Размер второго массива

            int* arr = new int[arrSize];
            int* ins = new int[insSize];

            cout << "Введите элементы первого массива:\n";
            inputArray(arr, arrSize); // Ввод элементов первого массива

            cout << "Введите элементы второго массива:\n";
            inputArray(ins, insSize); // Ввод элементов второго массива

            int pos = safeIntInput("Введите позицию для вставки: "); // Позиция для вставки

            int* newArr = add(arr, arrSize, ins, insSize, pos);

            // Вывод нового массива
            cout << "Новый массив: [";
            for (int i = 0; i < arrSize + insSize; i++) {
                cout << newArr[i];
                if (i < arrSize + insSize - 1) {
                    cout << ", ";
                }
            }
            cout << "]" << endl;

            delete[] arr; // Освобождение памяти первого массива
            delete[] ins; // Освобождение памяти второго массива
            delete[] newArr; // Освобождение памяти нового массива
            break;
        }

        case 18: {
            int size = safeIntInput("Введите размер массива: "); // Запрашиваем размер массива
            int* arr = new int[size]; // Динамически выделяем память для массива

            cout << "Введите элементы массива:\n";
            inputArray(arr, size); // Ввод элементов массива

            reverse(arr, size); // Вызываем функцию для реверсирования массива

            // Вывод измененного массива
            cout << "Измененный массив: [";
            for (int i = 0; i < size; i++) {
                cout << arr[i];
                if (i < size - 1) {
                    cout << ", ";
                }
            }
            cout << "]" << endl;

            delete[] arr; // Освобождение памяти
            break;
        }

        case 19: {
            int size = safeIntInput("Введите размер массива: "); // Запрашиваем размер массива
            int* arr = new int[size]; // Динамически выделяем память для массива

            cout << "Введите элементы массива:\n";
            inputArray(arr, size); // Ввод элементов массива

            int* reversedArray = reverseBack(arr, size); // Получаем новый массив

            // Выводим реверсированный массив
            cout << "Реверсированный массив: [";
            for (int i = 0; i < size; i++) {
                cout << reversedArray[i];
                if (i < size - 1) {
                    cout << ", ";
                }
            }
            cout << "]" << endl;

            delete[] arr; // Освобождаем выделенную память
            delete[] reversedArray; // Освобождаем выделенную память
            break;
        }

        case 20: {
            int size1 = safeIntInput("Введите размер первого массива: "); // Размер первого массива
            int size2 = safeIntInput("Введите размер второго массива: "); // Размер второго массива

            int* arr1 = new int[size1];
            int* arr2 = new int[size2];

            cout << "Введите элементы первого массива:\n";
            inputArray(arr1, size1); // Ввод элементов первого массива

            cout << "Введите элементы второго массива:\n";
            inputArray(arr2, size2); // Ввод элементов второго массива

            int* concatenatedArray = concat(arr1, size1, arr2, size2); // Объединяем массивы

            // Выводим объединенный массив
            cout << "Объединенный массив: [";
            for (int i = 0; i < size1 + size2; i++) {
                cout << concatenatedArray[i];
                if (i < size1 + size2 - 1) {
                    cout << ", ";
                }
            }
            cout << "]" << endl;

            delete[] arr1; // Освобождаем выделенную память
            delete[] arr2; // Освобождаем выделенную память
            delete[] concatenatedArray; // Освобождаем выделенную память
            break;
        }
        case 0:
            cout << "Выход из программы." << endl;
            return;
        default:
            cout << "Неверный выбор. Попробуйте снова." << endl;
            break;
        }

        // Предложение вернуться в меню
        cout << "Нажмите Enter, чтобы вернуться в главное меню." << endl;
        cin.get(); // Ожидаем нажатия Enter
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    mainMenu(); // Запускаем основное меню
    return 0;
}
