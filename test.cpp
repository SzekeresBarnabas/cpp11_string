#include <iostream>
#include "mystring.h"

int main()
{
    MyString alma = MyString("alma", 4);
    //std::cout<< "alma:"<< alma.getrefCount() <<std::endl; // alma = 1

    MyString korte = MyString("korte");
    //std::cout<< "korte:"<< korte.getrefCount() <<std::endl; // korte = 1
    //MyString b = MyString(korte);
    //std::cout<< "korte:"<< korte.getrefCount() <<std::endl; // korte = 2

    //korte + alma;
    //korte+ "korte";
    //korte + 'k';
    //MyString uj = MyString(alma + korte); 
    //MyString uj = alma + korte; 
    //std::cout<< uj.getChar() <<std::endl;
    //b = alma;
    //std::cout<< "korte:"<< korte.getrefCount() <<std::endl; // korte = 1
    //std::cout<< "alma:"<< alma.getrefCount() <<std::endl; // alma = 2
    //alma+=korte;
    //MyString  almai = alma + "f";
    
    //korte += 'i';
    //std::cout<< almai.getChar()<<std::endl;
    //std::cout<< alma.getChar()<<std::endl;
    //std::cout<< korte <<std::endl;
    //std::cout << korte <<std::endl;
    //std::cout<<korte[0]<<std::endl;
    MyString proba;
    std::cin>>proba;
    std::cout<< "ANYÁD" <<std::endl;

    std::cout<< proba <<std::endl;

    //MyString barack = MyString(&alma);
    //char *text = korte.str_->getChar();
    
    //std::cout<< korte.getChar() <<std::endl;
    //std::cout<< korte.getLength() <<std::endl;
    //std::cout<< korte.getrefCount() <<std::endl; //korte = 2
    //b.~MyString();
    //std::cout<< "alma:"<<alma.getrefCount() <<std::endl; //korte = 1
    //korte.~MyString(); 

    //std::cout<< alma.getrefCount() <<std::endl;
    
    //std::cout<< text <<std::endl;
    //std::cout<< alma.getSize() <<std::endl;


    //std::cout<< "Hello World!" <<std::endl;

    return 0;
}