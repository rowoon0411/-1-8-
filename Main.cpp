#include "Monster.h"

int main()
{
    string name;

    const int SIZE = 4;
    int stat[SIZE] = { 0 };

    vector<Item> inventory;

    cout << "================================\n";
    cout << "     [ 던전 탈출 텍스트 RPG ]\n";
    cout << "================================\n";

    cout << "\n용사의 이름을 입력해주세요: ";
    cin >> name;

    while (true)
    {
        cout << "\nHP와 MP를 입력해주세요: ";
        cin >> stat[0] >> stat[1];

        if (stat[0] >= 50 && stat[1] >= 50)
        {
            break;
        }

        cout << "HP나 MP의 값이 너무 작습니다. 다시 입력해주세요.\n";
    }

    while (true)
    {
        cout << "공격력과 방어력을 입력해주세요: ";
        cin >> stat[2] >> stat[3];

        if (stat[2] > 0 && stat[3] > 0)
        {
            break;
        }

        cout << "공격력이나 방어력이 너무 작습니다. 다시 입력해주세요.\n";
    }

    printStatus(name, stat);

    upgradeMenu(name, stat);

    Player* player = nullptr;

    int jobChoice;

    cout << "\n< 직업 시스템 >\n";
    cout << name << ", 직업을 선택해주세요!\n";
    cout << "1. 전사   2. 마법사   3. 도적   4. 궁수\n";
    cout << "선택: ";
    cin >> jobChoice;

    if (jobChoice == 1)
    {
        player = new Warrior(name, stat[0], stat[1], stat[2], stat[3]);
        cout << "* 전사로 전직하였습니다. (HP +30)\n";
    }
    else if (jobChoice == 2)
    {
        player = new Magician(name, stat[0], stat[1], stat[2], stat[3]);
        cout << "* 마법사로 전직하였습니다. (MP +30)\n";
    }
    else if (jobChoice == 3)
    {
        player = new Thief(name, stat[0], stat[1], stat[2], stat[3]);
        cout << "* 도적으로 전직하였습니다. (공격력 +30)\n";
    }
    else if (jobChoice == 4)
    {
        player = new Archer(name, stat[0], stat[1], stat[2], stat[3]);
        cout << "* 궁수로 전직하였습니다. (방어력 +30)\n";
    }
    else
    {
        cout << "잘못된 선택입니다. 기본 직업 전사로 전직합니다.\n";
        player = new Warrior(name, stat[0], stat[1], stat[2], stat[3]);
    }

    player->attack();
    player->printPlayerStatus();

    mainMenu(player, inventory);

    delete player;

    return 0;
}
