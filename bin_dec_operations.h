#include <cmath>
#include <iostream>
using namespace std;

int *const get_bin_repr(int dec_number)
{
    // creates an array contaning the binary representation of a number.
    int size = sizeof(dec_number) * 8;

    int *const bn_repr = new int[size];

    for (int i = 0; i < size; i++)
    {
        bn_repr[i] = dec_number % 2;
        dec_number /= 2;
    }
    return bn_repr;
}

int *const binary_sum(int *const first_num, int *const second_num)
{
    short size = sizeof(first_num[0]) * 8;

    int *const result = new int[size];
    int rest = 0;
    for (int i = 0; i < size; i++)
    {
        // Seba
        bool both_num_equal = first_num[i] == second_num[i];
        result[i] = (both_num_equal) ? rest : !rest;
        rest = (both_num_equal) ? first_num[i] == 1 : rest;

    }
    return result;
}

int get_dec_repr(int *const bn_num_array)
{
    short size = sizeof(bn_num_array[0]) * 8;
    ;
    int result = 0;
    for (int i = 0; i < size; i++)
    {
        result += bn_num_array[i] * pow(2, i);
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

/* 
   If the numbers are the same, and there can be 2 possibilities: they can boh 
   be equal to 1 or to 0. If they are both equal to 1 (=> first_num[i] == 1), then the 
   rest will always be one, since (1 + 1 + 1) or (1 + 1 + 0) will either yield 11 or 10,
   with the rest being always 1. Otherwise, when both first_num and second_num 
   are equal to 0, the rest will always be 0. 
   If the condition is false, that is first_num[i] != second_num[i], then the rest will always remain unchanged
*/

//result[i] = (first_num[i] == second_num[i]) ? rest: !rest;

/* The first equality checks if both first and second num are equal: in that case 
   the result will always be equal to the rest. 
   This is true because if first_num and second_num are both 0, then (0 + 0 + rest) =
   rest. If they are both 1, then (1 + 1 + rest) = 1 rest, (in binary form), which means
   either 10 if rest = 0, or 11 if rest = 1. 
   If the numbers are different, which means that their sum is necessarily 1, then the 
   value is going to be exacly the opposite of the current value of rest. If rest = 1, then
   rest + 1 = 10 => result = 0; on the countrary if rest = 0, then rest + 1 = 1 => result = 1.

*/