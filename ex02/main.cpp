#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	try
    {
        Bureaucrat              b("Svetlana", 25);
        Bureaucrat              b1("Vahe", 4);
        ShrubberyCreationForm   shrubbery("Home");
        RobotomyRequestForm     robotomy("Robotik");
        PresidentialPardonForm  presidential("President");

        shrubbery.beSigned(b);
        b.executeForm(shrubbery);
        robotomy.beSigned(b);
        b.executeForm(robotomy);
        presidential.beSigned(b1);
        b1.executeForm(presidential);
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}