#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class Bureaucrat;

class RobotomyRequestForm : public AForm
{
    public:
        RobotomyRequestForm(void);
        RobotomyRequestForm(std::string const& target);
        RobotomyRequestForm(const RobotomyRequestForm& other);
        RobotomyRequestForm&    operator=(const RobotomyRequestForm& other);
        ~RobotomyRequestForm(void);

        const std::string   getTarget(void) const;
        void                execute(Bureaucrat const& executor) const;
    
    private:
        std::string _target;
};

#endif