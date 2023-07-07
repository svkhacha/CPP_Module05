#include "AForm.hpp"

AForm::AForm(void)
: _name("Unknown"), _signed(false), _gradeSign(150), _gradeExe(150)
{
    std::cout<<GREEN<<"Default constructor called for AForm"<<std::endl;
    std::cout<<this->_name<<" form created !"<<RESET<<std::endl;
}

AForm::AForm(std::string const& name, int gradeSign, int gradeExe)
: _name(name), _signed(false), _gradeSign(gradeSign), _gradeExe(gradeExe)
{
    if (gradeSign > 150 || gradeExe > 150)
        throw(AForm::GradeTooLowException());
    if (gradeSign < 1 || gradeExe < 1)
        throw(AForm::GradeTooHighException());
    std::cout<<GREEN<<"Constructor with parameters called for AForm"<<std::endl;
    std::cout<<this->_name<<" form created !"<<RESET<<std::endl;
}

AForm::AForm(const AForm& other)
: _name(other._name), _signed(other._signed), _gradeSign(other._gradeSign), _gradeExe(other._gradeExe)
{
    std::cout<<GREEN<<"Copy constructor called for AForm"<<std::endl;
    std::cout<<this->_name<<" form copied !"<<RESET<<std::endl;
}

AForm&   AForm::operator=(const AForm& other)
{
    if (this != &other)
    {
        this->_signed = other._signed;
    }
    std::cout<<"Copy assignment operator of AForm called"<<std::endl;
    return *this;
}

AForm::~AForm(void)
{
    std::cout<<RED<<"Destructor called for AForm"<<std::endl;
    std::cout<<this->_name<<" form destroyed !"<<RESET<<std::endl;
}

const std::string&  AForm::getName(void) const { return this->_name; }

bool    AForm::getSigned(void) const { return this->_signed; }

int AForm::getGradeSign(void) const { return this->_gradeSign; }

int AForm::getGradeExe(void) const {return this->_gradeExe; }

void    AForm::beSigned(Bureaucrat& b)
{
    if (b.getGrade() > this->_gradeSign)
         throw(AForm::GradeTooLowException());
    this->_signed = true;
    std::cout<<BLUE<<this->_name<<" was signed by ";
    std::cout<<b.getName()<<RESET<<std::endl;
}

const char* AForm::GradeTooHighException::what(void) const throw()
{
    return (YELLOW "Exception: The grade is too HIGH" RESET);
}

const char* AForm::GradeTooLowException::what(void) const throw()
{
    return (YELLOW "Exception: The grade is too LOW" RESET);
}

const char* AForm::SignException::what(void) const throw()
{
    return (YELLOW "Exception: The form is unsigned" RESET);
}

const char* AForm::RobotomizationSuccessStatus::what(void) const throw()
{
    return (YELLOW "Exception: The target hasn't been robotomized successfully" RESET);
}

std::ostream& operator<<(std::ostream& out, const AForm& obj)
{
    out<<CYAN<<"Name: "<<RESET<<obj.getName()<<std::endl;
    out<<CYAN<<"Signed: "<<RESET<<obj.getSigned()<<std::endl;
    out<<CYAN<<"GradeSign: "<<RESET<<obj.getGradeSign()<<std::endl;
    out<<CYAN<<"GradeExecute: "<<RESET<<obj.getGradeExe();
    return out;
}

