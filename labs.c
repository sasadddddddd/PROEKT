#include "stdio.h"
#include "labs.h"


void swap(char *x, char *y) {
    char temp = *x;
    *x = *y;
    *y = temp;
}


int lab1()

{
float L;
float t1;
float t2;
float Vg;
printf("L = ");
scanf("%f", &L);
printf("t1 = ");
scanf("%f", &t1);
printf("t2 = ");
scanf("%f", &t2);
Vg=(L/t1-L/t2)/2;
printf("distance = %f\n", Vg);
}

int lab2()

{
    int L;
    float sum = 0.0; //  инициализируем переменную sum как сумму элементов ряда
    int sign = 1; // Переменная для хранения знака текущего элемента
    int denominator = 1; // Знаменатель начинается с 1
    int numerator = 3; // Числитель начинается с 3

    printf("Vvedite chislo L: "); // выводим приглашение для ввода значения N
    scanf("%d", &L); //  считываем значение N

    for (int i = 0; i < L; i++) { // начало цикла для вычисления суммы
        sum += sign * (float)numerator / denominator; // Добавляем текущий элемент к сумме
        sign *= -1; // Меняем знак для следующего элемента
        denominator += 3; // Увеличиваем знаменатель на 3
        numerator++; // Увеличиваем числитель на 1
    }

    printf("symma pervyx %d elementov rayda: %.2f\n", L, sum); //  выводим результат

    return 0; // завершаем программу? Оператор return завершает выполнение функции и возвращает управление вызывающей функции.
}

int lab3()
 {
    char c;
    int count = 0;
    int inWord = 0;
    int hasVowel = 0;

    printf("vvedite strochechky: ");

    while ((c = getchar()) != EOF ) {
        if (c != ' ') {
            if (!inWord) {
                inWord = 1;
                hasVowel = 0;
            }
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
                c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' ) {
             hasVowel = 1;
             }
        } else {
            inWord = 0;
            if (hasVowel) {
                count++;
            }
        }
    }

    if (hasVowel) {
        count++;
    }

    printf("kolichestvo slov s glasnumi: %d\n", count);

    return 0;
}

int lab4()
{
    char input[MAX_LENGTH];
    char output[MAX_LENGTH];
    int i = 0, j = 0;
    int wordLength = 0;

    printf("Введите строку: ");
    while ((input[i] = getchar()) != '\n') { // Считываем строку
        if (input[i] == ' ' || input[i] == '\t' || input[i] == '\n') {
            if (wordLength <= N) { // Если длина слова не превышает N, копируем его в выходную строку
                for (int k = i - wordLength; k < i; k++) {
                    output[j++] = input[k];
                }
            }
            output[j++] = input[i]; // Копируем пробел или символ табуляции
            wordLength = 0; // Сбрасываем длину текущего слова
        } else {
            wordLength++; // Увеличиваем длину текущего слова
        }
        i++;
    }
    output[j] = '\0'; // Добавляем завершающий нулевой символ

    printf("Результат: %s\n", output);

    return 0;
}

int lab5()

{
    int arr[10];
    int temp;

    printf("Введите 10 целых чисел:\n");
    for (int i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < 10 / 2; i++) {
        temp = arr[i];
        arr[i] = arr[10 - 1 - i];
        arr[10 - 1 - i] = temp;
    }

    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

int lab4a()
{
    char input[MAX_LENGTH]; // Эти строки объявляют два массива символов input и output, каждый размером MAX_LENGTH,
    char output[MAX_LENGTH]; //  которые будут использоваться для хранения входной и выходной строки соответственно.
    int i = 0, j = 0;
    int wordLength = 0;

    printf("vvedite stroky: ");
    while ((input[i] = getchar()) != EOF ) { // Считываем строку
        if (input[i] == ' ' || input[i] == '\t' || input[i] == '\n') {
            if (wordLength <= N) { // Если длина слова не превышает N, копируем его в выходную строку
                for (int k = i - wordLength; k < i; k++) {
                    output[j++] = input[k];
                }
            }
            output[j++] = input[i]; // Копируем пробел или символ табуляции
            wordLength = 0; // Сбрасываем длину текущего слова
        } else {
            wordLength++; // Увеличиваем длину текущего слова
        }
        i++;
    }
    output[j] = '\0'; // Добавляем завершающий нулевой символ

    printf("Rezultat: %s\n", output);

    return 0;
}


int lab5a() {
    int arr[10];
    printf("Vvedite elementy massiva:\n ");
    for (int i=0; i < 10; i++){
        scanf("%d", arr[i]);
        }

    for (int i=0; i < 10; i++){
    printf("%d\n", arr[i]);
    }

    for (int i = 0; i < 10; i += 2) {
        swap(&arr[i], &arr[i+1]);
    }

    printf("Izmenennyi massiv: %d\n", arr);
    return 0;
}

