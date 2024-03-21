/*
 * Ho Chi Minh City University of Technology
 * Faculty of Computer Science and Engineering
 * Initial code for Assignment 1
 * Programming Fundamentals Spring 2023
 * Author: Vu Van Tien
 * Date: 02.02.2023
 */

// The library here is concretely set, students are not allowed to include any other libraries.

#include "study_in_pink1.h"

using namespace std;

void sa_tc_01()
{
    cout << "----- Sample Testcase 01 -----" << endl;
    string input_file("sa_tc_01_input");
    int HP1, HP2, EXP1, EXP2, M1, M2, E1, E2, E3;
    if (!readFile(input_file, HP1, HP2, EXP1, EXP2, M1, M2, E1, E2, E3))
    {
        return;
    }

    // cout << "EXP1: " << EXP1 << ", HP1: " << HP1 << ", E2: " << E2 << ", M1: " << M1 << endl;
    // int result = traceLuggage(HP1, EXP1, M1, E2);
    // // // cout << "EXP1: " << EXP1 << ", EXP2: " << EXP2 << ", result: " << result << endl;
    // cout << "EXP1: " << EXP1 << ", HP1: " << HP1 << ", E2: " << E2 << ", M1: " << M1 << ", Result: " << result << endl;
    // string email = "pink@gmail.com";
    // string pass = "012345pink#pink";
    // const char *mail = &email[0];
    // const char *pas = &pass[0];
    // cout << checkPassword(pas, mail);
    std::cout << "----- Testcase 1203 -----" << std::endl;
   
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << std::endl;
    int result = traceLuggage(HP1, EXP1, M1, E2);
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << ", result: " << result << std::endl;
}

int main(int argc, const char *argv[])
{
    sa_tc_01();

    return 0;
}