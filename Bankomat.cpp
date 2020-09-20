//
// Created by Miller on 17.09.2020.
//

#include <iostream>
#include "Bankomat.h"
#include <cstdlib>
#include <ctime>


using namespace std;
int CurrentAmountDigit=0;
int MaxAmountDigit=0;
char *CurrentID = new char[5];
int i=0;

void Bankomat::ID() {

    int RandomDigit = 0;
    char Alphabet[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'Q', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S',
                         'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    char Numberbet[10] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};

    srand(time(NULL));

    for (int i=0; i<=3 ; i++) {
        RandomDigit= rand() % 25 + 0;
        CurrentID[i] = Alphabet[RandomDigit];
    }

    for(int i=3; i<=5;i++){
        RandomDigit=rand() %9+0;
        CurrentID[i]=Numberbet[RandomDigit];
    }
    }
void Bankomat::INFO() {
        CurrentAmountDigit=rand() %150000+50000;
        MaxAmountDigit=50000;
}

void Bankomat::Message(){
    cout <<"ID Данного банкомата: "<< CurrentID[i]<<CurrentID[i+1]<<CurrentID[i+2]<<"-"<<CurrentID[i+3]<<CurrentID[i+4] << endl;
    cout <<"Текущая сумма денег в банкомате: "<<CurrentAmountDigit<<"   [Максимальная сумма, которую можно снять разово: "<<MaxAmountDigit<<"]"<<endl;
    cout<<"Доступные действия: \n 1.Снять наличные. \n 2.Внести наличные."<<endl;
}
void Bankomat::Actions() {
    int Move = 0;
    int Summ=0;

    cin>>Move;

    if(Move==1){
        cout<<"Введите сумму,которую вы желаете снять: "; cin>>Summ;

        for(int i=1; Summ>MaxAmountDigit ; i++) {
            cout << "Вы ввели недопустимое значение"<< "   [Максимальная сумма, которую можно снять разово: "<<MaxAmountDigit<<"]"<<endl;
            cout<<"Неправильных попыток:"<<i<<endl;
            cout<<"Введите сумму,которую вы желаете снять: "; cin>>Summ;
        }

        CurrentAmountDigit=CurrentAmountDigit-Summ;
        cout<<"Вы успешно сняли наличные.\n Текущая сумма денег в банкомате:"<<CurrentAmountDigit<<"\n Желаете вернуться в главное меню?"<<endl;
       cout<<" 1.Да.\n 2.Нет."<<endl;
        cin>>Move;
if(Move==1){
    Message();
    Actions();
} else {
    system("pause");
       }
    }
if (Move==2){
    cout<<"Введите сумму,которую вы желаете внести: "; cin>>Summ;
    CurrentAmountDigit=CurrentAmountDigit+Summ;
    cout<<"Вы успешно внесли наличные.\n Текущая сумма денег в банкомате:"<<CurrentAmountDigit<<"\n Желаете вернуться в главное меню?"<<endl;
    cout<<" 1.Да.\n 2.Нет."<<endl;
    cin>>Move;
    if(Move==1){
        Message();
        Actions();
    } else {
        system("pause");
    }
}
}





