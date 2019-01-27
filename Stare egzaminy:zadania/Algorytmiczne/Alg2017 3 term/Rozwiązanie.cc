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
    
    std::vector <std::vector<int>> nowyObraz (wiersze, std::vector<int>(kolumny));

    for (int i = 0; i < wiersze; i++) {
        for (int j = 0; j < kolumny; j++){
            //narozniki
            if(i == 0 && j == 0)
                nowyObraz[i][j] = ((obraz[i][j] + obraz[i][j+1] + obraz[i+1][j] + obraz[i+1][j+1])/4);
            if(i == 0 && j == (kolumny-1))
                nowyObraz[i][j] = ((obraz[i][j] + obraz[i][j-1] + obraz[i+1][j] + obraz[i+1][j-1])/4);
            if(i == (wiersze-1) && j ==0)
                nowyObraz[i][j] = ((obraz[i][j] + obraz[i][j+1] + obraz[i-1][j] + obraz[i-1][j+1] )/4);
            if(i == (wiersze-1) && j == (kolumny-1))
                nowyObraz[i][j] = ((obraz[i][j] + obraz[i][j-1] + obraz[i-1][j] + obraz[i-1][j-1])/4);

            //boki
            if(i == 0 && 0 < j && j < (kolumny-1))
                nowyObraz[i][j] = ((obraz[i][j] + obraz[i][j+1] + obraz[i][j-1] + obraz[i+1][j] + obraz[i+1][j+1] + obraz[i+1][j-1])/6);
            if(i == (wiersze-1) && 0 < j && j < (kolumny-1))
                nowyObraz[i][j] = ((obraz[i][j] + obraz[i][j+1] + obraz[i][j-1] + obraz[i-1][j] + obraz[i-1][j+1] + obraz[i-1][j-1])/6);
            if(0 < i && i < (wiersze-1) && j == 0)
                nowyObraz[i][j] = ((obraz[i][j] + obraz[i][j+1] + obraz[i-1][j] + obraz[i+1][j] + obraz[i-1][j+1] + obraz[i+1][j+1])/6);
            if(0 < i && i < (wiersze-1) && j == (kolumny-1))
                nowyObraz[i][j] = ((obraz[i][j] + obraz[i][j-1] + obraz[i-1][j] + obraz[i-1][j-1] + obraz[i-1][j-1] + obraz[i+1][j-1])/6);

            //środek
            if( 0 < i && i < (wiersze-1) && 0 < j && j < (kolumny-1)){
                    nowyObraz[i][j] = ((obraz[i][j] + obraz[i-1][j-1] + obraz[i+1][j+1] + obraz[i-1][j+1] + obraz[i+1][j-1] + obraz[i+1][j] + obraz[i-1][j] + obraz[i][j-1] + obraz[i][j+1])/9);
            }

        }
    }

    zapisz(nazwaPlikuWyj, nowyObraz);
}
