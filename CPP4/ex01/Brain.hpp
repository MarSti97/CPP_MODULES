#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>
#include <string>

class Brain
{
	private :
		std::string ideas[100];
	public :
		Brain();
		Brain(std::string idea);
		Brain(const Brain& copy);
		~Brain();

		Brain& operator = (const Brain& copy);

		void addIdea(const std::string idea);
		void showIdeas();
};

#endif