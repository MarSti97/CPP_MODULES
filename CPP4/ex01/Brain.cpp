#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "A brain has developed!" << std::endl;
}

Brain::Brain(std::string idea)
{
	this->ideas[0] = idea;
	std::cout << "A brain has developed, with a single idea!" << std::endl;
}

Brain::Brain(const Brain& copy)
{
	*this = copy;
	std::cout << "Brain copied with copy constructor" << std::endl;
}

Brain& Brain::operator = (const Brain& copy)
{
	for (int i = 0; i < 99; i++)
	{
		if (copy.ideas[i] == "")
			break ;
		this->ideas[i] = copy.ideas[i];
	}
	return *this;	
}

Brain::~Brain()
{
	std::cout << "Brain destructed" << std::endl;
}

void Brain::addIdea(const std::string idea)
{
	int i = 0;

	while (this->ideas[i] != "" && i != 99)
		i++;
	this->ideas[i] = idea;
}

void Brain::showIdeas()
{
	int i = 0;

	if (this->ideas[i] == ""){
		std::cout << "This brain contains no ideas..." << std::endl;
		return ;
	}
	while (this->ideas[i] != "" && i != 99){
		std::cout << i + 1 << " : " << this->ideas[i] << std::endl;
		i++;
	}
}