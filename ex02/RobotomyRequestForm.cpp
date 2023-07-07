#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void)
: AForm("Robotomy", 72, 45), _target("")
{
    std::cout<<GREEN<<"Default constructor called for RobotomyRequestForm"<<RESET<<std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const& target)
: AForm("Robotomy", 72, 45), _target(target)
{
    std::cout<<GREEN<<"Constructor with parameter called for RobotomyRequestForm"<<RESET<<std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
: AForm("Robotomy", 72, 45), _target(other._target)
{
    std::cout<<GREEN<<"Copy constructor called for RobotomyRequestForm"<<RESET<<std::endl;
}

RobotomyRequestForm&    RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    if (this != &other)
    {
        this->_target = other._target;
    }
    std::cout<<"Copy assignment operator of RobotomyRequestForm called"<<std::endl;
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
    std::cout<<RED<<"Destructor called for RobotomyRequestForm"<<RESET<<std::endl;
}

const std::string   RobotomyRequestForm::getTarget(void) const { return this->_target; }

void    RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
    if (this->getSigned() == false)
        throw(AForm::SignException());
    if (executor.getGrade() > this->getGradeExe())
        throw(AForm::GradeTooLowException());
    std::srand(time(NULL));
    if (std::rand() % 2 == 0)
    {
        std::cout<<BLUE<<this->_target;
        std::cout<<" has been robotomized successfully 50% of the time"<<RESET<<std::endl;
    }
    else
        throw(AForm::RobotomizationSuccessStatus());
}