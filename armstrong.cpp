#include<iostream>
#include<math.h>
using namespace std;
int main(){
    int n;
    cin>>n;

    int sum=0;
    int originaln=n;
    int lastdigit ;
    while(n>0){
        lastdigit=n%10;
        cout << lastdigit << " ";
        cout << pow(lastdigit,3) << " ";
        cout << sum << " " ;
        sum = sum + (lastdigit * lastdigit * lastdigit);
        cout << sum << " " ;
        n=n/10;
        cout << n << endl;

    }

    if(sum==originaln){
        cout<<"Armstrong number"<<endl;
    }
    else{
        cout<<"not armstrong number"<<endl;
    }


    return 0;
}