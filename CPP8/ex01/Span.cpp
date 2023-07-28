#include "Span.hpp"

Span::Span() {}

Span::Span(unsigned int n) : N(n) {}

Span::Span(const Span& copy) : N(copy.N)
{
    vec.resize(N);
    std::copy(copy.vec.begin(), copy.vec.end(), vec.begin());
}

Span::~Span() {}

Span& Span::operator = (const Span& copy)
{
    if (this != &copy)
    {
        this->N = copy.N;
        this->vec.clear();
        this->vec.resize(N);
        std::copy(copy.vec.begin(), copy.vec.end(), this->vec.begin());
    }
    return *this;
}

void    Span::addNumber(int nbr)
{
    if (vec.size() < N)
        vec.push_back(nbr);
    else
        throw SpanIsFull();
}

int     Span::shortestSpan()
{
    if (vec.empty() || vec.size() == 1)
        throw NotEnoughElements();
    std::vector<int> temp(vec.size());
    std::copy(vec.begin(), vec.end(), temp.begin());
    std::sort(temp.begin(), temp.end());
    int span;
    int best = INT_MAX;
    for (unsigned int it = 1; it != (vec.size() - 1); it++){
        span = temp[it] - temp[it - 1];
        if (best > span)
            best = span;
    }
    return best;
}

int     Span::longestSpan()
{
    if (vec.empty() || vec.size() == 1)
        throw NotEnoughElements();
    int span;
    int best = 0;
    for (unsigned int it = 1; it != vec.size() - 1; it++){
        span = abs(vec[it] - vec[it - 1]);
        if (best < span)
            best = span;
    }
    return best;
}

void    Span::fillSpan()
{
    int random;  
    for (unsigned int i = vec.size(); i != N; i++)
    {
        random = rand() % N;
        vec.push_back(random);
    }
}

void    Span::printSpan()
{
    std::vector<int>::iterator it;
    for (it = vec.begin(); it != vec.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}

Span::SpanIsFull::SpanIsFull() {}

const char* Span::SpanIsFull::what() const throw(){
	return ("You've reached the maximum of your array");
}

Span::NotEnoughElements::NotEnoughElements() {}

const char* Span::NotEnoughElements::what() const throw(){
	return ("The array is either empty or has only one element, cannot perform action.");
}