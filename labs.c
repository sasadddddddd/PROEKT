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
    float sum = 0.0; //  �������������� ���������� sum ��� ����� ��������� ����
    int sign = 1; // ���������� ��� �������� ����� �������� ��������
    int denominator = 1; // ����������� ���������� � 1
    int numerator = 3; // ��������� ���������� � 3

    printf("Vvedite chislo L: "); // ������� ����������� ��� ����� �������� N
    scanf("%d", &L); //  ��������� �������� N

    for (int i = 0; i < L; i++) { // ������ ����� ��� ���������� �����
        sum += sign * (float)numerator / denominator; // ��������� ������� ������� � �����
        sign *= -1; // ������ ���� ��� ���������� ��������
        denominator += 3; // ����������� ����������� �� 3
        numerator++; // ����������� ��������� �� 1
    }

    printf("symma pervyx %d elementov rayda: %.2f\n", L, sum); //  ������� ���������

    return 0; // ��������� ���������? �������� return ��������� ���������� ������� � ���������� ���������� ���������� �������.
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

    printf("������� ������: ");
    while ((input[i] = getchar()) != '\n') { // ��������� ������
        if (input[i] == ' ' || input[i] == '\t' || input[i] == '\n') {
            if (wordLength <= N) { // ���� ����� ����� �� ��������� N, �������� ��� � �������� ������
                for (int k = i - wordLength; k < i; k++) {
                    output[j++] = input[k];
                }
            }
            output[j++] = input[i]; // �������� ������ ��� ������ ���������
            wordLength = 0; // ���������� ����� �������� �����
        } else {
            wordLength++; // ����������� ����� �������� �����
        }
        i++;
    }
    output[j] = '\0'; // ��������� ����������� ������� ������

    printf("���������: %s\n", output);

    return 0;
}

int lab5()

{
    int arr[10];
    int temp;

    printf("������� 10 ����� �����:\n");
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
    char input[MAX_LENGTH]; // ��� ������ ��������� ��� ������� �������� input � output, ������ �������� MAX_LENGTH,
    char output[MAX_LENGTH]; //  ������� ����� �������������� ��� �������� ������� � �������� ������ ��������������.
    int i = 0, j = 0;
    int wordLength = 0;

    printf("vvedite stroky: ");
    while ((input[i] = getchar()) != EOF ) { // ��������� ������
        if (input[i] == ' ' || input[i] == '\t' || input[i] == '\n') {
            if (wordLength <= N) { // ���� ����� ����� �� ��������� N, �������� ��� � �������� ������
                for (int k = i - wordLength; k < i; k++) {
                    output[j++] = input[k];
                }
            }
            output[j++] = input[i]; // �������� ������ ��� ������ ���������
            wordLength = 0; // ���������� ����� �������� �����
        } else {
            wordLength++; // ����������� ����� �������� �����
        }
        i++;
    }
    output[j] = '\0'; // ��������� ����������� ������� ������

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

