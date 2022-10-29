#include <iostream>     
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <conio.h>
#include <iomanip>
#include <random>

#define ALIGN 5
#define START 0
#define FINISH 70



int main () {
        
        // std::vector <int> *A = new std::vector <int>;
        // std::vector <int>::iterator it;
        // A->assign(5,30);
        // for (it =A->begin(); it!=A->end();it++)
        //         std::cout<<(*it)<<" ";
        
        // //std::cout<<char (getch());
        // system("pause");
        std::string ho_ten;
        int so_nguyen;
        double so_thuc;
        std::ifstream FILE;
        FILE.open("../txt/test.txt", std::ios::in | std::ios::app);
        std::stringstream ss;
        getline(FILE,ho_ten,',');
        FILE>>so_nguyen;
        FILE>>so_thuc;
        
        std::cout<<so_thuc;
        return 0;
        
}