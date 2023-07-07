#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    public:
        Form(void);
        Form(std::string const& name, int gradeSign, int gradeExe);
        Form(const Form& other);
        Form&   operator=(const Form& other);
        ~Form(void);

        const std::string&  getName(void) const;
        bool                getSigned(void) const;
        int                 getGradeSign(void) const;
        int                 getGradeExe(void) const;
        void                beSigned(Bureaucrat& b);

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
        bool                _signed;
        const int           _gradeSign;
        const int           _gradeExe;
};

std::ostream& operator<<(std::ostream& out, const Form& obj);

#endif