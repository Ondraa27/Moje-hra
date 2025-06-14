#include <iostream>
using namespace std;
#include <cstdlib>
#include <ctime>
int random(int min, int max) {
    return rand() % (max - min + 1) + min;
}
void lastvesnice(int &ziv, int &maxziv, int &eng, int &utokl, int &utokt, int &utokk, int &gold, int &maxeng) {
    int volba;
    while (true) {
        cout << "\n--- TOTO JE POSLEDNI VESNICE PRED TIM NEZ DORAZIS DO CHRONOFORGE ---" << endl;
        cout << "\nDobre si rozmysli co si koupis\n" << endl;
        cout <<"\n---Tvoje statistiky:---\n";
        cout <<"\nTvoje zivoty:"<<ziv<<"\n";
        cout <<"\nTvoje energie:"<<eng<<"\n";
        cout <<"\nLehky utok:"<<utokl<<"\n";
        cout <<"\nTezky utok:"<<utokt<<"\n";
        cout <<"\nKriticky utok:"<<utokk<<"\n";
        cout << "Stav goldu: " << gold << endl;
        cout << "1 - Doplneni zivotu (3 goldy)" << endl;
        cout << "2 - Zvyseni maximalnich zivotu o 5 (2 goldy)" << endl;
        cout << "3 - Zvyseni energie o 5 (2 goldy)" << endl;
        cout << "4 - Zvyseni utoku o 1 (3 goldy)" << endl;
        cout << "5 - Odejit z vesnice" << endl;
        cout << "Zadej svou volbu: ";
        cin >> volba;

        switch (volba) {
            case 1:
                if (gold >= 3) {
                    ziv = maxziv;
                    gold -= 3;
                    cout << "Zivoty byly doplneny na maximum." << endl;
                } else {
                    cout << "Nemas dostatek goldu." << endl;
                }
                break;

            case 2:
                if (gold >= 2) {
                    maxziv += 5;
                    gold -= 2;
                    cout << "Maximalni zivoty byly zvyseny o 5." << endl;
                    ziv = maxziv;
                } else {
                    cout << "Nemas dostatek goldu." << endl;
                }
                break;

            case 3:
                if (gold >= 2) {
                    maxeng += 5;
                    gold -= 2;
                    cout << "Energie byla zvysena o 5." << endl;
                } else {
                    cout << "Nemas dostatek goldu." << endl;
                }
                break;

            case 4:
                if (gold >= 3) {
                    utokl += 1;
                    gold -= 3;
                    cout << "Utok byl zvysen o 1 dmg." << endl;
                } else {
                    cout << "Nemas dostatek goldu." << endl;
                }
                break;

            case 5:
                cout << "Opoustis vesnici." << endl;
                return;

            default:
                cout << "Neplatna volba." << endl;
                break;
        }


        if (gold < 2) {
            cout << "\nNemas dostatek goldu na dalsi nakupy. Opoustis vesnici." << endl;
            return;
        }
    }
}
void fightvarujicirobot(int &ziv, int &maxziv, int &eng, int utokl, int utokt, int utokk, int &gold, int &maxeng) {
    srand(time(0));
    int robot1 = 10;
    int robot2 = 10;

    cout << "\n=== BOJ SE DVEMA ROBOTY ===\n";

    while (ziv > 0 && (robot1 > 0 || robot2 > 0)) {
        cout << "\nZivoty: " << ziv << "/" << maxziv << " | Energie: " << eng << endl;
        if (robot1 > 0) cout << "Robot 1: " << robot1 << " HP\n";
        if (robot2 > 0) cout << "Robot 2: " << robot2 << " HP\n";

        cout << "\nZvol utok:\n";
        cout << " 1) Lehky (" << utokl << " DMG, 2 energie)\n";
        cout << " 2) Tezky (" << utokt << " DMG, 4 energie)\n";
        cout << " 3) Kriticky (" << utokk << " DMG, 6 energie)\n";
        int volba, cil; cin >> volba;

        int dmg = 0, cost = 0;
        if (volba == 1) { dmg = utokl; cost = 2; }
        else if (volba == 2) { dmg = utokt; cost = 4; }
        else if (volba == 3) { dmg = utokk; cost = 6; }
        else { cout << "Neplatna volba.\n"; dmg = 0; cost = 0; }

        if (eng < cost) {
            cout << "Nemas dost energie.\n";
        } else if (dmg > 0) {
            cout << "Utocis na ktereho robota? (1 nebo 2): ";
            cin >> cil;

            if ((cil == 1 && robot1 <= 0) || (cil == 2 && robot2 <= 0)) {
                cout << "Ten robot uz je znicen.\n";
            } else {
                eng -= cost;
                if (cil == 1) {
                    robot1 -= dmg;
                    cout << "Zasahl jsi robota 1 za " << dmg << " DMG.\n";
                } else if (cil == 2) {
                    robot2 -= dmg;
                    cout << "Zasahl jsi robota 2 za " << dmg << " DMG.\n";
                }


                if ((robot1 <= 0 && robot2 > 0) || (robot2 <= 0 && robot1 > 0)) {
                    cout << "\nDruhy robot zjistil ze jsi na ceste znicit Chronobota a vydal se do Chronoforge ho varovat!\n";
                    return;
                }
            }
        }


        cout << "\n--- Tah robotù ---\n";
        if (robot1 > 0) {
            int dmg = random(2, 5);
            ziv -= dmg;
            cout << "Robot 1 ti udelil " << dmg << " DMG.\n";
        }
        if (robot2 > 0) {
            int dmg = random(2, 5);
            ziv -= dmg;
            cout << "Robot 2 ti udelil " << dmg << " DMG.\n";
        }
    }

    if (ziv <= 0) {
        cout << "\nByl jsi porazen!\n";
        exit(0);
    } else {
        cout << "\nOba roboti byli zniceni!\n";
        if (random(0, 1)) {
            int loot = random(2, 5);
            gold += loot;
            cout << "Ziskal jsi " << loot << " goldu.\n";
        }
        if (random(0, 1)) {
            int loot = random(2, 5);
            gold += loot;
            cout << "Ziskal jsi dalsich " << loot << " goldu.\n";
        }
    }

    eng = maxeng;
}


void fightFinalBossChronobot(int &ziv, int &maxziv, int &eng, int utokl, int utokt, int utokk, int &gold, int &maxeng) {
    srand(time(0));
    int bossHP = 80;
    int kolo = 1;
    int posledniUtokHrace = 0;
    int opakovanyUtok = 0;

    cout << "------Uspesne jsi dosel do tovarny Chronoforge...------ \n Hledal jsi chronobota ale nikde po tovarne jsi ho nemohl najit. Kdyz vtom jsi dostal ranu ze zadu, tato rana ti dala damage za 3 hp." <<endl;
    cout << "Chronobot *Robotickym hlasem*: No necekal jsem ze se sem dostanes, ale kdyz uz jsi tu pojd me zkusit porazit. Zapas s takovym marnym stvorenim jsem dneska v planu nemel.\n";

    while (ziv > 0 && bossHP > 0) {
        cout << "\n--- KOLO " << kolo << " ---\n";
        cout << "Zivoty: " << ziv << "/" << maxziv << " | Energie: " << eng << endl;
        cout << "Chronobot HP: " << bossHP << endl;


        cout << "\nZvol utok:\n";
        cout << "  1) Lehky (" << utokl << " DMG, 2 energie)\n";
        cout << "  2) Tezky (" << utokt << " DMG, 4 energie)\n";
        cout << "  3) Kriticky (" << utokk << " DMG, 6 energie)\n";
        int volba; cin >> volba;

        int dmg = 0, cost = 0;
        switch (volba) {
            case 1: dmg = utokl; cost = 2; break;
            case 2: dmg = utokt; cost = 4; break;
            case 3: dmg = utokk; cost = 6; break;
            default:
                cout << "Neplatna volba – ztracis tah!\n";
                break;
        }

        if (eng < cost) {
            cout << "Nemas dost energie! Utok selhal.\n";
        } else if (dmg > 0) {
            eng -= cost;
            bossHP -= dmg;
            cout << "Zasahl jsi Chronobota za " << dmg << " DMG.\n";

            if (volba == posledniUtokHrace) {
                opakovanyUtok++;
                if (opakovanyUtok >= 2) {
                    cout << "Chronobot kopiruje tvuj styl utoku!\n";
                    bossHP -= dmg;
                    cout << "Chronobot byl zasažen svou vlastní silou za " << dmg << " DMG navíc!\n";
                }
            } else {
                opakovanyUtok = 1;
                posledniUtokHrace = volba;
            }
        }

        if (bossHP <= 0) break;


        cout << "\n--- Tah Chronobota ---\n";
        int bossDmg = 0;
        int typ = (kolo - 1) % 4;

        switch (typ) {
            case 0: bossDmg = random(3, 5); cout << "Chronobot provadi SLABY utok!\n"; break;
            case 1: bossDmg = random(6, 8); cout << "Chronobot provadi STREDNI utok!\n"; break;
            case 2: bossDmg = random(9, 11); cout << "Chronobot provadi SILNY utok!\n"; break;
            case 3: bossDmg = random(13, 15); cout << "Chronobot provadi KRITICKY utok!\n"; break;
        }

        ziv -= bossDmg;
        cout << "Chronobot ti zada " << bossDmg << " DMG.\n";


        if (kolo % 5 == 0) {
            cout << "Chronobot PRESKOCIL CAS a opakuje utok!\n";
            ziv -= bossDmg;
            cout << "Dalsich " << bossDmg << " DMG ti bylo udeleno casovou smyckou!\n";
        }

        if (ziv <= 0) break;

        kolo++;
    }

    if (ziv <= 0) {

        cout << "Chronobot: No sice jsem vedel ze v zapasu proti MNE nemas sanci, ale aspon ses snazil.";
        cout << "\nChronobot te porazil a ovladl svet roboty...\n";
    } else {

        cout << "Chronobot: Necekal jsem ze budes tak silny. Ja se ale vratim a muj software bude vyvynutejsi a ty proti me nebude mit sanci!";
        cout << "\nChronobot je porazen! Lide jsou zachraneni!\n";
        int loot = random(15, 25);
        gold += loot;
        cout << "Ziskal jsi " << loot << " goldu z jeho trosek.\n";
    }
    eng = maxeng;
}




void fightMonster(int &ziv, int &maxziv, int &eng, int utokl, int utokt, int utokk, int &gold, int &maxeng, int pocetMonster = 1) {
    srand(time(0));
    int monsterHP[3] = {15, 10, 25};
    cout << "\n=== Boj proti robotum zacina! ===\n";

    while (ziv > 0) {
        bool zbyvaNepritel = false;
        for (int i = 0; i < pocetMonster; i++) {
            if (monsterHP[i] > 0) {
                zbyvaNepritel = true;
                break;
            }
        }
        if (!zbyvaNepritel) break;

        cout << "\n----------------------------\n";
        cout << "Zivoty: " << ziv << "/" << maxziv << " | Energie: " << eng << endl;
        cout << "Roboti:\n";
        for (int i = 0; i < pocetMonster; i++) {
            if (monsterHP[i] > 0)
                cout << "   - Robot " << i + 1 << ": " << monsterHP[i] << " HP\n";
        }

        cout << "\nZvol utok:\n";
        cout << "  1) Lehky (" << utokl << " DMG, 2 energie)\n";
        cout << "  2) Tezky (" << utokt << " DMG, 4 energie)\n";
        cout << "  3) Kriticky (" << utokk << " DMG, 6 energie)\n";
        int volba; cin >> volba;

        int dmg = 0, cost = 0;
        switch (volba) {
            case 1: dmg = utokl; cost = 2; break;
            case 2: dmg = utokt; cost = 4; break;
            case 3: dmg = utokk; cost = 6; break;
            default:
                cout << "Neplatna volba – ztracis tah!\n";
        }

        if (eng < cost) {
            cout << "Nemas dost energie! Utok selhal.\n";
        } else if (dmg > 0) {
            eng -= cost;
            int cil;
            do {
                cout << "Na ktereho robota (1 - " << pocetMonster << ") utocis?: ";
                cin >> cil;
                cil--;
            } while (cil < 0 || cil >= pocetMonster || monsterHP[cil] <= 0);

            monsterHP[cil] -= dmg;
            cout << "Zasahl jsi robota " << cil + 1 << " za " << dmg << " DMG.\n";
        }

        cout << "\n--- Tah robotu ---\n";
        for (int i = 0; i < pocetMonster; i++) {
            if (monsterHP[i] > 0) {
                int mdmg = random(0, 3);
                ziv -= mdmg;

            }
        }
    }

    if (ziv <= 0) {
        cout << "\nByl jsi porazen roboty!\n";
        exit(0);
    } else {
        cout << "\nZvitezil jsi nad roboty!\n";
        for (int i = 0; i < pocetMonster; i++) {
    if (monsterHP[i] <= 0 && random(0, 1)) {
        int loot = random(2, 5);
        gold += loot;
        cout << "Robot " << i + 1 << " u sebe mel " << loot << " goldu.\n";
    }
}

        }
        if (maxziv - ziv >= 15){
            ziv = ziv +15;
        }
        eng = maxeng;

    }




void fightMiniBoss(int &ziv, int &maxziv, int &eng, int utokl, int utokt, int utokk, int &gold, int &maxeng) {
    srand(time(0));
    int bossHP = 35;

    cout << "\n=== MiniBoss prichazi! ===\n";

    while (ziv > 0 && bossHP > 0) {
        int bdmg = random(5, 8);
        ziv -= bdmg;
        cout << "\nMiniBoss ti zada " << bdmg << " DMG jako prvni!\n";

        if (ziv <= 0) break;

        cout << "\nZivoty: " << ziv << "/" << maxziv << " | Energie: " << eng << endl;
        cout << "MiniBoss HP: " << bossHP << endl;

        cout << "\nZvol utok:\n";
        cout << "  1) Lehký (" << utokl << " DMG, 2 energie)\n";
        cout << "  2) Tezky (" << utokt << " DMG, 4 energie)\n";
        cout << "  3) Kriticky (" << utokk << " DMG, 6 energie)\n";
        int volba; cin >> volba;

        int dmg = 0, cost = 0;
        switch (volba) {
            case 1: dmg = utokl; cost = 2; break;
            case 2: dmg = utokt; cost = 4; break;
            case 3: dmg = utokk; cost = 6; break;
            default:
                cout << "Neplatna volba – ztracis tah!\n";
        }

        if (eng < cost) {
            cout << "Nemas dost energie! Utok selhal.\n";
        } else if (dmg > 0) {
            eng -= cost;
            bossHP -= dmg;
            cout << "Udelil jsi MiniBossovi " << dmg << " DMG.\n";
        }
    }

    if (ziv <= 0) {
        cout << "\nByl jsi porazen MiniBossem!\n";
        exit(0);
    } else {
        cout << "\nMiniBoss padl k zemi!\n";
        int loot = random(6, 10);
        gold += loot;
        cout << "Ziskal jsi " << loot << " goldu.\n";
    }
    eng = maxeng;
}


void vesnice(int &ziv, int &maxziv, int &eng, int &utokl, int &utokt, int &utokk, int &gold, int &maxeng) {
    int volba;
    while (true) {
        cout << "\n--- Vstoupil jsi do vesnice ---" << endl;
        cout << "Stav goldu: " << gold << endl;
        cout << "1 - Doplneni zivotu (3 goldy)" << endl;
        cout << "2 - Zvyseni maximalnich zivotu o 5 (2 goldy)" << endl;
        cout << "3 - Zvyseni energie o 5 (2 goldy)" << endl;
        cout << "4 - Zvyseni utoku o 1 (3 goldy)" << endl;
        cout << "5 - Odejit z vesnice" << endl;
        cout << "Zadej svou volbu: ";
        cin >> volba;

        switch (volba) {
            case 1:
                if (gold >= 3) {
                    ziv = maxziv;
                    gold -= 3;
                    cout << "Zivoty byly doplneny na maximum." << endl;
                } else {
                    cout << "Nemas dostatek goldu." << endl;
                }
                break;

            case 2:
                if (gold >= 2) {
                    maxziv += 5;
                    gold -= 2;
                    cout << "Maximalni zivoty byly zvyseny o 5." << endl;
                    ziv = maxziv;
                } else {
                    cout << "Nemas dostatek goldu." << endl;
                }
                break;

            case 3:
                if (gold >= 2) {
                    maxeng += 5;
                    gold -= 2;
                    cout << "Energie byla zvysena o 5." << endl;
                } else {
                    cout << "Nemas dostatek goldu." << endl;
                }
                break;

            case 4:
                if (gold >= 3) {
                    utokl += 1;
                    gold -= 3;
                    cout << "Utok byl zvysen o 1 dmg." << endl;
                } else {
                    cout << "Nemas dostatek goldu." << endl;
                }
                break;

            case 5:
                cout << "Opoustis vesnici." << endl;
                return;

            default:
                cout << "Neplatna volba." << endl;
                break;
        }


        if (gold < 2) {
            cout << "\nNemas dostatek goldu na dalsi nakupy. Opoustis vesnici." << endl;
            return;
        }
    }
}

void classa(int &volba, int &finalvolba, int &utokl, int &utokt, int &utokk, int &ziv, int &maxziv, int &eng, int &maxeng)
 {
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
                cout << "Max zivoty: 45"<<endl;
                maxziv = 45;
                cout << "Tve utoky: "<<endl;
                cout << "    -Lehky utok: dmg 3"<<endl;
                cout << "    -Tezky utok: dmg 5"<<endl;
                cout << "    -Kriticky utok: dmg 8"<<endl;
                utokl = 3;
                utokt = 5;
                utokk = 8;
                cout << "Max energie: 40"<<endl;
                maxeng = 40;
                eng = maxeng;
                cout << "Potvrzujes svuj vyber?(1 - ano, 0 - ne): ";
                cin >> finalvolba;
                if (finalvolba == 0) {
                    cout << "Vracim te k vyberu..." << endl;
                    break;
                } else {
                    cout << "Potvrdil jsi volbu, pokracujeme dal." << endl;
                    ziv = maxziv;
                }
                break;

            case 2:
                cout << "----JSI ASSASIN----" << endl;
                cout << "Tvoje matka jedoho vecera poridila domu ke tvym narozeninam robota, ten vecer se ale pokazil a tvou matku zabil. Po letech treninku se vydavas na lov Chronobota. Tvuj styl boje je rychly a tichy." << endl;
                cout << "-----TVE STATISTIKY-----" << endl;
                cout << "Max zivoty: 45"<<endl;
                maxziv = 45;
                cout << "Tve utoky: "<<endl;
                cout << "    -Lehky utok: dmg 1"<<endl;
                cout << "    -Tezky utok: dmg 4"<<endl;
                cout << "    -Kriticky utok: dmg 6"<<endl;
                utokl = 1;
                utokt = 4;
                utokk = 6;
                cout << "Max energie: 60"<<endl;
                maxeng = 60;
                eng = maxeng;
                cout << "Potvrzujes svuj vyber?(1 - ano, 0 - ne): ";
                cin >> finalvolba;
                if (finalvolba == 0) {
                    cout << "Vracim te k vyberu..." << endl;
                    break;
                } else {
                    cout << "Potvrdil jsi volbu, pokracujeme dal." << endl;
                    ziv = maxziv;
                }
                break;

            case 3:
                cout << "----JSI ROBOT DEVIANT----" << endl;
                cout << "Tvuj software se pri tve vyrobe pokazil a tovarna se te snazila zbavit.Ty jsi vsak prezil, avsak s nejakym poskozenim. Tvym ukolem je se pomstit Chronobotovi." << endl;
                cout << "-----TVE STATISTIKY-----" << endl;
                cout << "Max zivoty: 40"<<endl;
                maxziv = 40;
                cout << "Tve utoky: "<<endl;
                cout << "    -Lehky utok: dmg 2"<<endl;
                cout << "    -Tezky utok: dmg 6"<<endl;
                cout << "    -Kriticky utok: dmg 10"<<endl;
                utokl = 2;
                utokt = 6;
                utokk = 10;
                cout << "Max energie: 75"<<endl;
                maxeng = 75;
                eng = maxeng;
                cout << "Potvrzujes svuj vyber?(1 - ano, 0 - ne): ";
                cin >> finalvolba;
                if (finalvolba == 0) {
                    cout << "Vracim te k vyberu..." << endl;
                    break;
                } else {
                    cout << "-----------------Potvrdil jsi volbu, pokracujeme dal.--------------------" << endl;
                    ziv = maxziv;
                }
                break;

            default:
                cout << "Neplatna volba, zkuste to znovu." << endl;
                break;
        }
    } while (finalvolba == 0);
}


int main() {
    int ziv, maxziv, eng, attck, volbaves, gold=0;
    int volbaclass, finalvolba;
    int utokl, utokt, utokk;
    int maxeng;
    classa(volbaves, finalvolba, utokl, utokt, utokk, ziv, maxziv, eng, maxeng);
    cout << "------------UVEDENI DO DEJE------------" << endl;
    cout << "Ve meste jemnem Neomea je tovarna Chronoforge kde se vyrabi vsichni roboti a dodavaji se do okolnich mest. ";
    cout << "Hlava teto tovarny vytvorene lidmi je Chronobot. Umela inteligence naprogramovana lidmi k vyrobe robotu. ";
    cout << "Chronobotuv software se ale pokazil a touto vyrobou se snazi prevzit kontorlu nad lidmi, ale nikdy je nezabijet.";
    cout << "Par robotu se ale pokazilo a jejich majitele zabilo nebo vazne zranilo.";
    cout << "Lidi v techto pripadech volali policii, ale policie jsou take roboti ";
    cout << " z tovarny chronoforge, takze s tyto pripady se snazi zamest aby si verejnost dale roboty kupovala a Chronobotuv plan vysel.";
    cout << "Tvym ukolem je tedy zbavit se Chronobota a zastavit vyrobu techto robotu."<<endl;
    cout << ""<< endl;
    vesnice(ziv, maxziv, eng, utokl, utokt, utokk, gold, maxeng);
fightvarujicirobot(ziv, maxziv, eng, utokl, utokt, utokk, gold, maxeng);
fightMonster(ziv, maxziv, eng, utokl, utokt, utokk, gold, maxeng, 1);
vesnice(ziv, maxziv, eng, utokl, utokt, utokk, gold, maxeng);
fightMiniBoss(ziv, maxziv, eng, utokl, utokt, utokk, gold, maxeng);
vesnice(ziv, maxziv, eng, utokl, utokt, utokk, gold, maxeng);
fightMonster(ziv, maxziv, eng, utokl, utokt, utokk, gold, maxeng, 3);
vesnice(ziv, maxziv, eng, utokl, utokt, utokk, gold, maxeng);
fightMonster(ziv, maxziv, eng, utokl, utokt, utokk, gold, maxeng, 1);
fightMonster(ziv, maxziv, eng, utokl, utokt, utokk, gold, maxeng, 3);
vesnice(ziv, maxziv, eng, utokl, utokt, utokk, gold, maxeng);
fightMonster(ziv, maxziv, eng, utokl, utokt, utokk, gold, maxeng, 1);
fightMonster(ziv, maxziv, eng, utokl, utokt, utokk, gold, maxeng, 2);
vesnice(ziv, maxziv, eng, utokl, utokt, utokk, gold, maxeng);
fightMiniBoss(ziv, maxziv, eng, utokl, utokt, utokk, gold, maxeng);
vesnice(ziv, maxziv, eng, utokl, utokt, utokk, gold, maxeng);
fightMonster(ziv, maxziv, eng, utokl, utokt, utokk, gold, maxeng, 3);
fightMonster(ziv, maxziv, eng, utokl, utokt, utokk, gold, maxeng, 2);
lastvesnice(ziv, maxziv, eng, utokl, utokt, utokk, gold, maxeng);
fightFinalBossChronobot(ziv, maxziv, eng, utokl, utokt, utokk, gold, maxeng);

}
