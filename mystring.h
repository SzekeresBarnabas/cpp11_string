#include <cstring>
#include <string.h>
#include <iostream>


class MyString
{
private:
    char* s_;
    int* length_;
    int* prefCount_;

public:

    //létrehozás alapértelmezett konstruktorral
    MyString()
    {
        this->s_ = nullptr;
        this->length_ = nullptr;
        this->prefCount_ = nullptr;
    }

    //létrehozás karaktertömbből
    MyString(char* s, int length)
    {
        this->s_ = new char[length+1];
        this->length_ = new int(length);
       
        strcpy(s_, s);

        this->s_[length+1] = '\0';

        this->prefCount_ = new int(1);
    }
    
    MyString(char* s)
    {   
        int tmp = strlen(s);
        this->length_ = new int(tmp);
        this->s_ = new char[*length_+1];

        strcpy(s_, s);

        //this->s_[*length_+1] = '\0';

        this->prefCount_ = new int(1);
    }

    MyString(const MyString& theOther)
    {
        this->s_ = theOther.s_;
        this->length_ = theOther.length_;
        this->prefCount_ = theOther.prefCount_;

        ++ *prefCount_;
        
    }

    ~MyString()
    {
        this->felszab();
    }

    void felszab()
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

    char* getChar() const
    {
        return this->s_;
    }

    //hossz lekérezése
    int getLength() const
    {
        return *length_;
    }
    int getrefCount() const
    {
        return *this->prefCount_;
    }

    //értékadás:
    void operator=(const MyString& theOther)
    {   
        //ha eddig referált valamire akkor mostmár nem
        this->felszab();

        // mostmár egy mársikra referál
        this->s_ = theOther.s_;
        this->length_ = theOther.length_;
        this->prefCount_ = theOther.prefCount_;

        ++ *prefCount_;
    }

    //két sztring összefűzése operator+
    MyString& operator+(const MyString& theOther) const
    {
        int length = this->getLength()+theOther.getLength();
        char* sTmp = new char[length+1];
        strcpy(sTmp, this->s_);
        strcat(sTmp, theOther.s_);

        MyString* tmp = new MyString(sTmp, length);
        delete[] sTmp;
        return *tmp;
    }

    //két sztring összefűzése operator+=
    MyString& operator+=(const MyString& theOther)
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

    //sztring és karakter összefűzése operator+=
    MyString& operator+=(char theOther)
    {
        int length = this->getLength()+1;
        char* sTmp = new char[length+1];
        strcpy(sTmp, this->s_);
        //strcat(sTmp, &theOther);
        sTmp[length-1] = theOther;
        
        this->felszab();
        this->length_= new int(length);
        this->s_ = sTmp;
        this->s_[length] = '\0'; 
        this->prefCount_ = new int(1);
        return *this;
    }

    //sztring és karakter összefűzése operator+
    MyString& operator+(char *theOther) const
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
    char& operator[](int key)
    {
        return s_[key];
    }
};

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
    is.unget();
    return is;
}



