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
//���﷽��
int enemydir=0;
//���ֿ���
int backgroundmusiccontrol;
int attackmusiccontrol;
//������Ϸ
int isloadinggame;
//����ж�
int mousejudge=0;
//��Ϸ����ѭ��
float musictime=0;
//runtime
int runtime=0;
//backmenu��״̬
int backmenustate=0;
//esc����
int esctime=0;
//��ͣ
int ispause=0;
//��������Ϸʱ��
float time_3f=0;
int time_3i=0;
//�������
int fishstate=0;
//BossѪ��
int bosshp=10;
struct MyStruct
{
	int mapType[30];//�ݵ�����
	float map[30][2];//�ݵ�����
	float EnemyMap[5][3];//��������
	float absoluteEnemyMap[15];//ԭʼ����X������
	float Victory[2];// ��������
	int EnergyBallType[15];//����������
	float EnergyBallMap[15][2];//����������
	int xml[3];//����:0.�ݵ� 1.���� 2.������
}mygame[15]=
{
  {//��һ��
	{/*�ݵ�����*/0,1,2,3,1,2,3,2,3,1},
	{/*�ݵ�����*/{0.0f,0.0f},{-15.0f,33.7f},{36.0f,30.0f},{61.0f,26.5f},{115.0f,33.7f},{166.0f,30.0f},{191.0f,26.5f},{216.0f,30.0f},{241.0f,26.5f},{292.0f,33.7f}},
	{/*��������*/{0.0f,0.0f,0.0f},{15.0f,25.5f,1.0f},{145.0f,25.5f,4.0f}},
	{/*ԭʼ����X������*/},
	{/*��������*/290.0f,27.0f},
	{/*����������*/1,2},
	{/*����������*/{0.0f,28.0f},{10.0f,28.0f}},
	{/*����*/9,2,2}
  },
  {//�ڶ���
    {/*�ݵ�����*/0,1,4,4,4,4,4,4,4,5,4,4,4,4,5,4,4,4},
	{/*�ݵ�����*/
		{0.0f,0.0f},{-0.0f,33.7f},{28.0f,19.0f},{-0.0f,18.0f},{25.0f,1.0f},{-25.0f,1.0f},{1.0f,-10.0f},{35.0f,-17.0f},
		{-19.0f,-45.0f},{-22.0f,-28.0f},{10.0f,-55.0f},{30.0f,-65.0f},{10.0f,-80.0f},{-19.0f,-80.0f},{10.0f,-110.0f},
		{-45.0f,-90.0f},{30.0f,-128.0f},{0.0f,-138.0f}
	},
	{/*��������*/{0.0f,0.0f,0.0f},{10.0f,-38.0f},{40.0f,-117.0f}},
	{/*ԭʼ����X������*/},
	{/*��������*/-2.0f,-145.0f},
	{/*����������*/1,2,2},
	{/*����������*/{-25.0f,-2.0f},{1.0f,-14.0f},{-45.0f,-94.0f}},
	{/*����*/18,2,3}
  },
  {//������
	{/*�ݵ�����*/},
	{/*�ݵ�����*/},
	{/*��������*/},
	{/*ԭʼ����X������*/},
	{/*��������*/-100.0f,-100.0f},
	{/*����������*/},
	{/*����������*/},
	{/*����*/0,0,0}
  }
};
struct fishstruct
{
	int n;//����
	int pos[15][2];//����
}fishpos[10]=
{
  {//����һ
	/*����*/5,
	/*����*/{{55.0f,-30.0f},{55.0f,-15.0f},{55.0f,0.0f},{55.0f,15.0f},{55.0f,30.0f}}
  },
  {//���Ͷ�
    /*����*/5,
	/*����*/{{75.0f,-30.0f},{65.0f,-15.0f},{55.0f,0.0f},{65.0f,15.0f},{75.0f,30.0f}}
  },
  {//������
    /*����*/6,
	/*����*/{{55.0f,-30.0f},{55.0f,-20.0f},{55.0f,-10.0f},{55.0f,10.0f},{55.0f,20.0f},{55.0f,30.0f}}
  },
  {//������
    /*����*/9,
	/*����*/{{55.0f,-20.0f},{55.0f,0.0f},{55.0f,20.0f},{65.0f,-20.0f},{65.0f,0.0f},{65.0f,20.0f},{75.0f,-20.0f},{75.0f,0.0f},{75.0f,20.0f}}
  },
  {//������
    /*����*/
	/*����*/
  },
};
//==============================================================================
//
// ����ĳ�������Ϊ��GameMainLoop����Ϊ��ѭ��������������ÿ֡ˢ����Ļͼ��֮�󣬶��ᱻ����һ�Ρ�

//==============================================================================
//
// ���캯��
CGameMain::CGameMain()
{
	m_iGameState			=	0;
	GameNum = 0;
	backgroundmusiccontrol = 0 ;
	attackmusiccontrol = 0;
	energy=0.0f;
	//����Start���;���
	StartAnimation=new CSprite("StartAnimation");
	StartText1=new CTextSprite("StartText1");
	StartText2=new CTextSprite("StartText2");
	//�ؿ�
	LostAnimation=new CSprite("LostAnimation");
	LostText1=new CTextSprite("LostText1");
	LostText2=new CTextSprite("LostText2");
	//��������ɫ
	Leader=new CAnimateSprite("leader");
	//������ʾ
	gamenumtext1=new CTextSprite("gamenumtext1");
	gamenumtext2=new CTextSprite("gamenumtext2");
	energynumtext1=new CTextSprite("energytext1");
	energynumtext2=new CTextSprite("energytext2");
	//��������ͼ��
	icon1=new CSprite("icon1");
	icon2=new CSprite("icon2");
	icon3=new CSprite("icon3");
	icon4=new CSprite("icon4");
	//���챳��
	backgroundimg=new CSprite("backgroundimg");
	//�������
	mouse1=new CSprite("mouse1");
	mouse2=new CSprite("mouse2");
	//����ؿ�ѡ��
	gamenumbackground=new CSprite("gamenumbackground");
	gamenumselect[1]=new CSprite("gamenum1");
	gamenumselect[2]=new CSprite("gamenum2");
	gamenumselect[3]=new CSprite("gamenum3");
	//���쿪ʼ����
	buttons[0]=new CSprite("aboutus");
	buttons[1]=new CSprite("button1");
	buttons[2]=new CSprite("button2");
	buttons[3]=new CSprite("button3");
	buttons[4]=new CSprite("button4");
	aboutusimg=new CSprite("aboutusimg");
	//������Boss
	fishboss=new CSprite("fishboss");
	//�������
	list<CSprite*>::iterator i_fish;
	//����ʤ������
	CSprite* victoryimg=new CSprite("vimg");
	//������������
	dead=new CAnimateSprite("ddead");
	//����BossѪ����ʾ
	bosshptext=new CTextSprite("bht");
	bosshpnum=new CTextSprite("bhn");
}
//==============================================================================
//
// ��������
CGameMain::~CGameMain()
{
}
//==============================================================================
//
// ��Ϸ��ѭ�����˺���������ͣ�ĵ��ã�����ÿˢ��һ����Ļ���˺�����������һ��
// ���Դ�����Ϸ�Ŀ�ʼ�������С������ȸ���״̬. 
// ��������fDeltaTime : �ϴε��ñ��������˴ε��ñ�������ʱ��������λ����
void CGameMain::GameMainLoop( float	fDeltaTime )
{
	switch( GetGameState() )
	{
		// ��ʼ����Ϸ�������һ���������
	case 0:
		{
		GameInit();
		break;
		}
	case 1:
		{
			LoadingGame();
			SetGameState(2); // ��ʼ��֮�󣬽���Ϸ״̬����Ϊ������
		}
		break;

		// ��Ϸ�����У����������Ϸ�߼�
	case 2:
		{
			// TODO �޸Ĵ˴���Ϸѭ�������������ȷ��Ϸ�߼�
			if( true && GameOver==0)  //��Ϸ�Ƿ����
			{
				GameRun( fDeltaTime );
			}
			else // ��Ϸ������������Ϸ���㺯����������Ϸ״̬�޸�Ϊ����״̬
			{				
				SetGameState(0);
				GameEnd();
			}
		}
		break;
		// ��Ϸ����/�ȴ����ո����ʼ
	};
}
//=============================================================================
//
// ÿ�ֿ�ʼǰ���г�ʼ���������һ���������
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
// ÿ����Ϸ������
void CGameMain::GameRun( float fDeltaTime )
{
	centerX=Leader->GetSpritePositionX();
	centerY=Leader->GetSpritePositionY();
	//�Ƿ�׹��
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
	//�������ƶ�
	ScreenMove();
	MoveEnemy();
	//����λ��
	OldPosX=centerX;
	OldPosY=centerY;

	//��Ծʵ��
	stop=0;
	if(itime>0&&stop==0)
	{
		itime-=3*fDeltaTime;
		//�ٶ���itime�ı�
		if(GameNum==0)
			lSpeedTop=8-80*itime;
		else if(GameNum==1)
			lSpeedTop=2-20*itime;
		Running();
	}
	//����ѭ��
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
// ������Ϸ����
void CGameMain::GameEnd()
{
	DeleteMap();
	SetGameState(0);
	RestartDisplay_Show();
	isloadinggame=1;
}
//������Ϸͨ��
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
// ����ƶ�
// ���� fMouseX, fMouseY��Ϊ��굱ǰ����
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
// �����
// ���� iMouseType����갴��ֵ���� enum MouseTypes ����
// ���� fMouseX, fMouseY��Ϊ��굱ǰ����
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
// ��굯��
// ���� iMouseType����갴��ֵ���� enum MouseTypes ����
// ���� fMouseX, fMouseY��Ϊ��굱ǰ����
void CGameMain::OnMouseUp( const int iMouseType, const float fMouseX, const float fMouseY )
{
	
}
//==========================================================================
//
// ���̰���
// ���� iKey�������µļ���ֵ�� enum KeyCodes �궨��
// ���� iAltPress, iShiftPress��iCtrlPress�������ϵĹ��ܼ�Alt��Ctrl��Shift��ǰ�Ƿ�Ҳ���ڰ���״̬(0δ���£�1����)
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
		//��Ծ  �ٶȺ���Ϊ  lSpeedTop=20-20*itime
		if(iKey==KEY_W)
			{
			if(GameNum==2)
				lSpeedTop=-40.0f;
			else
				Jump();
			}
		Running();
		//����
		if(iKey==KEY_L)
			if(GameNum!=2)
				FastRun();
		//�ӵ�
		if(iKey==KEY_J&&JudgeBullet()==1)
			Shoot();
		//�����빥��
		if(iKey==KEY_K)
			if(GameNum!=2)
				AttackEnemy();
	}
}
//==========================================================================
//
// ���̵���
// ���� iKey������ļ���ֵ�� enum KeyCodes �궨��
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
		//������ɲ���ԭ����
		if(iKey==KEY_L)
		{
			Leader->AnimateSpritePlayAnimation("bossAnimation",true);
		}
		Running();
	}

}
//===========================================================================
//
// �����뾫����ײ
// ���� szSrcName��������ײ�ľ�������
// ���� szTarName������ײ�ľ�������
void CGameMain::OnSpriteColSprite( const char *szSrcName, const char *szTarName )
{
	if(m_iGameState==2)
	{
		//�����й���ײ
		if(strcmp(szSrcName,Leader->GetName())==0)
		{
			//������ݵ���ײ
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
			//�����������ײ
			for(int i=1;i<=mygame[GameNum].xml[1];i++)
			{
				if(strcmp(szTarName,Enemy[i]->GetName())==0)
				{
					GameOver=1;
				}
			}
			//������������ײ
			if(strcmp(szTarName,Victory->GetName())==0)
			{
				//ʤ�������
				GameVictory();
				LoadingGame();
			}
			//��������������ײ
			for(int i=0;i<mygame[GameNum].xml[2];i++)
				{
				if(strcmp(szTarName,m_energy[i]->GetName())==0)
					{
					energy+=mygame[GameNum].EnergyBallType[i];
					energynumtext2->SetTextValue(energy);
					m_energy[i]->DeleteSprite();
					}
				}
			//����������ײ
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
		//�ӵ�����������ʧ
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
		//�ӵ��������
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
// ����������߽���ײ
// ���� szName����ײ���߽�ľ�������
// ���� iColSide����ײ���ı߽� 0 ��ߣ�1 �ұߣ�2 �ϱߣ�3 �±�
void CGameMain::OnSpriteColWorldLimit( const char *szName, const int iColSide )
{
	//�����±߽�����  ������ֹͣ
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
	//�ӵ�����
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
//Start������ʧ
void CGameMain::StartDisplay_None()
{
	backgroundimg->DeleteSprite();
	StartAnimation->SetSpriteVisible(false);
	StartText1->SetSpriteVisible(false);
	StartText2->SetSpriteVisible(false);
}
//start�������
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
//Restart������ʧ
void CGameMain::RestartDisplay_None()
{
	dead->DeleteSprite();
	backgroundimg->DeleteSprite();
	LostAnimation->SetSpriteVisible(false);
	LostText1->SetSpriteVisible(false);
	LostText2->SetSpriteVisible(false);
}
//Restart�������
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
//���̿�������ɫ�ƶ�
void CGameMain::Running()
{
	//�ж��Ƿ���Ҫת��
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
	//�ϳ��ٶ�
	Leader->SetSpriteLinearVelocity(lSpeedLeft+lSpeedRight,lSpeedTop+lSpeedBottom);
}
//�����ƶ�  
void CGameMain::ScreenMove()
{
	//��Leader��λ��Ϊ��׼��  ��¼֮ǰ��λ�ã����о�����Leader�ƶ������෴���ʵ�ֳ����ƶ�
	//�ƶ�������ɫ������о���
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
		//��������ƶ������ͼ��Ե ��ȡ�������ƶ�
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
	//��̬�������

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
//�ж��Ƿ������Ծ    ����9����λ���вݵ� ������Ծ
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
//�ж��Ƿ���Է����ӵ�
int CGameMain::JudgeBullet()
{
	float bNowPosX=Bullet->GetSpritePositionX();
	int temp=0;
	if(bNowPosX>=45||bNowPosX<=-45)
		temp=1;
	return temp;
}
//���ص�ͼ
void CGameMain::LoadingMap()
{
	//����
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
	//�ݵ�
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
	//��������
	Victory=new CSprite(CSystem::MakeSpriteName("v",GameNum));
	Victory->CloneSprite("victory");
	Victory->SetSpritePosition(mygame[GameNum].Victory[0],mygame[GameNum].Victory[1]);
	//���켼��
	Bullet=new CAnimateSprite("Bullet");
	//����������
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
	//������ʾ
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
	//��������ͼ��
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
		//������boss
		fishboss=new CSprite(CSystem::MakeSpriteName("fb",0));
		fishboss->CloneSprite("fishboss");
		fishboss->SetSpritePosition(38.0f,0.0f);
		//����С���
		MakeSmallFish();
		//BossѪ������ʾ
		bosshp=20;
		bosshptext->CloneSprite("bosshptext");
		bosshpnum->CloneSprite("bosshpnum");
		bosshptext->SpriteMountToSpriteLinkPoint(fishboss->GetName(),1);
		bosshpnum->SpriteMountToSpriteLinkPoint(fishboss->GetName(),2);
		bosshpnum->SetTextValue(bosshp);
		}
}
//ɾ����ͼ
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
//��������
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
//���˶���
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
//��������
void CGameMain::AttackEnemy()
{
	if(attackmusiccontrol==0)
		mciSendString("play game//data//audio//hit_double.wav",NULL,0,NULL);
	float posx=Leader->GetSpritePositionX();
	float posy=Leader->GetSpritePositionY();
	float posx2=-7.0f*pow(-1,Direction);
	int isattack=0;//�Ƿ񹥻����˵���
	//�������ж�Leaderǰ��7�����Ƿ��е���
	for(int i=1;i<=mygame[GameNum].xml[1];i++)
		{
		if(Enemy[i]->IsPointInSprite(posx+posx2,posy))
			{
			Enemy[i]->DeleteSprite();
			Leader->AnimateSpritePlayAnimation("KickingAnimation",true);
			isattack=1;
			}
		}
	//δ���������Ŷ���
	if(isattack==0)
		{
		Leader->AnimateSpritePlayAnimation("KickingOneAnimation",true);
		}
}
//����
void CGameMain::FastRun()
{
	lNowPosX=Leader->GetSpritePositionX();
	lNowPosY=Leader->GetSpritePositionY();
	Leader->AnimateSpritePlayAnimation("RunningAnimation",true);
	//����
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
//����
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
//��Ծ
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
//���ƹ�����Ч
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
//���Ʊ�������
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
//������Ϸ
void CGameMain::LoadingGame()
{
	RestartDisplay_None();
	GameOver=0;
	lSpeedLeft=0;
	lSpeedRight=0;
	DeleteGamenumSelect();
	//�������
	CSystem::CursorOff();
	//����ʼ����
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
//���ؿ�ʼ����
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
//ɾ����ʼ����
void CGameMain::DeleteStartface()
{
	backgroundimg->DeleteSprite();
	buttons[0]->DeleteSprite();
	buttons[1]->DeleteSprite();
	buttons[4]->DeleteSprite();
}
//���عؿ�ѡ��
void CGameMain::ShowGamenumSelect()
{
	//�������
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
//ɾ���ؿ�ѡ��
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
//������Ϸ�в˵�
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
//ɾ����Ϸ�в˵�
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
//���ع�������
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
//ɾ����������
void CGameMain::DeleteAboutUs()
{
	backgroundimg->DeleteSprite();
	aboutusimg->DeleteSprite();
	buttons[2]->DeleteSprite();
}
//Boss�ƶ�
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
//������ͣ
void CGameMain::EnemyPause()
{
	for(int i=1;i<=mygame[GameNum].xml[1];i++)
		{
			Enemy[i]->SetSpriteLinearVelocityX(0);
			Enemy[i]->SetSpriteLinearVelocityY(0);
		}
}
//�����ƶ�
void CGameMain::EnemyStart()
{
	for(int i=1;i<=mygame[GameNum].xml[1];i++)
		{
		Enemy[i]->SetSpriteAtRest(true);
		}
}
//�������
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
//ɾ�����
void CGameMain::DeleteSmallFish()
{
	for(int i=0;i<fishpos[fishstate].n;i++)
		smallfish[i]->DeleteSprite();
}
//���׷��
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
//��ʾʤ������
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
//ɾ��ʤ������
void CGameMain::DeleteVictory()
{
	backgroundimg->DeleteSprite();
	victoryimg->DeleteSprite();
	buttons[2]->DeleteSprite();
	buttons[4]->DeleteSprite();
}