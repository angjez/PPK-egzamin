#include <iostream>
#include <chrono>
#include <random>
#include <fstream>
#include <string>

void Barnsley(const int N){
    if( N <= 0)
        return;
    float x = 0.0f;
    float y = 0.0f;
    std::ofstream file ("Coordinates.txt");
    file << x << " " << y << std::endl;
    std::srand(time(NULL));
    for(int i = 0; i < N - 1; ++i)
    {
        int t = rand() % 100;
        if(t < 85)
        {
            float x1 = 0.85 * x + 0.04 * y;
            float y1 = -0.04 * x + 0.85 * y + 1.6;
            x = x1;
            y = y1;
            
        }
        else if(t < 92)
        {
            float x1 = -0.15 * x + 0.28 * y;
            float y1 = 0.26 * x + 0.24 * y + 0.44;
            x = x1;
            y = y1;
        }
        else if(t < 99)
        {
            float x1 = 0.20 * x + -0.26 * y;
            float y1 = 0.23 * x + 0.22 * y + 1.6;
            x = x1;
            y = y1;
        }
        else
        {
            float x1 = 0;
            float y1 = 0.16 * y;
            x = x1;
            y = y1;
        }
        file << x << " " << y << std::endl;
    }
    file.close();
    return;
}


int main(){
    Barnsley(500);
    return 0;
}



