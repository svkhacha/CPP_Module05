#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    public:
        AForm(void);
        AForm(std::string const& name, int gradeSign, int gradeExe);
        AForm(const AForm& other);
        AForm&   operator=(const AForm& other);
        virtual ~AForm(void);

        const std::string&  getName(void) const;
        bool                getSigned(void) const;
        int                 getGradeSign(void) const;
        int                 getGradeExe(void) const;
        void                beSigned(Bureaucrat& b);
        virtual void        execute(Bureaucrat const& executor) const = 0;

    public:
        class GradeTooHighException : public std::exception
        {
            const char* what(void) const throw();
        };

        class GradeTooLowException : public std::exception
        {
            const char* what(void) const throw();
        };

        class SignException : public std::exception
        {
            const char* what(void) const throw();
        };

        class RobotomizationSuccessStatus : public std::exception
        {
            const char* what(void) const throw();
        };

    private:
        const std::string   _name;
        bool                _signed;
        const int           _gradeSign;
        const int           _gradeExe;
};

std::ostream& operator<<(std::ostream& out, const AForm& obj);

#endif