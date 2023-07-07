#include "Form.hpp"

Form::Form(void)
: _name("Unknown"), _signed(false), _gradeSign(150), _gradeExe(150)
{
    std::cout<<GREEN<<"Default constructor called for Form"<<std::endl;
    std::cout<<this->_name<<" form created !"<<RESET<<std::endl;
}

Form::Form(std::string const& name, int gradeSign, int gradeExe)
: _name(name), _signed(false), _gradeSign(gradeSign), _gradeExe(gradeExe)
{
    if (gradeSign > 150 || gradeExe > 150)
        throw(Form::GradeTooLowException());
    if (gradeSign < 1 || gradeExe < 1)
        throw(Form::GradeTooHighException());
    std::cout<<GREEN<<"Constructor with parameters called for Form"<<std::endl;
    std::cout<<this->_name<<" form created !"<<RESET<<std::endl;
}

Form::Form(const Form& other)
: _name(other._name), _signed(other._signed), _gradeSign(other._gradeSign), _gradeExe(other._gradeExe)
{
    std::cout<<GREEN<<"Copy constructor called for Form"<<std::endl;
    std::cout<<this->_name<<" form copied !"<<RESET<<std::endl;
}

Form&   Form::operator=(const Form& other)
{
    if (this != &other)
    {
        this->_signed = other._signed;
    }
    std::cout<<"Copy assignment operator of Form called"<<std::endl;
    return *this;
}

Form::~Form(void)
{
    std::cout<<RED<<"Destructor called for Form"<<std::endl;
    std::cout<<this->_name<<" form destroyed !"<<RESET<<std::endl;
}

const std::string&  Form::getName(void) const { return this->_name; }

bool    Form::getSigned(void) const { return this->_signed; }

int Form::getGradeSign(void) const { return this->_gradeSign; }

int Form::getGradeExe(void) const {return this->_gradeExe; }

void    Form::beSigned(Bureaucrat& b)
{
    if (b.getGrade() > this->_gradeSign)
         throw(Form::GradeTooLowException());
    this->_signed = true;
    std::cout<<BLUE<<this->_name<<" was signed by ";
    std::cout<<b.getName()<<RESET<<std::endl;
}

const char* Form::GradeTooHighException::what(void) const throw()
{
    return (YELLOW "Exception: The grade is too HIGH" RESET);
}

const char* Form::GradeTooLowException::what(void) const throw()
{
    return (YELLOW "Exception: The grade is too LOW" RESET);
}

std::ostream& operator<<(std::ostream& out, const Form& obj)
{
    out<<CYAN<<"Name: "<<RESET<<obj.getName()<<std::endl;
    out<<CYAN<<"Signed: "<<RESET<<obj.getSigned()<<std::endl;
    out<<CYAN<<"GradeSign: "<<RESET<<obj.getGradeSign()<<std::endl;
    out<<CYAN<<"GradeExecute: "<<RESET<<obj.getGradeExe();
    return out;
}

