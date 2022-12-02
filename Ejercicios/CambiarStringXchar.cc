#include <iostream>
using namespace std;
int main(){

    char c[6]="ii ii";
    string letra;
    char vasinga[5];
    string v="bb bb";

    letra=c;
//    vasinga[5]==v;
    cout<<letra<<endl;

    for(int t=0; t<5; t++){

        vasinga[t]=v.at(t);

    }
    for(int t=0; t<5; t++){
        cout<<vasinga[t];
    }

    return 0;
}