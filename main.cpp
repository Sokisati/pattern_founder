#include <iostream>
#include <vector>

using namespace std;


int main() {

    int aliveCellsArray[30];
    aliveCellsArray[1] = 1;
    aliveCellsArray[2] = 3;
    aliveCellsArray[3] = 4;
    aliveCellsArray[4] = 5;
    aliveCellsArray[5] = 3;
    aliveCellsArray[6] = 4;
    aliveCellsArray[7] = 5;
    aliveCellsArray[8] = 6;
    aliveCellsArray[9] = 8;
    aliveCellsArray[10] = 8;
    aliveCellsArray[11] = 8;
    aliveCellsArray[12] = 4;
    aliveCellsArray[13] = 5;
    aliveCellsArray[14] = 3;
    aliveCellsArray[15] = 6;
    aliveCellsArray[16] = 8;
    aliveCellsArray[17] = 9;
    aliveCellsArray[18] = 6;
    aliveCellsArray[19] = 8;
    aliveCellsArray[20] = 9;
    aliveCellsArray[21] = 6;
    aliveCellsArray[22] = 8;
    aliveCellsArray[23] = 9;
    aliveCellsArray[24] = 6;


    int limit = sizeof(aliveCellsArray)/sizeof(int);


    int i,c,p,checkAgain,t;
    bool searchBool = false;

    i = 1;
    p = 0;
    checkAgain = 1;


    for(i; i<limit; i++)
    {
        searchBool = false;
        checkAgain = 1;



        for(c=i-1; c>1; c--)
        {
            if(searchBool)
            {
                break;
            }

            while(aliveCellsArray[c]==aliveCellsArray[i])
            {

                searchBool = true;
                p++;
                if(i-c-p==0)
                {
                    if(checkAgain<2)
                    {
                        checkAgain++;
                     t = c;
                     c = i;
                     i = 2*i - t;
                     p = 0;
                    }
                    else {
                        p = 0;
                        for (p; i - c - p > 0; p++) {
                            cout << aliveCellsArray[i + p];
                        }
                        return 0;
                    }
                }
                
                //pattern with period of above 8 are not possible within a 30x30 grid, hence the i-c>8
                if(aliveCellsArray[c+p]!=aliveCellsArray[i+p] || i-c>8)
                {
                    p = 0;
                    break;
                }
            }
        }
    }



cout<<"No pattern found..."<<endl;



    return 0;
}