#include"Set.h"
using namespace std;

int main(){
    int p[5] = {1,4,6,2,8};
    int q[4] = {1,2,3,4};
    Set s(p, sizeof(p)/sizeof(int));
    Set s2(q, sizeof(q)/sizeof(int));
    // Set s2;
    // cin>>s2;
    cout<<s - 2<<endl;
    cout<<s + 9<<endl;
    Set s3 = s + s2;
    Set s4 = s - s2;
    Set s5 = s * s2;
    cout<<s3<<endl;
    cout<<s4<<endl;
    cout<<s5<<endl;
    return 0;
}