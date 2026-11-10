#include <stdio.h>
#include <Windows.h>

#define NUM_ELEMENTS 100

int arr[NUM_ELEMENTS];
int n = 0;

/* =========================================================
   Базовые операции над массивом
   ========================================================= */

void printElements() {
    printf("< ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf(">\n");
}

void keyboardInput() {
    printf("n = ");
    scanf_s("%d", &n);
    printf("input %d values: ", n);
    for (int i = 0; i < n; i++) scanf_s("%d", &arr[i]);
}

void addLastElement(int value) { arr[n++] = value; }

void deleteLastElement() { if (n > 0) n--; }

void insertElement(int insIndex, int value) {
    if (n >= NUM_ELEMENTS) return;
    for (int i = n; i > insIndex; i--) arr[i] = arr[i - 1];
    n++;
    arr[insIndex] = value;
}

void deleteElement(int delIndex) {
    if (delIndex < 0 || delIndex >= n) return;
    for (int i = delIndex; i < n - 1; i++) arr[i] = arr[i + 1];
    n--;
}

/* =========================================================
   Поиск индексов min / max
   ========================================================= */

int findIndexMin() {
    int idx = 0;
    for (int i = 1; i < n; i++) if (arr[i] < arr[idx]) idx = i;
    return idx;
}

int findIndexMax() {
    int idx = 0;
    for (int i = 1; i < n; i++) if (arr[i] > arr[idx]) idx = i;
    return idx;
}
   /* 6.1.1 Базовые операции */
int findMin() {
    int min = arr[0];
    for (int i = 1; i < n; i++) if (arr[i] < min) min = arr[i];
    return min;
}

void oddsX10() {
    for (int i = 0; i < n; i++)
        if (arr[i] % 2 == 1) arr[i] *= 10;
}

/* 6.1.2 Сколько элементов > 10 */
int countMore10() {
    int cnt = 0;
    for (int i = 0; i < n; i++) if (arr[i] > 10) cnt++;
    return cnt;
}

/* 6.1.3 x2 для последнего четного */
int findLastEven() {
    for (int i = n - 1; i >= 0; i--) if (arr[i] % 2 == 0) return i;
    return -1;
}

void lastEvenX2() {
    int idx = findLastEven();
    if (idx >= 0) arr[idx] *= 2;
}

/* 6.1.4 Сколько четных левее минимального */
int countEvenBeforeMin() {
    int idx = findIndexMin();
    int cnt = 0;
    for (int i = 0; i < idx; i++) if (arr[i] % 2 == 0) cnt++;
    return cnt;
}

/* 6.1.5* x10 для нечетных правее минимального */
void oddsAfterMinX10() {
    if (n == 0) return;
    int idxMin = findIndexMin();
    for (int i = idxMin + 1; i < n; i++)
        if (arr[i] % 2 != 0) arr[i] *= 10;
}


/* 6.1.7 Все четные умножить на -1 */
void evenXMinus1() {
    for (int i = 0; i < n; i++)
        if (arr[i] % 2 == 0) arr[i] = -arr[i];
}

/* 6.1.8 Все элементы < 4 заменить на 4 */
void less4To4() {
    for (int i = 0; i < n; i++)
        if (arr[i] < 4) arr[i] = 4;
}

/* 6.1.9 Вариант 1: все четные обнулить */
void zeroEven() {
    for (int i = 0; i < n; i++)
        if (arr[i] % 2 == 0) arr[i] = 0;
}


void deleteMin() {
    if (n == 0) return;
    int idx = findIndexMin();
    printf("Индекс минимального элемента = %d\n", idx);
    deleteElement(idx);
}

/* 6.2.4 Перед минимальным вставить 0 */
void insert0BeforeMin() {
    if (n == 0) return;
    int idx = findIndexMin();
    printf("Индекс минимального элемента = %d\n", idx);
    insertElement(idx, 0);
}

/* 6.2.5* Удалить все четные элементы */
void deleteAllEven() {
    int i = 0;
    while (i < n) {
        if (arr[i] % 2 == 0) deleteElement(i);
        else i++;
    }
}
/* 6.2.9 Вариант 1: удалить первый четный */
void deleteFirstEven() {
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) { deleteElement(i); break; }
    }
}

//вывод меню
void main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int item;
    do {
        printf("\n----------------------------------------\n");
        printf("Содержимое массива: ");
        printElements();
        printf("\nМеню:\n");
        printf("  1: Ввести массив с клавиатуры               (6.1.1)\n");
        printf("  2: x10 для нечетных                         (6.1.1)\n");
        printf("  3: Найти минимальный элемент                (6.1.1)\n");
        printf("  4: Сколько элементов > 10                   (6.1.2)\n");
        printf("  5: x2 для последнего четного                (6.1.3)\n");
        printf("  6: Сколько четных левее минимального        (6.1.4)\n");
        printf("  7: x10 для нечетных правее минимального     (6.1.5*)\n");
        printf("  9: Все четные умножить на -1                (6.1.7)\n");
        printf(" 10: Все элементы < 4 заменить на 4           (6.1.8)\n");
        printf(" 11: Все четные обнулить                      (6.1.9, вар.1)\n");
        printf(" 14: Удалить заданный элемент                 (6.2.1)\n");
        printf(" 15: Вставить новый элемент в заданное место  (6.2.2)\n");
        printf(" 16: Удалить минимальный элемент              (6.2.3)\n");
        printf(" 17: Перед минимальным вставить 0             (6.2.4)\n");
        printf(" 18: Удалить все четные элементы              (6.2.5*)\n");
        printf(" 22: Удалить первый четный                    (6.2.9, вар.1)\n");
        printf("  0: Выйти\n");
        printf("Выбранная операция >>>>>> ");
        scanf_s("%d", &item);
        //само меню
        switch (item) {
        case 1:  keyboardInput();
            break;
        case 2:  oddsX10(); 
            break;
        case 3:  printf("min = %d\n", findMin()); 
            break;
        case 4:  printf("%d элементов > 10\n", countMore10()); 
            break;
        case 5:  lastEvenX2(); 
            break;
        case 6:  printf("Левее минимального %d четных\n", countEvenBeforeMin()); 
            break;
        case 7:  oddsAfterMinX10(); 
            break;
        case 9:  evenXMinus1(); 
            break;
        case 10: less4To4(); 
            break;
        case 11: zeroEven(); 
            break;
        case 14: {
            printf("Индекс удаляемого элемента = ");
            int idx; scanf_s("%d", &idx);
            deleteElement(idx);
        } break;
        case 15: {
            printf("Индекс вставки = ");
            int idx; scanf_s("%d", &idx);
            printf("Значение = ");
            int v; scanf_s("%d", &v);
            insertElement(idx, v);
        } break;
        case 16: deleteMin(); 
            break;
        case 17: insert0BeforeMin(); 
            break;
        case 18: deleteAllEven(); 
            break;
        case 22: deleteFirstEven(); 
            break;
         }
    } while (item != 0);
}