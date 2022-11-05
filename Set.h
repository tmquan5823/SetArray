#include<iostream>
using namespace std;

class Set{
    private:
        int *Data;
        int n;
        int size;
    public:
        Set(int n = 0);
        Set(int*, int);
        Set(const Set&);
        ~Set();
        int &operator[] (const int&);
        const Set& operator = (const Set&);
        Set operator+ (const int&);
        Set operator- (const int&);
        Set operator + (const Set&);
        Set operator - (const Set&);
        Set operator * (const Set&);
        bool operator()(const int&);
        friend ostream& operator<<(ostream&, const Set&);
        friend istream& operator>>(istream&, Set&);
};