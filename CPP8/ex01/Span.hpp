#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <string>
#include <vector>
#include <exception>
#include <algorithm>
#include <cstdlib>

class Span
{
    private :
        unsigned int        N;
        std::vector<int>    vec;
        Span();
    public : 
        Span(unsigned int n);
        Span(const Span& copy);
        ~Span();

        Span& operator = (const Span& copy);

        void    addNumber(int nbr);
        int     shortestSpan();
        int     longestSpan();
        void    fillSpan();
        void    printSpan();

        class SpanIsFull : public std::exception
        {
            public :
                SpanIsFull() {}
                virtual const char* what() const throw(){
                    return ("You've reached the maximum of your array");
                }
        };
        
        class NotEnoughElements : public std::exception
        {
            public :
                NotEnoughElements() {}
                virtual const char* what() const throw(){
                    return ("The array is either empty or has only one element, cannot perform action.");
                }
        };
};

#endif