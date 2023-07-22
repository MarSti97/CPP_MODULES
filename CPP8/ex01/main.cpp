#include "Span.hpp"

int main()
{
	std::srand(std::time(0));
    {
        std::cout << "----- Basic Tests -----" << std::endl;
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        sp.printSpan();
        try{
        sp.addNumber(73);
        }
        catch (std::exception& e){
            std::cerr << e.what() << std::endl;
        }
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    std::cout << std::endl;
    std::cout << "----- Advanced tests -----" << std::endl;
    {
        Span ten(10);
        ten.fillSpan();
        ten.printSpan();
        std::cout << ten.shortestSpan() << std::endl;
        std::cout << ten.longestSpan() << std::endl;
        Span wrong(1);
        try{
            std::cout << wrong.shortestSpan() << std::endl;
            std::cout << wrong.longestSpan() << std::endl;
        } catch (std::exception& e){
            std::cerr << e.what() << std::endl;
        }
        wrong.addNumber(73);
        try{
            std::cout << wrong.shortestSpan() << std::endl;
            std::cout << wrong.longestSpan() << std::endl;
        } catch (std::exception& e){
            std::cerr << e.what() << std::endl;
        }
        wrong.printSpan();
        std::cout << "--- Copy and Assignemnt tests ---" << std::endl;
        Span copy(wrong);
        copy.printSpan();
        wrong = ten;
        wrong.printSpan();
        std::cout << "--- Huge Test (commented for readability) ---" << std::endl;
        // Span huge(10000);
        // huge.fillSpan();
        // huge.printSpan();
        // std::cout << huge.shortestSpan() << std::endl;
        // std::cout << huge.longestSpan() << std::endl;
    }
    return 0;
}