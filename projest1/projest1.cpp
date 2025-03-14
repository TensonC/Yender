
#include <iostream>
#include <stdio.h>
#include "BearLibTerminal.h"
#include "system.h"
#include "projest1.h"

using namespace std;




#undef main



Player player{
"Hero",
5,15,0x40,
HEALTHY,
FLAMEWAND,
HEALTHY,
HEALTHY,
HEALTHY,
HEALTHY,
HEALTHY,
HEALTHY,
1.7
};//角色的初始化

int nowstorey = 0;//现在所在层数，数字越大层数越深
bool gameloop = true;
vector<string> weaponpage = 
{ "flame wand", "ice wand", "rifle" };
map <int, int>healthystatus = 
{ {HEALTHY,0xFF00FFFF},{DEAD,0xFF000000},{INJURED,0xFF330066},{DESTORY,0xFFFF0000},{BLOOD,0xFFFFFF00} };
map <int, string>weapon_onhand = 
{ {FLAMEWAND,"flame wand"},{ICEWAND,"ice wand"},{RIFLE,"rifle"}};
vector<Player> monsterList;
int Title_Y[][3] = {
    {5, 7, 0x2551},{9, 8, 0x255D},{7, 9, 0x256C},{6, 8, 0x2557},{5, 6, 0x2566},{8, 9, 0x255D},{7, 10, 0x2569},{9, 7, 0x2551},
    {6, 9, 0x255A},{8, 8, 0x2554},{5, 8, 0x255A},{9, 6, 0x2566}
};
int Title_E[][3] = {
    {12, 8, 0x2560},{14, 6, 0x2550},{15, 10, 0x255D},{13, 8, 0x2550},{12, 7, 0x2551},{14, 8, 0x2550},{12, 9, 0x2551},{15, 6, 0x2557},
    {13, 10, 0x2550},{12, 6, 0x2554},{12, 10, 0x255A},{15, 8, 0x2563},{13, 6, 0x2550},{14, 10, 0x2550}
};
int Title_N[][3] = {
    {23, 6, 0x2566},{19, 7, 0x2551},{21, 7, 0x2557},{23, 7, 0x2551},{20, 7, 0x255A},{19, 8, 0x2551},{21, 8, 0x2551},{23, 8, 0x2551},
    {19, 9, 0x2551},{21, 9, 0x255A},{22, 9, 0x2557},{23, 9, 0x2551},{19, 10, 0x2569},{22, 10, 0x255A},{23, 10, 0x255D},{19, 6, 0x2554},{20, 6, 0x2557}
};
int Title_D[][3] = {
    {28, 6, 0x2550},{30, 7, 0x255A},{27, 8, 0x2551},{31, 7, 0x2557},{27, 7, 0x2551},{29, 6, 0x2550},{31, 8, 0x2551},{30, 6, 0x2557},
    {27, 9, 0x2551},{30, 9, 0x2554},{27, 10, 0x255A},{28, 10, 0x2550},{29, 10, 0x2550},{31, 9, 0x255D},{27, 6, 0x2554},{30, 10, 0x255D}
};
int Title_O[][3] = {
    {36, 6, 0x2550},{38, 7, 0x2551},{34, 8, 0x2560},{35, 6, 0x2550},{37, 6, 0x2550},{34, 7, 0x2551},{38, 8, 0x2563},{34, 9, 0x2551},
    {38, 9, 0x2551},{35, 10, 0x2550},{36, 10, 0x2550},{37, 10, 0x2550}
};
int Title_R[][3] = {
    {43, 6, 0x2550},{45, 7, 0x2551},{41, 8, 0x2551},{42, 6, 0x2550},{44, 6, 0x2557},{41, 7, 0x2551},{45, 8, 0x2551},{41, 9, 0x2551},
    {43, 9, 0x2550},{44, 9, 0x256C},{45, 9, 0x255D},{41, 10, 0x2551},{44, 10, 0x255A},{45, 10, 0x2557},{41, 6, 0x2554},{42, 9, 0x2550}
};


void PlayerRender()
{
    terminal_layer(OBJECT);
    terminal_color(healthystatus[player.health]);
    terminal_clear_area(player.x - 1, player.y - 1, 3, 3);
    terminal_put(player.x, player.y, player.img);
    terminal_refresh();
}


void Init()
{
    terminal_open();
    terminal_set("window:title='Projest',size=50*30;input:mouse-cursor=true,filter=[keyboard,mouse]");
    terminal_composition(TK_ON);
    //Title();
    terminal_layer(2);
    terminal_color(healthystatus[player.health]);
    terminal_put(player.x, player.y, player.img);
    terminal_layer(MAP);
    terminal_color(0xFFFFFFFF);
    terminal_put(5, 16, 0x2191);
    terminal_print(4,17,"You");
    terminal_put(20,17,0x003E);
    terminal_printf(22,17,"Start");
    terminal_printf(20,27,"Press[color = red] W[/color] to choose weapon");
    terminal_printf(20, 28, "Press[color = red] S[/color] to view your status");
    terminal_refresh();
}


void Title()
{
    terminal_layer(MAP);
    terminal_color(0xFF00FF00);
    for (int i = 0;i < 12;i++)
    {
        terminal_put(Title_Y[i][0],Title_Y[i][1],Title_Y[i][2]);
        terminal_refresh();
        terminal_delay(TIME);
    }
    for (int i = 0;i < 14;i++)
    {
        terminal_put(Title_E[i][0], Title_E[i][1], Title_E[i][2]);
        terminal_refresh();
        terminal_delay(TIME);
    }
    for (int i = 0;i < 17;i++)
    {
        terminal_put(Title_N[i][0], Title_N[i][1], Title_N[i][2]);
        terminal_refresh();
        terminal_delay(TIME);
    }
    for (int i = 0;i < 16;i++)
    {
        terminal_put(Title_D[i][0], Title_D[i][1], Title_D[i][2]);
        terminal_refresh();
        terminal_delay(TIME);
    }
    for (int i = 0;i < 12;i++)
    {
        terminal_put(Title_O[i][0], Title_O[i][1], Title_O[i][2]);
        terminal_refresh();
        terminal_delay(TIME);
    }
    for (int i = 0;i < 16;i++)
    {
        terminal_put(Title_R[i][0], Title_R[i][1], Title_R[i][2]);
        terminal_refresh();
        terminal_delay(TIME);
    }
   
}




int main()
{
    Init();
 
    while (gameloop)
    {
        if (terminal_has_input)
        {
            Input();
        }
        
        ActiveRender();
        
        EventCallBack(MapCheck());//地图事件的检测
    }
    terminal_close();
    
}
