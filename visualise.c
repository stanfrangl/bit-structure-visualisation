#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

bool edgeCaseZero(char *input);
bool edgeCaseMin(char *input);
bool isCharDesired(char *input);
bool isNegative(char *input);
void removeNegative(char *input);
void arrayToDigits(char *array);
bool isChar(char *input);
int charToNumber(char *array);
char *numberToBinary(int number);
void makeNegative(char *result);
char *makeBinaryPretty(char *result);

void allTests(void);
void testIsCharDesired(void);
void testIsNegative(void);
void testRemoveNegative(void);
void testArraytoDigits(void);
void testIsChar(void);
void testCharToNumber(void);
void testNumberToBinary(void);
void testMakeNegative(void);
void testMakeBinaryPretty(void);

int main(int argc, char *argv[]) {
    if (argc == 1) {
        allTests();
        printf("All tests pass.\n");
    }
    else if (isCharDesired(argv[1])) {
        if (edgeCaseZero(argv[2])) printf("0000 0000\n");
        else if (edgeCaseMin(argv[2])) printf("1000 0000\n");
        else {
            bool isNegativeFlag = isNegative(argv[2]);
            if (isNegativeFlag) removeNegative(argv[2]);
            arrayToDigits(argv[2]);
            if (isChar(argv[2])) {
                char *result = numberToBinary(charToNumber(argv[2]));
                if (isNegativeFlag) makeNegative(result);
                makeBinaryPretty(result);
                printf("%s\n", result);
                free(result);
                return 0;
            }
            else printf("Input error.\n");
        }
    }
    else {
        printf("Input error.\n");
        return 0;
    }
}

bool edgeCaseZero(char *input) {
     return (input[0] == '0' && strlen(input) == 1)
         || (input[0] == '-' && input[1] == '0'
         && strlen(input) == 2);
}

bool edgeCaseMin(char *input) {
    return input[0] == '-' && input[1] == '1'
        && input[2] == '2' && input[3] == '8';
}

bool isCharDesired(char *input) {
    return strcmp(input, "char") == 0;
}

bool isNegative(char *input) {
    return input[0] == '-';
}

void removeNegative(char *input) {
    int lengthOfInput = strlen(input);
    if (lengthOfInput == 2) {
        input[0] = input[1];
        input[1] = '\0';
    }
    else if (lengthOfInput == 3) {
        input[0] = input[1];
        input[1] = input[2];
        input[2] = '\0';
    }
    else if (lengthOfInput == 4) {
        input[0] = input[1];
        input[1] = input[2];
        input[2] = input[3];
        input[3] = '\0';
    }
}

void arrayToDigits(char *array) {
    int lengthOfInput = strlen(array);
    if (lengthOfInput == 1) array[0] = array[0] - '0';
    else if (lengthOfInput == 2) {
        array[0] = array[0] - '0';
        array[1] = array[1] - '0';
    }
    else if (lengthOfInput == 3) {
        array[0] = array[0] - '0';
        array[1] = array[1] - '0';
        array[2] = array[2] - '0';
    }
}

bool isChar(char *input) {
    int lengthOfInput = strlen(input);
    if (lengthOfInput == 1) {
        if (1 <= input[0] && input[0] <= 9) return true;
        else return false;
    }
    else if (lengthOfInput == 2) {
        if (1 <= input[0] && input[0] <= 9 
            && 0 <= input[1] && input[1] <= 9) return true;
        else return false;
    }
    else if (lengthOfInput == 3) {
        if (input[0] == 1) {
            if (0 <= input[1] && input[1] <= 1 
                && 0 <= input[2] && input[2] <= 9) {
                return true;
            }
            else if (input[1] == 2 && 0 <= input[2] && input[2] <= 7) {
                return true;
            }
            else return false;
        }
        else return false;
    }
    else return false;
}

int charToNumber(char *array) {
    int lengthOfArray = strlen(array);
    int number = 0;
    if (lengthOfArray == 1) number = array[0];
    else if (lengthOfArray == 2) {
        number = array[1];
        number += array[0] * 10;
    }
    else if (lengthOfArray == 3) {
        number = array[2];
        number += array[1] * 10;
        number += array[0] * 100;
    }
    return number;
}

char *numberToBinary(int number) {
    char *result = calloc(10, sizeof(char));
    int i = 7;
    while (i >= 0) {
            char digit = number % 2;
            number = number / 2;
            result[i] = digit;
            i --;
    }
    return result;
}

void makeNegative(char *result) {
    int i = 7;
    while (result[i] != 1) i --;
    i --;
    while (i >= 0) {
        if (result[i] == 0) result[i] = 1;
        else result[i] = 0;
        i --;
    }
}

char *makeBinaryPretty(char *result) {
    sprintf(result, "%d%d%d%d %d%d%d%d", result[0], result[1], result[2], result[3], 
                                         result[4], result[5], result[6], result[7]);
    return result;
}

void allTests(void) {
    testIsCharDesired();
    testIsNegative();
    testRemoveNegative();
    testArraytoDigits();
    testIsChar();
    testCharToNumber();
    testNumberToBinary();
    testMakeNegative();
    testMakeBinaryPretty();
}


void testIsCharDesired(void) {
    assert(isCharDesired("char") == true);
    assert(isCharDesired("cha") == false);
    assert(isCharDesired("int") == false);
}

void testIsNegative(void) {
    assert(isNegative("-7") == true);
    assert(isNegative("-17") == true);
    assert(isNegative("-127") == true);
    assert(isNegative("7") == false);
    assert(isNegative("17") == false);
    assert(isNegative("127") == false);
}

void testRemoveNegative(void) {
    char check7[] = "-7";
    removeNegative(check7);
    assert(strcmp(check7, "7") == 0);
}

void testArraytoDigits(void) {
    char check7[] = "7";
    arrayToDigits(check7);
    assert(check7[0] == 7);
    char check17[] = "17";
    arrayToDigits(check17);
    assert(check17[1] == 7);
    char check127[] = "127";
    arrayToDigits(check127);
    assert(check127[2] == 7);
}

void testIsChar(void) {
    char check7[] = "7";
    arrayToDigits(check7);
    assert(isChar(check7) == true);
    char check17[] = "17";
    arrayToDigits(check17);
    assert(isChar(check17) == true);
    char check127[] = "127";
    arrayToDigits(check127);
    assert(isChar(check127) == true);
    char check128[] = "128";
    arrayToDigits(check128);
    assert(isChar(check128) == false);
    char checkNegative[] = "-5";
    arrayToDigits(checkNegative);
    assert(isChar(checkNegative) == false);
    char checkLetters[] = "abc";
    arrayToDigits(checkLetters);
    assert(isChar(checkLetters) == false);
}

void testCharToNumber(void) {
    char check7[] = "7";
    arrayToDigits(check7);
    assert(charToNumber(check7) == 7);
    char check17[] = "17";
    arrayToDigits(check17);
    assert(charToNumber(check17) == 17);
    char check127[] = "127";
    arrayToDigits(check127);
    assert(charToNumber(check127) == 127);
}

void testNumberToBinary(void) {
    char *check7 = numberToBinary(7);
    sprintf(check7, "%d%d%d%d %d%d%d%d", check7[0], check7[1], check7[2], check7[3], 
                                         check7[4], check7[5], check7[6], check7[7]);
    assert(strcmp(check7, "0000 0111")  == 0);
    free(check7);
}

void testMakeNegative(void) {
    char checkNegative7[] = {0,0,0,0,0,1,1,1};
    makeNegative(checkNegative7);
    assert(checkNegative7[0] == 1);
    assert(checkNegative7[1] == 1);
    assert(checkNegative7[2] == 1);
    assert(checkNegative7[3] == 1);
    assert(checkNegative7[4] == 1);
    assert(checkNegative7[5] == 0);
    assert(checkNegative7[6] == 0);
    assert(checkNegative7[7] == 1);
}

void testMakeBinaryPretty(void) {
    char *check7 = makeBinaryPretty(numberToBinary(7));
    assert(strcmp(check7, "0000 0111")  == 0);
    free(check7);
}

