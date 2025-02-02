#ifndef STRING_H
#define STRING_H

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

#define ASSERT_STRING(expected, got) assertString(expected, got, \
__FILE__, __FUNCTION__, __LINE__)
#define MAX_STRING_SIZE 100
#define MAX_N_WORDS_IN_STRING 100
#define MAX_WORD_SIZE 20

char _stringBuffer[MAX_STRING_SIZE + 1];

typedef struct WordDescriptor {
    char *begin; //Позиция начала слова.
    char *end; //Позиция первого символа, после последнего символа слова.
} WordDescriptor;

typedef struct BagOfWords {
    WordDescriptor words[MAX_N_WORDS_IN_STRING];
    size_t size;
} BagOfWords;

//Возвращает количество символов в строке.
size_t strlen_(const char *begin);

//Возвращает указатель на первый элемент с кодом ch,
//расположенным на ленте памяти между адресами begin и end не включая end.
char *find(char *begin, char *end, int ch);

//Возвращает указатель на первый символ, отличный от пробельных,
//расположенный на ленте памяти, начиная с begin и заканчивая ноль-символом.
char *findNonSpace(char *begin);

//Возвращает указатель на первый пробельный символ, расположенный на ленте
//памяти начиная с адреса begin или на первый ноль-символ.
char *findSpace(char *begin);

//Возвращает указатель на первый справа символ, отличный от пробельных,
//расположенный на ленте памяти, начиная с rbegin и заканчивая rend.
char *findNonSpaceReverse(char *rbegin, const char *rend);

//Возвращает указатель на первый пробельный символ справа, расположенный
//на ленте памяти, начиная с rbegin и заканчивая rend.
char *findSpaceReverse(char *rbegin, const char *rend);

//Возвращает отрицательное значение, если lhs109 располагается до rhs
//в лексикографическом порядке, значение 0, если lhs и rhs равны, иначе – положительное значение.
int strcmp(const char *lhs, const char *rhs);

//Записывает по адресу beginDestination
//фрагмент памяти, начиная с адреса beginSource до endSource.
char *copy(const char *beginSource, const char *endSource,
           char *beginDestination);

//Записывает по адресу beginDestination элементы из фрагмента памяти
//начиная с beginSource заканчивая endSource, удовлетворяющие функции-предикату f.
char *copyIf(char *beginSource, const char *endSource,
             char *beginDestination, int (*f)(int));

//Записывает по адресу beginDestination элементы из фрагмента памяти
//начиная с rbeginSource заканчивая rendSource, удовлетворяющие функции-предикату f.
char *copyIfReverse(char *rbeginSource, const char *rendSource,
                    char *beginDestination, int (*f)(int));

//Возвращает значение 0, если слово не было считано, в противном
//случае будет возвращено значение 1 и в переменную word
//будут записаны позиции начала слова
//и первого символа после конца слова.
int getWord(char *beginSearch, WordDescriptor *word);

bool getWordReverse(char *rbegin, char *rend, WordDescriptor *word);

//Возвращает указатель на конец строки.
char *getEndOfString(char *s);

//Возвращает значение 0, если слово w1 не совпадает со словом w2 иначе 1.
int areWordsEqual(WordDescriptor w1, WordDescriptor w2);

void getBagOfWords(BagOfWords *bag, char *s);

//Возвращает значение 'истина', если слово является палиндромом.
bool isPalindrome(char *begin, char *end);

char *copyReverse(char *rbeginSource, const char *rendSource, char *beginDestination);

void assertString(const char *expected, char *got,
                  char const *fileName, char const *funcName, int line);

#endif //STRING_H