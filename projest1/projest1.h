#pragma once
#include <iostream>
#include <vector>
#include <map>

//层数//layer1=地图，layer2=人物,layer3=框，layer4=武器
#define MAP 1
#define OBJECT 2
#define BOX 3
#define WEAPON 4
#define MOUSE 5
#define SELECT 6
//武器
#define FLAMEWAND 0
#define ICEWAND 1
#define RIFLE 2
//健康状态
#define HEALTHY 4
#define BLOOD 3
#define INJURED 2
#define DESTORY 1
#define DEAD 0
#define TIME 40//动画刷新帧率
#define SPEED 100//速度
#define W_WIDTH 50
#define W_HEIGHT 30

using namespace std;
void Init();//初始化
void Title();//标题动画
void PlayerRender();



typedef struct
{
    string name;
    int x;
    int y;
    int img;//图像
    int health;//健康程度
    int Weapon;
    int head_health;
    int body_health;
    int leftarm_health;
    int rightarm_health;
    int leftleg_health;
    int rightleg_health;
    int height;//身高

}Player;

extern Player player;
extern vector<string> weaponpage;
extern vector<Player> monsterList;
extern map <int, int>healthystatus;
extern map <int, string>weapon_onhand;
extern bool gameloop;
extern int nowstorey;
