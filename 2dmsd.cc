#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;

int main(){
    srand(time(NULL));

    int N=pow(10,3);
    int m=N;
    int w[m]={0};

    fstream fout;
    fout.open("msd.txt",ios::out);
    for (int j = 0; j < 20; j++){
        int x=0,y=0;

        for (int i=0; i<N; i++){
            double p=(double)rand()/RAND_MAX;
            if(0<=p && p<1.0/4.0) {
                x++;
            }else if (1.0/4.0<=p && p<1.0/2.0){
                y++;
            }else if (1.0/2.0<=p && p<3.0/4.0)
            {
                x--;
            }else {
                y--;
            }
            w[i]=w[i]+(x*x+y*y);



    }

    }
            for (int i=0; i<100; i++) {
        fout << i+1<< " " << w[i]/20.0<<endl;
        }
    fout.close();
    return 0;
}