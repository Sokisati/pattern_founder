#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <random>


using namespace std;



vector<int> patternFinderFunction(vector<int> aliveCellsVector)
{

    int i,c,p,checkAgain,t;
    bool searchBool = false;

    i = 1;
    p = 0;
    checkAgain = 1;


    vector<int> patternFound;


    for(i; i<aliveCellsVector.size(); i++)
    {
        searchBool = false;
        checkAgain = 1;



        for(c=i-1; c>1; c--)
        {
            if(searchBool)
            {
                break;
            }

            while(aliveCellsVector[c]==aliveCellsVector[i])
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
                    else{
                        p = 0;
                        for (p; i - c - p > 0; p++) {
                            patternFound.push_back(aliveCellsVector[i + p]);
                        }
                        return patternFound;
                    }
                }

                //pattern with period of above 8 are not possible within a 30x30 grid, hence the i-c>8
                if(aliveCellsVector[c+p]!=aliveCellsVector[i+p] || i-c>8)
                {
                    p = 0;
                    break;
                }
            }
        }
    }

    return patternFound;
}

int main() {
    srand(time(0));


    vector<int> aliveCellsVector;
    vector<int> foundPattern;

    int randomNumber;



    while(true){

        randomNumber = (rand() % 8)+2;
        aliveCellsVector.push_back(randomNumber);
        cout<<randomNumber<<" ";



        foundPattern=patternFinderFunction(aliveCellsVector);

        if(!foundPattern.empty()){
            for (int i = 0; i < foundPattern.size(); i++) {

                cout<<endl<<"-------"<<endl;
                cout<<foundPattern[i]<<" ";
            }
            return 0;
        }

    }







    return 0;
}
