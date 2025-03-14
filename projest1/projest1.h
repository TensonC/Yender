#pragma once
#include <iostream>
#include <vector>
#include <map>

//����//layer1=��ͼ��layer2=����,layer3=��layer4=����
#define MAP 1
#define OBJECT 2
#define BOX 3
#define WEAPON 4
#define MOUSE 5
#define SELECT 6
//����
#define FLAMEWAND 0
#define ICEWAND 1
#define RIFLE 2
//����״̬
#define HEALTHY 4
#define BLOOD 3
#define INJURED 2
#define DESTORY 1
#define DEAD 0
#define TIME 40//����ˢ��֡��
#define SPEED 100//�ٶ�
#define W_WIDTH 50
#define W_HEIGHT 30

using namespace std;
void Init();//��ʼ��
void Title();//���⶯��
void PlayerRender();



typedef struct
{
    string name;
    int x;
    int y;
    int img;//ͼ��
    int health;//�����̶�
    int Weapon;
    int head_health;
    int body_health;
    int leftarm_health;
    int rightarm_health;
    int leftleg_health;
    int rightleg_health;
    int height;//���

}Player;

extern Player player;
extern vector<string> weaponpage;
extern vector<Player> monsterList;
extern map <int, int>healthystatus;
extern map <int, string>weapon_onhand;
extern bool gameloop;
extern int nowstorey;
