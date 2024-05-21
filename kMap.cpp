#include <iostream>
using namespace std;

void adjustMinterm(int &minterm) {
    if(minterm == 2){
        minterm++;
    }
    else if(minterm == 3){
        minterm--;
    }
    else if(minterm == 7){
        minterm--;
    }
    else if(minterm == 6){
        minterm++;
    }
    else if(minterm == 8){
        minterm +=4;
    }
    else if(minterm == 9){
        minterm +=4;
    }
    else if(minterm == 10){
        minterm +=5;
    }
    else if(minterm == 11){
        minterm +=3;
    }
    else if(minterm == 12){
        minterm-=4;
    }
    else if(minterm == 13){
        minterm-=4;
    }
    else if(minterm == 14){
        minterm-=3;
    }
    else if(minterm == 15){
        minterm-=5;
    }
}
void adjustMaxterm(int &minterm){
    adjustMinterm(minterm);

}
void printKMap(int array[4][4]) {
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }

    cout << "K-map expression: ";
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            if(array[i][j] == 1) {
                cout << "(";
                if(i == 0) cout << "A'";
                else cout << "A";
                if(j == 0) cout << "B'C'";
                else if(j == 1) cout << "B'C";
                else if(j == 2) cout << "BC";
                else if(j == 3) cout << "BC'";
                cout << ") + ";
            }
        }
    }
    cout << "\b\b  "; 
}
void printKMapPOS(int array[4][4]) {
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }

    cout << "K-map expression: ";
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            if(array[i][j] == 0) {
                cout << "(";
                if(i == 0) cout << "A";
                else cout << "A'";
                if(j == 0) cout << " + B + C";
                else if(j == 1) cout << " + B + C'";
                else if(j == 2) cout << " + B' + C'";
                else if(j == 3) cout << " + B' + C";
                cout << ") ";
            }
        }
    }
    cout << "\b\b  "; // Remove the last space
    cout << endl;
}

    


int main() {
    int op;
    int pos[4][4] ={{1,1,1,1},{1,1,1,1},{1,1,1,1},{1,1,1,1}};
    int array[4][4] = {0};
    int minTerm[16];
    int count;
  
    
   
    while(true){
        cout<<"Choose Your option: ";
        cout<<"1) For SOP";
        cout<<"2) For POS";
        cin>>op;
        switch(op){
            case 1:
                  cout << "Enter the number of Minterms you want" << endl;
                  cin >> count;
                  for(int i = 0; i < count; i++){
                  cout << "Enter " << i + 1 << " Minterm: ";
                  cin >> minTerm[i];
                  }

                  for(int i = 0; i < count; i++){
                  int minterm = minTerm[i];
                  adjustMinterm(minterm);
                  array[i / 4][minterm] = 1;
                  }
                  printKMap(array);
                  break;
            case 2:
                  cout << "Enter the number of Maxterm you want" << endl;
                  cin >>count;
                  for(int i = 0; i < count; i++){
                  cout << "Enter " << i + 1 << " Maxterm: ";
                  cin >> minTerm[i];
                  }
                  for(int i = 0; i < count; i++){
                  int minterm = minTerm[i];
                  adjustMaxterm(minterm);
                  pos[i / 4][minterm] = 0;
                  }
                  printKMapPOS(pos);

                  break;
            case 3:
                return 0;


            defualt: 
                return 0;

}
 
    }
     return 0;
}
