#include <iostream>
#include "Array.hpp"

#define MAX_VAL 50
int main(int, char**) // test with empty array!!!!
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand() % 100;
        numbers[i] = value;
        mirror[i] = value;
    }
    std::cout << "----- Base Array -----" << std::endl;
    numbers.print();
    std::cout << std::endl;
    std::cout << "----- Copy operator test -----" << std::endl;
    Array<int> tmp = numbers;
    tmp.print();
    std::cout << std::endl;
    //SCOPE
    {
        std::cout << "----- Copy constructor test -----" << std::endl;
        Array<int> test(tmp);
        test.print();
        std::cout << std::endl;
    } 
    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand() % 100;
    }
    std::cout << "----- New Sequence assisgned -----" << std::endl;
    numbers.print();
    std::cout << "----- Copy still the same -----" << std::endl;
    tmp.print();
    {
        std::cout << std::endl;
        std::cout << "----- Now with strings -----" << std::endl;
        Array<std::string> strings(10);
        int i = -1;
        strings[++i] = "This";
        strings[++i] = "is";
        strings[++i] = "the";
        strings[++i] = "array";
        strings[++i] = "of";
        strings[++i] = "strings.";
        strings[++i] = "YAAAAAY";
        strings[++i] = "!";
        strings[++i] = "It";
        strings[++i] = "worked...";
        strings.print();
        Array<std::string> copy(strings);
        copy[6] = "OMFG STILL WORKING";
        copy.print();
        strings.print();
    }
    delete [] mirror;
    return 0;
}