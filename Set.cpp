#include"Set.h"
using namespace std;

//Constructor
Set::Set(int n){
    this->size = n;
    if(this->size != 0){
        this->Data = new int[this->size];
        do
        {
            cout<<"Nhap so phan tu cua mang: ";
            cin>>this->n;
            if(this->n > this->size){
                cout<<"Nhap khong hop le!"<<endl;
            }
        }
        while(this->n > this->size);
        for(int i = 0;i<this->n; i++){
            cout<<"Data["<<i<<"]= ";
            cin>>*(this->Data + i);
        }
    }
}

Set::Set(int *p, int length){
    this->size = length;
    this->Data = new int[this->size];
    this->n = length;
    for(int i = 0;i<this->n;i++){
        *(this->Data + i) = p[i];
    }
}

Set::Set(const Set& s){
    this->size = s.size;
    this->n = s.n;
    this->Data = new int[this->size];
    for(int i = 0;i<n;i++){
        *(this->Data + i) = *(s.Data + i);
    }
}

//Destructor
Set::~Set(){
    delete[] this->Data;
}

//Toan tu truy cap
int& Set::operator[](const int& index){
    static int t = 0;
    if(index >= 0 && index <= this->n){
        return *(this->Data + index);
    }
    return t;
}

//Toan tu =
const Set &Set::operator= (const Set& s){
    this->size = s.size;
    this->n = s.n;
    if(this->Data != nullptr){
        delete[] this->Data;
    }
    this->Data = new int[this->size];
    for(int i = 0;i<this->n;i++){
        (*this)[i] = *(s.Data + i);
    }
}

//+ Them phan tu
Set Set::operator+(const int& x){
    this->n++;
    if(this->n > this->size){
        this->n--;
    }
    else{
        *(this->Data + this-> n - 1) = x;
    }
    return *this;
}

//- Xoa phan tu
Set Set::operator-(const int& x){
    for(int i = 0;i<this->n;i++){
        if(*(this->Data + i) == x){
            for(int j = i;j<this->n;j++){
                *(this->Data + j) = *(this->Data + j + 1);
            }
            this->n--;
            i--;
        }
    }
    return *this;
}

//+ Hop
Set Set::operator+(const Set& s){
    Set s1;
    s1.size = this->size + s.size;
    s1.Data = new int[s1.size];
    s1.n = 0;
    int i = 0, j = 0;
    while (i < this->n && j < s.n)
    {
        if(*(this->Data + i) == *(s.Data + j)) {
            *(s1.Data + s1.n) = *(this->Data + i);
            s1.n ++; i++; j++;
        }
        else if (*(this->Data + i) < *(s.Data + j)){
            *(s1.Data + s1.n) = *(this->Data + i);
            s1.n++; i++; 
        }
        else{
            *(s1.Data + s1.n) = *(s.Data + j);
            s1.n++; j++;
        }
    }
    while(i<this->n){
        *(s1.Data + s1.n) = *(this->Data + i);
        s1.n++; i++;
    }
    while(j<s.n){
        *(s1.Data + s1.n) = *(s.Data + j);
        s1.n++; j++;
    }
    return s1;
}

//- Hieu
Set Set::operator - (const Set& s){
    Set s1 = *this;
    for(int i = 0;i<s.n;i++){
        for(int j = 0;j<s1.n;j++){
            if(s.Data[i]==s1.Data[j]){
                for(int k = j;k<s1.n;k++){
                    s1.Data[k] = s1.Data[k + 1];
                }
                j--;
                s1.n--;
            }
        }
    }
    return s1;
}

// * Giao 
Set Set::operator* (const Set& s){
    Set s1;
    if(this->size <= s.size){
        s1.size = this->size;
    }
    else s1.size = s.size;
    s1.Data = new int[s1.size];
    s1.n = 0;
    for(int i = 0;i<this->n;i++){
        for(int j = 0;j<s.n ;j++){
            if(*(this->Data + i) == *(s.Data + j)){
                *(s1.Data + s1.n) = *(this->Data + i);
                s1.n++;
                break;
            }
        }
    }
    return s1;
}

// ()
bool Set::operator()(const int& x){
    for(int i = 0;i<this->n;i++){
        if(*(this->Data + i) == x) return true;
    }
    return false;
}

//Toan tu <<
ostream& operator<<(ostream& o, const Set& s){
    for(int i = 0;i<s.n - 1;i++){
        o<<*(s.Data + i)<<", ";
    }
    o<<*(s.Data + s.n - 1);
    return o;
}

//Toan tu >>
istream& operator>>(istream& i, Set& s){
    delete[] s.Data;
    do
    {
        cout<<"Nhap so phan tu toi da cua mang: ";
        i>>s.size;
        cout<<"Nhap so phan tu cua mang: ";
        i>>s.n;
        try{
            if(s.n > s.size){
                throw "Nhap khong hop le!";
            }
            s.Data = new int[s.size];
            for(int i = 0;i<s.n;i++){
            cout<<"Data["<<i<<"]= ";
            cin>>*(s.Data + i);
            }
        }
        catch (const char* s){
            cout<<"Error: "<<s<<endl;
        }
    }
    while(s.size < s.n);
    
    return i;
}