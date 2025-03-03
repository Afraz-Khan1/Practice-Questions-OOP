#include <iostream>
using namespace std;
void addition(int matrice_1[][50],int matrice_2[][50],int row1,int row2,int col1,int col2){
if(row1==row2 && col1==col2){
    int result[50][50]={0};
    for(int i=0;i<row1;i++){
        for(int j=0;j<col1;j++){
            result[i][j]=matrice_1[i][j]+matrice_2[i][j];
        }
    }
cout<<" The addition of matrices:"<<endl;
for(int i=0;i<row1;i++){
        for(int j=0;j<col2;j++){
            cout<<" "<<result[i][j];
        }
        cout<<"\n";
    }
}
}
void multiplication(int matrice_1[][50],int matrice_2[][50],int row1,int row2,int col1,int col2){
if(col1==row2){
    int result[50][50]={0};
    for(int i=0;i<row1;i++){
        for(int j=0;j<col2;j++){
            for(int k=0;k<col1;k++){
                result[i][j]+=matrice_1[i][k]*matrice_2[k][j];
            }
        }
    }
cout<<" The multiplication of matrices: "<<endl;
for(int i=0;i<row1;i++){
        for(int j=0;j<col2;j++){
            cout<<" "<<result[i][j];
        }
        cout<<"\n";
    }
}
}

int main(){
int row1,row2,col1,col2;
cout<<" Enter Matrice 1 rows: "<<endl;
cin>>row1;
cout<<" Enter Matrice 1 columns: "<<endl;
cin>>col1;
int matrice_1[50][50];

for(int i=0;i<row1;i++){
    for(int j=0;j<col1;j++){
        cout<<" Enter "<<"("<<i+1<<","<<j+1<<") value: "<<endl;
        cin>>matrice_1[i][j];
    }
}
for(int i=0;i<row1;i++){
    for(int j=0;j<col1;j++){
        cout<<" "<<matrice_1[i][j];
    }
    cout<<"\n";
}

cout<<" Enter Matrice 2 rows: "<<endl;
cin>>row2;
cout<<" Enter Matrice 2 columns: "<<endl;
cin>>col2;
int matrice_2[50][50];

for(int i=0;i<row2;i++){
    for(int j=0;j<col2;j++){
        cout<<" Enter "<<"("<<i+1<<","<<j+1<<") value: "<<endl;
        cin>>matrice_2[i][j];
    }
}
for(int i=0;i<row2;i++){
    for(int j=0;j<col2;j++){
        cout<<" "<<matrice_2[i][j];
    }
    cout<<"\n";
}
addition(matrice_1,matrice_2,row1,row2,col1,col2);
multiplication(matrice_1,matrice_2,row1,row2,col1,col2);
    return 0;
}