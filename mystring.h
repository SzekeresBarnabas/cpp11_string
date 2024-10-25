#include <cstring>
#include <string.h>
#include <iostream>

class MyString
{
private:
    char* s_;
    int* length_;
    int* prefCount_;

    // karakter tomb lekerdezese
    char* getChar() const;

    // felszabaditast vegzo tagfuggveny
    inline void felszab();

public:

    //letrehozas alapertelmezett konstruktorral
    MyString();
    
    //letrehozas karaktertombol es meretbol
    MyString(const char* s, const int length);

    // letrehozas csak karakter tombbol
    MyString(const char* s);
    
    // copy konstruktor
    MyString(const MyString& theOther);

    // mozgato konstruktor
    MyString(MyString&& theOther) noexcept;
    
    // destruktor
    ~MyString() noexcept;
    
//getterek:
    //hossz lekérezése
    int& getLength() const;
    
    // referencia szam lekerdezese
    int& getrefCount() const;
//operator tulterhelesek
    //értékadás operator =
    void operator=(const MyString& theOther);

    //két string összefűzése operator+
    MyString& operator+(const MyString& theOther) const;
    
    //két string összefűzése operator+=
    MyString& operator+=(const MyString& theOther);

    //string és karakter összefűzése operator+=
    MyString& operator+=(const char& theOther);
    

    //string és karakter összefűzése operator+
    MyString& operator+(const char *theOther) const;
    

    //indexelés:
    char& operator[](const int key);

    //kiírás
    friend std::ostream& operator<<(std::ostream& os, const MyString& write);
    
    //beolvasás
    friend std::istream& operator>>(std::istream& is, MyString& read) ;
    
};







