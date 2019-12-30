/////////////////////////////////////////////////////////////////////////////////
//
//
//
//
/////////////////////////////////////////////////////////////////////////////////
#ifndef _LESSON_X_H_
#define _LESSON_X_H_
#define maxsize 300
//
#include <Windows.h>
#include <iostream>
#include <vector>
#include <list>
using namespace std;
/////////////////////////////////////////////////////////////////////////////////
//
// 游戏总管类。负责处理游戏主循环、游戏初始化、结束等工作
class	CGameMain
{
private:
	int				m_iGameState;				// 游戏状态，0：结束或者等待开始；1：初始化；2：游戏进行中
	//游戏Start精灵
	CSprite* StartAnimation;
	CTextSprite* StartText1;
	CTextSprite* StartText2;
	//重开精灵
	CSprite* LostAnimation;
	CTextSprite* LostText1;
	CTextSprite* LostText2;
	//游戏主角色
	CAnimateSprite* Leader;
	//敌人角色
	CAnimateSprite* Enemy[15];
	//发射动画
	CAnimateSprite* Bullet;
	//背景
	CSprite* background;
	CSprite* backgroundimg;
	//草地
	CSprite* ground[50];
	//旗子
	CSprite* Victory;
	//能量与能量球
	float energy;
	CSprite* m_energy[15];
	//音乐控制图标
	CSprite* icon1;
	CSprite* icon2;
	CSprite* icon3;
	CSprite* icon4;
	//鼠标形状
	CSprite* mouse1;
	CSprite* mouse2;
	//关卡
	int GameNum;
	CTextSprite* gamenumtext1;
	CTextSprite* gamenumtext2;
	CTextSprite* energynumtext1;
	CTextSprite* energynumtext2;
	//鱼Boss
	CSprite* fishboss;
	//鱼兵
	list<CSprite*> smallfishlist;
	CSprite* smallfish[2000];
	//关于我们
	CSprite* aboutusimg;
	//开始游戏
	CSprite* buttons[10];
	//关卡选择
	CSprite* gamenumbackground;
	CSprite* gamenumselect[15];
	//胜利界面
	CSprite* victoryimg;
	//死亡精灵
	CAnimateSprite* dead;
	//Boss血量显示
	CTextSprite* bosshptext;
	CTextSprite* bosshpnum;
	//主角色系列控制变量
	float lSpeedLeft,lSpeedRight,lSpeedTop,lSpeedBottom;
	float centerX,centerY,OldPosX,OldPosY,lNowPosX,lNowPosY;
	int judgejump;
	int stop;
	//跳跃时间 二次跳跃
	float itime;
	int isjump;
	//方向
	int Direction;
	//游戏结束判断
	int GameOver;
public:
	CGameMain();            //构造函数
	~CGameMain();           //析构函数  

	// Get方法
	int				GetGameState()											{ return m_iGameState; }
	
	// Set方法
	void			SetGameState( const int iState )				{ m_iGameState	=	iState; }
	
	// 游戏主循环等
	void			GameMainLoop( float	fDeltaTime );
	void			GameInit();
	void			GameRun( float fDeltaTime );
	void			GameEnd();
	void 			OnMouseMove( const float fMouseX, const float fMouseY );
	void 			OnMouseClick( const int iMouseType, const float fMouseX, const float fMouseY );
	void 			OnMouseUp( const int iMouseType, const float fMouseX, const float fMouseY );
	void 			OnKeyDown( const int iKey, const bool bAltPress, const bool bShiftPress, const bool bCtrlPress );
	void 			OnKeyUp( const int iKey );
	void 			OnSpriteColSprite( const char *szSrcName, const char *szTarName );
	void 			OnSpriteColWorldLimit( const char *szName, const int iColSide );
	//Start精灵显示，消失
	void StartDisplay_None();
	void StartDisplay_Show();
	//Restart精灵显示，消失
	void RestartDisplay_None();
	void RestartDisplay_Show();
	//控制角色移动
	void Running();
	//主窗口移动
	void ScreenMove();
	//判断是否可以跳跃
	int JudgeJump();
	//是否可以发射子弹
	int JudgeBullet();
	//加载地图
	void LoadingMap();
	//删除地图
	void DeleteMap();
	//产生敌人
	void MakeEnemy();
	//敌人动向
	void MoveEnemy();
	//攻击敌人
	void AttackEnemy();
	//本局通过
	void GameVictory();
	//疾跑
	void FastRun();
	//技能
	void Shoot();
	//跳跃
	void Jump();
	//控制攻击音效
	void ControlAttackMusic();
	//控制背景音乐
	void ControlBackgroundMusic();
	//加载开始界面
	void ShowStartface();
	//删除开始界面
	void DeleteStartface();
	//加载关卡选择
	void ShowGamenumSelect();
	//删除关卡选择
	void DeleteGamenumSelect();
	//加载游戏
	void LoadingGame();
	//加载游戏中菜单
	void Loadingmenu();
	//删除游戏中菜单
	void Deletemenu();
	//加载关于我们
	void ShowAboutUs();
	//删除关于我们
	void DeleteAboutUs();
	//Boss移动
	void MoveBoss();
	//怪物暂停
	void EnemyPause();
	//怪物开始
	void EnemyStart();
	//生成鱼怪
	void MakeSmallFish();
	//删除鱼怪
	void DeleteSmallFish();
	//鱼怪追踪
	void SmallFishChase();
	//加载胜利界面
	void ShowVictory();
	//删除加载界面
	void DeleteVictory();
};

/////////////////////////////////////////////////////////////////////////////////
// 
extern CGameMain	g_GameMain;

#endif // _LESSON_X_H_