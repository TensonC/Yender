#pragma once
void StatusBox();//状态栏
void Input();
void WeaponBox();//武器栏
void MakeBox(int x, int y, int width, int hight, int color);
void ActiveRender();//全局渲染
int MapCheck();//地图中事件检测
void EventCallBack(int code);//接触类事件响应
void StairDown();//下楼梯
void MapBuild();//地图创建
void BorderCheck();//撞墙检测
void MonsterBuild();
