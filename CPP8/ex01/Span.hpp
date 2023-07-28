#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <string>
#include <vector>
#include <exception>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <climits>

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
                SpanIsFull();
                virtual const char* what() const throw();
        };
        
        class NotEnoughElements : public std::exception
        {
            public :
                NotEnoughElements();
                virtual const char* what() const throw();
        };
};

#endif