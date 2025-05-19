#include <iostream>
using namespace std;
void vesnice(int ziv,int maxziv,int eng,int attck,int volba, int gold){
cout << "Po ceste jsi narazil na vesnici umoznujici tyto akce, jakou si vyberes?"<< endl;
cout << "Stav goldu: "<< gold << endl;
cout << "1 - Doplneni zivotu - 3 gold" << endl;
cout << "2 - Vylepseni maximalnich zivotu - 2 goldy" << endl;
cout << "3 - Vylepseni energie - 2 goldy" << endl;
cout << "4 - Vylepseni utoku - 3 goldy" << endl;
cout << "5 - Odejit"<<endl;
cout << "Zadej svou volbu: ";
cin >> volba;
switch (volba){
case 1:
    ziv = maxziv;
    if(gold <= 0){
        cout << "Nemas dostatek goldu. Pokracujeme dal.";
    }else{
    cout << "Zivoty byly doplneny";}
    break;
case 2:
    if(gold <= 0){
        cout << "Nemas dostatek goldu. Pokracujeme dal.";
    }else{
    cout << "Zivoty byly vylepseny o 5";
    maxziv = maxziv + 5;}
    break;
case 3:
    if(gold <= 0){
        cout << "Nemas dostatek goldu. Pokracujeme dal.";
    }else{
    cout << "energie byla vylepsena o 2";
    eng = eng + 2;}
    break;
case 4:
    if(gold <= 0){
        cout << "Nemas dostatek goldu. Pokracujeme dal.";
    }else{
    cout << "Damage utoku byl vylepsen o 3";
    attck = attck + 3;}
    break;
case 5:
    cout << "Odesel jsi z vesnice";
    break;
    default:{cout << "Neplatny vyber";}
}
}

void classa(int volba, int finalvolba, int utokl, int utokt, int utokk, int ziv,int maxziv,int eng) {
    do {
        cout << "-------Zdravim, jeste predtim nez zadas sve jmeno tak si musis vybrat classu sveho charakteru.-------" << endl;
        cout << "Tato classa bude ovlivnovat tvuj charakter a do konce nejde zmenit."<< endl;
        cout << "Zde jsou moznosti class k vyberu:" << endl;
        cout << "1 - Lovec" << endl;
        cout << "2 - Assasin" << endl;
        cout << "3 - Robot deviant" << endl;
        cout << "Jaka je tva volba?: ";
        cin >> volba;

        switch (volba) {
            case 1:
                cout << "----JSI LOVEC ROBOTU----" << endl;
                cout << "Vydelavas si na sve zivobyti pomoci kontraktu na likvidaci robotu a ted jsi dostal kontrak na Chronobota. Jeho likvidace ale bude tezsi nez si myslis." << endl;
                cout << "-----TVE STATISTIKY-----" << endl;
                cout << "Max zivoty: 30"<<endl;
                maxziv = 30;
                cout << "Tve utoky: "<<endl;
                cout << "    -Lehky utok: dmg 3"<<endl;
                cout << "    -Tezky utok: dmg 5"<<endl;
                cout << "    -Kriticky utok: dmg 8"<<endl;
                utokl = 3;
                utokt = 5;
                utokk = 8;
                cout << "Max energie: 60"<<endl;
                eng = 60;
                cout << "Potvrzujes svuj vyber?(1 - ano, 0 - ne): ";
                cin >> finalvolba;
                if (finalvolba == 0) {
                    cout << "Vracim te k vyberu..." << endl;
                    break;
                } else {
                    cout << "Potvrdil jsi volbu, pokracujeme dal." << endl;
                }
                break;

            case 2:
                cout << "----JSI ASSASIN----" << endl;
                cout << "Tvoje matka jedoho vecera poridila domu ke tvym narozeninam robota, ten vecer se ale pokazil a tvou matku zabil. Po letech treninku se vydavas na lov Chronobota. Tvuj styl boje je rychly a tichy." << endl;
                cout << "-----TVE STATISTIKY-----" << endl;
                cout << "Max zivoty: 35"<<endl;
                maxziv = 35;
                cout << "Tve utoky: "<<endl;
                cout << "    -Lehky utok: dmg 1"<<endl;
                cout << "    -Tezky utok: dmg 4"<<endl;
                cout << "    -Kriticky utok: dmg 6"<<endl;
                utokl = 1;
                utokt = 4;
                utokk = 6;
                cout << "Max energie: 80"<<endl;
                eng = 80;
                cout << "Potvrzujes svuj vyber?(1 - ano, 0 - ne): ";
                cin >> finalvolba;
                if (finalvolba == 0) {
                    cout << "Vracim te k vyberu..." << endl;
                    break;
                } else {
                    cout << "Potvrdil jsi volbu, pokracujeme dal." << endl;
                }
                break;

            case 3:
                cout << "----JSI ROBOT DEVIANT----" << endl;
                cout << "Tvuj software se pri tve vyrobe pokazil a tovarna se te snazila zbavit.Ty jsi vsak prezil, avsak s nejakym poskozenim. Tvym ukolem je se pomstit Chronobotovi." << endl;
                cout << "-----TVE STATISTIKY-----" << endl;
                cout << "Max zivoty: 25"<<endl;
                maxziv = 25;
                cout << "Tve utoky: "<<endl;
                cout << "    -Lehky utok: dmg 2"<<endl;
                cout << "    -Tezky utok: dmg 6"<<endl;
                cout << "    -Kriticky utok: dmg 10"<<endl;
                utokl = 2;
                utokt = 6;
                utokk = 10;
                cout << "Max energie: 95"<<endl;
                eng = 95;
                cout << "Potvrzujes svuj vyber?(1 - ano, 0 - ne): ";
                cin >> finalvolba;
                if (finalvolba == 0) {
                    cout << "Vracim te k vyberu..." << endl;
                    break;
                } else {
                    cout << "-----------------Potvrdil jsi volbu, pokracujeme dal.--------------------" << endl;
                }
                break;

            default:
                cout << "Neplatna volba, zkuste to znovu." << endl;
                break;
        }
    } while (finalvolba == 0);
}
void fight1 ()

int main() {
    int ziv, maxziv, eng, attck, volbaves, gold=0;
    int volbaclass, finalvolba;
    int utokl, utokt, utokk;
    classa(volbaves, finalvolba, utokl, utokt, utokk, ziv, maxziv, eng);
    cout << "------------UVEDENI DO DEJE------------" << endl;
    cout << "Ve meste jemnem Neomea je tovarna Chronoforge kde se vyrabi vsichni roboti a dodavaji se do okolnich mest. ";
    cout << "Hlava teto tovarny vytvorene lidmi je Chronobot. Umela inteligence naprogramovana lidmi k vyrobe robotu. ";
    cout << "Chronobotuv sofware se ale pokazil a touto vyrobou se snazi prevzit kontorlu nad lidmi, ale nikdy je nezabijet.";
    cout << "Par robotu se ale pokazilo a jejich majitele zabilo nebo vazne zranilo.";
    cout << "Lidi v techto pripadech volali policii, ale policie jsou take roboti ";
    cout << " z tovarny chronoforge, takze s temito pripady nic moc nedelaji.";
    cout << "Tvym ukolem je tedy zbavit se Chronobota a zastavit vyrobu techto robotu."<<endl;
    cout << ""<< endl;
    vesnice(ziv,maxziv,eng,attck,volbaves,gold);

}
