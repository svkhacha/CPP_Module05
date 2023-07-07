#include "Intern.hpp"

Intern::Intern(void)
{
    std::cout<<GREEN<<"Default constructor called for Intern"<<RESET<<std::endl;
}

Intern::Intern(const Intern& other)
{
    *this = other;
    std::cout<<GREEN<<"Copy constructor called for Intern"<<RESET<<std::endl;
}

Intern& Intern::operator=(const Intern& other)
{
    if (this != &other)
    {
        *this = other;
    }
    std::cout<<"Copy assigment operator of Intern called"<<std::endl;
    return *this;
}

Intern::~Intern(void)
{
    std::cout<<RED<<"Destructor called for Intern"<<RESET<<std::endl;
}

const char* Intern::InternExistenceException::what(void) const throw()
{
    return (YELLOW "Exception: The form doesn't exist" RESET);
}

AForm*  Intern::_makeShrubbery(const std::string& shrubberyTarget) const
{
    return new ShrubberyCreationForm(shrubberyTarget);
}

AForm*  Intern::_makeRobotomy(const std::string& robotomyTarget) const
{
    return new RobotomyRequestForm(robotomyTarget);
}

AForm*  Intern::_makePresidential(const std::string& presidentialTarget) const
{
    return new PresidentialPardonForm(presidentialTarget);
}

AForm*  Intern::makeForm(const std::string& formName, const std::string& formTarget) const
{
    AForm*  (Intern::*functionPtrs[3])(const std::string& formTarget) const =
        {&Intern::_makeShrubbery, &Intern::_makeRobotomy, &Intern::_makePresidential};
    std::string formNames[3] = {"Shrubbery", "Robotomy", "Presidential"};
    for (int i = 0; i < 3; ++i)
    {
        if (formName.compare(formNames[i]) == 0)
        {
            std::cout<<PINK<<"Intern creates "<<formName<<" form"<<RESET<<std::endl;
            return ((this->*functionPtrs[i])(formTarget));
        }
    }
    throw(Intern::InternExistenceException());
    return NULL;
}

