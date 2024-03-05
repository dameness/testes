#include <iostream>
using namespace std;

int fibonacci(int n){
    if(n==0)
        return 0;
    if(n==1)
        return 1;
    else
        return(fibonacci(n-1) + fibonacci(n-2));
}
bool belongToFibonacci(int num){

    int i=0, n = fibonacci(i);

    if(n==num)
        return true;

    while(n < num){

        n = fibonacci(i++);

        if(n==num)
            return true;
    }

    return false;

}
main(){

    setlocale(LC_ALL, "portuguese");

    int n;
    cout << "Informe um número: ";
    cin >> n;

    if(belongToFibonacci(n)){
        cout << "\nO número " << n << " pertence à sequência de fibonacci!\n";
    }else{
        cout << "\nO número " << n << " NÃO pertence à sequência de fibonacci!\n";
    }
}
