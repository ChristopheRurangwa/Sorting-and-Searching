/*
Name: Christohe Rurangwa
Date: 9/03/2020
CIS 1202-501
Program Name: Searching and Sorting Arrays
Description of what the program does:

The program price video game consoles. it use parallel arrays to input,
 print, find the most valuable, and sort pricing data.

*/

#include <iostream>
#include<fstream>
#include<string>
#include <iomanip>


using namespace std;

int showMenu();
void loadArrays(string[],int [],int &);
void showArrays(string[],int[],int);
void lookUpPrices(string[],int[],int);
void sortPrices(string[],int [],int);
void highestPrice(string[],int [],int);

int main() {

    showMenu();



    return 0;
}


/**
 * This method will display the menu to the user
 * @return choice in the form of an int
 */
int showMenu(){
    int choice;
    cout<<"\tConsole Pricing - Main Menu"<<endl;
    cout<<"1. Display all console prices."<<endl;
    cout<<"2. Look up the price of a particular console."<<endl;
    cout<<"3. Sort prices in descending order."<<endl;
    cout<<"4. Display the console with the highest price."<<endl;
    cout<<"5. Exit the program."<<endl;

    do{

        const int SIZE=5;
        string console[SIZE];
        int prices[SIZE];
        int counter=0;
        loadArrays(console,prices,counter);

        cin>>choice;
        if(choice==1){
            showArrays(console,prices,SIZE);

            showMenu();
        }
        if(choice==2){
            lookUpPrices(console,prices,SIZE);
            showMenu();
        }
        if(choice==3){
            sortPrices(console,prices,SIZE);
            showMenu();
        }
        if(choice==4){
            highestPrice(console,prices,SIZE);
            showMenu();
        }
        if(choice==5){
            exit(0);
        }

    }while(choice<=5&&choice!=0);




    return  choice;
}

/**
 * This method will save txt file data into arrays.
 * @param console
 */
void loadArrays(string console[],int prices [],int &SIZE){

    int counter=0;
    string word;


    ifstream file("price.txt");


    if(file.is_open()){

while(getline(file,word)){


    while(getline(file,console[counter])){

        file>>console[counter];


        string temp;
        getline(file,temp);

        file>>prices[counter];
                counter++;

    }}
    file.close();




    }
    else{
        cout<<"Check the .txt file, it did not open."<<endl;
    }


}

/**
 * This function will display arrays to the console
 * @param console
 * @param prices
 * @param counter
 */
void showArrays(string console[],int prices [],int SIZE){
int counter;
    cout<<setw(21)<<"Console"; cout<< setw(21)<<"Price"<<"\n\n";


    for (counter =0; counter<SIZE;counter++){

        cout<<setw(21)<<console[counter]<<setw(21);
        cout<<prices[counter]<<"\n";


    }


}

/**
 * This method will look for specific data in
 * the arrays and display it to the user
 * @param console
 * @param prices
 * @param counter
 */
void lookUpPrices(string console[],int prices [],int SIZE){
    string consol;
    int pos;
    cout<<"Console first name? ";cin>>consol;cout<<endl;


    int counter=0;
    loadArrays(console,prices,counter);

    string tempConsole;
    int beginScan, highestValue,highestIndex;

    for (beginScan=0;beginScan<(SIZE-1);beginScan++) {

        highestIndex = beginScan;
        highestValue = prices[beginScan];
        tempConsole = console[beginScan];


        for (int i = beginScan + 1; i < SIZE; i++) {
            if (prices[i] > highestValue) {//sort in decending order

                highestValue = prices[i];
                highestIndex = i;
                tempConsole = console[i];

            }
        }

        prices[highestIndex] = prices[beginScan];
        prices[beginScan] = highestValue;

        console[highestIndex] = console[beginScan];
        console[beginScan] = tempConsole;
    }
    for(int k=0;k<SIZE;k++){
        if(console[k]==consol){

            cout<<"The current price for "<<consol<<" is "<<prices[k]<<"."<<endl;
            break;
        }


    }





}






/**
 * This function will sort or order values in the decending order
 * @param console
 * @param prices
 * @param counter
 */
void sortPrices(string console[],int prices [],int SIZE){
    int counter=0;
    loadArrays(console,prices,counter);

    string tempConsole;
    int beginScan, highestValue,highestIndex;

    for (beginScan=0;beginScan<(SIZE-1);beginScan++) {

        highestIndex = beginScan;
        highestValue = prices[beginScan];
        tempConsole = console[beginScan];


        for (int i = beginScan + 1; i < SIZE; i++) {
            if (prices[i] > highestValue) {//sort in decending order

                highestValue = prices[i];
                highestIndex = i;
                tempConsole = console[i];


            }
        }


        prices[highestIndex] = prices[beginScan];
        prices[beginScan] = highestValue;

        console[highestIndex] = console[beginScan];
        console[beginScan] = tempConsole;
    }
    cout<<setw(21)<<"Console"; cout<< setw(21)<<"Price"<<"\n\n";
    for (int x = 0; x < SIZE; x++) {
        cout<<setw(21) << console[x]<<setw(21);
        cout << prices[x]<<"\n";
    }


}

/**
 * This method will compare values and display the highest priced console
 * @param console
 * @param prices
 * @param counter
 */
void highestPrice(string console[],int prices [],int SIZE) {
    int max = prices[0];

    string nameCon;

    for (int i = 1; i < SIZE; i++) {

        if (prices[i] > max) {
            max = prices[i];
            nameCon = console[i];
        }
    }
    cout << "The " << nameCon << " Playstation 4 has the highest price of " << max <<".\n";

}