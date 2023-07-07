#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class Bureaucrat;

class PresidentialPardonForm : public AForm
{
    public:
        PresidentialPardonForm(void);
        PresidentialPardonForm(std::string const& target);
        PresidentialPardonForm(const PresidentialPardonForm& other);
        PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
        ~PresidentialPardonForm(void);

        const std::string   getTarget(void) const;
        void                execute(Bureaucrat const& executor) const;

    private:
        std::string _target;
};

#endif