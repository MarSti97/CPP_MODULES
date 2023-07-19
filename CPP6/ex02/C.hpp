#ifndef C_HPP
# define C_HPP

#include "Base.hpp"

class C : public Base
{
	private :
		const std::string type;
	public :
		C();
		~C();
};

#endif