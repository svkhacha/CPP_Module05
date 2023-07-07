#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
    try
    {
        Bureaucrat b("Svetlana", 100);
        Form    f("Num1", 100, 150);
        std::cout<<b<<std::endl;
        std::cout<<f<<std::endl;
        f.beSigned(b);
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
        Form    f1("Num2", 100, 150);
        std::cout<<f1<<std::endl;
        b1.signForm(f1);
        // std::cout<<b1<<std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout<<e.what()<<std::endl;
    }
    std::cout<<std::endl;
    try
    {
        Bureaucrat b3("Esimov", 125);
        std::cout<<b3<<std::endl;
        Form    f2("Num3", 145, 137);
        std::cout<<f2<<std::endl;
        f2.beSigned(b3);
        std::cout<<f2<<std::endl;
        b3.signForm(f2);
    }
    catch(const std::exception& e)
    {
        std::cout<<e.what()<<std::endl;
    }
    std::cout<<std::endl;
    try
    {
        Bureaucrat b4("Svetlana_2", 100);
        Form    f3("Num4", 78, 150);
        std::cout<<b4<<std::endl;
        std::cout<<f3<<std::endl;
        f3.beSigned(b4);
    }
    catch(const std::exception& e)
    {
        std::cout<<e.what()<<std::endl;
    }
}