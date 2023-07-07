#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("Unknown"), _grade(150)
{
    std::cout<<GREEN<<"Default constructor called for Bureaucrat"<<std::endl;
    std::cout<<this->_name<<" created !"<<RESET<<std::endl;
}

Bureaucrat::Bureaucrat(std::string const& name, int grade) : _name(name)
{
    if (grade > 150)
        throw(Bureaucrat::GradeTooLowException());
    if (grade < 1)
        throw(Bureaucrat::GradeTooHighException());
    this->_grade = grade;
    std::cout<<GREEN<<"Constructor with parameters called for Bureaucrat"<<std::endl;
    std::cout<<this->_name<<" created !"<<RESET<<std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade)
{
    std::cout<<GREEN<<"Copy constructor called for Bureaucrat"<<std::endl;
    std::cout<<this->_name<<" copied !"<<RESET<<std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    if (this != &other)
    {
        this->_grade = other._grade;
    }
    std::cout<<"Copy assignment operator of Bureaucrat called"<<std::endl;
    return *this;
}

Bureaucrat::~Bureaucrat(void) 
{
    std::cout<<RED<<"Destructor called for Bureaucrat"<<std::endl;
    std::cout<<this->_name<<" destroyed !"<<RESET<<std::endl;
}

const std::string& Bureaucrat::getName(void) const { return this->_name; }

int Bureaucrat::getGrade(void) const { return this->_grade; }

void    Bureaucrat::incrementGrade(void)
{
    if (this->_grade == 1)
        throw(Bureaucrat::GradeTooHighException());
    this->_grade--;
    std::cout<<BLUE<<this->_name<<"'s grade was incremented :)"<<RESET<<std::endl;
}

void    Bureaucrat::decrementGrade(void)
{
    if (this->_grade == 150)
        throw(Bureaucrat::GradeTooLowException());
    this->_grade++;
    std::cout<<BLUE<<this->_name<<"'s grade was decremented :("<<RESET<<std::endl;
}

const char* Bureaucrat::GradeTooHighException::what(void) const throw()
{
    return (YELLOW "Exception: The grade is too HIGH" RESET);
}

const char* Bureaucrat::GradeTooLowException::what(void) const throw()
{
    return (YELLOW "Exception: The grade is too LOW" RESET);
}

std::ostream&   operator<<(std::ostream& out, const Bureaucrat& obj)
{
    out<<CYAN<<obj.getName()<<", bureaucrat grade ";
    out<<obj.getGrade()<<"."<<RESET;
    return out;
}

void    Bureaucrat::signForm(AForm& f)
{
    if (f.getSigned())
    {
        std::cout<<BLUE<<this->_name<<" signed ";
        std::cout<<f.getName()<<RESET<<std::endl;
    }
    else if (this->_grade <= f.getGradeSign())
    {
        std::cout<<BLUE<<this->_name<<" has not signed yet";
        std::cout<<f.getName()<<"form"<<RESET<<std::endl;
    }
    else
    {
        std::cout<<BLUE<<this->_name<<" couldn’t sign "<<f.getName();
        std::cout<<" because the grade was not enough."<<RESET<<std::endl;
    }
}

void    Bureaucrat::executeForm(AForm const& form)
{
    try
    {
        form.execute(*this);
        std::cout<<BLUE<<this->_name<<" executed "<<form.getName()<<RESET<<std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout<<e.what()<<std::endl;
    }
}