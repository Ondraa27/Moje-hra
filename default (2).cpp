#include <iostream>
using namespace std;
void vesnice(int ziv,int maxziv,int eng,int attck,int volba, int gold){
cout << "Zdravim vitej ve vesnici jakou akci si prejes vykonat?"<< endl;
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
    cout << "Zivoty byly doplneny";
    break;
case 2:
    cout << "Zivoty byly vylepseny o 5";
    maxziv = maxziv + 5;
    break;
case 3:
    cout << "energie byla vylepsena o 2";
    eng = eng + 2;
    break;
case 4:
    cout << "Damage utoku byl vylepsen o 3";
    attck = attck + 3;
    break;
case 5:
    cout << "Odesel jsi z vesnice";
    break;
    default:{cout << "Neplatna hodnota";}
}
}

int main(){
string jmeno;
int zivoty, maxzivot, energie, utok, volba, gold = 10;
maxzivot = 10;
zivoty = maxzivot;
energie = 50;
utok = 3;
do {
    cout << "Zdravim jake si prejes aby bylo jmeno tveho charakteru?: ";
    cin >> jmeno;
}while (jmeno == "");
cout << "Jmeno tveho charakteru je: " << jmeno << endl;
vesnice (zivoty, maxzivot, energie, utok, volba, gold);
}

