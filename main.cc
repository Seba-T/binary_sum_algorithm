#include <iostream>
#include <cmath>
#include "bin_dec_operations.h"
using namespace std;

int *const get_bin_repr(int);
int *const binary_sum(int *const, int *const);
int get_dec_repr(int *);

int main()
{
    // Convert a number from decimal to binary base.
    int dec_number_a, dec_number_b;
    cout << "Insert the number: " << endl;
    cin >> dec_number_a >> dec_number_b;
    // it contains the number of bits of int.

    int *const bn_number_a = get_bin_repr(dec_number_a);
    int *const bn_number_b = get_bin_repr(dec_number_b);
    int *const bn_result = binary_sum(bn_number_a, bn_number_b);

    int dec_result = get_dec_repr(bn_result);

    delete bn_number_a;
    delete bn_number_b;
    delete bn_result;

    cout << "Here is the result in a decimal base: " << dec_result << endl;
    return 0;
};

/*int *const get_bin_repr(int dec_number)
{
    // Return an array contaning the binary representation of a number.
    short size = sizeof(dec_number) * 8;
    int bin_repr[size];
    for (int i = 0; i < size; i++)
    {
        bin_repr[i] = dec_number % 2;
        dec_number /= 2;
    }

    return bin_repr;
}

int *const binary_sum(int *const first_num, int *const second_num)
{
    short size = sizeof(first_num) * 8;
    int rest = 0;

    int result[size];
    for (int i = 0; i < size; i++)
    {
        rest = (first_num[i] == second_num[i]) ? first_num[i] == 1 : rest;
        result[i] = (first_num[i] == second_num[i]) * rest;
    }
}

int get_dec_repr(int *const bn_number_array)
{
    short size = sizeof(bn_number_array) * 8;
    int result = 0;
    for (int i = 0; i < size; i++)
    {
        result += bn_number_array[i] * pow(2, i);
    }
    return result;
}

// Fede
//rest = (first_num[i] != second_num[i] and first_num[i] != rest) ? !rest : rest;
//if (first_num[i] != second_num[i] and first_num[i] != rest)
//rest = !rest;
//result[i] = (first_num[i] xor second_num[i]) * (!rest);

// Seba

//rest = (first_num[i] == second_num[i])? first_num[i] == 1 : rest;


   If the numbers are the same, and there can be 2 possibilities: they can boh 
   be equal to 1 or to 0. If they are both equal to 1 (=> first_num[i] == 1), then the 
   rest will always be one, since (1 + 1 + 1) or (1 + 1 + 0) will either yield 11 or 10,
   with the rest being always 1. Otherwise, when both first_num and second_num 
   are equal to 0, the rest will always be 0. 
   If the condition is false, that is first_num[i] != second_num[i], then the rest will always remain unchanged
*/

//result[i] = (first_num[i] == second_num[i]) * rest;

/* The first equality checks if both first and second num are equal: in that case 
   the result will always be equal to the rest. 
   This is true because if first_num and second_num are both 0, then (0 + 0 + rest) =
   rest. If they are both 1, then (1 + 1 + rest) = 1 rest, (in binary form), which means
   either 10 if rest = 0, or 11 if rest = 1. 
   If the numbers are different, which means that their sum is necessarily 1, then the 
   value is going to be exacly the opposite of the current value of rest. If rest = 1, then
   rest + 1 = 10 => result = 0; on the countrary if rest = 0, then rest + 1 = 1 => result = 1.

*/
