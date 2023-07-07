#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include "AForm.hpp"

#define RED	    "\33[1;31m" // for destructor
#define GREEN	"\33[1;32m" // for constructors
#define YELLOW	"\33[1;33m" // for exceptions
#define BLUE	"\33[1;34m" // for sign
#define CYAN	"\33[1;36m" // for obj information
#define WHITE	"\033[0;37m" // for tree
#define RESET	"\33[0;m"

class AForm;

class Bureaucrat
{
    public:
        Bureaucrat(void);
        Bureaucrat(std::string const& name, int grade);
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat& operator=(const Bureaucrat& other);
        ~Bureaucrat(void);

        const std::string&  getName(void) const;
        int                 getGrade(void) const;
        void                incrementGrade(void);
        void                decrementGrade(void);
        void                signForm(AForm& f);
        void                executeForm(AForm const& form);

    public:
        class GradeTooHighException : public std::exception
        {
            const char* what(void) const throw();
        };

        class GradeTooLowException : public std::exception
        {
            const char* what(void) const throw();
        };

    private:
        const std::string   _name;
        int _grade;
};

std::ostream&   operator<<(std::ostream& out, const Bureaucrat& obj);

#endif