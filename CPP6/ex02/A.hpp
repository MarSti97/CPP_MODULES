#ifndef A_HPP
# define A_HPP

#include "Base.hpp"

class A : public Base
{
	private :
		const std::string type;
	public :
		A();
		~A();
};

#endif