//#include<>
class MyStringValue
{
    char* s_;
    int size_;

public:
    MyStringValue(char* s, int size): size_{size}
    {
        this->s_ = new char(size+1);
        for(int i = 0; i <= size; i++)
        {
            this->s_[i] = s[i];
        }

        this->s_[size+1] = '\0';
    }

    ~MyStringValue()
    {
        delete[] this->s_;
    }

    char* getChar()
    {
        return this->s_;
    }
};
class MyString
{
    MyStringValue* str_;
    int* prefCount;
public:
    MyString(MyStringValue* str): str_{str}
    {
        if(str)
        {
            prefCount = new int{1};
        }
        else
        {
            prefCount = nullptr;
        }

    }
    MyString(MyString& theOther):
    {

    }
};