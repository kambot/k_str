#include <stdio.h> 
#include <stdlib.h>

#include "k_str.h"




void main() {

    char* test_str = "This is a test.";
    char* test2_str = "popqw~na;spn.qw97834=na";
    char* test3_str = "000111001101";
    char* numbers_str = "0123456789";

    char* comp1_str = "abcd";
    char* comp2_str = "abca";
    char* comp3_str = calloc(4, sizeof(char));


    //get the length of a string
    printf("String length:\n");
    int test_len = k_strlen(test_str);
    printf("The sentence '%s', has %d characters.\n", test_str, test_len);

    //convert to uppercase
    printf("\nUppercase:\n");
    char* test_upper = calloc(k_strlen(test2_str), sizeof(char));
    k_toupper(test2_str, test_upper);
    printf("'%s' --> '%s'\n", test2_str, test_upper);

    //copy a string 
    printf("\nCopy:\n");
    printf("Before: '%s'\n", comp3_str);
    k_strcopy(comp1_str, comp3_str);
    printf("After: '%s'\n", comp3_str);

    //compare strings
    //comparison 1
    printf("\nString comparison:\n");
    int comp2 = k_strcmp(comp1_str, comp2_str);
    if (comp2 != 0) {
        printf("'%s' and '%s' are not equal.\n", comp1_str, comp2_str);
    } else {
        printf("'%s' and '%s' are equal.\n", comp1_str, comp2_str);
    }
    printf("Comparison value = %d\n", comp2);
    //comparison 2
    int comp3 = k_strcmp(comp1_str, comp3_str);
    if (comp3 != 0) {
        printf("'%s' and '%s' are not equal.\n", comp1_str, comp3_str);
    }
    else {
        printf("'%s' and '%s' are equal.\n", comp1_str, comp3_str);
    }
    printf("Comparison value = %d\n", comp3);

    //concatenate strings
    printf("\nString concatenation:\n");
    char* concat_str = calloc(k_strlen(numbers_str) + k_strlen(comp1_str), sizeof(char));
    k_strappend(numbers_str, comp1_str, concat_str);
    printf("'%s' + '%s' = '%s'\n", numbers_str, comp1_str, concat_str);

    //find and replace
    printf("\nFind and replace:\n");
    char* rep_str = calloc(1000, sizeof(char));
    k_strrep(test_str, " is ", " is not ", rep_str);
    printf("String: '%s'\n", test_str);
    printf("Find: '%s'\n", " is ");
    printf("Replacement: '%s'\n", " is not ");
    printf("Result: '%s'\n", rep_str);

    //occurrences
    printf("\nString occurrences:\n");
    int o1 = k_strfind(test3_str, "00", 0);
    int o2 = k_strfind(test3_str, "00", 1);
    printf("The string '%s' occurrs %d times in '%s'\n", "00", o1, test3_str);
    printf("The string '%s' occurrs %d times in '%s' (nested)\n", "00", o2, test3_str);


    //starting index
    printf("\nStarting index:\n");
    int index = k_strindex(test2_str, "na");
    int index2 = k_strindex(test2_str, "word");
    printf("The starting index of 'na' in '%s' is %d.\n", test2_str, index);
    printf("The starting index of 'word' in '%s' is %d.\n", test2_str, index2);

    //substrings
    printf("\nSubstrings:\n");
    int nlen = k_strlen(numbers_str);
    char* sub1 = k_substr(numbers_str, 0, 5);
    char* sub2 = k_substr(numbers_str, -1, -2 * nlen);
    char* sub3 = k_substr(numbers_str, 0, -5);
    char* sub4 = k_substr(numbers_str, 0, 2 * nlen - 1);
    printf("String: '%s'\n", numbers_str);
    printf("Start = %3d End = %3d Result = '%s'\n", 0, 5, sub1);
    printf("Start = %3d End = %3d Result = '%s'\n", -1, -2 * nlen, sub2);
    printf("Start = %3d End = %3d Result = '%s'\n", 0, -5, sub3);
    printf("Start = %3d End = %3d Result = '%s'\n", 0, 2 * nlen - 1, sub4);

    //string padding
    printf("\nString padding:\n");
    char* pad1 = k_strpad(numbers_str, '*', 20, 1);
    char* pad2 = k_strpad(numbers_str, '0', 15, 0);
    char* pad3 = k_strpad(numbers_str, 'X', 10, 1);
    printf("String: '%s'\n", numbers_str);
    printf("pad 1: '%s'\n", pad1);
    printf("pad 2: '%s'\n", pad2);
    printf("pad 3: '%s'\n", pad3);


    char **splittest = k_strsplit("a.bb..ccc..a..", "..");
    //char **splittest = k_strsplit("", "..");
    int total = 0;
    for (int i = 0; splittest[i] != NULL; i++) {
        total++;
    }

    int splen0 = k_strlen(splittest[0]);



}