#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void)
: AForm("Presidential", 25, 5), _target("")
{
    std::cout<<GREEN<<"Default constructor called for PresidentialPardonForm"<<RESET<<std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const& target)
: AForm("Presidential", 25, 5), _target(target)
{
    std::cout<<GREEN<<"Constructor with parameter called for PresidentialPardonForm"<<RESET<<std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
: AForm("Presidential", 25, 5), _target(other._target)
{
    std::cout<<GREEN<<"Copy constructor called for PresidentialPardonForm"<<RESET<<std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
    if (this != &other)
    {
        this->_target = other._target;
    }
    std::cout<<"Copy assignment operator of PresidentialPardonForm called"<<std::endl;
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
    std::cout<<RED<<"Destructor called for PresidentialPardonForm"<<RESET<<std::endl;
}

const std::string   PresidentialPardonForm::getTarget(void) const { return this->_target; }

void    PresidentialPardonForm::execute(Bureaucrat const& executor) const
{
    if (this->getSigned() == false)
        throw(AForm::SignException());
    if (executor.getGrade() > this->getGradeExe())
        throw(AForm::GradeTooLowException());
    std::cout<<BLUE<<this->_target<<" has been pardoned by Zaphod Beeblebrox."<<RESET<<std::endl;
}