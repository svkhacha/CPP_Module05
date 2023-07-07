#ifndef INTERN_HPP
#define INTERN_HPP

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class AForm;

class Intern
{
    public:
        Intern(void);
        Intern(const Intern& other);
        Intern& operator=(const Intern& other);
        ~Intern(void);

        AForm*  makeForm(const std::string& formName, const std::string& formTarget) const;

        class   InternExistenceException : public std::exception
        {
            const char* what(void) const throw();
        };
    
    private:
        AForm*  _makeShrubbery(const std::string& shrubberyTarget) const;
        AForm*  _makeRobotomy(const std::string& robotomyTarget) const;
        AForm*  _makePresidential(const std::string& presidentialTarget) const;
};

#endif