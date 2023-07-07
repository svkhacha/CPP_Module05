#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class Bureaucrat;

class ShrubberyCreationForm : public AForm
{
    public:
        ShrubberyCreationForm(void);
        ShrubberyCreationForm(std::string const& target);
        ShrubberyCreationForm(const ShrubberyCreationForm& other);
        ShrubberyCreationForm&  operator=(const ShrubberyCreationForm& other);
        ~ShrubberyCreationForm(void);

        const std::string   getTarget(void) const;
        void                execute(Bureaucrat const& executor) const;

    private:
        std::string _target;
};

#endif