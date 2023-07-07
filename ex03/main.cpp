#include "Intern.hpp"

int	main(void)
{
	try
	{
		Intern	intern;
		AForm	*form;
		
		form = intern.makeForm("Shrubbery", "home");
		std::cout<<*form<<std::endl;
		delete form;
	}
	catch (const std::exception &e)
	{
		std::cout<<e.what()<< std::endl;
	}
	try
	{
		Intern	intern1;
		AForm	*form1;

		form1 = intern1.makeForm("Robotomy", "robotik");
		std::cout<<*form1<<std::endl;
		delete form1;
	}
	catch (const std::exception &e)
	{
		std::cout<<e.what()<< std::endl;
	}
	try
	{
		Intern	intern2;
		AForm	*form2;

		form2 = intern2.makeForm("Presidential", "president");
		std::cout<<*form2<<std::endl;
		delete form2;
	}
	catch (const std::exception &e)
	{
		std::cout<<e.what()<< std::endl;
	}
	try
	{
		Intern	intern3;
		AForm	*form3;

		form3 = intern3.makeForm("blaa", "blaa");
		std::cout<<*form3<<std::endl;
		delete form3;
	}
	catch (const std::exception &e)
	{
		std::cout<<e.what()<< std::endl;
	}
	return (0);
}
