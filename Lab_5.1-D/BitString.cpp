
//BitString.cpp
#include "BitString.h"

BitString::BitString()
    : Pair()
{}

BitString::BitString(long first, long second) throw(logic_error)
{
    if ((first < 0 || first>20) && (second < 0 || second>20))
        throw logic_error("Condition is not met");

    this->SetFirst(first);
    this->SetSecond(second);
}

BitString::BitString(const BitString& v)
    : Pair(v)
{}




BitString operator ^ (const BitString& a, const BitString& b)
{
    BitString t;
    t.SetFirst(a.GetFirst() ^ b.GetFirst());
    t.SetSecond(a.GetSecond() ^ b.GetSecond());
    return t;
}

BitString operator << (const BitString& a, int n)
{
    BitString t = a;
    long tmp[2];
    const int last_bit = sizeof(long) * 8 - 1;
    for (size_t i = 0; i < n; i++)
    {
        tmp[0] = t.GetFirst() << 1;
        tmp[1] = t.GetFirst() << 1;

        if (t.GetSecond() & (1 << last_bit))
            tmp[0] |= (1 << 0);
        else
            tmp[0] &= ~(1 << 0);

        t.SetFirst(tmp[0]);
        t.SetSecond(tmp[1]);
    }
    return t;
}

BitString operator >> (const BitString& a, int n)
{
    BitString t = a;
    long tmp[2];
    const int last_bit = sizeof(long) * 8 - 1;
    for (size_t i = 0; i < n; i++)
    {
        tmp[0] = t.GetFirst() >> 1;
        tmp[1] = t.GetSecond() >> 1;
        if (t.GetFirst() & (1 << 0))
            tmp[1] |= (1 << last_bit);
        else
            tmp[1] &= ~(1 << last_bit);

        t.SetFirst(tmp[0]);
        t.SetSecond(tmp[1]);
    }
    return t;
}

BitString& BitString::operator --() throw(MyDerivedException)
{
    this->SetFirst(this->GetFirst() - 1);
    if (this->GetFirst() < 0)
        throw new MyDerivedException();
    return *this;
}

BitString& BitString::operator ++() throw(MyException)
{
    this->SetSecond(this->GetSecond() + 1);
    if (this->GetSecond() > 20)
        throw MyException("Second bigger than 20");
    return *this;
}

BitString BitString::operator --(int) throw(MyDerivedException)
{
    BitString a(*this);
    this->SetFirst(this->GetFirst() - 1);
    if (this->GetFirst() < 0)
        throw MyDerivedException();
    return a;
}

BitString BitString::operator ++(int) throw(logic_error)
{
    BitString a(*this);
    this->SetSecond(this->GetSecond() + 1);
    if (this->GetSecond() > 20)
        throw logic_error("Second bigger than 20");
    return a;
}


