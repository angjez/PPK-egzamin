#include <fstream>
#include <string>
#include <vector>
#include <iostream>

#include "funkcje.hpp"

std::vector <std::vector<int>> wczytaj (std::string nazwaPlikuWej)
{
    int wiersze=0, kolumny=0;
    std::ifstream plik (nazwaPlikuWej);
    if(plik) {
        plik >> wiersze >> kolumny;
    }
    std::vector <std::vector<int>> obraz (wiersze, std::vector<int>(kolumny));
    if(plik) {
        while(!plik.eof()){
            for(int i = 0; i < wiersze; i++)
                for (int j = 0; j < kolumny; j++)
                    plik >> obraz[i][j];
        }
    }
    plik.close();
    return obraz;
}

void zapisz (std::string nazwaPlikuWyj, std::vector <std::vector<int>> obraz)
{
    std::ofstream plik (nazwaPlikuWyj);
    if(plik) {
        int wiersze=0, kolumny=0;
        for (int i = 0; i < obraz.size(); i++) {
            for (int j = 0; j < obraz[i].size(); j++){
                kolumny++;
            }
            wiersze++;
        }
        kolumny = kolumny/wiersze;
        plik << kolumny << " " << wiersze << std::endl;
        
        for (int i = 0; i < wiersze; i++){
            for (int j = 0; j < kolumny; j++){
                plik << obraz[i][j] << " ";
            }
            plik << std::endl;
        }
    }
    plik.close();
}

void przeksztalc (std::string nazwaPlikuWej, std::string nazwaPlikuWyj)
{
    std::vector <std::vector<int>> obraz = wczytaj(nazwaPlikuWej);
    
    int wiersze=0, kolumny=0;
    for (int i = 0; i < obraz.size(); i++) {
        for (int j = 0; j < obraz[i].size(); j++){
            kolumny++;
        }
        wiersze++;
    }
    kolumny = kolumny/wiersze;

    zapisz(nazwaPlikuWyj, obraz);
}
