#include "mystring.h"

//letrehozas alapertelmezett konstruktorral
MyString::MyString(): s_{nullptr}, length_{nullptr}, prefCount_{nullptr} {}


// letrehozas karaktertombol es meretbol
MyString::MyString(const char* s, const int length)
{
    this->s_ = new char[length+1];
    this->length_ = new int(length);
    
    strcpy(s_, s);

    this->s_[length+1] = '\0';

    this->prefCount_ = new int(1);
}

// letrehozas csak karakter tombbol
MyString::MyString(const char* s)
{   
    int tmp = strlen(s);
    this->length_ = new int(tmp);
    this->s_ = new char[*length_+1];

    strcpy(s_, s);

    this->prefCount_ = new int(1);
}

// copy konstruktorcc
MyString::MyString(const MyString& theOther)
{
    this->s_ = theOther.s_;
    this->length_ = theOther.length_;
    this->prefCount_ = theOther.prefCount_;

    ++ *prefCount_;
}

//mozgato konstruktor
MyString::MyString(MyString&& theOther) noexcept : s_{theOther.s_}, length_{theOther.length_}, prefCount_{theOther.prefCount_}
{
    theOther.s_ = nullptr;
    theOther.length_ = nullptr;
    theOther.prefCount_ = nullptr;
}

// a felszabaditas vegzo tagfuggveny
inline void MyString::felszab()
{
    if(prefCount_ !=nullptr)
    {
        --*prefCount_;

        if(*prefCount_ == 0)
        {
            delete prefCount_;
            delete length_;
            delete[] this->s_;
            
            prefCount_ = nullptr;
            length_= nullptr;
            s_ = nullptr; 
        }
        else
        {
            prefCount_ = nullptr;
            length_= nullptr;
            s_ = nullptr;
        }
    }
}

// destruktor
MyString::~MyString() noexcept
{
    this->felszab();
}

//getterek
//hossz lekérezése
int& MyString::getLength() const
{
    return *length_;
}

// referencia szam lekerdezese
int& MyString::getrefCount() const
{
    return *this->prefCount_;
}

// karakter tomb lekerdezese
char* MyString::getChar() const
{
    return this->s_;
}

//értékadás operator =
void MyString::operator=(const MyString& theOther)
{   
    //ha eddig referált valamire akkor mostmár nem
    this->felszab();

    // mostmár egy mársikra referál
    this->s_ = theOther.s_;
    this->length_ = theOther.length_;
    this->prefCount_ = theOther.prefCount_;

    ++ *prefCount_;
}

//két string összefűzése operator+
MyString& MyString::operator+(const MyString& theOther) const
{
    int length = this->getLength()+theOther.getLength();
    char* sTmp = new char[length+1];
    strcpy(sTmp, this->s_);
    strcat(sTmp, theOther.s_);

    MyString* tmp = new MyString(sTmp, length);
    delete[] sTmp;
    return *tmp;
}

//két string összefűzése operator+=
MyString& MyString::operator+=(const MyString& theOther)
{
    int length = this->getLength()+theOther.getLength();
    char* sTmp = new char[length+1];
    strcpy(sTmp, this->s_);
    strcat(sTmp, theOther.s_);
    
    this->felszab();
    this->length_= new int(length+1);
    this->s_ = sTmp;
    this->s_[length+1] = '\0'; 
    this->prefCount_ = new int(1);
    return *this;
}
//string és karakter összefűzése operator+=
MyString& MyString::operator+=(const char& theOther)
{
    int length = this->getLength()+1;
    char* sTmp = new char[length+1];
    strcpy(sTmp, this->s_);
    sTmp[length-1] = theOther;
    
    this->felszab();
    this->length_= new int(length);
    this->s_ = sTmp;
    this->s_[length] = '\0'; 
    this->prefCount_ = new int(1);
    return *this;
}

//string és karakter összefűzése operator+
MyString& MyString::operator+(const char *theOther) const
{
    int tmpLength = this->getLength() + strlen(theOther);
    char* sTmp = new char[tmpLength];
    strcpy(sTmp, this->s_);
    strcat(sTmp, theOther);
        
    MyString* osszeg = new MyString(sTmp, tmpLength);
    delete[]sTmp;
    return *osszeg;
}

//indexelés:
char& MyString::operator[](const int key)
{
    if (key < 0 || key >= *length_)
    {
        throw std::out_of_range("a megadott index nem megfelelo");
    }
    return s_[key];
}

//kiírás
std::ostream& operator<<(std::ostream& os, const MyString& write)
{
    os<<write.getChar();
    return os;
}

//beolvasás
std::istream& operator>>(std::istream& is, MyString& read)
{
    read.felszab(); // Töröljük a meglévő tartalmat
    char ch;
    is.get(ch);
    MyString* tmpS = new MyString(&ch, (strlen(&ch)-6));
    while(is.get(ch) && ch!='\n')
    {
        tmpS->operator+=(ch);
    }
   
    read = *tmpS;
    return is;
}
