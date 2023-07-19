#ifndef B_HPP
# define B_HPP

#include "Base.hpp"

class B : public Base
{
	private :
		const std::string type;
	public :
		B();
		~B();
};

#endif