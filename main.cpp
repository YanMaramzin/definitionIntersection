#include <iostream>
#include <cmath>
#include <vector>
#include "calculator.h"

/*  Задача №4
    Известны географические координаты летательного аппарата (широта, долгота, высота), углы курса, крена и тангажа (п.2.).
    Считая подстилающую поверхность плоской, рассчитать координату пересечения с поверхностью.
*/

int main()
{
    double pitchAngle;           //угол тангажа
    double bankAngle;            //угол крена
    double headingAngle;        //угол курса

    double latitude;  //широта
    double longitude;  //долгота
    double height;    //высота

    //Ввод необходимых данных для рассчета
    std::cout<<"Введите значение угла тангажа от -180 до 180 градусов: ";
    std::cin>>pitchAngle;
    pitchAngle=conversionFromDegreesToRadians(pitchAngle);

    std::cout<<"Введите значение угла крена от -90 до 90 градусов: ";
    std::cin>>bankAngle;
    bankAngle=conversionFromDegreesToRadians(bankAngle);

    std::cout<<"Введите значение угла курса от -180 до 180 градусов: ";
    std::cin>>headingAngle;
    headingAngle=conversionFromDegreesToRadians(headingAngle);

    std::cout<<"Введите значение широты -90 до 90 градусов: ";
    std::cin>>latitude;

    std::cout<<"Введите значение долготы от -180 до 180 градусов: ";
    std::cin>>longitude;

    std::cout<<"Введите значение высоты: ";
    std::cin>>height;

    std::vector<std::vector<double>> unitVector={{1},{0},{0}};

    unitVector=rotationAroundAxes(-pitchAngle,bankAngle,-headingAngle,unitVector);

    //найдем координаты пересечения
    double h,x,y;

    if(unitVector[2][0]<0)
    {
        h=height/unitVector[2][0];
        x=latitude+unitVector[2][0]*h;
        y=longitude+unitVector[2][0]*h;
        std::cout<<"Координаты x= "<<x<<" y= "<<y<<"\n";
    }
    else {
        std::cout<<"Нет пересечния с поверхностью";
    }

    return 0;
}


