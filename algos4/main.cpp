//
//  main.cpp
//  algos4
//
//  Created by Paweł Zieliński on 21/10/2020.
//  Copyright © 2020 Paweł Zieliński. All rights reserved.
//
#include <iostream>
using namespace std;


struct pracownik{
    int id;
    string nazwaPracownika;
};

struct oddzial{
    string nazwa;
    pracownik pracownicy;
    int wielkosc_oddzialu;
    string nazwaKierownika;
    oddzial(string nazwa, int wielkosc_odzialu){
        pracownicy = *new pracownik[wielkosc_odzialu];
        this->nazwa = nazwa;
    }
    
    
};

struct ListaOddzialow{
    oddzial oddzialy;// = *new oddzial[1];

    void dodajOddzial(string nazwaOddzialu, int wielkoscZmiany){
        if(oddzialy != NULL){
            int size = sizeof(oddzial)/sizeof(oddzial[0]);
        }else{
            oddzialy = *new oddzial[1]
        }
        
    }
};

int main(int argc, const char * argv[]) {
    int n, iloscZmian,nowaWielkoscZmiany;
    cin >> n;
    char operationType1, operationType2;
    string nazwaOddzialu, nazwaPracownika,
    nowaNazwaOdzialu;
    int wielkoscZmiany, idPracownika;
    
    for(int i = 0; i < n; i++){
        cin >> operationType1;
        switch (operationType1) {
            case 'a':
                cin >> operationType2;
                
                switch (operationType2) {
                    case 'w':
                        cin >> nazwaOddzialu;
                        cin >> wielkoscZmiany;
                        break;
                        
                    case 'e':
                        cin >> nazwaPracownika;
                        cin >> nazwaOddzialu;
                        break;
                }
                break;
                
            case 'd':
                cin >> operationType2;
            
                    switch (operationType2) {
                        case 'w':
                            cin >> nazwaOddzialu;
                            break;
                                       
                        case 'e':
                            cin >> idPracownika;
                            break;
                }
                break;
                
            case 'm':
                cin >> idPracownika;
                cin >> nazwaOddzialu;
                break;
                
            case 'e':
                cin >> operationType2;
            
                    switch (operationType2) {
                        case 'w':
                            cin >> nazwaOddzialu;
                            cin >> nowaNazwaOdzialu;
                            cin >> nowaWielkoscZmiany;
                            break;
                                       
                        case 'e':
                            cin >> idPracownika;
                            cin >> nazwaPracownika;
                            break;
                }
                break;
                
            case 's':
                cin >> iloscZmian;
                break;
                
                //jednokierunkowa z oddzialami
                //cykliczna dwu pracownicy
                //wskazniki na pracownikow
        }
        
    }
    return 0;
}
