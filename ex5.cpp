#include <iostream>
using namespace std;

struct NoPilha{
    char dado;
    NoPilha *proximo;
};

struct Pilha{
    struct NoPilha *topo;

    Pilha(){
        topo = nullptr;
    }
};

void empilhar(Pilha *p, char dado){
    NoPilha *novo = new NoPilha();

    novo->dado = dado;
    novo->proximo = p->topo;
    p->topo = novo;
}

char desempilhar(Pilha *p){

    char dado = ' ';

    if(p->topo != nullptr){
        dado = p->topo->dado;
        NoPilha *apagar = p->topo;
        p->topo = p->topo->proximo;
        delete apagar;
    }

    return dado;
}

void inverterFrase(Pilha *p, string frase){
    for(int i=0; i<frase.size(); i++){

        empilhar(p, frase[i]);


        if(i == frase.size()-1){
            while(p->topo!=nullptr){
                cout << desempilhar(p);
            }
            cout << " ";
        }
    }
}

main(){
    setlocale(LC_ALL, "portuguese");

    Pilha p;
    string frase = "teste de inversão";

    inverterFrase(&p, frase);
}
