//#include<>
class MyString
{
    char* s_;
    int size_;

public:
    MyString(char* s, int size): size_{size}
    {
        this->s_ = new char(size+1);
        for(int i = 0; i <= size; i++)
        {
            this->s_[i] = s[i];
        }
    }

    ~MyString()
    {
        delete[] this->s_;
    }

    char* getChar()
    {
        return this->s_;
    }
};