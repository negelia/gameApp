#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <Windows.h>
#include <vector>
#include <list>
#include <iterator>
#include <cstdlib>
#include <conio.h>

using namespace std;
string name;
int deathMON, dung;
int HP = 0, EXP = 0, ATK = 0, MP = 0, LV = 0, GOLD = 0;
vector<string> inventory;
vector<string> creatures;
vector<string> Equipment = { "<Пусто>", "<Пусто>", "<Пусто>", "<Пусто>", "<Пусто>" };
vector<string> EquipmentARMOR = { "<Пусто>", "<Пусто>", "<Пусто>", "<Пусто>" };
vector<string> Runes = { "<Пусто>", "<Пусто>", "<Пусто>", "<Пусто>", "<Пусто>" };
vector<string> Mercenaries = { "<Пусто>", "<Пусто>", "<Пусто>" };
string InventorySlots[5] = { "Голова", "Грудная клетка", "Руки", "Ноги", "Стопы" };
int chARENA, hodh, chARMOREq, chARMORRun;
int chST = 0, chWEAPON = 0, chARMOR = 0, chRUNES = 0, input = 0, answer = 0, ch = 0, chCREATURES = 0, chINVENTORY = 0, inputGO = 0;
int  price = 0;
void check()
{
    while (true) // цикл продолжается до тех пор, пока пользователь не введет корректное значение
    {
        std::cout << "Enter a double value: ";
        double a;
        std::cin >> a;

        // Проверка на предыдущее извлечение
        if (std::cin.fail()) // если предыдущее извлечение оказалось неудачным,
        {
            std::cin.clear(); // то возвращаем cin в 'обычный' режим работы
            std::cin.ignore(32767, '\n'); // и удаляем значения предыдущего ввода из входного буфера
            std::cout << "Введите номер категории предмета\n";
        }
        else
        {
            std::cin.ignore(32767, '\n'); // удаляем лишние значения
        }
    }
}
class boss
{
public:
    string name;

    int HP = 0, ATK = 0, Bossgold = 0;
};
void BBB(boss& B)
{

    int n;
    n = rand() % 11 + 1;
    switch (n)
    {
    case 1:
    {
        B.name = "Qozit";
        B.HP = 50;
        B.ATK = 10;
        B.Bossgold = 55;
    }
    break;
    case 2:
    {
        B.name = "Gargantuar";
        B.HP = 40;
        B.ATK = 10;
        B.Bossgold = 47;
    }
    break;
    case 3:
    {
        B.name = "Misstress Albedo";
        B.HP = 35;
        B.ATK = 12;
        B.Bossgold = 50;
    }
    break;
    case 4:
    {
        B.name = " Demon [Highway to Hell]";
        B.HP = 25;
        B.ATK = 10;
        B.Bossgold = 50;
    }
    break;
    case 5:
    {
        B.name = "The greatest magister Ainz Oal Gown";
        B.HP = 100;
        B.ATK = 20;
        B.Bossgold = 100;
    }
    break;
    }
}
//
//class magic
//{
//    string name;
//    int ATK = 0, MP = 0;
//
//};
//void TYPE(magic& M)
//{
//    magic MAGIYA[6];
//}
//class spells
//{
//    string name;
//    int ATK = 0, MP = 0;
//
//};
//void TUPE(spells& S)
//{
//
//
//
//}
class party
{
public:
    string name;
    int HP = 0, EXP = 0, ATK = 0, MP = 0;

};

//class tools
//{
//    string name;
//    int HP = 0, ATK = 0, MP = 0;
//};
class player
{

public:
    string name;

    bool menu = true;


    string CLASS;

    int Brat_n = 0, mon_v = 0, parameter = 0;
    player(int choice)
    {
        if (choice == 1) {
            CLASS = "Воин";
            LV = 1;
            ATK = 8;
            HP = 18;
            MP = 10;
            GOLD = 100;// add gold for buying items
        }
        if (choice == 2) {
            CLASS = "Маг";
            LV = 1;
            ATK = 15;
            HP = 10;
            MP = 100;
            GOLD = 100;
        }
        if (choice == 3) {
            CLASS = "Стрелок";
            LV = 1;
            ATK = 10;
            HP = 15;
            MP = 30;
            GOLD = 100;
        }


    }
    string printClass()
    {
        return CLASS;
    }

    void togo()
    {
        std::cout << "Класс " << CLASS << endl;
        std::cout << "Атака " << ATK << endl;
        std::cout << "Здоровье " << HP << endl;
        std::cout << "Мана " << MP << endl;
        std::cout << "Уровень " << LV << endl;

    }
};
void ALLinventory()
{
    std::cout << endl;
    std::cout << "В вашем инвентаре находятся : " << endl; //ИНВЕНТАРЬ
    for (string n : inventory)
        std::cout << n << "\t" << endl;
    std::cout << endl;
    std::cout << endl;

Invent:
    std::cout << "Чтобы собрать сумку, выберите категорию предметов : " << endl;
    while (true)
    {
        std::cout << "1 - Броня; 2 - Орудие; 3 - Руны" << endl;
        std::cin >> chINVENTORY;

        if (std::cin.fail()) // если предыдущее извлечение оказалось неудачным,
        {
            std::cin.clear();
            std::cin.ignore(32767, '\n'); // удаляем значения предыдущего ввода из входного буфера
            std::cout << "Введите номер категории предмета\n";
        }
        else
        {
            std::cin.ignore(32767, '\n'); // удаляем лишние значения
            //return chINVENTORY;
        }

        if (chINVENTORY == 1)
        {
            std::cout << "Введите номер части тела, чтобы надеть броню" << endl;
            while (true)
            {
                std::cout << " 1 - Голова; 2 - Грудная клетка; 3 - Руки; 4 - Ноги; 5 - Стопы." << endl;
                std::cin >> input;

                if (std::cin.fail()) // если предыдущее извлечение оказалось неудачным,
                {
                    std::cin.clear();
                    std::cin.ignore(32767, '\n'); // удаляем значения предыдущего ввода из входного буфера
                    std::cout << "Введите номер категории предмета\n";
                }
                else
                {
                    std::cin.ignore(32767, '\n'); // удаляем лишние значения
                    //return chINVENTORY;
                }

                switch (input)
                {
                case 1:
                    for (int i = 0; i < inventory.size(); i++) {

                        if (inventory[i] == "Шлем") {
                            Equipment[0] = inventory[i];
                            std::cout << Equipment[0] << endl;
                            std::cout << "Вы надели шлем" << endl;
                            HP += 15;
                            cout << "Сейчас у вас HP: " << HP << endl;
                        }
                        else
                        {
                            cout << "У вас нет предмета для экипировки данной части тела" << endl;
                        }
                    }
                    break;
                case 2:
                    for (int i = 0; i < inventory.size(); i++) {

                        if (inventory[i] == "Нагрудник") {
                            Equipment[1] = inventory[i];
                            cout << Equipment[1] << endl;
                            cout << "Вы надели нагрудник" << endl;
                            HP += 15;
                            cout << "Сейчас у вас HP: " << HP << endl;
                            cout << "Сейчас у вас ATK: " << ATK << endl;
                        }
                        else
                        {
                            cout << "У вас нет предмета для экипировки данной части тела" << endl;
                        }
                    }
                    break;
                case 3:
                    for (int i = 0; i < inventory.size(); i++) {

                        if (inventory[i] == "Латные перчатки") {
                            Equipment[2] = inventory[i];
                            cout << Equipment[2] << endl;
                            cout << "Вы взяли латные перчатки" << endl;
                            HP += 5;
                            ATK += 3;
                            cout << "Сейчас у вас HP: " << HP << endl;
                        }
                        if (inventory[i] == "Щит") {
                            Equipment[2] = inventory[i];
                            cout << Equipment[2] << endl;
                            cout << "Вы взяли щит" << endl;
                            HP += 10;
                            std::cout << "Сейчас у вас HP: " << HP << endl;
                        }
                        else
                        {
                            std::cout << "У вас нет предмета для экипировки данной части тела" << endl;
                        }
                    }
                    break;
                case 4:
                    for (int i = 0; i < inventory.size(); i++) {

                        if (inventory[i] == "Латные ноги") {
                            Equipment[3] = inventory[i];
                            std::cout << Equipment[3] << endl;
                            std::cout << "Вы надели латные ноги" << endl;
                            HP += 3;
                            std::cout << "Сейчас у вас HP: " << HP << endl;
                        }
                        else
                        {
                            std::cout << "У вас нет предмета для экипировки данной части тела" << endl;
                        }
                    }
                    break;
                case 5:
                    for (int i = 0; i < inventory.size(); i++) {

                        if (inventory[i] == "Латные ботинки") {
                            Equipment[4] = inventory[i];
                            std::cout << Equipment[4] << endl;
                            std::cout << "Вы обули латные ботинки" << endl;
                            HP += 5;
                            std::cout << "Сейчас у вас HP: " << HP << endl;
                        }
                        else
                        {
                            std::cout << "У вас нет предмета для экипировки данной части тела" << endl;
                        }
                    }
                    break;
                }
                std::cout << "Вы взяли с собой : " << endl;
                for (string a : Equipment)
                    std::cout << a << "\t";
                std::cout << endl;
            }
        }
        else if (chINVENTORY == 2)
        {
            std::cout << "Введите номер орудия" << endl;
            while (true)
            {
                std::cout << " 1 - Щит; 2 - Топор; 3 - Меч; 4 - Лук для стрельбы." << endl;
                std::cin >> input;

                if (std::cin.fail()) // если предыдущее извлечение оказалось неудачным,
                {
                    std::cin.clear();
                    std::cin.ignore(32767, '\n'); // удаляем значения предыдущего ввода из входного буфера
                    std::cout << "Введите номер категории предмета\n";
                }
                else
                {
                    std::cin.ignore(32767, '\n'); // удаляем лишние значения
                }

                switch (input)
                {
                case 1:
                    for (int i = 0; i < inventory.size(); i++) {
                        if (inventory[i] == "Щит")
                        {
                            EquipmentARMOR[0] = inventory[i];
                            std::cout << EquipmentARMOR[0] << endl;
                            std::cout << "Вы взяли щит" << endl;
                        }
                        else
                        {
                            std::cout << "У вас нет предмета для экипировки данной части тела" << endl;
                        }
                    }
                    break;
                case 2:
                    for (int i = 0; i < inventory.size(); i++) {
                        if (inventory[i] == "Топор")
                        {
                            EquipmentARMOR[1] = inventory[i];
                            std::cout << EquipmentARMOR[1] << endl;
                            std::cout << "Вы взяли топор" << endl;
                        }
                        else
                        {
                            std::cout << "У вас нет предмета для экипировки данной части тела" << endl;
                        }
                    }
                    break;
                case 3:
                    for (int i = 0; i < inventory.size(); i++) {
                        if (inventory[i] == "Меч")
                        {
                            EquipmentARMOR[2] = inventory[i];
                            std::cout << EquipmentARMOR[2] << endl;
                            std::cout << "Вы взяли меч" << endl;
                        }
                        else
                        {
                            std::cout << "У вас нет предмета для экипировки данной части тела" << endl;
                        }
                    }
                    break;
                case 4:
                    for (int i = 0; i < inventory.size(); i++) {
                        if (inventory[i] == "Лук для стрельбы")
                        {
                            EquipmentARMOR[3] = inventory[i];
                            std::cout << EquipmentARMOR[3] << endl;
                            std::cout << "Вы взяли лук для стрельбы" << endl;
                        }
                        else
                        {
                            std::cout << "У вас нет предмета для экипировки данной части тела" << endl;
                        }
                    }
                    break;
                }
                std::cout << "Вы взяли с собой : " << endl;
                for (string c : EquipmentARMOR)
                    std::cout << c << "\t";
                std::cout << endl;
            }
        }
        else if (chINVENTORY == 3)
        {
            std::cout << "Введите номер руны" << endl;
            while (true)
            {
                std::cout << " 1 - Магия огня; 2 - Магия воздуха; 3 - Магия воды; 4 - Магия земли; 5 - Магия тьмы." << endl;
                std::cin >> input;

                if (std::cin.fail()) // если предыдущее извлечение оказалось неудачным,
                {
                    std::cin.clear();
                    std::cin.ignore(32767, '\n'); // удаляем значения предыдущего ввода из входного буфера
                    std::cout << "Введите номер категории предмета\n";
                }
                else
                {
                    std::cin.ignore(32767, '\n'); // удаляем лишние значения
                }

                switch (input)
                {
                case 1:
                    for (int i = 0; i < inventory.size(); i++) {
                        if (inventory[i] == "Магия огня") {
                            Runes[0] = inventory[i];
                            std::cout << Runes[0] << endl;
                            std::cout << "Вы обладаете магией огня" << endl;
                        }
                        else
                        {
                            std::cout << "Вы не обладаете данной магией" << endl;
                        }
                    }
                    break;
                case 2:
                    for (int i = 0; i < inventory.size(); i++) {
                        if (inventory[i] == "Магия воздуха") {
                            Runes[1] = inventory[i];
                            std::cout << Runes[1] << endl;
                            std::cout << "Вы обладаете магией воздуха" << endl;
                        }
                        else
                        {
                            std::cout << "Вы не обладаете данной магией" << endl;
                        }
                    }
                    break;
                case 3:
                    for (int i = 0; i < inventory.size(); i++) {
                        if (inventory[i] == "Магия воды") {
                            Runes[2] = inventory[i];
                            std::cout << Runes[2] << endl;
                            std::cout << "Вы обладаете магией воды" << endl;
                        }
                        else
                        {
                            std::cout << "Вы не обладаете данной магией" << endl;
                        }
                    }
                    break;
                case 4:
                    for (int i = 0; i < inventory.size(); i++) {
                        if (inventory[i] == "Магия земли") {
                            Runes[3] = inventory[i];
                            std::cout << Runes[3] << endl;
                            std::cout << "Вы обладаете магией земли" << endl;
                        }
                        else
                        {
                            std::cout << "Вы не обладаете данной магией" << endl;
                        }
                    }
                    break;
                case 5:
                    for (int i = 0; i < inventory.size(); i++) {
                        if (inventory[i] == "Магия тьмы") {
                            Runes[4] = inventory[i];
                            std::cout << Runes[4] << endl;
                            std::cout << "Вы обладаете магией тьмы" << endl;
                        }
                        else
                        {
                            std::cout << "Вы не обладаете данной магией" << endl;
                        }
                    }
                    break;
                }
                std::cout << "Вы взяли с собой руны : " << endl;
                for (string b : Runes)
                    std::cout << b << "\t";
                std::cout << endl;
            }
        }
    }
}
void shop()
{
    std::cout << "Добро пожаловать в магазин !" << endl;

    std::cout << "\nВыберите категорию предмета для покупки" << endl;
    while (true)
    {
        std::cout << "1 - Орудие, 2 - Броня, 3 - Руны, 4 - Наёмники; 5 - Выход" << endl;
        std::cin >> chST;

        if (std::cin.fail()) // если предыдущее извлечение оказалось неудачным,
        {
            std::cin.clear(); // то возвращаем cin в 'обычный' режим работы
            std::cin.ignore(32767, '\n'); // и удаляем значения предыдущего ввода из входного буфера
            std::cout << "Введите номер категории предмета\n";
        }
        else
        {
            std::cin.ignore(32767, '\n'); // удаляем лишние значения
        }

        switch (chST)
        {
            //ОРУДИЕ
        case 1:
            if (GOLD > 9)
            {
                std::cout << "Выберите орудие!" << endl;
                std::cout << " 1 - Топор (+5 ATK, +5 HP) : цена 10G" << endl;
                std::cout << " 2 - Меч (+10 ATK, +10 HP) : цена 20G" << endl;
                std::cout << " 3 - Лук для стрельбы (+15 ATK, +15 HP) : цена 30G" << endl;
                std::cin >> chWEAPON;

                if (std::cin.fail()) // если предыдущее извлечение оказалось неудачным,
                {
                    std::cin.clear(); // то возвращаем cin в 'обычный' режим работы
                    std::cin.ignore(32767, '\n'); // и удаляем значения предыдущего ввода из входного буфера
                    std::cout << "Введите номер категории предмета\n";
                }
                else
                {
                    std::cin.ignore(32767, '\n'); // удаляем лишние значения
                }

                if (chWEAPON == 1)
                {
                    std::cout << "Вы купили топор" << endl;
                    auto iter = inventory.cend();
                    inventory.insert(iter, "Топор");

                    price = 10;
                    GOLD -= price;

                }
                else if (chWEAPON == 2)
                {
                    std::cout << "Вы купили меч" << endl;
                    auto iter = inventory.cend();
                    inventory.insert(iter, "Меч");

                    price = 20;
                    GOLD -= price;

                }
                else if (chWEAPON == 3)
                {
                    std::cout << "Вы купили лук для стрельбы" << endl;
                    auto iter = inventory.cend();
                    inventory.insert(iter, "Лук для стрельбы");

                    price = 30;
                    GOLD -= price;
                }
                std::cout << "У вас осталось " << GOLD << " золота" << endl;
            }
            else
            {
                std::cout << "У вас не осталось золота"; //goto to the main menu
                std::cout << endl;
            }
            break;
            //БРОНЯ
        case 2:
            if (GOLD > 2)
            {
                std::cout << "Выберите броню!" << endl;
                std::cout << " 1 - Щит (+10 HP) : cost 10G" << endl;
                std::cout << " 2 - Шлем (+15 HP) : cost 25G" << endl;
                std::cout << " 3 - Нагрудник (+15 HP) : cost 35G" << endl;
                std::cout << " 4 - Латные перчатки (+5 HP, +3 ATK) : cost 30G" << endl;
                std::cout << " 5 - Латные ноги (+3 HP) : cost 3G" << endl;
                std::cout << " 6 - Латные ботинки (+5 HP) : cost 5G" << endl;
                std::cin >> chARMOR;

                if (std::cin.fail()) // если предыдущее извлечение оказалось неудачным,
                {
                    std::cin.clear(); // то возвращаем cin в 'обычный' режим работы
                    std::cin.ignore(32767, '\n'); // и удаляем значения предыдущего ввода из входного буфера
                    std::cout << "Введите номер категории предмета\n";
                }
                else
                {
                    std::cin.ignore(32767, '\n'); // удаляем лишние значения
                }

                if (chARMOR == 1)
                {
                    std::cout << "Вы купили щит" << endl;
                    auto iter = inventory.cend();
                    inventory.insert(iter, "Щит");

                    price = 15;
                    GOLD -= price;
                }
                else if (chARMOR == 2)
                {
                    std::cout << "Вы купили шлем" << endl;
                    auto iter = inventory.cend();
                    inventory.insert(iter, "Шлем");

                    price = 25;
                    GOLD -= price;
                }
                else if (chARMOR == 3)
                {
                    std::cout << "Вы купили нагрудник" << endl;
                    auto iter = inventory.cend();
                    inventory.insert(iter, "Нагрудник");

                    price = 35;
                    GOLD -= price;
                }
                else if (chARMOR == 4)
                {
                    std::cout << "Вы купили латные перчатки" << endl;
                    auto iter = inventory.cend();
                    inventory.insert(iter, "Латные перчатки");

                    price = 45;
                    GOLD -= price;
                }
                else if (chARMOR == 5)
                {
                    std::cout << "Вы купили латные ноги" << endl;
                    auto iter = inventory.cend();
                    inventory.insert(iter, "Латные ноги");

                    price = 55;
                    GOLD -= price;
                }
                else if (chARMOR == 6)
                {
                    std::cout << "Вы купили латные ботинки" << endl;
                    auto iter = inventory.cend();
                    inventory.insert(iter, "Латные ботинки");

                    std::cout << endl;
                    price = 65;
                    GOLD -= price;
                }
                std::cout << "У вас осталось " << GOLD << " золота" << endl;
            }
            else
            {
                std::cout << "У вас не осталось золота";
                std::cout << endl;
            }
            break;
            //РУНЫ
        case 3:
            if (GOLD > 29)
            {
                std::cout << "Выберите магические руны!" << endl;
                std::cout << " 1 - Магия огня (+5 ATK) : cost 30G" << endl; //secondary usage gives debaf
                std::cout << " 2 - Магия земли (+5 ATK) : cost 30G" << endl;
                std::cout << " 3 - Магия воздуха (+5 ATK) : cost 30G" << endl;
                std::cout << " 4 - Магия воды (+5 ATK) : cost 30G" << endl;
                std::cout << " 5 - Магия смерти (+20 ATK) : cost 100G" << endl; // death of monster - +100G (can buy after first battle)
                std::cin >> chRUNES;

                if (std::cin.fail()) // если предыдущее извлечение оказалось неудачным,
                {
                    std::cin.clear(); // то возвращаем cin в 'обычный' режим работы
                    std::cin.ignore(32767, '\n'); // и удаляем значения предыдущего ввода из входного буфера
                    std::cout << "Введите номер категории предмета\n";
                }
                else
                {
                    std::cin.ignore(32767, '\n'); // удаляем лишние значения
                }

                if (chRUNES == 1)
                {
                    std::cout << "Вы купили руну магии огня" << endl;
                    auto iter = inventory.cend();
                    inventory.insert(iter, "Магия огня");

                    price = 30;
                    GOLD -= price;
                }
                else if (chRUNES == 2)
                {
                    std::cout << "Вы купили руну магии земли" << endl;
                    auto iter = inventory.cend();
                    inventory.insert(iter, "Магия земли");

                    price = 30;
                    GOLD -= price;
                }
                else if (chRUNES == 3)
                {
                    std::cout << "Вы купили руну магии воздуха" << endl;
                    auto iter = inventory.cend();
                    inventory.insert(iter, "Магия воздуха");

                    price = 30;
                    GOLD -= price;
                }
                else if (chRUNES == 4)
                {
                    std::cout << "Вы купили руну магии воды" << endl;
                    auto iter = inventory.cend();
                    inventory.insert(iter, "Магия воды");

                    price = 30;
                    GOLD -= price;
                }
                else if (chRUNES == 5)
                {
                    std::cout << "Вы купили руну магии смерти" << endl;
                    auto iter = inventory.cend();
                    inventory.insert(iter, "Магия смерти");

                    price = 100;
                    GOLD -= price;
                }
            }
            else
            {
                std::cout << "У вас не осталось золота" << endl;
            }
            break;
            //НАЁМНИКИ
        case 4:
            if (GOLD > 49)
            {
                std::cout << "Выберите наёмника!" << endl;
                std::cout << " 1 - Человечек : cost 40G" << endl;
                std::cout << " 2 - Гоблин : cost 42G" << endl;
                std::cin >> chCREATURES;

                if (std::cin.fail()) // если предыдущее извлечение оказалось неудачным,
                {
                    std::cin.clear(); // то возвращаем cin в 'обычный' режим работы
                    std::cin.ignore(32767, '\n'); // и удаляем значения предыдущего ввода из входного буфера
                    std::cout << "Введите номер категории предмета\n";
                }
                else
                {
                    std::cin.ignore(32767, '\n'); // удаляем лишние значения
                }

                if (chCREATURES == 1)
                {
                    std::cout << "Вы купили Человечека" << endl;
                    auto iter = creatures.cend();
                    creatures.insert(iter, "Человечек");
                    price = 40;
                    GOLD -= price;
                }
                else if (chCREATURES == 2)
                {
                    std::cout << "Вы купили Гоблина" << endl;
                    auto iter = creatures.cend();
                    creatures.insert(iter, "Гоблин");
                    price = 42;
                    GOLD -= price;
                }
                std::cout << "У вас в команде : " << endl;
                for (string d : creatures)
                    std::cout << d << "\t";
                std::cout << endl;
            }
            else
            {
                std::cout << "У вас не осталось золота" << endl;
            }
            break;
            //ВЫХОД
        case 5:
            std::cout << "Вы покидаете магазин. Приходите снова !" << endl;
            break;
        }
    }
}
class merc
{
public:
    int mercHP, mercATK;
};
void mercVID(merc& M)
{
    for (int i = 0; i < creatures.size(); i++) {
        if (creatures[0] == "Человечек")
        {
            M.mercATK = 3;
            M.mercHP = 8;
            std::cout << "Человечка HP: " << M.mercHP << " " << "Человечка ATK: " << M.mercATK << "\n";
        }
        else if (creatures[1] == "Гоблин")
        {
            M.mercATK = 4;
            M.mercHP = 9;
            std::cout << "Гоблина HP: " << M.mercHP << " " << "Гоблина ATK: " << M.mercATK << "\n";
        }
    }
}

class beasters
{
public:
    string name;
    string weak;
    int HPbeast = 0, ATK = 0, LV = 0, GOLD = 0;

};
void VID(beasters& N)
{

    int n;
    n = rand() % 11 + 1;
    switch (n)
    {
    case 1:
    {
        N.name = "Skeleton";
        N.HPbeast = 10;
        N.ATK = 3;
        N.LV = 1;
        N.GOLD = 15;
    }
    break;

    case 2:
    {
        N.name = "Slime";
        N.HPbeast = 5;
        N.ATK = 1;
        N.LV = 1;
        N.GOLD = 10;
    }
    break;
    case 3:
    {
        N.name = "Undyne";
        N.HPbeast = 25;
        N.ATK = 5;
        N.LV = 1;
        N.GOLD = 25;
    }
    break;
    case 4:
    {
        N.name = "Goblin";
        N.HPbeast = 10;
        N.ATK = 5;
        N.LV = 1;
        N.GOLD = 10;
    }
    break;
    case 5:
    {
        N.name = "The Living Armor";
        N.HPbeast = 18;
        N.ATK = 6;
        N.LV = 1;
        N.GOLD = 21;
    }
    break;
    case 6:
    {
        N.name = "Orc";
        N.HPbeast = 16;
        N.ATK = 4;
        N.LV = 1;
        N.GOLD = 18;
    }
    break;
    case 7:
    {
        N.name = "Succubus";
        N.HPbeast = 15;
        N.ATK = 5;
        N.LV = 1;
        N.GOLD = 12;
    }
    break;
    case 8:
    {
        N.name = "Vendetta Skeleton";
        N.HPbeast = 1;
        N.ATK = 1000;
        N.LV = 1;
        N.GOLD = 5;
    }
    break;
    case 9:
    {
        N.name = "Root";
        N.HPbeast = 8;
        N.ATK = 4;
        N.LV = 1;
        N.GOLD = 7;
    }
    break;
    case 10:
    {
        N.name = "Ghost";
        N.HPbeast = 10;
        N.ATK = 4;
        N.LV = 1;
        N.GOLD = 11;
    }
    break;
    case 11:
    {
        N.name = "Forged";
        N.HPbeast = 14;
        N.ATK = 6;
        N.LV = 1;
        N.GOLD = 12;
    }
    break;
    case 12:
    {
        N.name = "Hobgoblin";
        N.HPbeast = 12;
        N.ATK = 5;
        N.LV = 1;
        N.GOLD = 13;
    }
    break;
    case 13:
    {
        N.name = "Grim Reaper";
        N.HPbeast = 15;
        N.ATK = 10;
        N.LV = 1;
        N.GOLD = 27;
    }
    break;
    case 14:
    {
        N.name = "Lich";
        N.HPbeast = 17;
        N.ATK = 9;
        N.LV = 1;
        N.GOLD = 21;
    }
    break;
    case 15:
    {
        N.name = "Golem";
        N.HPbeast = 27;
        N.ATK = 7;
        N.LV = 1;
        N.GOLD = 35;
    }
    break;



    default:
        break;
    }
    std::cout << N.name << "\n";

    std::cout << "HP: " << N.HPbeast << " " << "Атака: " << N.ATK << " " << "Уровень: " << N.LV << "\n";
}
void COMRAD(player& t, party& P)
{

    int n;

    n = rand() % 2 + 1;
    switch (n)
    {
    case 1:
    {

        P.HP = 10;
        P.ATK = 1;
    }
    break;

    case 2:
    {
        P.HP = 20;
    }
    break;



    default:
        break;
    }
    std::cout << P.HP << "\n";


    t.Brat_n++;
}
void death()
{
    std::cout << "ВЫ МЕРТВЫ!";

    std::cout << "ВАШЕ ПРИКЛЮЧЕНИЕ ЗАКАНЧИВАЕТСЯ ЗДЕСЬ!";

    std::cout << "ВАША ДУША ТЕПЕРЬ ЧАСТЬ ЛЕСА!";
    system("cls");
    cout << "Таблица лидеров" << endl;
    ofstream file("file.txt", ios::app);
    if (!file)
        exit(1);
    file << "___________________________________" << "\n";
    file << "Уровень" << "  :  " << LV << endl;
    file << "Имя" << "  :  " << name << endl;
    file << "Золото" << "  :  " << GOLD << endl;
    file << "Очки" << "  :  " << EXP << endl;
    file << "___________________________________" << "\n";
    string line;
    ifstream in("file.txt");
    if (in.is_open())
    {
        while (getline(in, line))
        {
            cout << line << endl;
        }
    }

    file.close();

    exit(1);
}
void battler(int CH, int hHP)
{

    player character(CH);
    std::cout << "WARNING!" << endl;
    Sleep(1000);
    std::cout << "WARNING!" << endl;
    Sleep(1000);
    std::cout << "WARNING!" << endl;
    Sleep(1000);
    std::cout << "На тебя напал монстр!";

    std::cout << "Характеристики монстра: " << endl;
    beasters monster;
    VID(monster);//вывод параметров монстра

    merc Merc;
    int mHP = monster.HPbeast;
    hHP = HP;

    std::cout << "Ваша характеристика: " << endl;
    character.togo();

    for (int i = 0; i < creatures.size(); i++) {
        if (creatures[i] != "")
        {
            std::cout << "У вас в команде : " << endl;
            for (string d : creatures)
                std::cout << d << "\t";
            std::cout << endl;

            std::cout << "Характеристики наёмников: " << endl;
            mercVID(Merc); //вывод параметров наёмников

        }
        else
        {
            std::cout << "У вас нет армии. Сражайтесь в одиночку. " << endl;
        }
    }
    while (hHP != 0 || mHP != 0)
    {
    HOD:
        std::cout << "Выберите действие: " << endl;//ход игрока
        std::cout << "[1] Обычная атака" << endl;
        std::cout << "[2] Защита (+5)" << endl;;
        std::cout << "[3] Лечение(+3)" << endl;;
        std::cout << "[4] Выбор предмета" << endl;;
        std::cin >> hodh;
        switch (hodh)
        {
        case 1:
            system("cls");
            std::cout << "[1] Обычная атака" << endl;
            mHP -= ATK;
            for (int i = 0; i < creatures.size(); i++) {
                if (creatures[i] != "")
                {
                    mHP -= Merc.mercATK;
                }
            }
            break;
        case 2:
            system("cls");
            std::cout << "[2] Защита" << endl;;
            hHP += 5;
            for (int i = 0; i < creatures.size(); i++) {
                if (creatures[i] != "")
                {
                    Merc.mercHP += 5;
                }
            }
            break;
        case 3:
            system("cls");
            std::cout << "[3] Лечение" << endl;;
            hHP += 3;
            for (int i = 0; i < creatures.size(); i++) {
                if (creatures[i] != "")
                {
                    Merc.mercHP += 5;
                }
            }
            break;
        case 4:
            system("cls");
            std::cout << "Выберите категорию предмета для атаки: " << endl;;
            std::cout << "1 - Орудие; 2 - Руны." << endl;;
            std::cin >> chARENA;
            if (chARENA == 1)
            {
                for (int i = 0; i < EquipmentARMOR.size(); i++) {   //проходимся по всей сумке в поиске оружия 
                    if (EquipmentARMOR[i] != "<Пусто>")
                    {
                        std::cout << "Выберите название оружия, чтобы взять его" << endl;
                        std::cout << "1 - Топор; 2 - Меч; 3 - Лук для стрельбы; 4 - Выход." << endl;
                        std::cin >> chARMOREq;
                        if (chARMOREq == 1)
                        {
                            std::cout << "Вы взяли в руки топор" << endl;
                            HP += 5;
                            ATK += 5;
                            std::cout << "Сейчас ваше HP : " << HP << endl;
                            std::cout << "Сейчас ваша ATK : " << ATK << endl;
                        }
                        else if (chARMOREq == 2)
                        {
                            std::cout << "Вы взяли в руки меч" << endl;
                            HP += 10;
                            ATK += 10;
                            std::cout << "Сейчас ваше HP : " << HP << endl;
                            std::cout << "Сейчас ваша ATK : " << ATK << endl;
                            std::cout << endl;
                        }
                        else if (chARMOREq == 3)
                        {
                            std::cout << "Вы взяли в руки лук для стрельбы" << endl;
                            HP += 15;
                            ATK += 15;
                            std::cout << "Сейчас ваше HP : " << HP << endl;
                            std::cout << "Сейчас ваша ATK : " << ATK << endl;
                        }
                        else if (chARMOREq == 4)
                        {
                            goto HOD;
                        }
                    }
                    if (EquipmentARMOR[i] == "<Пусто>")
                    {
                        std::cout << "У вас нет орудия" << endl;
                    }
                }
            }
            else if (chARENA == 2)
            {
                if (MP > 0)
                {
                    for (int i = 0; i < Runes.size(); i++) {   //проходимся по всей сумке в поиске рун 
                        if (Runes[i] != "<Пусто>")
                        {
                            std::cout << "Выберите название руны, чтобы овладеть магией" << endl;
                            std::cout << "1 - Магия огня; 2 - Магия воды; 3 - Магия земли; 4 - Магия воздуха; 5 - Магия тьмы; 6 - Выход." << endl;
                            std::cin >> chARMORRun;
                            if (chARMORRun == 1)
                            {
                                std::cout << "Вы овладели магией огня" << endl;
                                ATK += 5;
                                MP -= 5;
                                std::cout << "Сейчас ваша ATK : " << ATK << endl;
                                std::cout << "Сейчас ваша MP : " << MP << endl;
                                mHP -= 3;
                            }
                            else if (chARMORRun == 2)
                            {
                                std::cout << "Вы овладели магией воды" << endl;
                                ATK += 5;
                                MP -= 5;
                                std::cout << "Сейчас ваша ATK : " << ATK << endl;
                                std::cout << "Сейчас ваша MP : " << MP << endl;
                                mHP -= 4;
                            }
                            else if (chARMORRun == 3)
                            {
                                std::cout << "Вы овладели магией земли" << endl;
                                ATK += 5;
                                MP -= 5;
                                std::cout << "Сейчас ваша ATK : " << ATK << endl;
                                std::cout << "Сейчас ваша MP : " << MP << endl;
                                mHP -= 5;
                            }
                            else if (chARMORRun == 4)
                            {
                                std::cout << "Вы овладели магией воздуха" << endl;
                                ATK += 5;
                                MP -= 5;
                                std::cout << "Сейчас ваша ATK : " << ATK << endl;
                                std::cout << "Сейчас ваша MP : " << MP << endl;
                                mHP -= 6;
                            }
                            else if (chARMORRun == 5)
                            {
                                std::cout << "Вы овладели магией тьмы" << endl;
                                ATK += 20;
                                MP -= 20;
                                std::cout << "Сейчас ваша ATK : " << ATK << endl;
                                std::cout << "Сейчас ваша MP : " << MP << endl;
                                mHP -= 10;
                            }
                            else if (chARMOREq == 6)
                            {
                                goto HOD;
                            }
                        }
                        else
                        {
                            std::cout << "У вас нет рун" << endl;
                        }

                    }
                }
                else
                {
                    std::cout << "У вас не осталось MP " << endl;
                    goto HOD;
                }
            }
            break;
        default:
            goto HOD;
            break;
        }
        std::cout << "Ваш ход совершен!";
        if (mHP <= 0)
        {
            std::cout << "ВЫ ОДОЛЕЛИ СОПЕРНИКА!" << monster.name << endl;
            std::cout << "Вы продолжаете идти... " << endl;
            EXP += 5;
            Sleep(3000);
            system("cls");
            HP = hHP;//сохранение здоровья после боя
            EXP += 10;
            return;
        }
        else
        {
            std::cout << "Противник атакует!!!";
            hHP -= monster.ATK;
            for (int i = 0; i < creatures.size(); i++) {
                if (creatures[i] != "")
                {
                    Merc.mercHP -= monster.ATK;
                }
            }
            if (hHP <= 0)
            {
                death();//метод окончания игры
            }

            for (int i = 0; i < creatures.size(); i++) {
                if (creatures[i] == "Человечек")
                {
                    if (Merc.mercHP <= 0)
                    {
                        std::cout << "НАЁМНИК МЁРТВ" << endl;
                        auto deathMERC = creatures.cbegin();
                        /*creatures.erase(deathMERC + "Человечек");*/
                    }
                }
            }
        }

        for (int i = 0; i < creatures.size(); i++) {
            if (creatures[i] == "Гоблин")
            {
                if (Merc.mercHP <= 0)
                {
                    std::cout << "НАЁМНИК МЁРТВ" << endl;
                    auto deathMERC = creatures.cbegin();
                    /*creatures.erase(deathMERC + "Гоблин");*/
                }
            }
        }
    }

    /*else
    {
    std::cout << "БИТВА ПРОДОЛЖАЕТСЯ!" << endl;
    std::cout << "ВАШЕ ЗДОРОВЬЕ: " << hHP << endl;

    for (int i = 0; i < creatures.size(); i++) {
        if (creatures[i] != "")
        {
            std::cout << "ЗДОРОВЬЕ НАЁМНИКА: " << Merc.mercHP << endl;
        }
    }

    std::cout << "ЗДОРОВЬЕ СОПЕРНИКА: " << mHP << endl;
    }*/
}
void Advent(int CH)
{
    player character(CH);
    int che = 0;
ways:
    std::cout << "Выберите 1 из 3 путей или же откройте инвентарь: " << endl;
    std::cout << "1)Направо\n";
    std::cout << "2)Вперед\n";
    std::cout << "3)Налево\n";
    std::cout << "4)Открыть инвентарь\n";
    std::cout << "Ваши хп " << HP << endl;
    int a;
    std::cin >> a;
    if (a <= 0 || a > 4)
    {
        goto ways;
    }
    else if (a == 4)
    {
        ALLinventory();
        goto ways;
    }
    {
        srand(time(0));
        int bossapp = 0;
        int dungroom = 0;
        int battle = 0;
        int mHP = 0;
        int hHP = 0;
        int i = 0;
        int dungDif = rand() % 2 + 1;//рандом сложности данжа
        int dung = rand() % 3 + 1;//рандом типа безопасной зоны(лагерь, магазин, пещера)
        battle = rand() % 2 + 1; //рандом безопасности и опасности зоны

        while (battle != 2)
        {
            if (dung == 0 || dung == 1)
            {
                std::cout << "Здесь безопасно, можно отдохнуть.(ВАШЕ ЗДОРОВЬЕ БЫЛО ВОСТАНОВЛЕНО)" << endl;
                if (CH == 1)
                {
                    HP = 18;//восстановление здоровья войну
                }
                if (CH == 2)
                {
                    HP = 10;//восстановление здоровья магу
                }
                if (CH == 3)
                {
                    HP = 15;//восстановление здоровья стрелку
                }
            }
            else if (dung == 2)//встреча торговца
            {
                std::cout << "Вы встретили заблудшего торговца" << endl;
                std::cout << "Он готов вам продать то, что у него есть..." << endl;
                shop();
                goto ways;//временный переход
            }
            else if (dung == 3)//нахождение данжа
            {
                std::cout << "Перед вами вход в данж уровня " << dungDif << endl;
                switch (dungDif)//подбор количество комнат в зависимости от сложности данжа
                {
                case 1:
                    dungroom = 5;
                    break;
                case 2:
                    dungroom = 10;
                    break;
                case 3:
                    dungroom = 20;
                    break;
                default:
                    dungroom = 5;
                    break;


                }
                std::cout << "Войдете ли вы в нее?" << endl;
                std::cout << "[1]Да                         [2]Нет" << endl;
            dungch:
                int dungCH = 0;
                std::cin >> dungCH;//пойти в данж или нет
                switch (dungCH)
                {
                case 1:
                    std::cout << "Вы медленно погружаетесь в тени пещеры и углубляетесь под землю..." << endl;
                    Sleep(3000);
                    system("cls");
                    std::cout << "Вы вошли в данж! Приготовьтесь к битве!" << endl;

                    while (i < dungroom)
                    {

                        battler(CH, hHP);
                        i += 1;
                    }

                    std::cout << "Вы прошли данж!" << endl;
                    goto ways;
                    break;

                case 2:
                    std::cout << "Вы решаете не идти бездумно в темную пещеру и продолжаете свое приключение...";
                    goto ways;
                    break;
                default:
                    goto dungch;
                    break;
                }

            }

            goto ways;

        }

        battler(CH, HP);
        goto ways;
    }
}
int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(0));

    beasters MOSTA[10];
    party BRAT[10];
    int choice;
    srand(time(0));

nam:
    std::cout << "Введите имя: ";
    getline(cin, name);
    if (name.find(' ') != std::string::npos)
    {
        cin.sync();
        std::cout << "Введите имя без пробела" << endl;
        goto nam;
    }
    else if (name.empty())
    {
        cin.sync();
        goto nam;
    }

    std::cout << "Выберите класс персонажу. \n[1] Воин [2] Маг [3] Стрелок : ";
    std::cin >> choice;

    while (!std::cin >> choice || choice > 3 || choice < 1) {
        std::cout << "Неподходящее значение. \nВыберите класс персонажу. \n[1] Воин [2] Маг [3] Стрелок : ";
        std::cin >> choice;
    }

    std::cout << "\n Приветствую, " << name << ".Начнем же твое приключение!" << endl;
    player character(choice);
    character.togo();
    std::cin.ignore();
    std::cin.get();
    //начало приключения
    std::cout << "Вы очутились в темном лесу. Вокруг только кромешная тьма. Лишь 4 пути, ведущие в никуда." << endl;
    std::cout << "Вы хотите испытать судьбу? Хотите попытаться выбраться из сердца тьмы?" << endl;
    std::cin.ignore();
    std::cin.get();
    system("cls");
    std::cout << "..." << endl;
    Sleep(3000);
beg:
    system("cls");
    std::cout << "...или же вы оставите надежду и станете частью леса...?" << endl;
    std::cout << "[1]остаться                               [2] отправиться";
    int theend;
    std::cin >> theend;
    if (theend == 2)
    {
        std::cout << "Несмотря на все вы продолжаете стремиться к свету...";
        Sleep(2000);
        system("cls");
        Advent(choice);
    }
    else if (theend == 1)
    {
        system("cls");
        std::cout << "Оставив надежду выложитесь обратно, где и очутились и закрываете глаза в ожидании долгой и мучительной смерти...";
        Sleep(5000);
        system("cls");
        death();
    }
    else
    {
        goto beg;
    }
}

