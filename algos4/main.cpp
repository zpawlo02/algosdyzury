
#include <iostream>
using namespace std;



struct pracownik{
    string nazwaPracownika;
    pracownik *poprzedni, *nastepny;
};

struct ListaPracownikow{
    
    pracownik **tabPracownicy;
    
    unsigned int rozmiarTablicy;
    unsigned int ilePracownikow;
    
    pracownik *get(unsigned int& idPracownika)const
    {
        return tabPracownicy[idPracownika];
    }
    
    void usunPracownika(unsigned int& idPracownika)const
    {
        tabPracownicy[idPracownika]=nullptr;
    }
    
    void dodajPracownika(pracownik *& nPracownik){
        if( ilePracownikow == rozmiarTablicy ){
            rozmiarTablicy = rozmiarTablicy * 2;
            
            pracownik **wiekszaTab =
            new pracownik*[rozmiarTablicy];
            
            for(int i = 0; i < ilePracownikow; i++){
                
                wiekszaTab[i] = tabPracownicy[i];
                
            }
            delete[] tabPracownicy;
            tabPracownicy = wiekszaTab;
            delete[] wiekszaTab;

        }
        
        tabPracownicy[ilePracownikow] = nPracownik;
        
        ilePracownikow += 1;
        
    }
};

struct oddzial{
    
    string nazwa;
    unsigned int wielkoscZmiany;
    unsigned int iloscPracownikow;
    pracownik* prac;
    oddzial* nastepnyOddzial;
    ListaPracownikow lPracownikow;
    oddzial(string nazwa, unsigned int wielkoscZmiany){
        this->nazwa = nazwa;
        this->wielkoscZmiany = wielkoscZmiany;
    }
};
/*
struct ListaOddzialow{
    
    oddzial *

};*/

oddzial *ogon = NULL, *glowa = NULL;

void dodajOddzial( string nazwa, int wielkoscZmiany){
    oddzial *nOddzial = new oddzial(nazwa, wielkoscZmiany);
   
    if(ogon == NULL && glowa == NULL){
        ogon = nOddzial;
        glowa = nOddzial;
    }else{
        glowa->nastepnyOddzial = nOddzial;
        glowa = nOddzial;
    }
        
}





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
                        dodajOddzial( nazwaOddzialu, wielkoscZmiany);
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
