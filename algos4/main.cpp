
#include <iostream>
using namespace std;


struct oddzial{
    
    string nazwa;
    unsigned int wielkoscZmiany;
    unsigned int iloscPracownikow;
   // pracownik* prac;
    oddzial* nastepnyOddzial;
    oddzial(string nazwa, unsigned int wielkoscZmiany){
        this->nazwa = nazwa;
        this->wielkoscZmiany = wielkoscZmiany;
    }
    
};

struct pracownik{
    string nazwaPracownika;
    pracownik *poprzedni, *nastepny;
    oddzial *nOddzial;
    
    pracownik(string nazwa, oddzial *nOddzial){
        this->nOddzial = nOddzial;
        this->nazwaPracownika = nazwa;
    }
    
};

struct ListaPracownikow{
    
    pracownik **tabPracownicy;
    
    unsigned int rozmiarTablicy;
    unsigned int ilePracownikow;
    
    pracownik *get(unsigned int  idPracownika)const
    {
        return tabPracownicy[idPracownika];
    }
    
    void usunPracownika(unsigned int  idPracownika)const
    {
        tabPracownicy[idPracownika]=nullptr;
    }
    
    void dodajPracownika(pracownik *& nPracownik){
        if(rozmiarTablicy > 0){
          nPracownik->poprzedni = tabPracownicy[rozmiarTablicy-1];
            tabPracownicy[rozmiarTablicy-1]->nastepny = nPracownik;
        }else{
            nPracownik->poprzedni = nullptr;
        }
        
        
        if( ilePracownikow == rozmiarTablicy ){
            rozmiarTablicy += 1;
            
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

void dodajPracownika(ListaPracownikow lPracownikow, string nazwaPracownika, string nazwaOddzialu){
    oddzial *itOddzial = ogon;
    while(itOddzial->nazwa != nazwaOddzialu){
        itOddzial++;
    }
    pracownik *nPracownik = new pracownik(nazwaPracownika, itOddzial);
    lPracownikow.dodajPracownika(nPracownik);
    
}


void usunOddzial(string nazwaOddzialu){
    oddzial *itOddzial = ogon;
    while(itOddzial->nazwa != nazwaOddzialu){
        itOddzial++;
    }
    
    itOddzial = nullptr;
    
}

void przeniesPracownika(ListaPracownikow lPracownikow, unsigned int idPracownika, string nazwaOddzialu){
    
    oddzial *itOddzial = ogon;
    while(itOddzial->nazwa != nazwaOddzialu){
        itOddzial++;
    }
    lPracownikow.get(idPracownika)->nOddzial = itOddzial;
}

void edycjaOddzialu(string nazwaOddzialu, string nowaNazwa, unsigned int nowaWielkoscZmiany){
    oddzial *itOddzial = ogon;
    while(itOddzial->nazwa != nazwaOddzialu){
        itOddzial++;
    }
    itOddzial->nazwa = nowaNazwa;
    itOddzial->wielkoscZmiany = nowaWielkoscZmiany;
}


int main(int argc, const char * argv[]) {
    ListaPracownikow lPracownikow;
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
                        dodajOddzial(nazwaOddzialu, wielkoscZmiany);
                        break;
                        
                    case 'e':
                        cin >> nazwaPracownika;
                        cin >> nazwaOddzialu;
                        dodajPracownika(lPracownikow, nazwaPracownika, nazwaOddzialu);
                        break;
                }
                break;
                
            case 'd':
                cin >> operationType2;
            
                    switch (operationType2) {
                        case 'w':
                            cin >> nazwaOddzialu;
                            usunOddzial(nazwaOddzialu);
                            break;
                                       
                        case 'e':
                            cin >> idPracownika;
                            lPracownikow.usunPracownika((unsigned int) idPracownika);
                            break;
                }
                break;
                
            case 'm':
                cin >> idPracownika;
                cin >> nazwaOddzialu;
                przeniesPracownika(lPracownikow, (unsigned int) idPracownika, nazwaOddzialu);
                break;
                
            case 'e':
                cin >> operationType2;
            
                    switch (operationType2) {
                        case 'w':
                            cin >> nazwaOddzialu;
                            cin >> nowaNazwaOdzialu;
                            cin >> nowaWielkoscZmiany;
                            edycjaOddzialu(nazwaPracownika, nowaNazwaOdzialu, (unsigned int) nowaWielkoscZmiany);
                            break;
                                       
                        case 'e':
                            cin >> idPracownika;
                            cin >> nazwaPracownika;
                            lPracownikow.get((unsigned int) idPracownika)->nazwaPracownika = nazwaPracownika;
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
