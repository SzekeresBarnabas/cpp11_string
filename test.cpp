#include <iostream>
#include "mystring.h"

int main()
{
    // referencia szamlalas
    MyString a = "alma";
    MyString b = a;
    MyString c = b;
    std::cout << "'a' = alma" << std::endl << "'b' = 'a', 'c' = 'b'" << std::endl;
    std::cout << "'c': " << c << std::endl;
    std::cout <<"'a' refCount: " << a.getrefCount() << std::endl;
    c.~MyString();
    std::cout << "'a' refcount 'c' destruktora utan: " << a.getrefCount() << std::endl;

    //operator+=
    b+=a;
    std::cout << std::endl << "'b' += 'a': "<< b << std::endl;

    b.~MyString();
    a.~MyString();

    MyString barack = "barack";
    barack += 's';
    std::cout << std::endl << "barack += 's': " << barack << std::endl;

    barack.~MyString();
    
    //operator +
    MyString korte = "korte";
    MyString alma = "alma";
    MyString almaKorte = alma + korte;
    std::cout << std::endl << "alma + korte: " << almaKorte  << std::endl;
    // operator []
    std::cout << std::endl << "alma[3]: " << alma[3] << std::endl;

    almaKorte.~MyString();
    alma.~MyString();
    korte.~MyString();

    std::cout << std::endl << "irjon be egy tetszoleges stringet:" << std::endl;
    MyString tetszoleges;  // létrehozas alapertelmezett konstruktorral
    std::cin >> tetszoleges;
    std::cout << "a megadott string: " << tetszoleges << std::endl;
    std::cout << "hossza: " << tetszoleges.getLength() << std::endl;

    tetszoleges.felszab();


    return 0;
}