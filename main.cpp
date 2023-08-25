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
    aliveCellsArray[7] = 7;
    aliveCellsArray[8] = 5;
    aliveCellsArray[9] = 8;
    aliveCellsArray[10] = 7;
    aliveCellsArray[11] = 5;
    aliveCellsArray[12] = 7;
    aliveCellsArray[13] = 10;
    aliveCellsArray[14] = 5;
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


    int i,c,p;
    bool searchBool = false;

    i = 1;
    p = 0;


    for(i; i<limit; i++)
    {
        searchBool = false;


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
                    //pattern found
                    p = 0;
                    for(p; i-c-p>0; p++)
                    {
                        cout<<aliveCellsArray[i+p];
                    }
                    return 0;
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

    cout<<"No pattern exists..."<<endl;

    return 0;
}