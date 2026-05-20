#include "Monster.h"

// =====================
// Item
// =====================
void Item::PrintInfo() const
{
    cout << name << " (" << price << "G)\n";
}

// =====================
// PotionRecipe
// =====================
void PotionRecipe::ShowRecipe() const
{
    cout << "-> " << potionName << " (";

    for (int i = 0; i < ingredients.size(); i++)
    {
        cout << ingredients[i];

        if (i < ingredients.size() - 1)
        {
            cout << ", ";
        }
    }

    cout << ")\n";
}

// =====================
// AlchemyWorkshop
// =====================
AlchemyWorkshop::AlchemyWorkshop()
{
    PotionRecipe hpPotion;
    hpPotion.potionName = "HP포션";
    hpPotion.ingredients.push_back("허브 x1");
    hpPotion.ingredients.push_back("맑은물 x1");

    PotionRecipe mpPotion;
    mpPotion.potionName = "MP포션";
    mpPotion.ingredients.push_back("마나풀 x1");
    mpPotion.ingredients.push_back("맑은물 x1");

    PotionRecipe staminaPotion;
    staminaPotion.potionName = "스태미나포션";
    staminaPotion.ingredients.push_back("허브 x1");
    staminaPotion.ingredients.push_back("베리 x1");

    recipes.push_back(hpPotion);
    recipes.push_back(mpPotion);
    recipes.push_back(staminaPotion);
}

void AlchemyWorkshop::ShowAllRecipes()
{
    cout << "\n=== 전체 레시피 보기 ===\n";

    for (const PotionRecipe& recipe : recipes)
    {
        recipe.ShowRecipe();
    }
}

void AlchemyWorkshop::SearchByName(string name)
{
    bool isFound = false;

    for (const PotionRecipe& recipe : recipes)
    {
        if (recipe.potionName == name)
        {
            recipe.ShowRecipe();
            isFound = true;
        }
    }

    if (!isFound)
    {
        cout << "찾을 수 없습니다.\n";
    }
}

void AlchemyWorkshop::SearchByIngredient(string ingredient)
{
    int count = 0;

    for (const PotionRecipe& recipe : recipes)
    {
        for (const string& item : recipe.ingredients)
        {
            if (item.find(ingredient) != string::npos)
            {
                recipe.ShowRecipe();
                count++;
                break;
            }
        }
    }

    if (count == 0)
    {
        cout << "찾을 수 없습니다.\n";
    }
    else
    {
        cout << "총 " << count << "개의 레시피를 찾았습니다.\n";
    }
}

void AlchemyWorkshop::OpenWorkshop()
{
    int choice;

    while (true)
    {
        cout << "\n=== 포션 제작소 ===\n";
        cout << "1. 전체 레시피 보기\n";
        cout << "2. 포션 이름으로 검색\n";
        cout << "3. 재료로 검색\n";
        cout << "0. 돌아가기\n";

        cout << "\n선택: ";
        cin >> choice;

        if (choice == 1)
        {
            ShowAllRecipes();
        }
        else if (choice == 2)
        {
            string name;

            cout << "검색할 포션 이름: ";
            cin >> name;

            SearchByName(name);
        }
        else if (choice == 3)
        {
            string ingredient;

            cout << "검색할 재료: ";
            cin >> ingredient;

            SearchByIngredient(ingredient);
        }
        else if (choice == 0)
        {
            break;
        }
        else
        {
            cout << "잘못된 입력입니다.\n";
        }
    }
}

// =====================
// 기본 함수
// =====================
void printStatus(string name, int stat[])
{
    cout << "\n============================\n";
    cout << name << " 의 현재 능력치\n";
    cout << "============================\n";

    cout << "HP: " << stat[0]
        << "   MP: " << stat[1] << endl;

    cout << "공격력: " << stat[2]
        << "   방어력: " << stat[3] << endl;

    cout << "============================\n";
}

void upgradeMenu(string name, int stat[])
{
    int hpPotion = 5;
    int mpPotion = 5;

    bool isGameStart = false;

    cout << "\n* HP 포션 5개, MP 포션 5개가 기본 지급되었습니다.\n";

    while (!isGameStart)
    {
        int choice;

        cout << "\n================================\n";
        cout << "< 캐릭터 강화 >\n";
        cout << "1. HP UP    2. MP UP    3. 공격력 2배\n";
        cout << "4. 방어력 2배    5. 현재 능력치    0. 게임 시작\n";
        cout << "================================\n";

        cout << "보조를 선택해주세요: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            if (hpPotion > 0)
            {
                stat[0] += 20;
                hpPotion--;
                cout << "* HP가 20 증가했습니다. (HP 포션 잔량: " << hpPotion << "개)\n";
            }
            else
            {
                cout << "HP 포션이 부족합니다.\n";
            }
            break;

        case 2:
            if (mpPotion > 0)
            {
                stat[1] += 20;
                mpPotion--;
                cout << "* MP가 20 증가했습니다. (MP 포션 잔량: " << mpPotion << "개)\n";
            }
            else
            {
                cout << "MP 포션이 부족합니다.\n";
            }
            break;

        case 3:
            stat[2] *= 2;
            cout << "* 공격력이 2배 증가했습니다.\n";
            break;

        case 4:
            stat[3] *= 2;
            cout << "* 방어력이 2배 증가했습니다.\n";
            break;

        case 5:
            printStatus(name, stat);
            break;

        case 0:
            cout << "게임을 시작합니다!\n";
            isGameStart = true;
            break;

        default:
            cout << "잘못된 입력입니다.\n";
            break;
        }
    }
}

// =====================
// Player
// =====================
Player::Player(string name, string job, int hp, int mp, int power, int defence)
{
    this->name = name;
    this->job = job;
    this->level = 1;
    this->hp = hp;
    this->mp = mp;
    this->power = power;
    this->defence = defence;
}

string Player::getName()
{
    return name;
}

string Player::getJob()
{
    return job;
}

int Player::getHP()
{
    return hp;
}

int Player::getPower()
{
    return power;
}

int Player::getDefence()
{
    return defence;
}

void Player::setHP(int newHP)
{
    hp = newHP;
}

void Player::printPlayerStatus()
{
    cout << "\n--------------------------------\n";
    cout << "닉네임: " << name
        << " | 직업: " << job
        << " | Lv." << level << endl;

    cout << "HP: " << hp
        << " | MP: " << mp
        << " | 공격력: " << power
        << " | 방어력: " << defence << endl;

    cout << "--------------------------------\n";
}

// =====================
// 직업 클래스
// =====================
Warrior::Warrior(string name, int hp, int mp, int power, int defence)
    : Player(name, "전사", hp, mp, power, defence)
{
    this->hp += 30;
}

void Warrior::attack()
{
    cout << "* 검으로 공격합니다!\n";
}

Magician::Magician(string name, int hp, int mp, int power, int defence)
    : Player(name, "마법사", hp, mp, power, defence)
{
    this->mp += 30;
}

void Magician::attack()
{
    cout << "* 파이어볼을 발사합니다!\n";
}

Thief::Thief(string name, int hp, int mp, int power, int defence)
    : Player(name, "도적", hp, mp, power, defence)
{
    this->power += 30;
}

void Thief::attack()
{
    cout << "* 단검으로 빠르게 공격합니다!\n";
}

Archer::Archer(string name, int hp, int mp, int power, int defence)
    : Player(name, "궁수", hp, mp, power, defence)
{
    this->defence += 30;
}

void Archer::attack()
{
    cout << "* 화살을 발사합니다!\n";
}

// =====================
// Monster
// =====================
Monster::Monster(string name, int hp, int power, int defence,
    string dropItemName, int dropItemPrice)
{
    this->name = name;
    this->hp = hp;
    this->power = power;
    this->defence = defence;
    this->dropItemName = dropItemName;
    this->dropItemPrice = dropItemPrice;
}

string Monster::getName()
{
    return name;
}

int Monster::getHP()
{
    return hp;
}

int Monster::getPower()
{
    return power;
}

int Monster::getDefence()
{
    return defence;
}

string Monster::getDropItemName()
{
    return dropItemName;
}

int Monster::getDropItemPrice()
{
    return dropItemPrice;
}

void Monster::setHP(int newHP)
{
    hp = newHP;
}

void Monster::attack(Player* player)
{
    cout << "* " << name << "이 공격합니다!\n";

    int damage = power - player->getDefence();

    if (damage < 1)
    {
        damage = 1;
    }

    int beforeHP = player->getHP();
    player->setHP(beforeHP - damage);

    cout << player->getName() << "에게 " << damage << " 데미지!\n";
    cout << player->getName() << " HP: " << beforeHP << " -> " << player->getHP() << endl;
}

// =====================
// 전투 함수
// =====================
void battle(Player* player, Monster& monster, vector<Item>& inventory)
{
    cout << "\n[ 전투 시작! ] "
        << player->getName() << "(" << player->getJob() << ")"
        << " vs " << monster.getName() << "\n";

    while (player->getHP() > 0 && monster.getHP() > 0)
    {
        cout << "\n--- 플레이어 턴 ---\n";

        player->attack();

        int damage = player->getPower() - monster.getDefence();

        if (damage < 1)
        {
            damage = 1;
        }

        int beforeMonsterHP = monster.getHP();
        monster.setHP(beforeMonsterHP - damage);

        cout << monster.getName() << "에게 " << damage << " 데미지!\n";
        cout << monster.getName() << " HP: "
            << beforeMonsterHP << " -> " << monster.getHP();

        if (monster.getHP() <= 0)
        {
            cout << " (사망)";
        }

        cout << endl;

        if (monster.getHP() <= 0)
        {
            break;
        }

        cout << "\n--- 몬스터 턴 ---\n";

        monster.attack(player);
    }

    if (player->getHP() > 0)
    {
        Item droppedItem;
        droppedItem.name = monster.getDropItemName();
        droppedItem.price = monster.getDropItemPrice();

        inventory.push_back(droppedItem);

        cout << "\n★ 전투 승리!\n";
        cout << "-> " << droppedItem.name << " 획득!\n";
        cout << "-> 인벤토리에 저장되었습니다.\n";
    }
    else
    {
        cout << "\n전투 패배...\n";
    }
}

// =====================
// 메인 메뉴
// =====================
void mainMenu(Player* player, vector<Item>& inventory)
{
    AlchemyWorkshop workshop;

    int choice;
    int dungeonCount = 0;

    while (true)
    {
        cout << "\n=== 메인 메뉴 ===\n";
        cout << "1. 던전 입장\n";
        cout << "2. 인벤토리 확인\n";
        cout << "3. 포션 제작소\n";
        cout << "0. 게임 종료\n";

        cout << "\n선택: ";
        cin >> choice;

        if (choice == 1)
        {
            dungeonCount++;

            if (dungeonCount % 2 == 1)
            {
                Monster slime(
                    "슬라임",
                    10,
                    20,
                    10,
                    "슬라임의 끈적한 젤리",
                    30
                );

                battle(player, slime, inventory);
            }
            else
            {
                Monster goblin(
                    "고블린",
                    30,
                    25,
                    5,
                    "고블린의 단검",
                    50
                );

                battle(player, goblin, inventory);
            }

            if (player->getHP() <= 0)
            {
                cout << "\n플레이어가 쓰러져 게임을 종료합니다.\n";
                break;
            }
        }
        else if (choice == 2)
        {
            cout << "\n[ 인벤토리 (" << inventory.size() << "/10) ]\n";

            if (inventory.empty())
            {
                cout << "인벤토리가 비어있습니다.\n";
            }
            else
            {
                int index = 1;

                for (const Item& item : inventory)
                {
                    cout << index << ". ";
                    item.PrintInfo();
                    index++;
                }
            }
        }
        else if (choice == 3)
        {
            workshop.OpenWorkshop();
        }
        else if (choice == 0)
        {
            cout << "\n게임 종료!\n";
            break;
        }
        else
        {
            cout << "\n잘못된 입력입니다.\n";
        }
    }
}
