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
// ��Ϸ�ܹ��ࡣ��������Ϸ��ѭ������Ϸ��ʼ���������ȹ���
class	CGameMain
{
private:
	int				m_iGameState;				// ��Ϸ״̬��0���������ߵȴ���ʼ��1����ʼ����2����Ϸ������
	//��ϷStart����
	CSprite* StartAnimation;
	CTextSprite* StartText1;
	CTextSprite* StartText2;
	//�ؿ�����
	CSprite* LostAnimation;
	CTextSprite* LostText1;
	CTextSprite* LostText2;
	//��Ϸ����ɫ
	CAnimateSprite* Leader;
	//���˽�ɫ
	CAnimateSprite* Enemy[15];
	//���䶯��
	CAnimateSprite* Bullet;
	//����
	CSprite* background;
	CSprite* backgroundimg;
	//�ݵ�
	CSprite* ground[50];
	//����
	CSprite* Victory;
	//������������
	float energy;
	CSprite* m_energy[15];
	//���ֿ���ͼ��
	CSprite* icon1;
	CSprite* icon2;
	CSprite* icon3;
	CSprite* icon4;
	//�����״
	CSprite* mouse1;
	CSprite* mouse2;
	//�ؿ�
	int GameNum;
	CTextSprite* gamenumtext1;
	CTextSprite* gamenumtext2;
	CTextSprite* energynumtext1;
	CTextSprite* energynumtext2;
	//��Boss
	CSprite* fishboss;
	//���
	list<CSprite*> smallfishlist;
	CSprite* smallfish[2000];
	//��������
	CSprite* aboutusimg;
	//��ʼ��Ϸ
	CSprite* buttons[10];
	//�ؿ�ѡ��
	CSprite* gamenumbackground;
	CSprite* gamenumselect[15];
	//ʤ������
	CSprite* victoryimg;
	//��������
	CAnimateSprite* dead;
	//BossѪ����ʾ
	CTextSprite* bosshptext;
	CTextSprite* bosshpnum;
	//����ɫϵ�п��Ʊ���
	float lSpeedLeft,lSpeedRight,lSpeedTop,lSpeedBottom;
	float centerX,centerY,OldPosX,OldPosY,lNowPosX,lNowPosY;
	int judgejump;
	int stop;
	//��Ծʱ�� ������Ծ
	float itime;
	int isjump;
	//����
	int Direction;
	//��Ϸ�����ж�
	int GameOver;
public:
	CGameMain();            //���캯��
	~CGameMain();           //��������  

	// Get����
	int				GetGameState()											{ return m_iGameState; }
	
	// Set����
	void			SetGameState( const int iState )				{ m_iGameState	=	iState; }
	
	// ��Ϸ��ѭ����
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
	//Start������ʾ����ʧ
	void StartDisplay_None();
	void StartDisplay_Show();
	//Restart������ʾ����ʧ
	void RestartDisplay_None();
	void RestartDisplay_Show();
	//���ƽ�ɫ�ƶ�
	void Running();
	//�������ƶ�
	void ScreenMove();
	//�ж��Ƿ������Ծ
	int JudgeJump();
	//�Ƿ���Է����ӵ�
	int JudgeBullet();
	//���ص�ͼ
	void LoadingMap();
	//ɾ����ͼ
	void DeleteMap();
	//��������
	void MakeEnemy();
	//���˶���
	void MoveEnemy();
	//��������
	void AttackEnemy();
	//����ͨ��
	void GameVictory();
	//����
	void FastRun();
	//����
	void Shoot();
	//��Ծ
	void Jump();
	//���ƹ�����Ч
	void ControlAttackMusic();
	//���Ʊ�������
	void ControlBackgroundMusic();
	//���ؿ�ʼ����
	void ShowStartface();
	//ɾ����ʼ����
	void DeleteStartface();
	//���عؿ�ѡ��
	void ShowGamenumSelect();
	//ɾ���ؿ�ѡ��
	void DeleteGamenumSelect();
	//������Ϸ
	void LoadingGame();
	//������Ϸ�в˵�
	void Loadingmenu();
	//ɾ����Ϸ�в˵�
	void Deletemenu();
	//���ع�������
	void ShowAboutUs();
	//ɾ����������
	void DeleteAboutUs();
	//Boss�ƶ�
	void MoveBoss();
	//������ͣ
	void EnemyPause();
	//���￪ʼ
	void EnemyStart();
	//�������
	void MakeSmallFish();
	//ɾ�����
	void DeleteSmallFish();
	//���׷��
	void SmallFishChase();
	//����ʤ������
	void ShowVictory();
	//ɾ�����ؽ���
	void DeleteVictory();
};

/////////////////////////////////////////////////////////////////////////////////
// 
extern CGameMain	g_GameMain;

#endif // _LESSON_X_H_