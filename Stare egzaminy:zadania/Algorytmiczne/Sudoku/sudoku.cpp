#include "iostream"
#include "fstream"
#include "string"


bool check(const std::string &nazwa)
{
   std::ifstream plik;
   plik.open(nazwa);
   char tab[9][9] = {};
   for(int i = 0; i < 9; ++i)
   {
       for(int j = 0; j < 9; ++j)
       {
           char x;
           plik >> x;
           tab[i][j] = x;
       }
   }
    for(int i=0; i<9;++i)
        for(char k='1'; k<='9'; ++k)
            for(int j=0; j<9; j++)
            {
                if(tab[i][j]==k)
                    break;
                else if(j==8)
                    return false;
            }
    for(int i=0; i<9;++i)
        for(char k='1'; k<='9'; ++k)
            for(int j=0; j<9; j++)
            {
                if(tab[j][i]==k)
                    break;
                else if(j==8)
                    return false;
            }
    for(int p=0; p<3;p++)
        for(int q=0; q<3;q++)
            for(char k='1'; k<='9'; k++)
            {
                int v=0;
                for(int i=0; i<3;++i)
                        for(int j=0; j<3; j++)
                        {
                            if(tab[i + 3*p][j + 3*q]==k)
                            {
                                v=1;
                                break;
                            }
                            else if(j==2 && i==2)
                                return false;
                            if(v==1)
                                break;
                        }
                        
                    }
    
    
    return true;
}


int main(){
    std::cout<<(check("nazwa.txt")?"TAK":"NIE");
    std::cout<<std::endl;
    return 0;
}
