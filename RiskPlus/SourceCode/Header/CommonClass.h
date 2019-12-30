/////////////////////////////////////////////////////////////////////////////////
//
//
//
//
/////////////////////////////////////////////////////////////////////////////////
#ifndef _COMMON_CLASS_H_
#define _COMMON_CLASS_H_
//
#include <windows.h>
/////////////////////////////////////////////////////////////////////////////////
//
// ȫ�ֱ������궨��
#define		MAX_NAME_LEN		128	// ���ֳ���
/////////////////////////////////////////////////////////////////////////////////
//
// Sprite����������߽���ײ��Ӧ����( ��ײ֮��API OnSpriteColWorldLimit �������� )
enum EWorldLimit
{
	WORLD_LIMIT_OFF,			// �ر�������߽����ײ
	WORLD_LIMIT_NULL,			// ��ײ֮�����治���κδ����ɸ���Ϸ�Լ�������Ӧ
	WORLD_LIMIT_RIGID,			// ����������ײ��Ӧ
	WORLD_LIMIT_BOUNCE,			// ����ģʽ
	WORLD_LIMIT_CLAMP,			// С����������ֹͣģʽ(�����������)
	WORLD_LIMIT_STICKY,			// ��ײ֮��ֹ
	WORLD_LIMIT_KILL,			// ��ײ֮���齫��ɾ��

	WORLD_LIMIT_INVALID,		//	��Чֵ
};
/////////////////////////////////////////////////////////////////////////////////
//
/// �����뾫��֮�䡢�������ͼ����������֮�����ײ��Ӧ( ��ײ֮��API OnSpriteColSprite �������� )
enum ECollisionResponse
{
	COL_RESPONSE_OFF,			//	�ر���ײ��Ӧ(������OnSpriteColSprite)

	COL_RESPONSE_RIGID,			//	����������ײ��Ӧ
	COL_RESPONSE_BOUNCE,		//	����ģʽ
	COL_RESPONSE_CLAMP,			//	С����������ֹͣģʽ(�����������)
	COL_RESPONSE_STICKY,		//	��ײ֮��ֹ
	COL_RESPONSE_KILL,			//	��ײ֮���齫��ɾ��
	COL_RESPONSE_CUSTOM,		//	��ײ֮�����治���κδ����ɸ���Ϸ�Լ�������Ӧ

	COL_RESPONSE_INVALID,		//	��Чֵ
};
//================================================================================
//
// ��갴��ֵ����
enum MouseTypes 
{
	MOUSE_LEFT		=	0,		// ���
	MOUSE_RIGHT		=	1,		// �Ҽ�
	MOUSE_MIDDLE	=	2		// �м�
};
/////////////////////////////////////////////////////////////////////////////////
//
// ����KEYֵ����
enum KeyCodes 
{
	KEY_NULL          = 0x000,     ///< Invalid KeyCode
	KEY_BACKSPACE     = 0x001,
	KEY_TAB           = 0x002,
	KEY_ENTER         = 0x003,
	KEY_CONTROL       = 0x004,
	KEY_ALT           = 0x005,
	KEY_SHIFT         = 0x006,
	KEY_PAUSE         = 0x007,
	KEY_CAPSLOCK      = 0x008,
	KEY_ESCAPE        = 0x009,
	KEY_SPACE         = 0x00a,
	KEY_PAGE_DOWN     = 0x00b,
	KEY_PAGE_UP       = 0x00c,
	KEY_END           = 0x00d,
	KEY_HOME          = 0x00e,
	KEY_LEFT          = 0x00f,
	KEY_UP            = 0x010,
	KEY_RIGHT         = 0x011,
	KEY_DOWN          = 0x012,
	KEY_PRINT         = 0x013,
	KEY_INSERT        = 0x014,
	KEY_DELETE        = 0x015,
	KEY_HELP          = 0x016,

	KEY_0             = 0x017,
	KEY_1             = 0x018,
	KEY_2             = 0x019,
	KEY_3             = 0x01a,
	KEY_4             = 0x01b,
	KEY_5             = 0x01c,
	KEY_6             = 0x01d,
	KEY_7             = 0x01e,
	KEY_8             = 0x01f,
	KEY_9             = 0x020,

	KEY_A             = 0x021,
	KEY_B             = 0x022,
	KEY_C             = 0x023,
	KEY_D             = 0x024,
	KEY_E             = 0x025,
	KEY_F             = 0x026,
	KEY_G             = 0x027,
	KEY_H             = 0x028,
	KEY_I             = 0x029,
	KEY_J             = 0x02a,
	KEY_K             = 0x02b,
	KEY_L             = 0x02c,
	KEY_M             = 0x02d,
	KEY_N             = 0x02e,
	KEY_O             = 0x02f,
	KEY_P             = 0x030,
	KEY_Q             = 0x031,
	KEY_R             = 0x032,
	KEY_S             = 0x033,
	KEY_T             = 0x034,
	KEY_U             = 0x035,
	KEY_V             = 0x036,
	KEY_W             = 0x037,
	KEY_X             = 0x038,
	KEY_Y             = 0x039,
	KEY_Z             = 0x03a,

	KEY_TILDE         = 0x03b,
	KEY_MINUS         = 0x03c,
	KEY_EQUALS        = 0x03d,
	KEY_LBRACKET      = 0x03e,
	KEY_RBRACKET      = 0x03f,
	KEY_BACKSLASH     = 0x040,
	KEY_SEMICOLON     = 0x041,
	KEY_APOSTROPHE    = 0x042,
	KEY_COMMA         = 0x043,
	KEY_PERIOD        = 0x044,
	KEY_SLASH         = 0x045,
	KEY_NUMPAD0       = 0x046,
	KEY_NUMPAD1       = 0x047,
	KEY_NUMPAD2       = 0x048,
	KEY_NUMPAD3       = 0x049,
	KEY_NUMPAD4       = 0x04a,
	KEY_NUMPAD5       = 0x04b,
	KEY_NUMPAD6       = 0x04c,
	KEY_NUMPAD7       = 0x04d,
	KEY_NUMPAD8       = 0x04e,
	KEY_NUMPAD9       = 0x04f,
	KEY_MULTIPLY      = 0x050,
	KEY_ADD           = 0x051,
	KEY_SEPARATOR     = 0x052,
	KEY_SUBTRACT      = 0x053,
	KEY_DECIMAL       = 0x054,
	KEY_DIVIDE        = 0x055,
	KEY_NUMPADENTER   = 0x056,

	KEY_F1            = 0x057,
	KEY_F2            = 0x058,
	KEY_F3            = 0x059,
	KEY_F4            = 0x05a,
	KEY_F5            = 0x05b,
	KEY_F6            = 0x05c,
	KEY_F7            = 0x05d,
	KEY_F8            = 0x05e,
	KEY_F9            = 0x05f,
	KEY_F10           = 0x060,
	KEY_F11           = 0x061,
	KEY_F12           = 0x062,
	KEY_F13           = 0x063,
	KEY_F14           = 0x064,
	KEY_F15           = 0x065,
	KEY_F16           = 0x066,
	KEY_F17           = 0x067,
	KEY_F18           = 0x068,
	KEY_F19           = 0x069,
	KEY_F20           = 0x06a,
	KEY_F21           = 0x06b,
	KEY_F22           = 0x06c,
	KEY_F23           = 0x06d,
	KEY_F24           = 0x06e,

	KEY_NUMLOCK       = 0x06f,
	KEY_SCROLLLOCK    = 0x070,
	KEY_LCONTROL      = 0x071,
	KEY_RCONTROL      = 0x072,
	KEY_LALT          = 0x073,
	KEY_RALT          = 0x074,
	KEY_LSHIFT        = 0x075,
	KEY_RSHIFT        = 0x076,
	KEY_WIN_LWINDOW   = 0x077,
	KEY_WIN_RWINDOW   = 0x078,
	KEY_WIN_APPS      = 0x079,
	KEY_OEM_102       = 0x080,

	KEY_MAC_OPT       = 0x090,
	KEY_MAC_LOPT      = 0x091,
	KEY_MAC_ROPT      = 0x092,

	KEY_BUTTON0       = 0x0100,
	KEY_BUTTON1       = 0x0101,
	KEY_BUTTON2       = 0x0102,
	KEY_BUTTON3       = 0x0103,
	KEY_BUTTON4       = 0x0104,
	KEY_BUTTON5       = 0x0105,
	KEY_BUTTON6       = 0x0106,
	KEY_BUTTON7       = 0x0107,
	KEY_BUTTON8       = 0x0108,
	KEY_BUTTON9       = 0x0109,
	KEY_BUTTON10      = 0x010A,
	KEY_BUTTON11      = 0x010B,
	KEY_BUTTON12      = 0x010C,
	KEY_BUTTON13      = 0x010D,
	KEY_BUTTON14      = 0x010E,
	KEY_BUTTON15      = 0x010F,
	KEY_BUTTON16      = 0x0110,
	KEY_BUTTON17      = 0x0111,
	KEY_BUTTON18      = 0x0112,
	KEY_BUTTON19      = 0x0113,
	KEY_BUTTON20      = 0x0114,
	KEY_BUTTON21      = 0x0115,
	KEY_BUTTON22      = 0x0116,
	KEY_BUTTON23      = 0x0117,
	KEY_BUTTON24      = 0x0118,
	KEY_BUTTON25      = 0x0119,
	KEY_BUTTON26      = 0x011A,
	KEY_BUTTON27      = 0x011B,
	KEY_BUTTON28      = 0x011C,
	KEY_BUTTON29      = 0x011D,
	KEY_BUTTON30      = 0x011E,
	KEY_BUTTON31      = 0x011F,
	KEY_ANYKEY         = 0xfffe
};
//////////////////////////////////////////////////////////////////////////////
//
// �ࣺCSprite
// ���о���Ļ��ࡣ��������ľ�̬���飬��̬���飬���֣���Ч�Ⱦ��ɴ���̳���ȥ
// һ���ͼƬ����ӱ���̳���ȥ���ɡ�ֻ������ľ��飬����������ľ��飬����Ҫ�Ӷ�̬����̳���ȥ
//
class CSprite
{
private:
	char		m_szName[MAX_NAME_LEN];		// ��������

public:

	// ���캯������Ҫ����һ���ǿյľ��������ַ��������������ǵ�ͼ��ڷźõľ������֣�����༴���ͼ��ľ����
	// ����������һ���µľ������֣�����Ҫ���ó�Ա���� CloneSprite������һ�ݾ������ʵ��������ʵ�ʵĵ�ͼ�����������
	// szCloneName : Ԥ�ȴ����ڳ����У���Ҫ��¡�ľ�������
	CSprite( const char *szName );
	CSprite( const char *szName, const char *szCloneName );
	virtual ~CSprite();

	// GetName
	// ����ֵ�����ؾ�������
	const char *GetName();


	// CloneSprite������(����)һ�����顣����Ĵ�����ʽ�����ڵ�ͼ�аڷ�һ��������Ϊģ�壬���úø��������Ȼ���ڴ�����ʹ�ô˺�����¡һ��ʵ��
	// ����ֵ��true��ʾ��¡�ɹ���false��¡ʧ�ܡ�ʧ�ܵ�ԭ��������ڵ�ͼ��δ�ҵ���Ӧ���ֵľ���
	// ���� szSrcName����ͼ������ģ��ľ�������
	//
	bool		CloneSprite( const char *szSrcName );

	// DeleteSprite���ڵ�ͼ��ɾ���뱾����ʵ�������ľ���
	//
	void		DeleteSprite();

	// SetSpriteVisible�����þ������ػ�����ʾ(�ɼ����ɼ�)
	// ���� bVisible��true �ɼ� false���ɼ�
	//
	void		SetSpriteVisible( const bool bVisible );

	// IsSpriteVisible����ȡ�þ��鵱ǰ�Ƿ�ɼ�
	//
	bool		IsSpriteVisible();

	// SetSpriteEnable����ֹ�������øþ��顣����ֹ�ľ��齫�������κ���Ӧ���������ƶ���û����ײ�ȣ��������ڵ�ͼ����ʾ
	// ���� bEnable��true���� false��ֹ
	//
	void		SetSpriteEnable( const bool bEnable );

	// SetSpriteScale�����þ��������ֵ
	// ���� fScale������ֵ������0��ֵ
	//
	void		SetSpriteScale( const float fScale );

	// IsPointInSprite���ж�ĳ��������Ƿ�λ�ھ����ڲ�
	// ���� fPosX��X�����
	// ���� fPosY��Y�����
	//
	bool 		IsPointInSprite( const float fPosX, const float fPosY );

	// SetSpritePosition�����þ���λ��
	// ���� fPosX��X����
	// ���� fPosY��Y����
	//
	void		SetSpritePosition( const float fPosX, const float fPosY );

	// SetSpritePositionX��ֻ���þ���X����
	// ���� fPosX��X����
	//
	void		SetSpritePositionX( const float fPosX );

	// SetSpritePositionY��ֻ���þ���Y����
	// ���� fPosY��Y����
	//
	void		SetSpritePositionY( const float fPosY );

	// GetSpritePositionX����ȡ����X����
	// ����ֵ�������X����
	//
	float		GetSpritePositionX();

	// GetSpritePositionY����ȡ����Y����
	// ����ֵ�������Y����
	//
	float		GetSpritePositionY();

	// GetSpriteLinkPointPosX����ȡ�������ӵ�X���ꡣ���ӵ��������ھ����һ������㣬�����ڱ༭�������ӻ���ɾ��
	// ���� iId�����ӵ���ţ���һ��Ϊ1���������εݼ�
	//
	float		GetSpriteLinkPointPosX( const int iId );

	// GetSpriteLinkPointPosY����ȡ�������ӵ�Y���ꡣ���ӵ��������ھ����һ������㣬�����ڱ༭�������ӻ���ɾ��
	// ���� iId�����ӵ���ţ���һ��Ϊ1���������εݼ�
	//
	float		GetSpriteLinkPointPosY( const int iId );

	// SetSpriteRotation�����þ������ת�Ƕ�
	// ���� fRot����ת�Ƕȣ���Χ0 - 360
	//
	void		SetSpriteRotation( const float fRot );

	// GetSpriteRotation����ȡ�������ת�Ƕ�
	// ����ֵ���������ת�Ƕ�
	//
	float		GetSpriteRotation();

	// SetSpriteAutoRot�����þ��鰴��ָ���ٶ��Զ���ת
	// ���� fRotSpeed����ת�ٶ�
	//
	void 		SetSpriteAutoRot( const float fRotSpeed );

	// SetSpriteWidth�����þ������ο��
	// ���� fWidth�����ֵ������0
	//
	void		SetSpriteWidth( const float fWidth );

	// GetSpriteWidth����ȡ�������ο��
	// ����ֵ��������ֵ
	//
	float		GetSpriteWidth();

	// SetSpriteHeight�����þ������θ߶�
	// ���� fHeight������߶�ֵ
	//
	void		SetSpriteHeight( const float fHeight );

	// GetSpriteHeight����ȡ�������θ߶�
	// ����ֵ������߶�ֵ
	//
	float		GetSpriteHeight();

	// SetSpriteFlipX�����þ���ͼƬX����ת��ʾ
	// ���� bFlipX��true ��ת false����ת(�ָ�ԭ������)
	//
	void		SetSpriteFlipX( const bool bFlipX );

	// GetSpriteFlipX����ȡ��ǰ����ͼƬX�����Ƿ��Ƿ�ת��ʾ
	// ����ֵ��true ��ת false����ת
	//
	bool		GetSpriteFlipX();

	// SetSpriteFlipY�����þ���ͼƬY����ת��ʾ
	// ���� bFlipY��true ��ת false����ת(�ָ�ԭ������)
	//
	void		SetSpriteFlipY( const bool bFlipY );

	// GetSpriteFlipY����ȡ��ǰ����ͼƬY�����Ƿ��Ƿ�ת��ʾ
	// ����ֵ��true ��ת false����ת
	//
	bool		GetSpriteFlipY();

	// SetSpriteFlip��ͬʱ���þ��鷭תX��Y����
	// ���� bFlipX��true ��ת false����ת(�ָ�ԭ������)
	// ���� bFlipY��true ��ת false����ת(�ָ�ԭ������)
	//
	void		SetSpriteFlip( const bool bFlipX, const bool bFlipY );

	// SetSpriteLifeTime�����þ��������ʱ����ʱ�䵽��֮���Զ���ɾ��
	// ���� fLifeTime������ʱ������λ ��
	//
	void		SetSpriteLifeTime( const float fLifeTime );

	// GetSpriteLifeTime����ȡ��������ʱ��
	// ����ֵ������ʱ������λ ��
	//
	float		GetSpriteLifeTime();	


	// SpriteMoveTo���þ��鰴�ո����ٶ��ƶ������������
	// ���� fPosX���ƶ���Ŀ��X����ֵ
	// ���� fPosY���ƶ���Ŀ��Y����ֵ
	// ���� fSpeed���ƶ��ٶ�
	// ���� bAutoStop���ƶ����յ�֮���Ƿ��Զ�ֹͣ
	//
	void		SpriteMoveTo( const float fPosX, const float fPosY, const float fSpeed, const bool bAutoStop );

	// SpriteRotateTo���þ��鰴�ո����ٶ���ת�������ĽǶ�
	// ���� fRotation��������Ŀ����תֵ
	// ���� fRotSpeed����ת�ٶ�
	// ���� bAutoStop����ת���յ�֮���Ƿ��Զ�ֹͣ
	//
	void		SpriteRotateTo( const float fRotation, const float fRotSpeed, const bool bAutoStop );

	// SetSpriteWorldLimit�����þ��������߽��������Ƽ���ײģʽ
	// ���� Limit����ײ������߽�֮�����Ӧģʽ�����ΪOFF�����ǹر�����߽���ײ������ֵ�� EWorldLimit
	// ���� fLeft���߽�����X����
	// ���� fTop���߽���ϱ�Y����
	// ���� fRight���߽���ұ�X����
	// ���� fBottom���߽���±�Y����
	//
	void		SetSpriteWorldLimit( const EWorldLimit Limit, const float fLeft, const float fTop, const float fRight, const float fBottom );

	// SetSpriteWorldLimitMode�����þ��������߽���ײģʽ
	// ���� Limit����ײ������߽�֮�����Ӧģʽ�����ΪOFF�����ǹر�����߽���ײ������ֵ�� EWorldLimit
	//
	void		SetSpriteWorldLimitMode( const EWorldLimit Limit );

	// SetSpriteWorldLimitMin�����þ��������߽��ϱ߼������������
	// ���� fLeft���߽�����X����
	// ���� fTop���߽���ϱ�Y����
	//
	void		SetSpriteWorldLimitMin( const float fLeft, const float fTop );

	// SetSpriteWorldLimitMax�����þ��������߽��±߼��ұ���������
	// ���� fRight���߽���ұ�X����
	// ���� fBottom���߽���±�Y����
	//
	void		SetSpriteWorldLimitMax( const float fRight, const float fBottom );

	// GetSpriteWorldLimitLeft����ȡ��������߽���߽�����
	//
	float		GetSpriteWorldLimitLeft();

	// GetSpriteWorldLimitTop����ȡ��������߽��ϱ߽�����
	//
	float		GetSpriteWorldLimitTop();

	// GetSpriteWorldLimitRight����ȡ��������߽��ұ߽�����
	//
	float		GetSpriteWorldLimitRight();

	// GetSpriteWorldLimitBottom����ȡ��������߽��±߽�����
	//
	float		GetSpriteWorldLimitBottom();

	// SetSpriteCollisionSend�����þ����Ƿ���Է���(����)��ײ
	// �������ײ��ʽΪ����A�ƶ�������Bʱ�����A�ǿ��Բ�����ײ�ģ�B�ǿ��Խ�����ײ�ģ�����2������������ײ��������ײ��API�������á���������ײ����
	// ���� bSend��true ���Բ��� false ������
	//
	void 		SetSpriteCollisionSend( const bool bSend );

	// SetSpriteCollisionReceive�����þ����Ƿ���Խ�����ײ
	// �������ײ��ʽΪ����A�ƶ�������Bʱ�����A�ǿ��Բ�����ײ�ģ�B�ǿ��Խ�����ײ�ģ�����2������������ײ��������ײ��API�������á���������ײ����
	// ���� bReceive��true ���Խ��� false ������
	//
	void 		SetSpriteCollisionReceive( const bool bReceive );

	// SetSpriteCollisionActive��ͬʱ���þ����Ƿ���Բ�����������ײ
	// �������ײ��ʽΪ����A�ƶ�������Bʱ�����A�ǿ��Բ�����ײ�ģ�B�ǿ��Խ�����ײ�ģ�����2������������ײ��������ײ��API�������á���������ײ����
	// ���� bSend��true ���Բ��� false ������
	// ���� bReceive��true ���Խ��� false ������
	//
	void 		SetSpriteCollisionActive( const bool bSend, const bool bReceive );

	// SetSpriteCollisionPhysicsSend�����þ����Ƿ���Է���(����)������ײ
	// ���� bSend��true ���Բ��� false ������
	//
	void 		SetSpriteCollisionPhysicsSend( const bool bSend );

	// SetSpriteCollisionPhysicsReceive�����þ����Ƿ���Խ���������ײ
	// ���� bReceive��true ���Խ��� false ������
	//
	void 		SetSpriteCollisionPhysicsReceive( const bool bReceive );

	// GetSpriteCollisionSend����ȡ���鵱ǰ�Ƿ��ǿ��Բ�����ײ
	// ����ֵ��true ���Բ��� false ������
	//
	bool 		GetSpriteCollisionSend();

	// GetSpriteCollisionReceive����ȡ���鵱ǰ�Ƿ��ǿ��Խ�����ײ
	// ����ֵ��true ���Խ��� false ������
	//
	bool 		GetSpriteCollisionReceive();

	// SetSpriteCollisionResponse�����þ����뾫�����ײ��Ӧģʽ
	// ���� Response����Ӧģʽ�����ΪOFF����Ϊ�ر���ײ��Ӧ����ײAPI�����ᱻ���á�����ֵ�� ECollisionResponse
	//
	void		SetSpriteCollisionResponse( const ECollisionResponse Response );

	// SetSpriteCollisionMaxIterations�����þ�����ײ֮�����󷴵�����
	// ���� iTimes����������
	//
	void		SetSpriteCollisionMaxIterations( const int iTimes );

	// SetSpriteForwardMovementOnly�����þ����Ƿ�ֻ�ܳ�ǰ�ƶ�
	// ���� bForward��true ֻ�ܳ�ǰ�ƶ� false ���Գ����������ƶ�
	//
	void		SetSpriteForwardMovementOnly( const bool bForward );

	// GetSpriteForwardMovementOnly����ȡ���鵱ǰ�Ƿ�ֻ�ܳ�ǰ�ƶ�
	// ����ֵ��true ֻ�ܳ�ǰ�ƶ� false ���Գ����������ƶ�
	//
	bool		GetSpriteForwardMovementOnly();

	// SetSpriteForwardSpeed�����þ�����ǰ���ٶ�
	// ���� fSpeed���ٶ�
	//
	void		SetSpriteForwardSpeed( const float fSpeed );

	// SetSpriteImpulseForce�����þ���˲������
	// ���� fForceX��X����������С
	// ���� fForceY��Y����������С
	// ���� bGravitic���Ƿ��������
	//
	void 		SetSpriteImpulseForce( const float fForceX, const float fForceY, const bool bGravitic );

	// SetSpriteImpulseForcePolar�����Ƕȳ������þ���˲������
	// ���� fPolar���Ƕȳ���
	// ���� fForce��������С
	// ���� bGravitic���Ƿ��������
	//
	void 		SetSpriteImpulseForcePolar( const float fPolar, const float fForce, const bool bGravitic );

	// SetSpriteConstantForceX�����þ���X����������
	// ���� fForceX��X����������С
	//
	void 		SetSpriteConstantForceX( const float fForceX );

	// SetSpriteConstantForceY�����þ���Y����������
	// ���� fForceY��Y����������С
	//
	void 		SetSpriteConstantForceY( const float fForceY );

	// SetSpriteConstantForceGravitic�������ڼ��㳣��������ʱ���Ƿ��������
	// ���� bGravitic���Ƿ��������
	//
	void 		SetSpriteConstantForceGravitic( const bool bGravitic );

	// SetSpriteConstantForce�����þ��鳣������
	// ���� fForceX��X����������С
	// ���� fForceY��Y����������С
	// ���� bGravitic���Ƿ��������
	//
	void 		SetSpriteConstantForce( const float fForceX, const float fForceY, const bool bGravitic );

	// SetSpriteConstantForcePolar�����Ƕȳ������þ��鳣������
	// ���� fPolar���Ƕȳ���
	// ���� fForce��������С
	// ���� bGravitic���Ƿ��������
	//
	void 		SetSpriteConstantForcePolar( const float fPolar, const float fForce, const bool bGravitic );

	// StopSpriteConstantForce��ֹͣ���鳣������
	//
	void 		StopSpriteConstantForce();

	// SetSpriteForceScale�����������ž��鵱ǰ�ܵ�����
	// ���� fScale������ֵ
	//
	void 		SetSpriteForceScale( const float fScale );

	// SetSpriteAtRest����ͣ/��������ĸ�����������
	// ���� bRest��true ��ͣ false ����
	//
	void 		SetSpriteAtRest( const bool bRest );

	// GetSpriteAtRest����ȡ���鵱ǰ�Ƿ�����ͣ��
	// ����ֵ��true ��ͣ�� false ����
	//
	bool 		GetSpriteAtRest( );

	// SetSpriteFriction�����þ���Ħ����
	// ���� fFriction��Ħ������С
	//
	void 		SetSpriteFriction( const float fFriction );

	// SetSpriteRestitution�����þ��鵯��
	// ���� fRestitution������ֵ��С
	//
	void 		SetSpriteRestitution( const float fRestitution );

	// SetSpriteMass�����þ�������
	// ���� fMass��������С
	//
	void 		SetSpriteMass( const float fMass );

	// GetSpriteMass����ȡ��������
	// ����ֵ ��������С
	//
	float 		GetSpriteMass();

	// SetSpriteAutoMassInertia���������߹رվ������
	// ���� bStatus��true ���� false �ر�
	//
	void 		SetSpriteAutoMassInertia( const bool bStatus );

	// SetSpriteInertialMoment�����þ�����Դ�С
	// ���� fInert�����Դ�С
	//
	void 		SetSpriteInertialMoment( const float fInert );

	// SetSpriteDamping�����þ���˥��ֵ
	// ���� fDamp��˥��ֵ��С
	//
	void 		SetSpriteDamping( const float fDamp );

	// SetSpriteImmovable�����þ����Ƿ񲻿��ƶ�
	// ���� bImmovable��true �������ƶ� false �����ƶ�
	//
	void 		SetSpriteImmovable( const bool bImmovable );

	// GetSpriteImmovable����ȡ���鵱ǰ�Ƿ񲻿����ƶ�
	// ����ֵ��true �������ƶ� false �����ƶ�
	//
	bool 		GetSpriteImmovable();

	// SetSpriteLinearVelocity�����þ����ƶ��ٶ�
	// ���� fVelX��X�����ٶ�
	// ���� fVelY��Y�����ٶ�
	//
	void 		SetSpriteLinearVelocity( const float fVelX, const float fVelY );

	// SetSpriteLinearVelocityX�����þ���X�����ƶ��ٶ�
	// ���� fVelX��X�����ٶ�
	//
	void 		SetSpriteLinearVelocityX( const float fVelX );

	// SetSpriteLinearVelocityY�����þ���Y�����ƶ��ٶ�
	// ���� fVelY��Y�����ٶ�
	//
	void 		SetSpriteLinearVelocityY( const float fVelY );

	// SetSpriteLinearVelocityPolar�����Ƕȳ������þ����ƶ��ٶ�
	// ���� fSpeed���ƶ��ٶ�
	// ���� fPolar���Ƕȳ���
	//
	void 		SetSpriteLinearVelocityPolar( const float fSpeed, const float fPolar );

	// SetSpriteAngularVelocity�����þ���Ƕ���ת�ٶ�
	// ���� fAngular���Ƕ���ת�ٶ�
	//
	void 		SetSpriteAngularVelocity( const float fAngular );

	// SetSpriteMinLinearVelocity�����þ�����С�ٶ�
	// ���� fMin����С�ٶ�ֵ
	//
	void 		SetSpriteMinLinearVelocity( const float fMin );

	// SetSpriteMaxLinearVelocity�����þ�������ٶ�
	// ���� fMax������ٶ�ֵ
	//
	void 		SetSpriteMaxLinearVelocity( const float fMax );

	// SetSpriteMinAngularVelocity�����þ�����С���ٶ�
	// ���� fMin����С���ٶ�
	//
	void 		SetSpriteMinAngularVelocity( const float fMin );

	// SetSpriteMaxAngularVelocity�����þ��������ٶ�
	// ���� fMax�������ٶ�
	//
	void 		SetSpriteMaxAngularVelocity( const float fMax );

	// GetSpriteLinearVelocityX����ȡ����X�����ٶ�
	// ����ֵ��X�����ٶ�
	//
	float 		GetSpriteLinearVelocityX();

	// GetSpriteLinearVelocityY����ȡ����Y�����ٶ�
	// ����ֵ��Y�����ٶ�
	//
	float 		GetSpriteLinearVelocityY();


	// SpriteMountToSprite����һ������󶨵���һ�������ϣ���ʱ�ĳ�Ϊ��һ�������һ���֣��������˶���
	// ���� szDstName�����ذ󶨵�ĸ�徫������
	// ���� fOffSetX����ƫ��X
	// ���� fOffsetY����ƫ��Y
	// ����ֵ������һ����ID
	//
	int			SpriteMountToSprite( const char *szDstName, const float fOffSetX, const float fOffsetY );

	// SpriteMountToSpriteLinkPoint����һ������󶨵���һ�������ϣ���λ��Ϊָ�������ӵ㣬��ʱ�ĳ�Ϊ��һ�������һ���֣��������˶���
	// ���� szDstName�����ذ󶨵�ĸ�徫������
	// ���� iPointId�����ӵ����
	// ����ֵ������һ����ID
	//
	int			SpriteMountToSpriteLinkPoint( const char *szDstName, const int iPointId );

	// SetSpriteMountRotation�����þ���İ󶨳��򣬼������ĸ��ĳ���
	// ���� fRot���Ƕȳ���0 - 360
	//
	void		SetSpriteMountRotation( const float fRot );

	// GetSpriteMountRotation����ȡ����İ󶨳��򣬼������ĸ��ĳ���
	// ����ֵ���Ƕȳ���
	//
	float		GetSpriteMountRotation();

	// SetSpriteAutoMountRotation�����þ����֮���Զ���ת
	// ���� fRot����ת�ٶ�
	//
	void		SetSpriteAutoMountRotation( const float fRot );

	// GetSpriteAutoMountRotation����ȡ�����֮����Զ���תֵ
	// ����ֵ����ת�ٶ�
	//
	float		GetSpriteAutoMountRotation();

	// SetSpriteMountForce��������һ������ʱ�����ӵ�������
	// ���� fFroce��������
	//
	void		SetSpriteMountForce( const float fForce );

	// SetSpriteMountTrackRotation���󶨵ľ����Ƿ����ĸ����ת
	// ���� bTrackRotation��true ���� false ������
	//
	void		SetSpriteMountTrackRotation( const bool bTrackRotation );

	// SetSpriteMountOwned��ĸ�屻ɾ����ʱ�򣬰󶨵ľ����Ƿ�Ҳ���ű�ɾ��
	// ���� bMountOwned��true ���� false ������
	//
	void		SetSpriteMountOwned( const bool bMountOwned );

	// SetSpriteMountInheritAttributes���󶨵�ʱ���Ƿ�̳�ĸ�������
	// ���� bInherAttr��true �̳� false ���̳�
	//
	void		SetSpriteMountInheritAttributes( const bool bInherAttr );

	// SpriteDismount�����Ѿ��󶨵ľ�����н��
	//
	void		SpriteDismount();

	// GetSpriteIsMounted���жϾ����Ƿ������һ��������
	// ����ֵ��true �� false ����
	//
	bool		GetSpriteIsMounted();

	// GetSpriteMountedParent����ȡ�󶨵�ĸ�徫�������
	// ����ֵ��ĸ�徫�����֣����δ�󶨣��򷵻ؿ��ַ���
	//
	const char*	GetSpriteMountedParent();


	// SetSpriteColorRed�����ľ�����ʾ��ɫ�еĺ�ɫ��Ĭ�Ͼ���ĺ���������ɫ��ֵ��Ϊ255���޸�����һ����Ըı�����ɫ
	// ���� iCol����ɫ��Χ 0 - 255
	//
	void		SetSpriteColorRed( const int iCol );

	// SetSpriteColorGreen�����ľ�����ʾ��ɫ�е���ɫ��Ĭ�Ͼ���ĺ���������ɫ��ֵ��Ϊ255���޸�����һ����Ըı�����ɫ
	// ���� iCol����ɫ��Χ 0 - 255
	//
	void		SetSpriteColorGreen( const int iCol );

	// SetSpriteColorBlue�����ľ�����ʾ��ɫ�е���ɫ��Ĭ�Ͼ���ĺ���������ɫ��ֵ��Ϊ255���޸�����һ����Ըı�����ɫ
	// ���� iCol����ɫ��Χ 0 - 255
	//
	void		SetSpriteColorBlue( const int iCol );

	// SetSpriteColorAlpha�����þ���͸����
	// ���� iCol��͸���ȣ�ֵ0 - 255������ȫ͸������ȫ��͸��
	//
	void		SetSpriteColorAlpha( const int iCol );

	// GetSpriteColorRed����ȡ������ʾ��ɫ�еĺ�ɫֵ
	// ����ֵ����ɫֵ
	//
	int			GetSpriteColorRed();

	// GetSpriteColorGreen����ȡ������ʾ��ɫ�е���ɫֵ
	// ����ֵ����ɫֵ
	//
	int			GetSpriteColorGreen();

	// GetSpriteColorBlue����ȡ������ʾ��ɫ�е���ɫֵ
	// ����ֵ����ɫֵ
	//
	int			GetSpriteColorBlue();

	// GetSpriteColorAlpha����ȡ����͸����
	// ����ֵ��͸����
	//
	int			GetSpriteColorAlpha();
};
//////////////////////////////////////////////////////////////////////////////
//
// �ࣺCStaticSprite
// ��̬����(��̬ͼƬ��ʾ)����CSprite�������̳��������Ȼ�����˼������ƾ���ͼƬ��ʾ�ĺ���
// 
class CStaticSprite : public CSprite
{
public:
	CStaticSprite( const char *szName );
	CStaticSprite( const char *szName, const char *szCloneName );
	~CStaticSprite();

	// SetStaticSpriteImage������/���ľ�̬�������ʾͼƬ
	// ���� szImageName��ͼƬ����
	// ���� iFrame����ͼƬ����ʾ֡����Ϊ�༭��Ԥ��ͼ����ʾ��1/N����ΧΪ 0 �� N - 1
	//
	void		SetStaticSpriteImage( const char *szImageName, const int iFrame );

	// SetStaticSpriteFrame�����þ�̬���鵱ǰͼƬ����ʾ֡��
	// ���� iFrame����ͼƬ����ʾ֡����Ϊ�༭��Ԥ��ͼ����ʾ��1/N����ΧΪ 0 �� N - 1
	//
	void		SetStaticSpriteFrame( const int iFrame );
	//

	// GetStaticSpriteImage����ȡ���鵱ǰ��ʾ��ͼƬ����
	// ����ֵ��ͼƬ����
	//
	const char* GetStaticSpriteImage();

	// GetStaticSpriteFrame����ȡ���鵱ǰ��ʾ��ͼƬ֡��
	// ����ֵ��֡��
	//
	int			GetStaticSpriteFrame();
};
//////////////////////////////////////////////////////////////////////////////
//
// �ࣺCAnimateSprite
// ��̬����(��ͼƬ����)����CSprite�������̳��������Ȼ�����˼�������ͼƬ�����ĺ���
//
class CAnimateSprite : public CSprite
{
public:
	CAnimateSprite( const char *szName );
	CAnimateSprite( const char *szName, const char *szCloneName );
	~CAnimateSprite();

	// SetAnimateSpriteFrame�����ö�̬����Ķ���֡��
	// ���� iFrame������֡��
	//
	void		SetAnimateSpriteFrame( const int iFrame );

	// GetAnimateSpriteAnimationName����ȡ��̬���鵱ǰ��������
	// ����ֵ����������
	//
	const char* GetAnimateSpriteAnimationName();

	// GetAnimateSpriteAnimationTime����ȡ�������鵱ǰ����ʱ�䳤��
	// ����ֵ�����ȣ���λ��
	//
	float		GetAnimateSpriteAnimationTime();

	// IsAnimateSpriteAnimationFinished���ж϶�̬���鵱ǰ�����Ƿ񲥷���ϣ�ֻ��Է�ѭ����������
	// ����ֵ��true ��� false δ���
	//
	bool		IsAnimateSpriteAnimationFinished();

	// AnimateSpritePlayAnimation���������鲥�Ŷ���
	// ���� szAnim����������
	// ���� bRestore��������Ϻ��Ƿ�ָ���ǰ����
	// ����ֵ���Ƿ񲥷ųɹ�
	//
	bool		AnimateSpritePlayAnimation( const char *szAnim, const bool bRestore );
};
//////////////////////////////////////////////////////////////////////////////
//
// �ࣺCTextSprite
// ���־��飬�����ھ����е�һ�֡������÷����ڵ�ͼ��ڷ�һ�������֡����壬�������
// Ȼ���ڴ����ﶨ��һ�����־���Ķ���ʵ��������������Ϊ���캯���Ĳ�����Ȼ����ö�Ӧ�ĳ�Ա��������������ʾ����
//
class CTextSprite : public CSprite
{
public:
	CTextSprite( const char *szName );
	CTextSprite( const char *szName, const char *szCloneName );
	~CTextSprite();


	// SetTextValue�����־�����ʾĳ����ֵ
	// ���� iValue��Ҫ��ʾ����ֵ
	//
	void		SetTextValue( int iValue );

	// SetTextValueFloat�����־�����ʾĳ��������ֵ
	// ���� fValue��Ҫ��ʾ����ֵ
	//
	void		SetTextValueFloat( float fValue );

	// SetTextString�����־�����ʾĳ���ַ�������
	// ���� szStr��Ҫ��ʾ���ַ���
	//
	void		SetTextString( const char *szStr );

	// SetTextChar�����־�����ʾĳ���ַ�
	// ���� szChar��Ҫ��ʾ���ַ�
	//
	void		SetTextChar( char szChar );
};
/////////////////////////////////////////////////////////////////////////////
//
// �ࣺCEffect
// ��Ч���飬���ھ����е�һ�֡��÷������־���һ�������ڵ�ͼ��ڷ�һ����Ч��Ϊģ�壬������
// Ȼ���ڴ����ﶨ��һ����Ч����Ķ���ʵ������ʹ��
class CEffect : public CSprite
{
	char		m_szCloneName[MAX_NAME_LEN];		// �ڵ�ͼ��Ԥ�Ȱڷźõ�������¡����Ч����
	float		m_fTime;							// ��ѭ����Ч������ʱ����ѭ����Ч��ѭ��ʱ��
public:
	
	// ���캯�� 
	// ���� szCloneName����ͼ��ڷźõ���Ч����
	// ���� szMyName���µ���Ч���֡�ע�⣺�����ѭ����Ч����ô����һ��ѭ����Ч�Ͷ���һ������ʵ�����ò�ͬ������
	//                �������һ��ͬ����ѭ����Ч�����Ŷ�Σ���ɾ����ʱ�������⡣��ѭ����Ч�������һ��ʵ����β���
	// ���� fTime����ѭ����Ч������ʱ����ѭ����Ч��ѭ��ʱ��
	//
	CEffect( const char *szCloneName, const char *szMyName, const float fTime );
	~CEffect();

	// GetCloneName����ȡ������¡����Ч����
	// 
	const char*	GetCloneName();

	// GetTime��������Чѭ��ʱ����������ʱ��
	//
	float		GetTime();

	// PlayEffect������һ����ѭ������Ч���������֮�����Ч�Զ�ɾ��
	// ���ŷ�ѭ����Ч��ʱ�򣬿���ʹ��һ��CEffect�Ķ���ʵ�������Ŷ����Ч
	// ���� fPosX�����ŵ�X����
	// ���� fPosY�����ŵ�Y����
	// ���� fRotation�����ŵĽǶȳ���
	//
	void		PlayEffect( const float fPosX, const float fPosY, const float fRotation);

	// PlayLoopEffect������һ��ѭ����Ч������Ҫ����Ч��ʱ����Ҫ�Լ�����API����ɾ��
	// ���� fPosX�����ŵ�X����
	// ���� fPosY�����ŵ�Y����
	// ���� fRotation�����ŵĽǶȳ���
	//
	void		PlayLoopEffect( const float fPosX, const float fPosY, const float fRotation);

	// DeleteEffect��ɾ��һ�����ڲ��ŵ���Ч��ֻ��ѭ����Ч����Ҫ�ֶ�ɾ��
	//
	void		DeleteEffect(); 
};
/////////////////////////////////////////////////////////////////////////////
//
// �ࣺCSound
// �����������࣬����һ������ʵ�������ò��ź�������ʵ�������Ĳ���
// 
class CSound
{
private:
	char		m_szName[MAX_NAME_LEN];	// ������
	int			m_iSoundId;				// ���沥��������ʱ�򣬷��ص�ID
	bool		m_bLoop;				// bLoop : �Ƿ�ѭ�����š����Ϊѭ����Ч������CSoundʵ��������ʱ���Զ�����StopSoundֹͣ�������Ĳ���
	float		m_fVolume;				// ������С��0-1��1Ϊ�����ļ���ԭ����С

public:

	// ���캯��
	// ���� szName��������·�������ƣ�����ֵ���ڱ༭������Դ -> �����������鿴����Ŀ���������Դ�����������Ǹ�·��ֵ��д����
	// ���� bLoop���Ƿ�ѭ�����š������ѭ�����ŵ���������Ҫ�ֶ�����APIֹͣ����
	// ���� fVolume��������С��0-1��1Ϊ�����ļ���ԭ����С
	//
	CSound( const char *szName, const bool bLoop, const float fVolume );
	~CSound();

	// GetName����ȡ��������
	//
	const char*	GetName();

	// PlaySound�����Ÿ�����
	//
	void		PlaySound();

	// StopSound��ֹͣ�������Ĳ���
	// ��ѭ���Ĳ�����֮���Զ�ֹͣ������һ�㲻��Ҫ���ô˺�����ֻ��ѭ������������Ҫ���á�����ѭ����Ч��������������Ҳ���Զ����ô˺���
	//
	void		StopSound();
	
	// StopAllSound��ֹͣ������������
	// ��̬�����������Դ��ַ�ʽ���ã�CSound::StopAllSound����ֹͣ��Ϸ���������ڲ��ŵ�����
	//
	static void	StopAllSound();
};

////////////////////////////////////////////////////////////////////////////////
//
// �ࣺCSystem
// ϵͳ��ع��ܵ���. �������÷��� CSystem::������();
//
class CSystem
{
public:
	CSystem();
	~CSystem();

	// OnMouseMove������ƶ��󽫱����õĺ��������ڴ˺�������(Main.cpp)�����Լ�����Ӧ����
	// ���� fMouseX, fMouseY��Ϊ��굱ǰ����
	//
	static void		OnMouseMove( const float fMouseX, const float fMouseY );

	// OnMouseClick����갴�º󽫱����õĺ��������ڴ˺�������(Main.cpp)�����Լ�����Ӧ����
	// ���� iMouseType����갴��ֵ���� enum MouseTypes ����
	// ���� fMouseX, fMouseY��Ϊ��굱ǰ����
	//
	static void		OnMouseClick( const int iMouseType, const float fMouseX, const float fMouseY );

	// OnMouseUp����갴�º󽫱����õĺ��������ڴ˺�������(Main.cpp)�����Լ�����Ӧ����
	// ���� iMouseType����갴��ֵ���� enum MouseTypes ����
	// ���� fMouseX, fMouseY��Ϊ��굱ǰ����
	//
	static void		OnMouseUp( const int iMouseType, const float fMouseX, const float fMouseY );

	// OnKeyDown�����̱����º󽫱����õĺ��������ڴ˺�������(Main.cpp)�����Լ�����Ӧ����
	// ���� iKey�������µļ���ֵ�� enum KeyCodes �궨��
	// ���� bAltPress, bShiftPress��bCtrlPress�������ϵĹ��ܼ�Alt��Ctrl��Shift��ǰ�Ƿ�Ҳ���ڰ���״̬
	//
	static void		OnKeyDown( const int iKey, const bool bAltPress, const bool bShiftPress, const bool bCtrlPress );

	// OnKeyUp�����̰�������󽫱����õĺ��������ڴ˺�������(Main.cpp)�����Լ�����Ӧ����
	// ���� iKey������ļ���ֵ�� enum KeyCodes �궨��
	//
	static void		OnKeyUp( const int iKey );

	// OnSpriteColSprite�������뾫����ײ�󽫱����õĺ��������ڴ˺�������(Main.cpp)�����Լ�����Ӧ����
	// ����֮��Ҫ������ײ�������ڱ༭�����ߴ��������þ��鷢�ͼ�������ײ
	// ���� szSrcName��������ײ�ľ�������
	// ���� szTarName������ײ�ľ�������
	//
	static void		OnSpriteColSprite( const char *szSrcName, const char *szTarName );

	// OnSpriteColWorldLimit������������߽���ײ�󽫱����õĺ��������ڴ˺�������(Main.cpp)�����Լ�����Ӧ����
	// ����֮��Ҫ������ײ�������ڱ༭�����ߴ��������þ��������߽�����
	// ���� szName����ײ���߽�ľ�������
	// ���� iColSide����ײ���ı߽� 0 ��ߣ�1 �ұߣ�2 �ϱߣ�3 �±�
	//
	static void		OnSpriteColWorldLimit( const char *szName, const int iColSide );

	// MakeSpriteName: ��ǰ����ַ����������������ϳ�һ���ַ�����
	// ���� szPrev��һ���ǿ��ַ���������ܳ���20��Ӣ���ַ�������ǰ����ַ���
	// ���� iId��һ������
	// ����ֵ������һ���ַ��������紫��("xxx", 2),�򷵻�"xxx2"
	//
	static char* MakeSpriteName(const char *szPrev, const int iId);

	// CursorOff���ر���겻��ʾ����API���ص�������Windows����꣬���ǵ��ÿ�������API dCursorOn��������꽫һֱ����ʾ
	//
	static void		CursorOff();

	// CursorOn�����������ʾ����API dCursorOff�رյ�������¿�����ʾ
	//
	static void		CursorOn();

	// IsCursorOn����ǰ����ǿ������ǹرա���Ӧ������API dCursorOff��dCursorOn�������߹رյĲ���
	// ����ֵ��trueΪ����״̬��falseΪ�ر�״̬
	//
	static bool		IsCursorOn();

	// ShowCursor������/��ʾ��ꡣ��APIֻ�����ر����򴰿��ڵ���꣬�ƶ����������ʱ����껹�ǻ���ʾ
	// ���� bShow��true Ϊ��ʾ��false Ϊ����
	//
	static void		ShowCursor( const bool bShow );

	// IsShowCursor����ǰ�������ʾ�������ء���Ӧ������API ShowCursor���ػ�����ʾ�Ĳ���
	// ����ֵ��trueΪ����״̬��falseΪ�ر�״̬
	//
	static bool		IsShowCursor();

	// SetWindowTitle�����ô�������/����
	// ���� szTitle���ǿ��ַ���
	//
	static void		SetWindowTitle( const char *szTitle );

	// ResizeWindow�����Ĵ��ڴ�С
	// ���� iWidth����ȣ�����0С�ڵ���1920
	// ���� iHeight���߶ȣ�����0С�ڵ���1080
	//
	static void		ResizeWindow(int iWidth, int iHeight);

	// GetHwnd����ȡ���ھ��
	// ����ֵ�����ھ��
	//
	static void		*GetHwnd();

	// Random����ȡһ�����ڵ���0�������
	// ����ֵ��int����Χ0 - 2147483648
	//
	static int		Random();

	// RandomRange����ȡһ��λ�ڲ���1������2֮��������
	// ����ֵ��int����ΧiMin - iMax
	// ���� iMin��С��iMax������
	// ���� iMax������iMin������
	//
	static int		RandomRange( const int iMin, const int iMax );

	// CalLineRotation�������������ߵ�ֱ�ߵ���ת�Ƕ�
	// ����ֵ���Ƕȣ���Χ0 - 360
	// ���� fStartX����ʼ����X
	// ���� fStartY����ʼ����Y
	// ���� fEndX���յ�����X
	// ���� fEndY���յ�����Y
	//
	static float	CalLineRotation( const float fStartX, const float fStartY, const float fEndX, const float fEndY );

	// RotationToVectorX������ĳ���Ƕȶ�Ӧ��ֱ��������X����
	// ���� fRotation���Ƕȣ���Χ0 - 360
	// ����ֵ ����ֱ��������Xֵ
	//
	static float	RotationToVectorX( const float fRotation );

	// RotationToVectorY������ĳ���Ƕȶ�Ӧ��ֱ��������Y����
	// ���� fRotation���Ƕȣ���Χ0 - 360
	// ����ֵ ����ֱ��������Yֵ
	//
	static float	RotationToVectorY( const float fRotation );

	// DrawLine��������֮�仭һ����
	// ���� fStartX����ʼ����X
	// ���� fStartY����ʼ����Y
	// ���� fEndX���յ�����X
	// ���� fEndY���յ�����Y
	// ���� fLineWidth���ߵĴ�ϸ�����ڵ���1
	// ���� iLayer���������ڵĲ㣬��༭�������õľ���Ĳ㼶��ͬһ�������Χ0 - 31��
	// ���� iRed, iGreen, iBlue : ��������ԭɫ����ɫֵ����Χ 0 - 255
	// ���� iAlpha���ߵ�͸���ȣ���Χ0-255. 0Ϊȫ͸����255Ϊ��͸��
	//
	static void		DrawLine( const float fStartX, const float fStartY, const float fEndX, const float fEndY, const float fLineWidth, const int iLayer, const int iRed, const int iGreen, const int iBlue, const int iAlpha );

	// DrawTriangle����һ��������
	// ���� fX1,fX2,fX3�����������������X����
	// ���� fY1,fY2,fY3�����������������Y����
	// ���� fLineWidth���ߵĴ�ϸ�����ڵ���1
	// ���� iLayer�������������ڵĲ㣬��༭�������õľ���Ĳ㼶��ͬһ�������Χ0 - 31��
	// ���� iRed, iGreen, iBlue : ��������ԭɫ����ɫֵ����Χ 0 - 255
	// ���� iAlpha�������ε�͸���ȣ���Χ0-255. 0Ϊȫ͸����255Ϊ��͸��
	//
	static void		DrawTriangle( const float fX1, const float fY1, const float fX2, const float fY2, const float fX3, const float fY3, const float fLineWidth, const int iLayer, const int iRed, const int iGreen, const int iBlue, const int iAlpha );

	// DrawRect����һ������
	// ���� fUpperX�����Ͻ�����X
	// ���� fUpperY�����Ͻ�����Y
	// ���� fLowerX�����½�����X
	// ���� fLowerY�����½�����Y
	// ���� fLineWidth���ߵĴ�ϸ�����ڵ���1
	// ���� iLayer���þ������ڵĲ㣬��༭�������õľ���Ĳ㼶��ͬһ�������Χ0 - 31��
	// ���� iRed, iGreen, iBlue : ��������ԭɫ����ɫֵ����Χ 0 - 255
	// ���� iAlpha�����ε�͸���ȣ���Χ0-255. 0Ϊȫ͸����255Ϊ��͸��
	//
	static void		DrawRect( const float fUpperX, const float fUpperY, const float fLowerX, const float fLowerY, const float fLineWidth, const int iLayer, const int iRed, const int iGreen, const int iBlue, const int iAlpha );

	// DrawCircle����һ��Բ
	// ���� fCenterX��Բ������X
	// ���� fCenterY��Բ������Y
	// ���� fRadius��Բ�İ뾶
	// ���� iSegment��Բ����������Χ4-72. ���紫��6�����õ�һ��6���Σ�����Խ��ԽԲ�������ǻ�ͼЧ��Խ��
	// ���� fLineWidth���ߵĴ�ϸ�����ڵ���1
	// ���� iLayer����Բ���ڵĲ㣬��༭�������õľ���Ĳ㼶��ͬһ�������Χ0 - 31��
	// ���� iRed, iGreen, iBlue : ��������ԭɫ����ɫֵ����Χ 0 - 255
	// ���� iAlpha��Բ��͸���ȣ���Χ0-255. 0Ϊȫ͸����255Ϊ��͸��
	//
	static void		DrawCircle( const float fCenterX, const float fCenterY, const float fRadius, const int iSegment, const float fLineWidth, const int iLayer, const int iRed, const int iGreen, const int iBlue, const int iAlpha );

	// GetScreenLeft����ȡ����߽�֮���X����
	// ����ֵ����߽�X����
	//
	static float	GetScreenLeft();

	// GetScreenTop����ȡ����߽�֮�ϱ�Y����
	// ����ֵ���ϱ߽�Y����
	//
	static float	GetScreenTop();

	// GetScreenRight����ȡ����߽�֮�ұ�X����
	// ����ֵ���ұ߽�X����
	//
	static float	GetScreenRight();

	// GetScreenBottom����ȡ����߽�֮�±�Y����
	// ����ֵ���±߽�Y����
	//
	static float	GetScreenBottom();

	// LoadMap�������³�����ע�⣬�����³�����ʱ�򣬾ɳ��������о��鶼��������ɾ���������������ڳ����д��������Ƴ����ľ��鶼�����ڵ��ñ�API֮ǰ��ɾ����
	// ���� szName���������֡����½����������ʱ��ȡ�����֣������Сд�ĺ�׺ -- xxx.t2d�����ô�·��
	//
	static void		LoadMap( const char *szName );

	//////////////////////////////////////////////////////////////////////////////////////////
	//
	// ����APIΪϵͳAPI�������Լ�����
	//
	//////////////////////////////////////////////////////////////////////////////////////////

	// GetTimeDelta����ȡ���ε��ñ�����֮���ʱ���
	// ����ֵ��float����λ ��
	//
	static float	GetTimeDelta();
	// EngineMainLoop��������ѭ�������������Լ�����
	//
	static bool		EngineMainLoop();
	// InitGameEngine����ʼ�����棬�����Լ�����
	//
	static bool		InitGameEngine( HINSTANCE hInstance, LPSTR lpCmdLine );
	static bool		InitGameEngineEx( HINSTANCE hInstance, LPSTR lpCmdLine );
	// ShutdownGameEngine���ر����棬�����Լ�����
	//
	static void		ShutdownGameEngine();
};

//
#endif // _COMMON_API_H_