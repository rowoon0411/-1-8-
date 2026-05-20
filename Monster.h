#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void printStatus(string name, int stat[]);
void upgradeMenu(string name, int stat[]);

struct Item
{
    string name;
    int price;

    void PrintInfo() const;
};

struct PotionRecipe
{
    string potionName;
    vector<string> ingredients;

    void ShowRecipe() const;
};

class AlchemyWorkshop
{
private:
    vector<PotionRecipe> recipes;

public:
    AlchemyWorkshop();

    void ShowAllRecipes();
    void SearchByName(string name);
    void SearchByIngredient(string ingredient);
    void OpenWorkshop();
};

class Player
{
protected:
    string name;
    string job;

    int level;
    int hp;
    int mp;
    int power;
    int defence;

public:
    Player(string name, string job, int hp, int mp, int power, int defence);

    string getName();
    string getJob();

    int getHP();
    int getPower();
    int getDefence();

    void setHP(int newHP);

    void printPlayerStatus();

    virtual void attack() = 0;

    virtual ~Player() {}
};

class Warrior : public Player
{
public:
    Warrior(string name, int hp, int mp, int power, int defence);
    void attack() override;
};

class Magician : public Player
{
public:
    Magician(string name, int hp, int mp, int power, int defence);
    void attack() override;
};

class Thief : public Player
{
public:
    Thief(string name, int hp, int mp, int power, int defence);
    void attack() override;
};

class Archer : public Player
{
public:
    Archer(string name, int hp, int mp, int power, int defence);
    void attack() override;
};

class Monster
{
private:
    string name;
    int hp;
    int power;
    int defence;

    string dropItemName;
    int dropItemPrice;

public:
    Monster(string name, int hp, int power, int defence,
        string dropItemName, int dropItemPrice);

    string getName();
    int getHP();
    int getPower();
    int getDefence();

    string getDropItemName();
    int getDropItemPrice();

    void setHP(int newHP);

    void attack(Player* player);
};

void battle(Player* player, Monster& monster, vector<Item>& inventory);
void mainMenu(Player* player, vector<Item>& inventory);
