/////////////////////////////////////////////////////////////////////////////////
//
//
//
//
/////////////////////////////////////////////////////////////////////////////////
#include <Stdio.h>
#include "CommonClass.h"
#include "LessonX.h"
#include <string>
#include <iostream>
#include <string.h>
#include <algorithm>
#pragma comment(lib,"winmm.lib")
#include "mmsystem.h"
#include "windows.h"
using namespace std;
////////////////////////////////////////////////////////////////////////////////
//
//
CGameMain		g_GameMain;	
//怪物方向
int enemydir=0;
//音乐控制
int backgroundmusiccontrol;
int attackmusiccontrol;
//加载游戏
int isloadinggame;
//鼠标判断
int mousejudge=0;
//游戏音乐循环
float musictime=0;
//runtime
int runtime=0;
//backmenu的状态
int backmenustate=0;
//esc次数
int esctime=0;
//暂停
int ispause=0;
//第三关游戏时间
float time_3f=0;
int time_3i=0;
//鱼怪类型
int fishstate=0;
//Boss血量
int bosshp=10;
struct MyStruct
{
	int mapType[30];//草地类型
	float map[30][2];//草地坐标
	float EnemyMap[5][3];//怪物坐标
	float absoluteEnemyMap[15];//原始怪物X轴坐标
	float Victory[2];// 旗子坐标
	int EnergyBallType[15];//能量球类型
	float EnergyBallMap[15][2];//能量球坐标
	int xml[3];//数量:0.草地 1.怪物 2.能量球
}mygame[15]=
{
  {//第一关
	{/*草地类型*/0,1,2,3,1,2,3,2,3,1},
	{/*草地坐标*/{0.0f,0.0f},{-15.0f,33.7f},{36.0f,30.0f},{61.0f,26.5f},{115.0f,33.7f},{166.0f,30.0f},{191.0f,26.5f},{216.0f,30.0f},{241.0f,26.5f},{292.0f,33.7f}},
	{/*怪物坐标*/{0.0f,0.0f,0.0f},{15.0f,25.5f,1.0f},{145.0f,25.5f,4.0f}},
	{/*原始怪物X轴坐标*/},
	{/*旗子坐标*/290.0f,27.0f},
	{/*能量球类型*/1,2},
	{/*能量球坐标*/{0.0f,28.0f},{10.0f,28.0f}},
	{/*数量*/9,2,2}
  },
  {//第二关
    {/*草地类型*/0,1,4,4,4,4,4,4,4,5,4,4,4,4,5,4,4,4},
	{/*草地坐标*/
		{0.0f,0.0f},{-0.0f,33.7f},{28.0f,19.0f},{-0.0f,18.0f},{25.0f,1.0f},{-25.0f,1.0f},{1.0f,-10.0f},{35.0f,-17.0f},
		{-19.0f,-45.0f},{-22.0f,-28.0f},{10.0f,-55.0f},{30.0f,-65.0f},{10.0f,-80.0f},{-19.0f,-80.0f},{10.0f,-110.0f},
		{-45.0f,-90.0f},{30.0f,-128.0f},{0.0f,-138.0f}
	},
	{/*怪物坐标*/{0.0f,0.0f,0.0f},{10.0f,-38.0f},{40.0f,-117.0f}},
	{/*原始怪物X轴坐标*/},
	{/*旗子坐标*/-2.0f,-145.0f},
	{/*能量球类型*/1,2,2},
	{/*能量球坐标*/{-25.0f,-2.0f},{1.0f,-14.0f},{-45.0f,-94.0f}},
	{/*数量*/18,2,3}
  },
  {//第三关
	{/*草地类型*/},
	{/*草地坐标*/},
	{/*怪物坐标*/},
	{/*原始怪物X轴坐标*/},
	{/*旗子坐标*/-100.0f,-100.0f},
	{/*能量球类型*/},
	{/*能量球坐标*/},
	{/*数量*/0,0,0}
  }
};
struct fishstruct
{
	int n;//数量
	int pos[15][2];//坐标
}fishpos[10]=
{
  {//类型一
	/*数量*/5,
	/*坐标*/{{55.0f,-30.0f},{55.0f,-15.0f},{55.0f,0.0f},{55.0f,15.0f},{55.0f,30.0f}}
  },
  {//类型二
    /*数量*/5,
	/*坐标*/{{75.0f,-30.0f},{65.0f,-15.0f},{55.0f,0.0f},{65.0f,15.0f},{75.0f,30.0f}}
  },
  {//类型三
    /*数量*/6,
	/*坐标*/{{55.0f,-30.0f},{55.0f,-20.0f},{55.0f,-10.0f},{55.0f,10.0f},{55.0f,20.0f},{55.0f,30.0f}}
  },
  {//类型四
    /*数量*/9,
	/*坐标*/{{55.0f,-20.0f},{55.0f,0.0f},{55.0f,20.0f},{65.0f,-20.0f},{65.0f,0.0f},{65.0f,20.0f},{75.0f,-20.0f},{75.0f,0.0f},{75.0f,20.0f}}
  },
  {//类型五
    /*数量*/
	/*坐标*/
  },
};
//==============================================================================
//
// 大体的程序流程为：GameMainLoop函数为主循环函数，在引擎每帧刷新屏幕图像之后，都会被调用一次。

//==============================================================================
//
// 构造函数
CGameMain::CGameMain()
{
	m_iGameState			=	0;
	GameNum = 0;
	backgroundmusiccontrol = 0 ;
	attackmusiccontrol = 0;
	energy=0.0f;
	//构造Start类型精灵
	StartAnimation=new CSprite("StartAnimation");
	StartText1=new CTextSprite("StartText1");
	StartText2=new CTextSprite("StartText2");
	//重开
	LostAnimation=new CSprite("LostAnimation");
	LostText1=new CTextSprite("LostText1");
	LostText2=new CTextSprite("LostText2");
	//构造主角色
	Leader=new CAnimateSprite("leader");
	//构造显示
	gamenumtext1=new CTextSprite("gamenumtext1");
	gamenumtext2=new CTextSprite("gamenumtext2");
	energynumtext1=new CTextSprite("energytext1");
	energynumtext2=new CTextSprite("energytext2");
	//构造音乐图标
	icon1=new CSprite("icon1");
	icon2=new CSprite("icon2");
	icon3=new CSprite("icon3");
	icon4=new CSprite("icon4");
	//构造背景
	backgroundimg=new CSprite("backgroundimg");
	//构造鼠标
	mouse1=new CSprite("mouse1");
	mouse2=new CSprite("mouse2");
	//构造关卡选择
	gamenumbackground=new CSprite("gamenumbackground");
	gamenumselect[1]=new CSprite("gamenum1");
	gamenumselect[2]=new CSprite("gamenum2");
	gamenumselect[3]=new CSprite("gamenum3");
	//构造开始界面
	buttons[0]=new CSprite("aboutus");
	buttons[1]=new CSprite("button1");
	buttons[2]=new CSprite("button2");
	buttons[3]=new CSprite("button3");
	buttons[4]=new CSprite("button4");
	aboutusimg=new CSprite("aboutusimg");
	//构造鱼Boss
	fishboss=new CSprite("fishboss");
	//构造鱼兵
	list<CSprite*>::iterator i_fish;
	//构造胜利界面
	CSprite* victoryimg=new CSprite("vimg");
	//构造死亡精灵
	dead=new CAnimateSprite("ddead");
	//构造Boss血量显示
	bosshptext=new CTextSprite("bht");
	bosshpnum=new CTextSprite("bhn");
}
//==============================================================================
//
// 析构函数
CGameMain::~CGameMain()
{
}
//==============================================================================
//
// 游戏主循环，此函数将被不停的调用，引擎每刷新一次屏幕，此函数即被调用一次
// 用以处理游戏的开始、进行中、结束等各种状态. 
// 函数参数fDeltaTime : 上次调用本函数到此次调用本函数的时间间隔，单位：秒
void CGameMain::GameMainLoop( float	fDeltaTime )
{
	switch( GetGameState() )
	{
		// 初始化游戏，清空上一局相关数据
	case 0:
		{
		GameInit();
		break;
		}
	case 1:
		{
			LoadingGame();
			SetGameState(2); // 初始化之后，将游戏状态设置为进行中
		}
		break;

		// 游戏进行中，处理各种游戏逻辑
	case 2:
		{
			// TODO 修改此处游戏循环条件，完成正确游戏逻辑
			if( true && GameOver==0)  //游戏是否结束
			{
				GameRun( fDeltaTime );
			}
			else // 游戏结束。调用游戏结算函数，并把游戏状态修改为结束状态
			{				
				SetGameState(0);
				GameEnd();
			}
		}
		break;
		// 游戏结束/等待按空格键开始
	};
}
//=============================================================================
//
// 每局开始前进行初始化，清空上一局相关数据
void CGameMain::GameInit()
{
	if(runtime==0)
		{
		ShowStartface();
		runtime=1;
		}
}
//=============================================================================
//
// 每局游戏进行中
void CGameMain::GameRun( float fDeltaTime )
{
	centerX=Leader->GetSpritePositionX();
	centerY=Leader->GetSpritePositionY();
	//是否坠落
	int temp=JudgeJump();
	if(temp==1)
		judgejump=1;
	else 
	{
		if(GameNum==0)
			Leader->SetSpriteLinearVelocityY(25);
		else if(GameNum==1)
			Leader->SetSpriteLinearVelocityY(10);
	}
	//主窗口移动
	ScreenMove();
	MoveEnemy();
	//更新位置
	OldPosX=centerX;
	OldPosY=centerY;

	//跳跃实现
	stop=0;
	if(itime>0&&stop==0)
	{
		itime-=3*fDeltaTime;
		//速度随itime改变
		if(GameNum==0)
			lSpeedTop=8-80*itime;
		else if(GameNum==1)
			lSpeedTop=2-20*itime;
		Running();
	}
	//音乐循环
	musictime+=fDeltaTime;
	if(musictime>72.0f)
		{
		mciSendString("close game//data//audio//backgroundmusic.wav",NULL,0,NULL);
		mciSendString("play game//data//audio//backgroundmusic.wav",NULL,0,NULL);
		musictime=0;
		}
	if(GameNum==2)
		{
		MoveBoss();
		time_3f+=fDeltaTime;
		time_3i=time_3f;
		if(time_3i%5==0)
			{
			DeleteSmallFish();
			MakeSmallFish();
			}
		}
	if(ispause==1)
		EnemyPause();
}
//=============================================================================
//
// 本局游戏结束
void CGameMain::GameEnd()
{
	DeleteMap();
	SetGameState(0);
	RestartDisplay_Show();
	isloadinggame=1;
}
//本局游戏通过
void CGameMain::GameVictory()
{
	if(GameNum==2)
		{
		DeleteMap();
		}
	else
		{
		DeleteMap();
		GameNum++;
		}
}
//==========================================================================
//
// 鼠标移动
// 参数 fMouseX, fMouseY：为鼠标当前坐标
void CGameMain::OnMouseMove( const float fMouseX, const float fMouseY )
{
	mouse1->SetSpritePosition(fMouseX,fMouseY);
	mouse2->SetSpritePosition(fMouseX,fMouseY);
	mousejudge=0;
	for(int i=1;i<=3;i++)
		{
		if(gamenumselect[i]->IsPointInSprite(fMouseX,fMouseY))
			{
			mousejudge=1;
			}
		}
	for(int i=0;i<5;i++)
		{
		if(buttons[i]->IsPointInSprite(fMouseX,fMouseY))
			{
			mousejudge=1;
			}
		}
	if(mousejudge!=0)
		{
		mouse1->SetSpriteVisible(false);
		mouse2->SetSpriteVisible(true);
		}
	else
		{
		mouse2->SetSpriteVisible(false);
		mouse1->SetSpriteVisible(true);
		}
}
//==========================================================================
//
// 鼠标点击
// 参数 iMouseType：鼠标按键值，见 enum MouseTypes 定义
// 参数 fMouseX, fMouseY：为鼠标当前坐标
void CGameMain::OnMouseClick( const int iMouseType, const float fMouseX, const float fMouseY )
{
	for(int i=1;i<=3;i++)
		{
		if(gamenumselect[i]->IsPointInSprite(fMouseX,fMouseY))
			{
			DeleteGamenumSelect();
			isloadinggame=1;
			GameNum=i-1;
			StartDisplay_Show();
			}
		}
	for(int i=0;i<5;i++)
		{
		if(buttons[i]->IsPointInSprite(fMouseX,fMouseY))
			{
			switch(i)
				{
				case 0:
					DeleteStartface();
					ShowAboutUs();
					break;
				case 1:
					DeleteStartface();
					ShowGamenumSelect();
					break;
				case 2:
					if(backmenustate==1)
						{
						DeleteGamenumSelect();
						ShowStartface();
						mouse1->SetSpriteVisible(true);
						}
					if(backmenustate==2)
						{
						DeleteAboutUs();
						ShowStartface();
						}
					if(backmenustate==3)
						{
						DeleteMap();
						Deletemenu();
						SetGameState(0);
						ShowStartface();
						}
					if(backmenustate==4)
						{
						DeleteVictory();
						ShowStartface();
						}
					break;
				case 3:
					Deletemenu();
					break;
				case 4:
					exit(0);
					break;
				case 5:
					Deletemenu();
					DeleteMap();
					Leader->DeleteSprite();
					runtime=0;
					CSystem::CursorOn();
					SetGameState(0);
					break;
				}
			break;
			}
		}
}
//==========================================================================
//
// 鼠标弹起
// 参数 iMouseType：鼠标按键值，见 enum MouseTypes 定义
// 参数 fMouseX, fMouseY：为鼠标当前坐标
void CGameMain::OnMouseUp( const int iMouseType, const float fMouseX, const float fMouseY )
{
	
}
//==========================================================================
//
// 键盘按下
// 参数 iKey：被按下的键，值见 enum KeyCodes 宏定义
// 参数 iAltPress, iShiftPress，iCtrlPress：键盘上的功能键Alt，Ctrl，Shift当前是否也处于按下状态(0未按下，1按下)
void CGameMain::OnKeyDown( const int iKey, const bool bAltPress, const bool bShiftPress, const bool bCtrlPress )
{	
	if(m_iGameState==0&&iKey==KEY_SPACE&&isloadinggame==1)
	{
		StartDisplay_None();
		GameOver=0;  
		m_iGameState=1;
		isloadinggame=0;
	}
	else if(m_iGameState==2)
	{
		switch (iKey)
		{
		case KEY_A: 
			if(GameNum==0)
				lSpeedLeft=-10.f;
			else if(GameNum==1)
				lSpeedLeft=-30.f;
			else if(GameNum==2)
				lSpeedLeft=-40.f;
			Direction=0;
			break;
		case KEY_D:
			if(GameNum==0)
				lSpeedRight=10.f;
			else if(GameNum==1)
				lSpeedRight=30.f;
			else if(GameNum==2)
				lSpeedRight=40.f;
			Direction=1;
			break;
		case KEY_S:
			if(GameNum==2)
				lSpeedBottom=40.0f;
			else
				lSpeedBottom=15.f;
			break;
		case KEY_P:
			backgroundmusiccontrol=backgroundmusiccontrol==1?0:1;
			ControlBackgroundMusic();
			break;
		case KEY_O:
			attackmusiccontrol=attackmusiccontrol==1?0:1;
			ControlAttackMusic();
			break;
		case KEY_ESCAPE:
			if(esctime==0)
				{
				esctime=1;
				Loadingmenu();
				}
			else
				{
				esctime=0;
				Deletemenu();
				}
			break;
		}
		//跳跃  速度函数为  lSpeedTop=20-20*itime
		if(iKey==KEY_W)
			{
			if(GameNum==2)
				lSpeedTop=-40.0f;
			else
				Jump();
			}
		Running();
		//疾跑
		if(iKey==KEY_L)
			if(GameNum!=2)
				FastRun();
		//子弹
		if(iKey==KEY_J&&JudgeBullet()==1)
			Shoot();
		//近距离攻击
		if(iKey==KEY_K)
			if(GameNum!=2)
				AttackEnemy();
	}
}
//==========================================================================
//
// 键盘弹起
// 参数 iKey：弹起的键，值见 enum KeyCodes 宏定义
void CGameMain::OnKeyUp( const int iKey )
{
	switch (iKey)
		{
		case KEY_A:
			lSpeedLeft=0.f;
			break;
		case KEY_D:
			lSpeedRight=0.f;
			break;
		case KEY_S:
			lSpeedBottom=0.f;
			break;
		case KEY_W:
			if(GameNum==2)
				lSpeedTop=0;
			break;
		}
	if(m_iGameState==2)
	{
		//奔跑完成播放原动画
		if(iKey==KEY_L)
		{
			Leader->AnimateSpritePlayAnimation("bossAnimation",true);
		}
		Running();
	}

}
//===========================================================================
//
// 精灵与精灵碰撞
// 参数 szSrcName：发起碰撞的精灵名字
// 参数 szTarName：被碰撞的精灵名字
void CGameMain::OnSpriteColSprite( const char *szSrcName, const char *szTarName )
{
	if(m_iGameState==2)
	{
		//人物有关碰撞
		if(strcmp(szSrcName,Leader->GetName())==0)
		{
			//人物与草地碰撞
			for(int i=1;i<=mygame[GameNum].xml[0];i++)
			{
				if(strcmp(szTarName,ground[i]->GetName())==0)
				{
					lSpeedTop=0;
					lSpeedBottom=0;
					stop=1;
					Leader->AnimateSpritePlayAnimation("bossAnimation",false);
					Running();
				}
			}
			//人物与敌人碰撞
			for(int i=1;i<=mygame[GameNum].xml[1];i++)
			{
				if(strcmp(szTarName,Enemy[i]->GetName())==0)
				{
					GameOver=1;
				}
			}
			//人物与旗子碰撞
			if(strcmp(szTarName,Victory->GetName())==0)
			{
				//胜利后代码
				GameVictory();
				LoadingGame();
			}
			//人物与能量球碰撞
			for(int i=0;i<mygame[GameNum].xml[2];i++)
				{
				if(strcmp(szTarName,m_energy[i]->GetName())==0)
					{
					energy+=mygame[GameNum].EnergyBallType[i];
					energynumtext2->SetTextValue(energy);
					m_energy[i]->DeleteSprite();
					}
				}
			//人物与鱼碰撞
			if(GameNum==2)
				{
				for(int i=0;i<fishpos[fishstate].n;i++)
					{
					if(strcmp(szTarName,smallfish[i]->GetName())==0)
						{
						smallfish[i]->DeleteSprite();
						GameOver=1;
						}
					}
				if(strcmp(szTarName,fishboss->GetName())==0)
					GameOver=1;
				}
		}
		//子弹碰到地面消失
		if(strcmp(szSrcName,Bullet->GetName())==0)
			{
			for(int i=1;i<=mygame[GameNum].xml[0];i++)
				{
				if(strcmp(szTarName,ground[i]->GetName())==0)
					{
					Bullet->SetSpriteLinearVelocityX(0);
					Bullet->SetSpriteVisible(false);
					Bullet->SetSpritePosition(50,60);
					}
				}
			}
		//子弹解决敌人
		if(strcmp(szSrcName,Bullet->GetName())==0)
			{
			for(int i=1;i<=mygame[GameNum].xml[1];i++)
				{
				if(strcmp(szTarName,Enemy[i]->GetName())==0)
					{
					if(attackmusiccontrol==0)
						{
						mciSendString("play game//data//audio//hit.wav",NULL,0,NULL);
						mciSendString("close game//data//audio//skill.wav",NULL,0,NULL);
						}
					Bullet->SetSpriteLinearVelocityX(0);
					Bullet->SetSpriteVisible(false);
					Bullet->SetSpritePosition(50,60);
					Enemy[i]->DeleteSprite();
					}
				}
			if(GameNum==2)
				{
				if(strcmp(szTarName,fishboss->GetName())==0)
					{
					bosshp--;
					bosshpnum->SetTextValue(bosshp);
					Bullet->SetSpriteLinearVelocityX(0);
					Bullet->SetSpriteVisible(false);
					Bullet->SetSpritePosition(50,60);
					if(bosshp==0)
						{
						SetGameState(0);
						DeleteMap();
						ShowVictory();
						}
					}
				for(int i=0;i<fishpos[fishstate].n;i++)
					{
					if(strcmp(szTarName,smallfish[i]->GetName())==0)
						{
						if(attackmusiccontrol==0)
							{
							mciSendString("play game//data//audio//hit.wav",NULL,0,NULL);
							mciSendString("close game//data//audio//skill.wav",NULL,0,NULL);
							}
						Bullet->SetSpriteLinearVelocityX(0);
						Bullet->SetSpriteVisible(false);
						Bullet->SetSpritePosition(-100.0f,100.0f);
						smallfish[i]->DeleteSprite();
						}
					}
				}
			}
	}
}
//===========================================================================
//
// 精灵与世界边界碰撞
// 参数 szName：碰撞到边界的精灵名字
// 参数 iColSide：碰撞到的边界 0 左边，1 右边，2 上边，3 下边
void CGameMain::OnSpriteColWorldLimit( const char *szName, const int iColSide )
{
	//触碰下边界死亡  其他则停止
	if(strcmp(szName,Leader->GetName())==0)
	{
		if(GameNum==2)
			{
			switch (iColSide)
				{
				case 0:
					Leader->SetSpritePositionX(-46.0f);
					break;
				case 1:
					Leader->SetSpritePositionX(46.0f);
					break;
				case 2:
					Leader->SetSpritePositionY(-34.0f);
					break;
				case 3:
					Leader->SetSpritePositionY(33.0f);
					break;
				}
			}
		else
			{
			if(iColSide==3)
				GameOver=1;
			else
				Leader->SetSpriteLinearVelocity(0,0);
			}
	}
	//子弹出界
	if(strcmp(szName,Bullet->GetName()))
	{
		if(iColSide==0||iColSide==1)
		{
			Bullet->SetSpriteLinearVelocityX(0);
			Bullet->SetSpriteVisible(false);
			Bullet->SetSpritePosition(50,60);
		}
	}
}
//Start精灵消失
void CGameMain::StartDisplay_None()
{
	backgroundimg->DeleteSprite();
	StartAnimation->SetSpriteVisible(false);
	StartText1->SetSpriteVisible(false);
	StartText2->SetSpriteVisible(false);
}
//start精灵出现
void CGameMain::StartDisplay_Show()
{
	backgroundimg=new CSprite(CSystem::MakeSpriteName("bgimg",0));
	backgroundimg->CloneSprite("backgroundimg");
	backgroundimg->SetSpritePosition(0,0);
	StartAnimation->SetSpritePosition(-25.0f,-12.5f);
	StartAnimation->SetSpriteVisible(true);
	StartText1->SetSpritePosition(-5.0f,20.0f);
	StartText1->SetSpriteVisible(true);
	StartText2->SetSpritePosition(20.0f,-15.0f);
	StartText2->SetSpriteVisible(true);
}
//Restart精灵消失
void CGameMain::RestartDisplay_None()
{
	dead->DeleteSprite();
	backgroundimg->DeleteSprite();
	LostAnimation->SetSpriteVisible(false);
	LostText1->SetSpriteVisible(false);
	LostText2->SetSpriteVisible(false);
}
//Restart精灵出现
void CGameMain::RestartDisplay_Show()
{
	dead->CloneSprite("dead");
	dead->SetSpritePosition(centerX,centerY);
	dead->SpriteMoveTo(centerX,-50,30,false);
	backgroundimg->CloneSprite("backgroundimg");
	backgroundimg->SetSpritePosition(0.0f,0.0f);
	LostAnimation->SetSpritePosition(-25.0,-12.5);
	LostText1->SetSpritePosition(12.0,-15.0);
	LostText2->SetSpritePosition(0.0,20.0);
	LostAnimation->SetSpriteVisible(true);
	LostText1->SetSpriteVisible(true);
	LostText2->SetSpriteVisible(true);
}
//键盘控制主角色移动
void CGameMain::Running()
{
	//判断是否需要转向
	if((lSpeedLeft+lSpeedRight)<0)
	{
		if(GameNum==2)
			Leader->SetSpriteFlipX(false);
		else
			Leader->SetSpriteFlipX(true);
	}else if((lSpeedLeft+lSpeedRight)>0)
	{
		if(GameNum==2)
			Leader->SetSpriteFlipX(true);
		else
			Leader->SetSpriteFlipX(false);;
	}
	//合成速度
	Leader->SetSpriteLinearVelocity(lSpeedLeft+lSpeedRight,lSpeedTop+lSpeedBottom);
}
//窗口移动  
void CGameMain::ScreenMove()
{
	//以Leader的位置为基准线  记录之前的位置，所有精灵与Leader移动方向相反间接实现场景移动
	//移动除主角色外的所有精灵
	switch (GameNum+1)
	{
	case 1:
		background->SetSpritePosition(background->GetSpritePositionX()-(centerX-OldPosX)*3.5f,background->GetSpritePositionY());
		for(int i=1;i<=mygame[GameNum].xml[0];i++)
		{
			ground[i]->SetSpritePosition(ground[i]->GetSpritePositionX()-(centerX-OldPosX)*3.5f,ground[i]->GetSpritePositionY());
		}
		for(int i=1;i<=mygame[GameNum].xml[1];i++)
		{
			Enemy[i]->SetSpritePosition(Enemy[i]->GetSpritePositionX()-(centerX-OldPosX)*3.5f,Enemy[i]->GetSpritePositionY());
			mygame[GameNum].absoluteEnemyMap[i]=ground[1]->GetSpritePositionX()+mygame[GameNum].EnemyMap[i][0]-mygame[GameNum].map[1][0];
		}
		for(int i=0;i<mygame[GameNum].xml[2];i++)
		{
			m_energy[i]->SetSpritePosition(m_energy[i]->GetSpritePositionX()-(centerX-OldPosX)*3.5f,m_energy[i]->GetSpritePositionY());
		}
		Victory->SetSpritePosition(Victory->GetSpritePositionX()-(centerX-OldPosX)*3.5f,Victory->GetSpritePositionY());
		//如果本次移动到达地图边缘 则取消本次移动
		if(background->GetSpritePositionX()<-105||background->GetSpritePositionX()>175)
		{
			background->SetSpritePosition(background->GetSpritePositionX()+(centerX-OldPosX)*3.5f,background->GetSpritePositionY());
			for(int i=1;i<=mygame[GameNum].xml[0];i++)
			{
				ground[i]->SetSpritePosition(ground[i]->GetSpritePositionX()+(centerX-OldPosX)*3.5f,ground[i]->GetSpritePositionY());
			}
			for(int i=1;i<=mygame[GameNum].xml[1];i++)
			{
				Enemy[i]->SetSpritePosition(Enemy[i]->GetSpritePositionX()+(centerX-OldPosX)*3.5f,Enemy[i]->GetSpritePositionY());
			}
			for(int i=0;i<mygame[GameNum].xml[2];i++)
			{
			m_energy[i]->SetSpritePosition(m_energy[i]->GetSpritePositionX()+(centerX-OldPosX)*3.5f,m_energy[i]->GetSpritePositionY());
			}
			Victory->SetSpritePosition(Victory->GetSpritePositionX()+(centerX-OldPosX)*3.5f,Victory->GetSpritePositionY());
		}
		break;
	case 2:
		for(int i=1;i<=mygame[GameNum].xml[1];i++)
		{
			Enemy[i]->SetSpritePosition(Enemy[i]->GetSpritePositionX(),Enemy[i]->GetSpritePositionY()+(OldPosY-centerY)*3);
			mygame[GameNum].absoluteEnemyMap[i]=ground[1]->GetSpritePositionX()+mygame[GameNum].EnemyMap[i][0]-mygame[GameNum].map[1][0];
		}
		background->SetSpritePosition(background->GetSpritePositionX(),background->GetSpritePositionY()+(OldPosY-centerY)*3);
		for(int i=1;i<=mygame[GameNum].xml[0];i++)
		{
			ground[i]->SetSpritePosition(ground[i]->GetSpritePositionX(),ground[i]->GetSpritePositionY()+(OldPosY-centerY)*3);
		}
		for(int i=0;i<mygame[GameNum].xml[2];i++)
		{
			m_energy[i]->SetSpritePosition(m_energy[i]->GetSpritePositionX(),m_energy[i]->GetSpritePositionY()+(OldPosY-centerY)*3);
		}
		Victory->SetSpritePosition(Victory->GetSpritePositionX(),Victory->GetSpritePositionY()+(OldPosY-centerY)*3);
		Bullet->SetSpritePosition(Bullet->GetSpritePositionX(),Bullet->GetSpritePositionY()+(OldPosY-centerY)*3);
		if(background->GetSpritePositionY()<-135||background->GetSpritePositionY()>135)
		{
			for(int i=1;i<=mygame[GameNum].xml[1];i++)
			{
			Enemy[i]->SetSpritePosition(Enemy[i]->GetSpritePositionX(),Enemy[i]->GetSpritePositionY()-(OldPosY-centerY)*3);
			}
			background->SetSpritePosition(background->GetSpritePositionX(),background->GetSpritePositionY()-(OldPosY-centerY)*3);
			for(int i=1;i<=mygame[GameNum].xml[0];i++)
			{
				ground[i]->SetSpritePosition(ground[i]->GetSpritePositionX(),ground[i]->GetSpritePositionY()-(OldPosY-centerY)*3);
			}
			for(int i=0;i<mygame[GameNum].xml[2];i++)
			{
			m_energy[i]->SetSpritePosition(m_energy[i]->GetSpritePositionX(),m_energy[i]->GetSpritePositionY()-(OldPosY-centerY)*3);
			}
			Victory->SetSpritePosition(Victory->GetSpritePositionX(),Victory->GetSpritePositionY()-(OldPosY-centerY)*3);
			Bullet->SetSpritePosition(Bullet->GetSpritePositionX(),Bullet->GetSpritePositionY()-(OldPosY-centerY)*3);
		}
		break;
	}
	//动态数组测试

	/*for(int i=0;i<AllSprite.size();i++)
	{
		AllSprite[i]->SetSpritePosition(background->GetSpritePositionX()-(centerX-OldPosX)*2,background->GetSpritePositionY());
	}
	if(background->GetSpritePositionX()<-140||background->GetSpritePositionX()>140)
	{
		for(int i=0;i<AllSprite.size();i++)
	{
		AllSprite[i]->SetSpritePosition(background->GetSpritePositionX()+(centerX-OldPosX)*2,background->GetSpritePositionY());
	}
	}*/
}
//判断是否可以跳跃    脚下9个单位内有草地 即可跳跃
int CGameMain::JudgeJump()
{
	int temp=0;
	for(int i=1;i<=mygame[GameNum].xml[0];i++)
	{
		if(ground[i]->IsPointInSprite(centerX,centerY+7))
		{
			temp=1;
		}
	}
	return temp;
}
//判断是否可以发射子弹
int CGameMain::JudgeBullet()
{
	float bNowPosX=Bullet->GetSpritePositionX();
	int temp=0;
	if(bNowPosX>=45||bNowPosX<=-45)
		temp=1;
	return temp;
}
//加载地图
void CGameMain::LoadingMap()
{
	//背景
	if(GameNum==0)
	{
		background=new CSprite(CSystem::MakeSpriteName("bg",1));
		background->CloneSprite("background");
		background->SetSpritePosition(175,0);
	}
	else if(GameNum==1)
	{
		background=new CSprite(CSystem::MakeSpriteName("bg",2));
		background->CloneSprite("background2");
		background->SetSpritePosition(0.0,-135.0);
	}
	else if(GameNum==2)
	{
		background=new CSprite(CSystem::MakeSpriteName("bg",3));
		background->CloneSprite("background3");
		background->SetSpritePosition(0.0f,0.0f);
	}
	//草地
		for(int i=1;i<=mygame[GameNum].xml[0];i++)
			{
			ground[i]=new CSprite(CSystem::MakeSpriteName("gd",i));
			switch (mygame[GameNum].mapType[i])
				{
				case 1:
					ground[i]->CloneSprite("ground1");
					break;
				case 2:
					ground[i]->CloneSprite("ground2");
					break;
				case 3:
					ground[i]->CloneSprite("ground3");
					break; 		
				case 4:
					ground[i]->CloneSprite("cloud1");
					break;
				case 5:
					ground[i]->CloneSprite("cloud2");
					break;
				}
			ground[i]->SetSpriteCollisionActive(false,true); 
			ground[i]->SetSpritePosition(mygame[GameNum].map[i][0],mygame[GameNum].map[i][1]); 
			}
	//构造旗子
	Victory=new CSprite(CSystem::MakeSpriteName("v",GameNum));
	Victory->CloneSprite("victory");
	Victory->SetSpritePosition(mygame[GameNum].Victory[0],mygame[GameNum].Victory[1]);
	//构造技能
	Bullet=new CAnimateSprite("Bullet");
	//构造能量球
	for(int i=0;i<mygame[GameNum].xml[2];i++)
		{
		m_energy[i]=new CSprite(CSystem::MakeSpriteName("eb",i));
		if(mygame[GameNum].EnergyBallType[i]==1)
			m_energy[i]->CloneSprite("energyball1");
		if(mygame[GameNum].EnergyBallType[i]==2)
			m_energy[i]->CloneSprite("energyball2");
		m_energy[i]->SetSpriteCollisionActive(false,true);
		m_energy[i]->SetSpritePosition(mygame[GameNum].EnergyBallMap[i][0],mygame[GameNum].EnergyBallMap[i][1]);
		}
	//构造显示
	gamenumtext1->SetSpriteVisible(true);
	gamenumtext2->SetSpriteVisible(true);
	energynumtext1->SetSpriteVisible(true);
	energynumtext2->SetSpriteVisible(true);
	icon1->SetSpriteVisible(true);
	icon2->SetSpriteVisible(true);
	icon3->SetSpriteVisible(true);
	icon4->SetSpriteVisible(true);
	gamenumtext1->SetSpritePosition(-42.5f,-33.5f);
	gamenumtext2->SetSpritePosition(-32.5f,-33.5f);
	gamenumtext2->SetTextValue(GameNum+1);
	energynumtext1->SetSpritePosition(-20.5f,-33.5f);
	energynumtext2->SetSpritePosition(-10.5f,-33.5f);
	energynumtext2->SetTextValue(energy);
	//构造音乐图标
	icon1->SetSpriteVisible(true);
	icon1->SetSpritePosition(34.0f,-35.0f);
	icon2->SetSpriteVisible(false);
	icon2->SetSpritePosition(34.0f,-35.0f);
	icon3->SetSpriteVisible(true);
	icon3->SetSpritePosition(40.0f,-35.0f);
	icon4->SetSpriteVisible(false);
	icon4->SetSpritePosition(40.0f,-35.0f);
	if(GameNum==2)
		{
		//生成鱼boss
		fishboss=new CSprite(CSystem::MakeSpriteName("fb",0));
		fishboss->CloneSprite("fishboss");
		fishboss->SetSpritePosition(38.0f,0.0f);
		//生成小鱼怪
		MakeSmallFish();
		//Boss血量与显示
		bosshp=20;
		bosshptext->CloneSprite("bosshptext");
		bosshpnum->CloneSprite("bosshpnum");
		bosshptext->SpriteMountToSpriteLinkPoint(fishboss->GetName(),1);
		bosshpnum->SpriteMountToSpriteLinkPoint(fishboss->GetName(),2);
		bosshpnum->SetTextValue(bosshp);
		}
}
//删除地图
void CGameMain::DeleteMap()
{
	gamenumtext1->SetSpriteVisible(false);
	gamenumtext2->SetSpriteVisible(false);
	energynumtext1->SetSpriteVisible(false);
	energynumtext2->SetSpriteVisible(false);
	icon1->SetSpriteVisible(false);
	icon2->SetSpriteVisible(false);
	icon3->SetSpriteVisible(false);
	icon4->SetSpriteVisible(false);
	background->DeleteSprite();
	Leader->DeleteSprite();
	for(int i=1;i<=mygame[GameNum].xml[0];i++)
		{
		ground[i]->DeleteSprite();
		}
	for(int i=1;i<=mygame[GameNum].xml[1];i++)
		{
		Enemy[i]->DeleteSprite();
		}
	for(int i=0;i<mygame[GameNum].xml[2];i++)
		{
		m_energy[i]->DeleteSprite();
		}
	Victory->DeleteSprite();
	if(GameNum==2)
		{
		fishboss->DeleteSprite();
		for(int i=0;i<fishpos[fishstate].n;i++)
			{
			smallfish[i]->DeleteSprite();
			}
		bosshpnum->DeleteSprite();
		bosshptext->DeleteSprite();
		}
}
//产生敌人
void CGameMain::MakeEnemy()
{
	for(int i=1;i<=mygame[GameNum].xml[1];i++)
	{
		Enemy[i]=new CAnimateSprite(CSystem::MakeSpriteName("enemy",i));
		Enemy[i]->CloneSprite("enemy");
		Enemy[i]->SetSpriteCollisionActive(false,true);
		Enemy[i]->SetSpritePosition(mygame[GameNum].EnemyMap[i][0],mygame[GameNum].EnemyMap[i][1]);
	}
}
//敌人动向
void CGameMain::MoveEnemy()
{
	for(int i=1;i<=mygame[GameNum].xml[1];i++)
	{
		float nowposx=Enemy[i]->GetSpritePositionX();
		float nowposy=Enemy[i]->GetSpritePositionY();
		float oldposx=mygame[GameNum].absoluteEnemyMap[i];
		if(nowposx==oldposx)
		    {
			enemydir=0;
			Enemy[i]->SetSpriteFlipX(false);
		    }
		if(nowposx==oldposx-25)
			{
			enemydir=1;
			Enemy[i]->SetSpriteFlipX(true);
			}
		if(enemydir==0)
			Enemy[i]->SpriteMoveTo(oldposx-25,nowposy,20,true);
		if(enemydir==1)
			Enemy[i]->SpriteMoveTo(oldposx,nowposy,20,true);
	}
}
//攻击敌人
void CGameMain::AttackEnemy()
{
	if(attackmusiccontrol==0)
		mciSendString("play game//data//audio//hit_double.wav",NULL,0,NULL);
	float posx=Leader->GetSpritePositionX();
	float posy=Leader->GetSpritePositionY();
	float posx2=-7.0f*pow(-1,Direction);
	int isattack=0;//是否攻击到了敌人
	//按方向判断Leader前方7格内是否有敌人
	for(int i=1;i<=mygame[GameNum].xml[1];i++)
		{
		if(Enemy[i]->IsPointInSprite(posx+posx2,posy))
			{
			Enemy[i]->DeleteSprite();
			Leader->AnimateSpritePlayAnimation("KickingAnimation",true);
			isattack=1;
			}
		}
	//未攻击到播放动画
	if(isattack==0)
		{
		Leader->AnimateSpritePlayAnimation("KickingOneAnimation",true);
		}
}
//疾跑
void CGameMain::FastRun()
{
	lNowPosX=Leader->GetSpritePositionX();
	lNowPosY=Leader->GetSpritePositionY();
	Leader->AnimateSpritePlayAnimation("RunningAnimation",true);
	//方向
	if(GameNum==0)
	{
		if(Direction==1)
			Leader->SpriteMoveTo(lNowPosX+50,lNowPosY,35,true);
		else 
			Leader->SpriteMoveTo(lNowPosX-50,lNowPosY,35,true);
	}else 
	{
		if(Direction==1)
			Leader->SpriteMoveTo(lNowPosX+50,lNowPosY,60,true);
		else 
			Leader->SpriteMoveTo(lNowPosX-50,lNowPosY,60,true);
	}
}
//技能
void CGameMain::Shoot()
{
	if(energy<1)
		return;
	if(attackmusiccontrol==0)
		mciSendString("play game//data//audio//skill.wav",NULL,0,NULL);
	float lNowX=Leader->GetSpritePositionX();
	float lNowY=Leader->GetSpritePositionY();
	Bullet->SetSpriteCollisionActive(true,true);
	Bullet->SetSpriteWidth(5);
	Bullet->SetSpriteHeight(5);
	Bullet->SetSpriteVisible(true);
	if(Direction==1)
		{
		Bullet->SetSpritePosition(lNowX+3,lNowY);
		Bullet->SetSpriteLinearVelocityX(40);
		}
	else
		{
		Bullet->SetSpritePosition(lNowX-3,lNowY);
		Bullet->SetSpriteLinearVelocityX(-40);
		}
	energy-=1;
	energynumtext2->SetTextValue(energy);
}
//跳跃
void CGameMain::Jump()
{
	int temp=JudgeJump();
	if(isjump==1)
		{
		isjump=0;
		Leader->AnimateSpritePlayAnimation("JumpFinalAnimation",true);
		itime=1;
		}
	if(temp==1&&isjump==0)
		{
		Leader->AnimateSpritePlayAnimation("JumpFinalAnimation",true);
		itime=1;
		isjump=1;
		}
}
//控制攻击音效
void CGameMain::ControlAttackMusic()
{
	if(attackmusiccontrol==0)
		{
		icon1->SetSpriteVisible(true);
		icon2->SetSpriteVisible(false);
		}
	else
		{
		icon2->SetSpriteVisible(true);
		icon1->SetSpriteVisible(false);
		}
}
//控制背景音乐
void CGameMain::ControlBackgroundMusic()
{
	if(backgroundmusiccontrol==0)
		{
		mciSendString("play game//data//audio//backgroundmusic.wav",NULL,0,NULL);
		icon4->SetSpriteVisible(false);
		icon3->SetSpriteVisible(true);
		}
	else
		{
		mciSendString("close game//data//audio//backgroundmusic.wav",NULL,0,NULL);
		icon3->SetSpriteVisible(false);
		icon4->SetSpriteVisible(true);
		}
}
//加载游戏
void CGameMain::LoadingGame()
{
	RestartDisplay_None();
	GameOver=0;
	lSpeedLeft=0;
	lSpeedRight=0;
	DeleteGamenumSelect();
	//鼠标隐藏
	CSystem::CursorOff();
	//各初始数据
	if(GameNum==0)
		{	
		OldPosX=-45.f;
		OldPosY=0.f;
		}
	else if(GameNum==1)
		{
		OldPosX=-30.f;
		OldPosY=26.5f;
		}
	else if(GameNum==2)
		{
		OldPosX=-30.0f;
		OldPosY=0.0f;
		}
	Direction=1;
	stop=0;
	itime=0;
	Leader=new CAnimateSprite(CSystem::MakeSpriteName("l",0));
	energy=0;
	if(GameNum==2)
		{
		Leader->CloneSprite("swiming");
		time_3f=1.1f;
		energy=99;
		}
	else
		{
		Leader->CloneSprite("leader");
		Leader->AnimateSpritePlayAnimation("bossAnimation",false);
		}
	Leader->SetSpritePosition(OldPosX,OldPosY);
	Leader->SetSpriteCollisionActive(true,true);
	Leader->SetSpriteWorldLimitMode(WORLD_LIMIT_NULL);
	LoadingMap();
	MakeEnemy();
	ControlAttackMusic();
	ControlBackgroundMusic();
}
//加载开始界面
void CGameMain::ShowStartface()
{
	CSystem::CursorOn();
	CSystem::ShowCursor(false);
	buttons[0]=new CSprite(CSystem::MakeSpriteName("bn",0));
	buttons[1]=new CSprite(CSystem::MakeSpriteName("bn",1));
	buttons[4]=new CSprite(CSystem::MakeSpriteName("bn",4));
	buttons[0]->CloneSprite("aboutus");
	buttons[1]->CloneSprite("button1");
	buttons[4]->CloneSprite("button4");
	backgroundimg=new CSprite(CSystem::MakeSpriteName("bgimg",0));
	backgroundimg->CloneSprite("backgroundimg");
	backgroundimg->SetSpritePosition(0,0);
	buttons[0]->SetSpritePosition(0.0f,20.0f);
	buttons[1]->SetSpritePosition(0.0f,0.0f);  
	buttons[4]->SetSpritePosition(0.0f,10.0f);
}
//删除开始界面
void CGameMain::DeleteStartface()
{
	backgroundimg->DeleteSprite();
	buttons[0]->DeleteSprite();
	buttons[1]->DeleteSprite();
	buttons[4]->DeleteSprite();
}
//加载关卡选择
void CGameMain::ShowGamenumSelect()
{
	//构造鼠标
	backgroundimg=new CSprite(CSystem::MakeSpriteName("bgimg",0));
	backgroundimg->CloneSprite("backgroundimg");
	backgroundimg->SetSpritePosition(0,0);
	backmenustate=1;
	mouse1->SetSpriteVisible(true);
	CSystem::ShowCursor(false);
	gamenumbackground=new CSprite(CSystem::MakeSpriteName("gbr",0));
	gamenumbackground->CloneSprite("gamenumbackground");
	gamenumbackground->SetSpritePosition(0.0f,0.0f);
	for(int i=1;i<=3;i++)
		gamenumselect[i]=new CSprite(CSystem::MakeSpriteName("gns",i));
	gamenumselect[1]->CloneSprite("gamenum1");
	gamenumselect[1]->SetSpritePosition(-15.0f,-5.0f);
	gamenumselect[2]->CloneSprite("gamenum2");
	gamenumselect[2]->SetSpritePosition(-0.0f,-5.0f);
	gamenumselect[3]->CloneSprite("gamenum3");
	gamenumselect[3]->SetSpritePosition(15.0f,-5.0f);
	buttons[2]=new CSprite(CSystem::MakeSpriteName("bn",2));
	buttons[2]->CloneSprite("button2");
	buttons[2]->SetSpritePosition(0.0f,10.0f);
}
//删除关卡选择
void CGameMain::DeleteGamenumSelect()
{
	backgroundimg->DeleteSprite();
	gamenumbackground->DeleteSprite();
	for(int i=1;i<=3;i++)
		{
		gamenumselect[i]->DeleteSprite();
		}
	buttons[2]->DeleteSprite();
	mouse1->SetSpriteVisible(false);
	mouse2->SetSpriteVisible(false);
}
//加载游戏中菜单
void CGameMain::Loadingmenu()
{
	ispause=1;
	CSystem::CursorOn();
	CSystem::ShowCursor(false);
	backmenustate=3;
	for(int i=2;i<5;i++)
		{
		buttons[i]=new CSprite(CSystem::MakeSpriteName("bn",i));
		buttons[i]->CloneSprite(CSystem::MakeSpriteName("button",i));
		}
	buttons[3]->SetSpritePosition(0.0f,0.0f);
	buttons[4]->SetSpritePosition(0.0f,20.0f);
	buttons[2]->SetSpritePosition(0.0f,10.0f);
	mouse1->SetSpriteVisible(true);
	//ShowGamenumSelect();
	//ShowStartface();
}
//删除游戏中菜单
void CGameMain::Deletemenu()
{
	ispause=0;
	CSystem::CursorOff();
	CSystem::ShowCursor(false);
	for(int i=2;i<5;i++)
		{
		buttons[i]->DeleteSprite();
		}
	mouse1->SetSpriteVisible(false);
	mouse2->SetSpriteVisible(false);
}
//加载关于我们
void CGameMain::ShowAboutUs()
{
	backgroundimg=new CSprite(CSystem::MakeSpriteName("bgimg",0));
	backgroundimg->CloneSprite("backgroundimg");
	backgroundimg->SetSpritePosition(0,0);
	backmenustate=2;
	aboutusimg->CloneSprite("aboutusimg");
	aboutusimg->SetSpritePosition(0.0f,0.0f);
	buttons[2]->CloneSprite("button2");
	buttons[2]->SetSpritePosition(0.0f,24.0f);
}
//删除关于我们
void CGameMain::DeleteAboutUs()
{
	backgroundimg->DeleteSprite();
	aboutusimg->DeleteSprite();
	buttons[2]->DeleteSprite();
}
//Boss移动
void CGameMain::MoveBoss()
{
	int posx=fishboss->GetSpritePositionX();
	int posy=fishboss->GetSpritePositionY();
	if(posy==-20)
		enemydir=0;
	if(posy==20)
		enemydir=1;
	if(enemydir==0)
		fishboss->SpriteMoveTo(posx,20,20,true);
	else
		fishboss->SpriteMoveTo(posx,-20,20,true);
}
//怪物暂停
void CGameMain::EnemyPause()
{
	for(int i=1;i<=mygame[GameNum].xml[1];i++)
		{
			Enemy[i]->SetSpriteLinearVelocityX(0);
			Enemy[i]->SetSpriteLinearVelocityY(0);
		}
}
//怪物移动
void CGameMain::EnemyStart()
{
	for(int i=1;i<=mygame[GameNum].xml[1];i++)
		{
		Enemy[i]->SetSpriteAtRest(true);
		}
}
//生成鱼怪
void CGameMain::MakeSmallFish()
{
	int x;
	fishstate=rand()%4;
	for(int i=0,j=2;i<fishpos[fishstate].n;i++,j++)
		{
		x=1+rand()%2;
		smallfish[i]=new CSprite(CSystem::MakeSpriteName("sf",i));
		smallfish[i]->CloneSprite(CSystem::MakeSpriteName("fish",x));
		smallfish[i]->SetSpritePosition(fishpos[fishstate].pos[i][0],fishpos[fishstate].pos[i][1]);
		smallfish[i]->SpriteMoveTo(-70.0f,fishpos[fishstate].pos[i][1],35,false);
		}
}
//删除鱼怪
void CGameMain::DeleteSmallFish()
{
	for(int i=0;i<fishpos[fishstate].n;i++)
		smallfish[i]->DeleteSprite();
}
//鱼怪追踪
void CGameMain::SmallFishChase()
{
	int leader_posx,leader_posy;
	for(int i=0;i<5;i++)
		{
		leader_posx=Leader->GetSpritePositionX();
		leader_posy=Leader->GetSpritePositionY();
		smallfish[i]->SpriteMoveTo(leader_posx,leader_posy,20,false);
		if(smallfish[i]->GetSpritePositionX()>leader_posx)
			smallfish[i]->SetSpriteFlipX(false);
		else
			smallfish[i]->SetSpriteFlipX(true);
		}
}
//显示胜利界面
void CGameMain::ShowVictory()
{
	CSystem::CursorOn();
	backgroundimg=new CSprite("bgimg");
	victoryimg=new CSprite("vimg");
	buttons[2]=new CSprite("bn2");
	buttons[4]=new CSprite("bn4");
	backgroundimg->CloneSprite("backgroundimg");
	victoryimg->CloneSprite("victoryimg");
	buttons[2]->CloneSprite("button2");
	buttons[4]->CloneSprite("button4");
	backgroundimg->SetSpritePosition(0.0f,0.0f);
	victoryimg->SetSpritePosition(0.0f,0.0f);
	buttons[2]->SetSpritePosition(-15.0f,26.0f);
	buttons[4]->SetSpritePosition(15.0f,26.0f);
	backmenustate=4;
}
//删除胜利界面
void CGameMain::DeleteVictory()
{
	backgroundimg->DeleteSprite();
	victoryimg->DeleteSprite();
	buttons[2]->DeleteSprite();
	buttons[4]->DeleteSprite();
}