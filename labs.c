#include <stdio.h>
#include "labs.h"
#ifndef LABS_H
#define LABS_H
#define MAX_LENGTH 100
#define N 5
#define MAXN 100
#define MAXK 100


void swap(char *x, char *y) {
    char temp = *x;
    *x = *y;
    *y = temp;
}

// Функция для нахождения количества значащих бит в числе
int bit_length(unsigned int n) {
    int bits = 0;
    while (n > 0) {
        bits++;
        n >>= 1;
    }
    return bits;
}

// Функция для зеркального отражения битов
unsigned int reverse_bits(unsigned int n) {
    unsigned int reversed = 0;
    int bits = bit_length(n);

    for (int i = 0; i < bits; i++) {
        if (n & (1 << i)) {
            reversed |= (1 << (bits - 1 - i));
        }
    }
    return reversed;
}

void printMatrix(int matrix[MAXN][MAXK], int N, int K) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int isPalindrome(int row[MAXK], int K) {
    for (int i = 0; i < K / 2; i++) {
        if (row[i] != row[K - 1 - i]) {
            return 0; // not a palindrome
        }
    }
    return 1; // is a palindrome
}

void zeroRow(int row[MAXK], int K) {
    for (int i = 0; i < K; i++) {
        row[i] = 0;
    }
}

void processMatrix(int matrix[MAXN][MAXK], int N, int K) {
    for (int i = 0; i < N; i++) {
        if (isPalindrome(matrix[i], K)) {
            zeroRow(matrix[i], K);
        }
    }
}

void shakerSort(int matrix[MAXN][MAXK], int N, int K) {
    int left = 0;
    int right = N - 1;
    int swapped = 1;

    while (left < right && swapped) {
        swapped = 0;

        // Bubble up
        for (int i = left; i < right; i++) {
            for (int j = 0; j < K; j++) {
                if (matrix[i][j] > matrix[i + 1][j]) {
                    for (int k = 0; k < K; k++) {
                        int temp = matrix[i][k];
                        matrix[i][k] = matrix[i + 1][k];
                        matrix[i + 1][k] = temp;
                    }
                    swapped = 1;
                    break;
                } else if (matrix[i][j] < matrix[i + 1][j]) {
                    break;
                }
            }
        }
        right--;

        // Bubble down
        for (int i = right; i > left; i--) {
            for (int j = 0; j < K; j++) {
                if (matrix[i][j] < matrix[i - 1][j]) {
                    for (int k = 0; k < K; k++) {
                        int temp = matrix[i][k];
                        matrix[i][k] = matrix[i - 1][k];
                        matrix[i - 1][k] = temp;
                    }
                    swapped = 1;
                    break;
                } else if (matrix[i][j] > matrix[i - 1][j]) {
                    break;
                }
            }
        }
        left++;
    }
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
    float sum = 0.0; //  èíèöèàëèçèðóåì ïåðåìåííóþ sum êàê ñóììó ýëåìåíòîâ ðÿäà
    int sign = 1; // Ïåðåìåííàÿ äëÿ õðàíåíèÿ çíàêà òåêóùåãî ýëåìåíòà
    int denominator = 1; // Çíàìåíàòåëü íà÷èíàåòñÿ ñ 1
    int numerator = 3; // ×èñëèòåëü íà÷èíàåòñÿ ñ 3

    printf("Vvedite chislo L: "); // âûâîäèì ïðèãëàøåíèå äëÿ ââîäà çíà÷åíèÿ N
    scanf("%d", &L); //  ñ÷èòûâàåì çíà÷åíèå N

    for (int i = 0; i < L; i++) { // íà÷àëî öèêëà äëÿ âû÷èñëåíèÿ ñóììû
        sum += sign * (float)numerator / denominator; // Äîáàâëÿåì òåêóùèé ýëåìåíò ê ñóììå
        sign *= -1; // Ìåíÿåì çíàê äëÿ ñëåäóþùåãî ýëåìåíòà
        denominator += 3; // Óâåëè÷èâàåì çíàìåíàòåëü íà 3
        numerator++; // Óâåëè÷èâàåì ÷èñëèòåëü íà 1
    }

    printf("symma pervyx %d elementov rayda: %.2f\n", L, sum); //  âûâîäèì ðåçóëüòàò

    return 0; // çàâåðøàåì ïðîãðàììó? Îïåðàòîð return çàâåðøàåò âûïîëíåíèå ôóíêöèè è âîçâðàùàåò óïðàâëåíèå âûçûâàþùåé ôóíêöèè.
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

    printf("Ââåäèòå ñòðîêó: ");
    while ((input[i] = getchar()) != '\n') { // Ñ÷èòûâàåì ñòðîêó
        if (input[i] == ' ' || input[i] == '\t' || input[i] == '\n') {
            if (wordLength <= N) { // Åñëè äëèíà ñëîâà íå ïðåâûøàåò N, êîïèðóåì åãî â âûõîäíóþ ñòðîêó
                for (int k = i - wordLength; k < i; k++) {
                    output[j++] = input[k];
                }
            }
            output[j++] = input[i]; // Êîïèðóåì ïðîáåë èëè ñèìâîë òàáóëÿöèè
            wordLength = 0; // Ñáðàñûâàåì äëèíó òåêóùåãî ñëîâà
        } else {
            wordLength++; // Óâåëè÷èâàåì äëèíó òåêóùåãî ñëîâà
        }
        i++;
    }
    output[j] = '\0'; // Äîáàâëÿåì çàâåðøàþùèé íóëåâîé ñèìâîë

    printf("Ðåçóëüòàò: %s\n", output);

    return 0;
}

int lab5()

{
    int arr[10];
    int temp;

    printf("Ââåäèòå 10 öåëûõ ÷èñåë:\n");
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

int laba6() {
    int N, K;
    int matrix[MAXN][MAXK];
    
    // Reading matrix dimensions
    printf("Enter number of rows (N) and columns (K): ");
    scanf("%d %d", &N, &K);
    
    // Reading the matrix elements
    printf("Enter the matrix elements:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    
    // Print original matrix
    printf("Original matrix:\n");
    printMatrix(matrix, N, K);
    
    // Process the matrix to zero palindrome rows
    processMatrix(matrix, N, K);
    
    // Print modified matrix
    printf("Modified matrix:\n");
    printMatrix(matrix, N, K);
    
    // Sort the modified matrix using shaker sort
    shakerSort(matrix, N, K);
    
    // Print sorted matrix
    printf("Sorted matrix:\n");
    printMatrix(matrix, N, K);
    
    return 0;
}
int laba7() {
    unsigned int N;
    printf("Введите целое число: ");
    scanf("%u", &N);

    unsigned int reversed_N = reverse_bits(N);
    printf("Зеркальное отображение битов: %u\n", reversed_N);
    return 0;
}

int lab4a()
{
    char input[MAX_LENGTH]; // Ýòè ñòðîêè îáúÿâëÿþò äâà ìàññèâà ñèìâîëîâ input è output, êàæäûé ðàçìåðîì MAX_LENGTH,
    char output[MAX_LENGTH]; //  êîòîðûå áóäóò èñïîëüçîâàòüñÿ äëÿ õðàíåíèÿ âõîäíîé è âûõîäíîé ñòðîêè ñîîòâåòñòâåííî.
    int i = 0, j = 0;
    int wordLength = 0;

    printf("vvedite stroky: ");
    while ((input[i] = getchar()) != EOF ) { // Ñ÷èòûâàåì ñòðîêó
        if (input[i] == ' ' || input[i] == '\t' || input[i] == '\n') {
            if (wordLength <= N) { // Åñëè äëèíà ñëîâà íå ïðåâûøàåò N, êîïèðóåì åãî â âûõîäíóþ ñòðîêó
                for (int k = i - wordLength; k < i; k++) {
                    output[j++] = input[k];
                }
            }
            output[j++] = input[i]; // Êîïèðóåì ïðîáåë èëè ñèìâîë òàáóëÿöèè
            wordLength = 0; // Ñáðàñûâàåì äëèíó òåêóùåãî ñëîâà
        } else {
            wordLength++; // Óâåëè÷èâàåì äëèíó òåêóùåãî ñëîâà
        }
        i++;
    }
    output[j] = '\0'; // Äîáàâëÿåì çàâåðøàþùèé íóëåâîé ñèìâîë

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
#endif
