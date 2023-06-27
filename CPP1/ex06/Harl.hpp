#ifndef HARL_H
# define HARL_H

#include <iostream>
#include <string>
#include <list>

class Harl
{
	private :
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);
	public :
		Harl();
		~Harl();
		void complain(std::string level);
};

enum levels
{
	DEBUG,
	INFO,
	WARNING,
	ERROR,
};

#endif