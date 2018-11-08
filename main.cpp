#include <iostream>
#include <math.h>
#include <string>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

/*void characterstat (int attribute[6]) {
    int attribute[6] = {1, 1, 1, 1, 1, 1}; // strength, dex, con, int, wis, char//
    int stats[4] = {1, 1, 1, 1}; // HP, DEF, SP, AP//

    stats[0] = attribute[2] * 2 + attribute [0]
    stats[1] = attribute[2] * 1.5 + attribute [1] \ 2
    stats[2] = attribute[3] * 3 + attribute [4]
    stats[3] = attribute[0] * 2 + attribute[1] * 2

    return 0;

} */

/*int attSum(int a[], int n)  
{ 
    int initial_sum  = 0;  
    return accumulate(a, a+n, initial_sum); 
} */
int random(){
    return (rand() % 6 + 1);
}
int attSum(int array[], int size){
    int sum=0;
    for(int i=0; i < size; ++i){
        sum = array[i]+sum;
    }
    return sum;
}

int main(){

    int attribute[6] = {1, 1, 1, 1, 1, 1}; // strength, dex, con, int, wis, char//
    int stats[4] = {1, 1, 1, 1}; // HP, DEF, SP, AP//

   /* stats[0] = attribute[2] * 2 + attribute [0];
    stats[1] = attribute[2] * 1.5 + attribute [1] \ 2;
    stats[2] = attribute[3] * 3 + attribute [4];
    stats[3] = attribute[0] * 2 + attribute[1] * 2; */









    srand(time(NULL));
    int rollsix  = (rand() % 6 + 1);
    int atroll[4] = {1, 1, 1, 1};
    int pickst[3] = {1, 1, 1};
    int pick;
    int prevpick;
    string rdy = "Yes";

    cout << "You Must Roll Your Characters Attributes" << endl;
    cout << "You will roll a D6 four times per attribute" << endl;
    cout << "You may then pick the best 3" << endl;
    cout << "Then The Sum of the three you select will be the value of that attribute" << endl;
    cout << "When you are ready press enter" << endl;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    

    for (int rn = 0; rn < 4; ++rn){
        strroll:
        cout << "To Roll for Strength " <<endl;
        cout << "Press enter to roll" << endl;
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        atroll[rn] = random();
        cout << atroll[rn] << endl;
        
        
    }
    cout<< "Your Rolls are: " << endl;
    for(int rn = 0; rn < 4; ++rn ){
        cout << rn+1 << ") " << atroll[rn] << endl;
    }

    cout << "Pick 3 Rolls to add to Strength" << endl; //figure out how to make user selection not be an option on the next loop
    for (int rn = 0; rn < 3; ++rn){
        repick:
        cin >> pick;
    
        if (pick == 1){
            pick = 0;
            pickst[rn] = atroll[pick];
        }
        else if (pick == 2){
            pick = 1;
            pickst[rn] = atroll[pick];
        }
        else if (pick == 3){
            pick = 2;
            pickst[rn] = atroll[pick];
        }
        else if (pick == 4){
            pick = 3;
            pickst[rn] = atroll[pick];
        }
        else{
            cout << "Must pick a number between one and 4" << endl;
            goto repick;
        }
    }

    attribute[0]=attSum(pickst, 3);
    cout << "Your Strength is " << attribute[0] << endl;






        
    









return 0;


}

