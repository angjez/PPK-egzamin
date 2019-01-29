bool szachownicaPoprawna (std::string nazwaPliku)
{
    char tab[8][8];
    std::fstream plik;
    plik.open(nazwaPliku);
    if (!plik)
        return false;
    int w = 0;
    int k = 0;
    for(int i=0; i<8; i++)
        for (int j = 0; j < 8; j++) {
            plik >> tab[i][j];
        }
    plik.close();
    
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (tab[i][j] == 'H') {
                w++;
                if (w > 1) return false;
            }
            if (tab[j][i] == 'H') {
                k++;
                if (k > 1) return false;
            }
        }
        w = 0;
        k = 0;
    }
    
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < i + 1; j++) {
            if (tab[i-j][j] == 'H') {
                w++;
                if (w > 1) return false;
            }
            if (tab[7 - i + j][7-j] == 'H') {
                k++;
                if (k > 1) return false;
            }
        }
        w = 0;
        k = 0;
    }
    
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8 - i; j++) {
            if (tab[j][j + i] == 'H') {
                w++;
                if (w > 1) return false;
            }
            if (tab[i][i+j] == 'H') {
                k++;
                if (k > 1) return false;
            }
        }
        w = 0;
        k = 0;
    }
    return true;
}