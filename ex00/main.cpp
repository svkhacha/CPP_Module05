#include "Bureaucrat.hpp"

int main(void)
{
    try
    {
        Bureaucrat b("Svetlana", 10);
        std::cout<<b<<std::endl;
        b.decrementGrade();
        std::cout<<b<<std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout<<e.what()<<std::endl;
    }
    std::cout<<std::endl;
    try
    {
        Bureaucrat b1("Vahe", 150);
        std::cout<<b1 <<std::endl;
        Bureaucrat b2(b1);
        std::cout<<b2<<std::endl;
        b2.incrementGrade();
        b1.decrementGrade();
        std::cout<<b1<<std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout<<e.what()<<std::endl;
    }
    std::cout<<std::endl;
    try
    {
        Bureaucrat b3("Esimov", 0);
        std::cout<<b3<<std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout<<e.what()<<std::endl;
    }
}