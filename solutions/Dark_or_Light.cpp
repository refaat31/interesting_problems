#include<bits/stdc++.h>
using namespace std;

void checkLampIllumination(int N, int noOfLamps, int** lamps, int noOfQueries, int** queries);
bool checkValidPosition(int x, int y, int N);
void removeAdjacent(int x,int y, int noOfLamps, int lamps_temp[][2], int N);

int main(){

    printf("please enter the size of the grid:\n");
    int N;
    scanf("%d",&N);
    int** lamps;
    int** queries;

    int noOfLamps,noOfQueries;

    printf("\nplease enter the number of lamps:\n ");
    scanf("%d",&noOfLamps);

    lamps = new int*[noOfLamps];
    for(int i=0;i<noOfLamps;i++)
        lamps[i] = new int[2];

    printf("\nplease enter the position of the lamps:\n ");
    for(int i=0;i<noOfLamps;i++){
        scanf("%d %d",&lamps[i][0],&lamps[i][1]);
    }


    printf("\nplease enter the number of queries:\n ");
    scanf("%d",&noOfQueries);
    queries = new int*[noOfQueries];
    for(int i=0;i<noOfQueries;i++)
        queries[i] = new int[2];

    printf("\nplease enter the position of the queries:\n ");
    for(int i=0;i<noOfQueries;i++){
        scanf("%d %d",&queries[i][0],&queries[i][1]);
    }



    checkLampIllumination(N,noOfLamps,lamps,noOfQueries,queries);
    return 0;
}

void checkLampIllumination(int N, int noOfLamps, int** lamps, int noOfQueries, int** queries){

    for(int i=0;i<noOfQueries;i++){

        int lamps_temp[noOfLamps][2];


        for(int k=0;k<noOfLamps;k++){
            lamps_temp[k][0] = lamps[k][0];
            lamps_temp[k][1] = lamps[k][1];
        }


        // assuming every query is independent of each other.

        // check if it's adjacent
        removeAdjacent(queries[i][0],queries[i][1],noOfLamps,lamps_temp,N);

        int flag = 0;
        for(int j=0;j<noOfLamps;j++){
            if(lamps_temp[j][0]==-1 && lamps_temp[j][1]==-1) continue;

            // query position = lamp position
            if((lamps_temp[j][0]==queries[i][0]) && (lamps_temp[j][1]==queries[i][1])) break;

            // same row
            if(lamps_temp[j][0]==queries[i][0]){
                flag = 1;
                break;
            }

            // same column
            if(lamps_temp[j][1]==queries[i][1]){
                flag = 1;
                break;
            }

            // diagonal
            if( abs(lamps_temp[j][0]-queries[i][0]) == abs(lamps_temp[j][1]-queries[i][1])){
                flag = 1;
                break;
            }

        }

        if(flag==1) printf("LIGHT\n");
        else printf("DARK\n");

    }
}

void removeAdjacent(int x,int y, int noOfLamps, int lamps_temp[][2], int N){
    int temp[8][2] = {{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1}};

    // x - row. y - column.

    // left
    if(checkValidPosition(x,y-1,N)){
        temp[0][0] = x;
        temp[0][1] = y-1;
    }

    // up-left
    if(checkValidPosition(x-1,y-1,N)){
        temp[1][0] = x-1;
        temp[1][1] = y-1;
    }

    // up
    if(checkValidPosition(x-1,y,N)){
        temp[2][0] = x-1;
        temp[2][1] = y;
    }

    // up right
    if(checkValidPosition(x-1,y+1,N)){
        temp[3][0] = x-1;
        temp[3][1] = y+1;
    }

    // right
    if(checkValidPosition(x,y+1,N)){
        temp[4][0] = x;
        temp[4][1] = y+1;
    }

    // down right
    if(checkValidPosition(x+1,y+1,N)){
        temp[5][0] = x+1;
        temp[5][1] = y+1;
    }

    // down
    if(checkValidPosition(x+1,y,N)){
        temp[6][0] = x+1;
        temp[6][1] = y;
    }

    // down left
    if(checkValidPosition(x+1,y-1,N)){
        temp[7][0] = x+1;
        temp[7][1] = y-1;
    }


    for(int i=0;i<noOfLamps;i++){
        for(int j=0;j<8;j++){
            if(temp[j][0]==-1 || temp[j][1]==-1)
                continue;

            // check if the lamp is adjacent:
            if(temp[j][0]==lamps_temp[i][0] && temp[j][1]==lamps_temp[i][1]){
            // if it is, then remove it. i.e. set it to -1,-1
                lamps_temp[i][0] = -1;
                lamps_temp[i][1] = -1;
            }

        }
    }



}

bool checkValidPosition(int x, int y, int N){
    if(x<0 || x>(N-1)) return false;
    if(y<0 || y>(N-1)) return false;
    return true;
}
