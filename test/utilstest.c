/*******************************************************************************
 *   Ledger Stellar App
 *   (c) 2017 LeNonDupe
 *
 *  adapted from https://github.com/mjg59/tpmtotp/blob/master/base32.h
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 ********************************************************************************/
#include <stdio.h>
#include <string.h>
#include "stlr_utils.h"

void test_print_amount(uint64_t amount, char *expected) {
    char *asset = "XLM";
    char printed[24];
    print_amount(amount, asset, printed, 22);

    if (strcmp(printed, expected) != 0) {
        printf("Test failed. Expected: %s; Actual: %s\n", expected, printed);
    }

}

int main(int argc, char *argv[]) {

    uint64_t amount = 1;
    char *expected = "0.0000001 XLM";
    test_print_amount(amount, expected);

    amount = 10000000;
    expected = "1 XLM";
    test_print_amount(amount, expected);

    amount = 100000000000001;
    expected = "10000000.0000001 XLM";
    test_print_amount(amount, expected);

    amount = 100000001;
    expected = "10.0000001 XLM";
    test_print_amount(amount, expected);

    amount = 100000001000000;
    expected = "10000000.1 XLM";
    test_print_amount(amount, expected);

    return 0;

}
