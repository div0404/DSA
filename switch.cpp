#include<iostream>
using namespace std;
//Hello in different languages
int main (){
    char button;
    cin>>button;

    switch(button){
        case 'a':
        cout<<"Namaste"<<endl;
        break;

        case 'b':
        cout<<"Hello"<<endl;
        break;

        case 'c':
        cout<<"Hola"<<endl;
        break;

        case 'd':
        cout<<"Ciao"<<endl;
        break;

        case 'e':
        cout<<"Solut"<<endl;
        break;

        default:
        cout<<"I'm still learning";
    }
    return 0;
}