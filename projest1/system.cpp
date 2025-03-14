#include "BearLibTerminal.h"
#include "system.h"
#include "projest1.h"
#include <stdio.h>
#include <vector>
#include <cstdlib>


bool WeaponBox_open = false;
bool StatusBox_open = false;
int lpx = player.x;//角色的上一个位置
int lpy = player.y;


void StatusBox()
{
    StatusBox_open = true;
    MakeBox(25, 10, 20, 10, 0xFFFFFFFF);
    terminal_color(healthystatus[player.head_health]);
    terminal_printf(27, 12, "head");
    terminal_color(healthystatus[player.body_health]);
    terminal_printf(27, 13, "body");
    terminal_color(healthystatus[player.leftarm_health]);
    terminal_printf(27, 14, "leftarm");
    terminal_color(healthystatus[player.rightarm_health]);
    terminal_printf(27, 15, "rightarm");
    terminal_color(healthystatus[player.leftleg_health]);
    terminal_printf(27, 16, "leftleg");
    terminal_color(healthystatus[player.rightleg_health]);
    terminal_printf(27, 17, "rightleg");
    terminal_color(0xFFFFFFFF);
    terminal_printf(27, 18, "weapon:%s", weapon_onhand[player.Weapon].c_str());
    terminal_refresh();
    while (true)
    {
        int key = terminal_read();
        if (key == TK_ESCAPE)
        {
            StatusBox_open = false;
            terminal_clear_area(0, 0, W_WIDTH, W_HEIGHT);
            terminal_refresh();
            break;
        }
    }


}

void MakeBox(int x, int y, int width, int height, int color)
{
    terminal_layer(BOX);
    terminal_color(color);
    terminal_put(x, y, 0x2554);
    terminal_put(x + width, y, 0x2557);
    terminal_put(x, y + height, 0x255A);
    terminal_put(x + width, y + height, 0x255D);
    for (int i = x + 1;i < x + width;i++)
        for (int j = y + 1;j < y + height;j++)
        {
            terminal_put(i, y, 0x2550);
            terminal_put(i, y + height, 0x2550);
            terminal_put(x, j, 0x2551);
            terminal_put(x + width, j, 0x2551);
        }
    terminal_refresh();
}

void WeaponBox()
{
    int current_index = 0;
    WeaponBox_open = true;
    MakeBox(25, 10, 20, weaponpage.size() + 3, 0xFFFFFFFF);
    while (true)
    {
        for (int i = 0;i < weaponpage.size();i++)
        {
            bool select = i == current_index;
            terminal_color(select ? color_from_name("orange") : 0xFFFFFFFF);
            terminal_printf(27, 12 + i, "%s", weaponpage[i].c_str());
        }
        terminal_refresh();
        int key = terminal_read();
        if (key == TK_ESCAPE)
        {
            terminal_clear_area(25, 10, 30, weaponpage.size() + 5);
            WeaponBox_open = false;
            terminal_refresh();
            break;
        }
        else if (key == TK_UP && current_index > 0)
        {
            current_index--;
        }
        else if (key == TK_DOWN && current_index < weaponpage.size() - 1)
        {
            current_index++;
        }
        else if (key == TK_ENTER)
        {
            player.Weapon = current_index;
            terminal_clear_area(0, 0, W_WIDTH, W_HEIGHT);
            WeaponBox_open = false;
            terminal_refresh();
            break;
        }
    }

}

void Input()
{   
    int key = terminal_read();
    switch (key)
    {
    case TK_UP:lpy = player.y;player.y--;break;
    case TK_DOWN:lpy = player.y;player.y++;break;
    case TK_RIGHT:lpx = player.x;player.x++;break;
    case TK_LEFT:lpx = player.x;player.x--;break;
    case TK_W:WeaponBox();break;
    case TK_S:StatusBox();break;
    case TK_M:MonsterBuild();break;
    case TK_CLOSE:gameloop = false;break;
    default:break;
    }
    
}




void ActiveRender()
{
    PlayerRender();
    
}

int MapCheck()
{
    terminal_layer(MAP);
    int code = terminal_pick(player.x,player.y);
    //printf("%d\n",code);
    return code;
}

void EventCallBack(int code)
{
    switch (code)
    {
    case 62:StairDown();break;//">"代表下一层
    case 35:BorderCheck();break;//碰到边界（墙）检测
    default:break;
    }
}

void StairDown()
{
    terminal_layer(MAP);
    terminal_clear_area(0,0,W_WIDTH,W_HEIGHT);
    terminal_refresh();
    nowstorey++;
    MapBuild();
    terminal_refresh();
}

void MapBuild()
{
    //在写了在写了
}

void BorderCheck()
{
    player.x = lpx;
    player.y = lpy;
    PlayerRender();
}


void MonsterBuild()
{
    srand(time(0));
    int x = 1 + rand() % 40;
    int y = 1 + rand() % 20;
    Player monster;
    monster.name = "goblin";
    monster.x = x;
    monster.y = y;
    monster.health = HEALTHY;
    monster.body_health = HEALTHY;
    monster.head_health = HEALTHY;
    monster.rightarm_health = HEALTHY;
    monster.leftarm_health = HEALTHY;
    monster.rightleg_health = HEALTHY;
    monster.leftleg_health = HEALTHY;
    monster.img = 0x0067;
    monsterList.push_back(monster);
    terminal_color(0xFF6600CC);
    terminal_put(monster.x, monster.y, monster.img);
    terminal_refresh();
}
