#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void)
: AForm("Shrubbery", 145, 137), _target("")
{
    std::cout<<GREEN<<"Default constructor called for ShrubberyCreationForm"<<RESET<<std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const& target)
: AForm("Shrubbery", 145, 137), _target(target)
{
    std::cout<<GREEN<<"Constructor with parameter called for ShrubberyCreationForm"<<RESET<<std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
: AForm("Shrubbery", 145, 137), _target(other._target)
{
    std::cout<<GREEN<<"Copy constructor called for ShrubberyCreationForm"<<RESET<<std::endl;
}

ShrubberyCreationForm&  ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    if (this != &other)
    {
        this->_target = other._target;
    }
    std::cout<<"Copy assignment operator of ShrubberyCreationForm called"<<std::endl;
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
    std::cout<<RED<<"Destructor called for ShrubberyCreationForm"<<RESET<<std::endl;
}

const std::string   ShrubberyCreationForm::getTarget(void) const { return this->_target; }

void    ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
    if (this->getSigned() ==  false)
        throw(AForm::SignException());
    if (executor.getGrade() > this->getGradeExe())
        throw(AForm::GradeTooLowException());
    
    std::string     fileName = this->_target + "_shrubbery";
	std::ofstream	outFile(fileName.c_str());
    if (!outFile.is_open())
    {
        std::cerr<<RED<<"❌ ERROR: Can't open file !"<<RESET<<std::endl;
        return ;
    }
	outFile <<GREEN<< 	"                       .  ,****** **  ,                     " << std::endl;
	outFile << 			"            .  ** *** ***//*******//*****                   " << std::endl;
	outFile << 			"          * ,**/******/////*///***//////**                  " << std::endl;
	outFile << 			"       ,***//////////**(((//////**(((*****,*** ******,      " << std::endl;
	outFile << 			"       *//****//*/*******,*/(//(/****/*////*****////****    " << std::endl;
	outFile << 			"      *****///((***/////*/////////***///////*****((/*/**,.  " << std::endl;
	outFile << 			"   **.****//(((((((/*//////****////**(((///****(((/*****    " << std::endl;
	outFile << 			"     */(((***/////****////*//////*/////***/***((*/////****  " << std::endl;
	outFile << 			"    ,**(***/////////**/*((///(////**//****///****////#//****" << std::endl;
	outFile << 			"   **((((((/////////(((((/#((((((((((((/*/////****(%%##(***," << std::endl;
	outFile << 			" ,**((***((((((((/######(((((#(((*/*/*((((((((*%%###(****.  " << std::endl;
	outFile << 			" ***/((((%%#%#%&%#(((#%#(((%%((%%&#((((#***(%#%%##%%%%**    " << std::endl;
	outFile << 			"  *.***/(/(///%%#(%%%%%#%%*%%%&##(%#%%%*(%##%(*%%%%%* ,     " << std::endl;
	outFile << 			"         **(((((((%#####*%%%%%%##%%&(%(%/((((((**           " << std::endl;
	outFile << 			"            *, ,*, .*#&&#####&(/#((##((/.    *              " << std::endl;
	outFile << 			"                         &%(#%#((..#(/                      " << std::endl;
	outFile << 			"                          &#(#((##(#*                       " << std::endl;
	outFile << 			"                          &#((##(#                          " << std::endl;
	outFile << 			"                          &##(#(#                           " << std::endl;
	outFile << 			"                          ###(((*                           " << std::endl;
	outFile << 			"                         (#&#((**                           " << std::endl;
	outFile << 			"                        &&&#(#((#/                          " << std::endl;
	outFile << 			"                       &%##&(#((##*                         " << std::endl;
	outFile << 			"                     &&&&&&#(%(((##(.                       " << std::endl;
	outFile << 			"                     &#%##%%#&%#*%&##(                      " <<RESET<<RESET<< std::endl;
	outFile.close();
}