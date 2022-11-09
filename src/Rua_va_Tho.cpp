#include<iostream>
#include<random>
#include<iomanip>
#include<conio.h>

#define ALIGN 5
#define START 0
#define FINISH 70


void Buoc_rua(int &Vi_tri, const int &x);       //cập nhật vị trí của rùa
void Buoc_tho(int &Vi_tri, const int &x);       //cập nhật vị trí của thỏ
void Display(const int &Rua, const int &Tho);   //mô phỏng chuyển động


int main()
{
    //random seed
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution <int> uni(1,10);

    int So_lan_Rua_thang =0;
    int So_lan_Tho_thang =0;
    int So_lan_Hoa=0;
    int So_tran_dau=0;
    do
    {
        int Rua =0, Tho = 0;
        system("cls");
        std::cout<<"GAME START!";
        _sleep(1000);
        while (Rua < FINISH && Tho < FINISH )
        {
            int Random_Rua = uni(rng);
            int Random_Tho = uni(rng);
            Buoc_rua(Rua, Random_Rua);
            Buoc_tho(Tho, Random_Tho);
            Display(Rua, Tho);
            _sleep(10);
        }
        if (Rua > Tho) 
        {
            std::cout<<"Rua thang\n";
            So_lan_Rua_thang++;
        }
        else if (Rua < Tho)
        {
            std::cout<<"Tho thang\n";
            So_lan_Tho_thang++;
        }
            else 
            {
                std::cout<<"Hoa\n";
                So_lan_Hoa++;
            }
        So_tran_dau++;
        std::cout<<"Ban co muon tiep tuc cuoc choi khong? (Y/N)";
    }
    while (char (getch()) == 'Y'  || char (getch()) =='y');
    
    //tổng kết
    std::cout<<"\nTong ket: \n\t(!)So lan rua thang: "<<So_lan_Rua_thang;
    std::cout<<"\n\t(!)So lan tho thang: "<<So_lan_Tho_thang;
    std::cout<<"\n\t(!)So lan hoa: "<<So_lan_Hoa;
    std::cout<<"\n\t(!)Tong so tran dau: "<<So_tran_dau;

}

void Buoc_rua(int &Vi_tri, const int &x)
{
    switch (x)
    {
        case 1:
        case 9:
        case 4:
        case 2:
        case 8:
            Vi_tri+= +3;
            break;
        case 5:
        case 10:
        case 3:
            Vi_tri+= +1;
            break;
        case 7:
        case 6:
            Vi_tri+= -6;
            break;
    }
    if (Vi_tri < START) Vi_tri = START;
    else if (Vi_tri > FINISH) Vi_tri = FINISH;
}

void Buoc_tho(int &Vi_tri, const int &x)
{
    switch (x)
    {
        case 2: case 10:
            Vi_tri+= 0;
            break;
        case 7: case 6:
            Vi_tri+= +9;
            break;
        case 9: case 4:
            Vi_tri+= -2;
            break;
        case 1: case 8: case 3:
            Vi_tri+= +1;
            break;
        case 5:
            Vi_tri+= -12;
            break;
    }
    if (Vi_tri < START) Vi_tri = START;
    else if (Vi_tri > FINISH) Vi_tri = FINISH;
}

void Display(const int &Rua, const int &Tho)
{
    system("cls");
    std::cout << "\n" << std::setw(ALIGN) << "" << std::setw(START) << "|" << std::setw(FINISH) << "F" << "\n";
    std::cout << std::setw(ALIGN) << "" << std::setw(START) << "S" << std::setw(FINISH) << "I" << "\n";
    std::cout << std::setw(ALIGN) << "" << std::setw(START) << "T" << std::setw(FINISH) << "N" << "\n";
    std::cout << std::setw(ALIGN) << "" << std::setw(START) << "A" << std::setw(FINISH) << "I" << "\n";
    std::cout << std::setw(ALIGN) << "" << std::setw(START) << "R" << std::setw(FINISH) << "S" << "\n";
    std::cout << std::setw(ALIGN) << "" << std::setw(START) << "T" << std::setw(FINISH) << "H" << "\n";
    std::cout << std::setw(ALIGN) << "" << std::setw(START) << "|" << std::setw(FINISH) << "|" << "\n";
   
    if (Rua == 0) {
        std::cout << std::setw(ALIGN) << "" << std::setw(START) << "R" << std::setw(FINISH) << "|" << "\n";
    }
    else if (Rua == FINISH) {
        std::cout << std::setw(ALIGN) << "" << std::setw(START) << "|" << std::setw(FINISH) << "R" << "\n";
    }
        else {
        std::cout << std::setw(ALIGN) << "" << std::setw(START) << "|" << std::setw(Rua) << "R" << std::setw(FINISH - Rua) << "|" << "\n";
        }

    std::cout << std::setw(ALIGN) << "" << std::setw(START) << "|" << std::setw(FINISH) << "|" << "\n";

    if (Tho == 0) {
        std::cout << std::setw(ALIGN) << "" << std::setw(START) << "T" << std::setw(FINISH) << "|" << "\n";
    }
    else if (Tho == FINISH) {
        std::cout << std::setw(ALIGN) << "" << std::setw(START) << "|" << std::setw(FINISH) << "T" << "\n";
    }
    else {
        std::cout << std::setw(ALIGN) << "" << std::setw(START) << "|" << std::setw(Tho) << "T" << std::setw(FINISH - Tho) << "|" << "\n";
    }

    std::cout << std::setw(ALIGN) << "" << std::setw(START) << "|" << std::setw(FINISH) << "|" << "\n" << "\n";
}