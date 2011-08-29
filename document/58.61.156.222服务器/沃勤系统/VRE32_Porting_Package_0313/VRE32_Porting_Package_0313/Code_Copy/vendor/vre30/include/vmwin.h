#ifndef VMWIN_H_
#define VMWIN_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "vmsys.h"

#define GET_PARAM_LOW(x) (x & 0x00ffff)
#define GET_PARAM_HI(x) (x >> 16)
#define MAKE_PARAM(hi, low) (hi << 16 + low)
#define INSIDE_RECT(px, py, x, y, width, height) ((px >= x) && (px < x + width) && (py >= y) && (py < y + height))

#define COMP_SHAPE		1
#define COMP_LISTBOX	2
#define COMP_BUTTON		3
#define COMP_IMAGE		4
#define COMP_LABEL		5
#define COMP_BROWSER	6
#define COMP_GAUGE		7
#define COMP_MENU		8
#define COMP_EDITBOX    9
#define COMP_CHECKBOX   10

#define ALIGN_LEFT		1
#define ALIGN_RIGHT		2
#define ALIGN_CENTER	3
	
struct component_base_t {
	VMINT type;
	VMINT id;
	VMINT x;
	VMINT y;
	VMINT z;
	VMINT width;
	VMINT height;
	VMINT color;
	VMINT bgcolor;
	VMINT bgimage;
	VMINT visible;
	void* extra;
	struct window_t* parent;
	struct component_base_t* next;
};

struct button_t {
	VMWCHAR label[50];
};

/**
 * �б����Ŀ��
 */
struct list_item_t {
	VMINT iconid;				/* ͼ���ţ���Ϊ-1��ʾû��ͼ�ꡣ	*/
	VMINT value;				/* ��Ŀ��ֵ��						*/
	VMWCHAR label[50];			/* ��ʾ��ǩ��						*/
};

struct listbox_t {
	VMINT scr_bar_color;
	VMINT scr_bg_color;
	VMINT border_color;
	VMINT bgcolor;
	VMINT text_color;
	VMINT sel_bg_color;
	VMINT sel_bg_image;
	VMINT sel_text_color;
	VMINT has_border;
	VMINT selidx;
	VMINT nitem;
	VMINT icon_width;
	VMINT icon_height;
	struct list_item_t* items;
};

struct label_t {
	VMINT align;
	VMWCHAR text[255];
};

/*
 * �����б�������
 */
#define WS_HAS_TITLE	1

/*
 * �������������
 */
#define WS_HAS_SKBAR	2

struct window_t 
{
	VMINT id;									// ���ڵı�š�
	VMINT x;									// ���ڵ�X���ꡣ
	VMINT y;									// ���ڵ�Y���ꡣ
	VMINT width;								// ���ڵĿ�ȡ�
	VMINT height;								// ���ڵĸ߶ȡ�
	VMWCHAR title[50];							// ���ڵı��⡣
	VMINT style;								// ���ڵķ��
	struct window_t* parent_window;				// �������ڹ����ĸ��״��ڡ�
	struct component_base_t* left_softkey;		// �������
	struct component_base_t* right_softkey;		// �������
	struct component_base_t* comp_root;			// �����������ڵ�������ڵ㡣
	struct component_base_t* focus_component;	// ��ǰ���ھ۽��������
	struct component_base_t* popup_menu;		// ���ڵ����˵�����
	VMINT (*winproc)(int message, int param);	// �û�ע��Ļص�������
};

struct image_t {
	VMINT resid;
};

struct rect_t {
	VMINT left;
	VMINT top;
	VMINT width;
	VMINT height;
};

/**
 * �������Ŀ��
 */
struct browser_item_t {
	VMINT id;				/* ��Ŀ���	*/
	VMINT type;				/* ��Ŀ����	*/
	VMWCHAR label[255];		/* ��Ŀ��ʾ������ */
	VMCHAR herf[255];		/* �����ӵ�ַ */
	VMINT selectable;		/* �ܷ�ѡ�� */
};

/**
 * ����������
 */
struct browser_t {
	VMINT nitem;						/* ��Ŀ���� */
	VMINT point;						/* ��ǰָ����Ŀ���*/		
	VMINT sel_item;						/* ��ѡ�е���Ŀ��� */
	VMINT text_color;					/* ��Ŀ������ɫ */
	VMINT sel_bg_color;					/* ѡ����Ŀ������ɫ */
	VMINT scr_bar_color;				/* ��������ɫ */
	VMINT scr_bg_color;					/* ����������ɫ */
	VMINT win_bagin_po;					/* ��ʾ���ڵ���ʼ��Ŀ��� */
	VMINT win_row_total;				/* ��ʾ���ڵ������� */
	struct browser_item_t * bitems;		/* �������Ŀ���� */
};

/**
 * ��������
 */
struct gauge_t {
	VMINT percent;						/* ���ȡ�			*/
};

/*
 * ������Ϣ��
 */
struct download_info_t{
	char herf[255];
	short label[255];
};

/*
 * ����ϵͳ�����⡣
 */
struct window_scheme_t {
	VMINT win_bgcolor;					/* ���ڿͻ����ı�����ɫ��*/
	VMINT win_sys_bgcolor;				/* ����ϵͳ���ı�����ɫ��*/
	VMINT win_text_color;				/* ���ڵ�������ɫ��*/
	VMINT win_sktext_color;				/* �����������������ɫ��*/
	VMINT win_title_height;				/* ���ڱ������ĸ߶ȡ�*/
	VMINT win_skbar_height;				/* ����״̬���ĸ߶ȡ�*/
	VMINT listbox_bgcolor;				/* �б��ı�����ɫ��*/
	VMINT listbox_text_color;			/* �б���������ɫ��*/
	VMINT listbox_sel_bgcolor;			/* �б��ѡ����Ŀ�ı�����ɫ��*/
	VMINT listbox_scrbar_box_color;		/* �б��Ĺ�������ɫ��*/
	VMINT listbox_scrbar_bgcolor;		/* �б��������ı�����ɫ��*/
};

/*
 * �����˵��
 */
struct vm_menu_item_t {
	VMWCHAR label[50];								/* �˵������ƣ����ڲ˵�������ʾ���ַ���			*/
	VMINT value;									/* �˵����ֵ��Ӧ�ó���Ӧ���޸ĸ�ֵ��			*/
	VMINT visible;									/* �˵���˵����Ƿ�ɼ�������ò˵���ɼ� 
	                                                   ��ô�ò˵����µ��Ӳ˵�Ҳ���ɼ���				*/
	
	struct vm_second_level_menu_list_t *second_level_list;
};

/*
 * ����һ���˵��б�
 */
struct vm_menu_list_t {
	VMINT selidx;
	VMINT nitem;
	VMINT nsize;
	VMINT has_second_level;
	VMINT active_second_level;
	struct vm_menu_item_t *items;
};

/*
 * ���������˵��
 */
struct vm_second_level_menu_item_t {
	VMWCHAR label[50];
	VMINT value;
	VMINT visible;
};

/*
 * ���������˵��б�
 */
struct vm_second_level_menu_list_t {
	VMINT selidx;
	VMINT nsize;
	VMINT nitem;
	struct rect_t rect;
	struct vm_second_level_menu_item_t *items;
};

/*
 * �༭��
 */
struct editbox_t 
{
	VMUSHORT type;							/* �༭����������͡�	*/
	VMWCHAR text[255];						/* �༭������ݡ�		*/
	VMUSHORT canDrawCusor;					/* �Ƿ���Ҫ���α�ı�־ */
};

/*
 * ��ѡ��
 */
struct checkbox_t 
{
	VMINT select;							/* �Ƿ�ѡ���ˡ�		*/
};

/**
 * ��ť������Ϣ��param�ֶθ���ָ�򱻰��°�ť��ָ�롣
 */
#define VM_WM_BUTTON_CLICK		1

/**
 * �б��ѡ�������߰���OK����Ϣ�����ڲ����û�����б��ĳ��ѡ���¼���
 * param�ֶθ�����������б�����ָ�롣
 */
#define VM_WM_LISTBOX_CLICK		3

/**
 * ���̰�����Ϣ��param�ֶθ���������keycode��
 */
#define VM_WM_KEYDOWN			4

/**
 * �����ͷ���Ϣ��param�ֶθ���������keycode��
 */
#define VM_WM_KEYUP				5

/**
 * �ʰ�����Ϣ��param�ֶεĸ�λ2�ֽ�Ϊ����ĺ����꣬��λ2�ֽ�Ϊ����������ꡣ
 */
#define VM_WM_PEN_TAP			6

/**
 * ���ͷ���Ϣ��param�ֶεĸ�2�ֽ�Ϊ�ͷŵ�ĺ����꣬��λ2�ֽ�Ϊ�ͷŵ�������ꡣ
 */
#define VM_WM_PEN_RELEASE		7

/**
 * VRE���ڻ״̬����ʱ������VRE֮�ϵ�Ӧ�ó����ڿ�ִ��״̬��
 */
#define VM_WM_ACTIVATE			8

/**
 * VRE����ȥ��״̬����ʱ������VRE֮�ϵ�Ӧ�ó��������ͣ���е���Ļ���¡���Ƶ��
 * �ŵȶ������Ա��ֻ�ִ��ȥ������������������绰�������ŵȡ�
 */
#define VM_WM_INACTIVATE		9

/**
 * �����ػ���Ϣ����ʱ������ϵͳ�Ѿ��ѻ�Ծ�����ϵ����������ϣ�Ӧ�ó������
 * �������Ϣ�ڽ��������ӻ����Լ���ͼ�Ρ�
 */
#define VM_WM_PAINT				12

/**
 * ������������¡�
 */
#define VM_WM_LEFT_SOFTKEY_CLICK	10

/**
 * ������������¡�
 */
#define VM_WM_RIGHT_SOFTKEY_CLICK	11

/**
 * �б����Ŀ�ı���Ϣ��param���������˷�����Ϣ���б�����ָ�롣
 */
#define VM_WM_LISTBOX_CHANGED	13

/**
 * �����������������Ϣ��param����������download_info_t ����ָ�롣
 */
#define VM_WM_BROWSER_DOWNLOAD		16

/**
 * �˵���ѡ����Ϣ��param����������struct vm_menu_item_tָ�룬���Ǳ�ѡ��
 * �˵���Ŀ��ָ�롣
 */
#define VM_WM_MENU_SELECTED			18

/**
 * VREϵͳ�˳�ǰ�Ĵ�����Ϣ��
 */
#define	VM_WM_QUIT					20

/**
 * �������ڡ�
 *
 * @param id			���ڱ�ʶ�ţ�����Ψһ��ʶ���ڡ�
 * @param x				�������ϽǺ����ꡣ
 * @param y				�������Ͻ������ꡣ
 * @param width			���ڿ�ȡ�
 * @param height		���ڸ߶ȡ�
 * 
 * @return				���ش���ָ�룬�����������ʧ���򷵻�NULL��
 */
struct window_t* vm_create_window(VMINT id, VMINT x, VMINT y, VMINT width, VMINT height);

/**
 * ���ô��ڻ�����뽹��������������뽹�������ܹ��������еİ�����Ϣ��
 *
 * @param pwin			����ָ�롣
 * @param comp			Ҫ����������
 */
void vm_set_focus(struct window_t* pwin, struct component_base_t* comp);

/**
 * ���ô��������ǰ����ɫ��
 *
 * @param component		�����õ������
 * @param color			ǰ����ɫ��
 */
void vm_set_component_color(struct component_base_t* component, VMINT color);

/**
 * ���ô�������ı�����ɫ��
 *
 * @param component		�����õ������
 * @param color			������ɫ��
 */
void vm_set_component_bgcolor(struct component_base_t* component, VMINT color);

/**
 * ���ô�������ı���ͼ��
 *
 * @param component		�����õ������
 * @param image			����ͼ��
 */
void vm_set_component_bgimage(struct component_base_t* component, VMINT image);

/**
 * ������ť��
 *
 * @param pwin			��ť�����Ĵ���ָ�롣
 * @param id				�����ID
 * @param x				��ť���ϽǺ����ꡣ
 * @param y				��ť���Ͻ������ꡣ
 * @param width			��ť�Ŀ�ȡ�
 * @param height		��ť�ĸ߶ȡ�
 * @param label			��ť�����֡�
 *
 * @return				���ذ�ťָ�룬����NULL��ʾ������ťʧ�ܡ�
 */
struct component_base_t* vm_create_button(struct window_t* pwin, VMINT id, VMINT x, VMINT y,
	VMINT width, VMINT height, VMWSTR label);

/**
 * ����ͼ��ͼ����Ǵ����ϵ�һ����ֹͼ�󣬲��ܲ������롣
 *
 * @param pwin			ͼ������Ĵ���ָ�롣
 * @param id			ͼ���ʶ�š�
 * @param x				ͼ�����ϽǺ����ꡣ
 * @param y				ͼ�����Ͻ������ꡣ
 * @param width			ͼ���ȡ�
 * @param height		ͼ��߶ȡ�
 * @param resid			ͼ����ʹ�õ�ͼƬ��Դ��š�
 * 
 * @return				����ͼ��ָ�룬����NULL��ʾ����ͼ��ʧ�ܡ�
 */
struct component_base_t* vm_create_image(struct window_t* pwin, VMINT id, VMINT x, VMINT y,
	VMINT width, VMINT height, VMINT resid);

/**
 * ������ͼ�Σ�Ŀǰֻ֧�־���ɫ�飬�����ṩ�򵥵���ɫ������
 *
 * @param pwin			ͼ�ι�������ָ�롣
 * @param x				ͼ�����ϽǺ����ꡣ
 * @param y				ͼ�����Ͻ������ꡣ
 * @param width			ͼ�εĿ�ȡ�
 * @param height		ͼ�εĸ߶ȡ�
 * @param bgcolor		ͼ�εı�����ɫ��
 *
 * @return				����ͼ�ζ���ָ�룬����NULL��ʾ����ʧ�ܡ�
 */
struct component_base_t* vm_create_shape(struct window_t* pwin, VMINT x, VMINT y,
	VMINT width, VMINT height, VMINT bgcolor);

/**
 * �����б�򣬸��б��Ĭ�����б߿�ġ�
 *
 * @param pwin			�б������Ĵ���ָ�롣
 * @param id			�б���ʶ�š�
 * @param x				�б�����ϽǺ����ꡣ
 * @param y				�б�����Ͻ������ꡣ
 * @param width			�б���ȡ�
 * @param height		�б��߶ȡ�
 * @param nitem			�б���Ŀ�ĸ�����
 * @param items			�б���Ŀ������ָ�롣
 *
 * @return				�����б��ָ�룬����NULL��ʾ����ʧ�ܡ�
 */
struct component_base_t* vm_create_listbox(struct window_t* pwin, VMINT id, VMINT x, VMINT y,
	VMINT width, VMINT height, VMINT nitem, struct list_item_t* items);

/**
 * �����б���Ƿ���Ҫ�߿�
 *
 * @param component		�б�����
 * @param is_border		�Ƿ���Ҫ���ñ߿�TRUE�Ǳ�ʾ��Ҫ���ñ߿�ģ�FALSE���ʾ����Ҫ��
 */
void vm_set_listbox_border (struct component_base_t* component, VMINT is_border);

/**
 * �����б������ݡ�
 *
 * @param component		�б�����
 * @param items			�б���Ŀ��
 * @param nitems		�б���Ŀ������
 */
void vm_set_listbox_items(struct component_base_t* component, struct list_item_t* items, VMINT nitems);

/**
 * �趨�б���е�ѡ����Ŀ���б���е���Ŀ��Ŵ�0��ʼ�����һ����Ŀ�ı����n-1�����������ѡ��
 * ��Ŀ���������б���Ŀ����ϵͳ�����κβ�����
 *
 * @param component		�б�����
 * @param index			��ѡ�е���Ŀ��š�
 */
void vm_set_listbox_selidx(struct component_base_t* component, VMINT index);

/**
 * ����б��ѡ����Ŀ��������������Ŵ�0��ʼ������-1��ʾ��ǰû���κ���Ŀ��ѡ�С�
 *
 * @param component		�б�����ָ�롣
 *
 * @return				���ر�ѡ�е���Ŀ��ţ���Ŵ�0��ʼ������-1��ʾ�б��û��ѡ����Ŀ��
 */
VMINT vm_get_listbox_selidx(struct component_base_t* component);

/**
 * �����б���ICON�ĳ��Ϳ�
 *
 * @param component		ָ���б�������ָ�롣
 * @param width			ICONͼƬ�Ŀ�ȡ�
 * @param height		ICONͼƬ�ĸ߶ȡ�
 */
void vm_set_listbox_icon_size(struct component_base_t* component, 
	VMUINT8 width, VMUINT8 height);

/**
 * ������ǩ����ǩ�Ǵ����ϵ�һ�ξ�̬���֣�������ʾ��Ϣ��
 *
 * @param pwin			��ǩ��������ָ�롣
 * @param id			��ǩ��ʶ�š�
 * @param x				��ǩ���ϽǺ����ꡣ
 * @param y				��ǩ���Ͻ������ꡣ
 * @param width			��ǩ��ȡ�
 * @param height		��ǩ�߶ȡ�
 * @param text			��ǩ���֡�
 *
 * @return				���ر�ǩָ�룬����NULL��ʾ����ʧ�ܡ�
 */
struct component_base_t* vm_create_label(struct window_t* pwin, VMINT id, VMINT x, VMINT y,
	VMINT width, VMINT height, VMWSTR text);

/**
 * ���ñ�ǩ�Ķ����ʽ��
 *
 * @param component		��ǩָ��
 * @param align			���뷽ʽ
 */
void vm_set_label_alignment(struct component_base_t* component, VMINT align);

#define LISTBOX_TEXT_COLOR			1
#define LISTBOX_SELECT_TEXT_COLOR	2	
#define LISTBOX_SELECT_BG_COLOR		3
#define LISTBOX_SCROLLBAR_BG_COLOR	4
#define LISTBOX_SCROLLBAR_BOX_COLOR	5
#define LISTBOX_SELECT_BG_IMAGE		6

/**
 * �����б�����ɫ��
 *
 * @param listbox			�б��ָ�룬���ָ������������������κζ���������
 * @param where				������ɫ��λ�ã���LISTBOX�������塣
 * @param color				��ɫ��
 */
void vm_set_listbox_color(struct component_base_t* listbox, VMINT where, VMINT color);

/**
 * �رմ��ڣ������ڵ����������ᱻ�Զ�ɾ�������ڶ���Ҳ�ᱻ�Զ�ɾ����
 *
 * @param pwin			���رյĴ���ָ�롣
 */
void vm_close_window(struct window_t* pwin);

/**
 * ע�ᴰ�ڻص�������Ӧ�ó����ڴ������ں������ñ������Բ��񴰿��¼���
 *
 * @param pwin			Ҫ�����¼��Ĵ���ָ�롣
 * @param f				�����¼��ص�������
 *
 * @return				����0��ʾ�¼��Ѿ���Ӧ�ó���������Ҫϵͳ��������1��ʾ
 *						��Ҫϵͳ����Ҫ��������¼���
 */
void vm_reg_winproc(struct window_t* pwin, int (*f)(int message, int param));

/**
 * ���ô��ڵ��������
 *
 * @param pwin			����ָ�롣
 * @param is_left		����ΪTRUE��ʾ�������������������������
 * @param id			�������ť��ID��
 * @param label			������ı��⡣
 *
 * @return				�������ťָ�롣
 */
struct component_base_t* vm_set_window_softkey(struct window_t* pwin, VMINT is_left, 
	VMINT id, VMWSTR label);

/**
 * �Ѹ����Ĵ����趨Ϊ��Ծ���ڣ���VRE����ϵͳ�У���һʱ�̶�ֻ����һ����Ծ���ڣ���Ծ
 * �����ܹ��������еļ��̺ͱ����롣
 *
 * @param pwin			Ҫ����Ĵ��ڡ�
 */
void vm_active_window(struct window_t* pwin);

/**
 * ��ʼ��������ϵͳ���������������ʹ�ô�����ϵͳ֮ǰ���á�
 */
void vm_init_window_system(void);

/**
 * �رմ�����ϵͳ���������ֻ��VRE�ڲ�ʹ�ã������ڴ���ϵͳ֮�ϵ�Ӧ�ó�������������
 * ���ܻ����𲻿�Ԥ��ĺ����
 */
void vm_shutdown_window_system(void);

/**
 * �ڴ������ҵ�����ID�������
 *
 * @param pwin			����ָ�롣
 * @param id			�����ʶ�š�
 *
 * @return				�ҵ��򷵻����ָ�룬���򷵻�NULL��
 */
struct component_base_t* vm_find_component(struct window_t* pwin, VMINT id);

/**
 * ���ػ�����ʾ�����
 *
 * @param pwin			��������Ĵ���ָ�롣
 * @param pcomp			���ָ�롣
 * @param hide			��ΪTRUE�����������������ʾ�����
 */
void vm_hide_component(struct window_t* pwin, struct component_base_t* pcomp, VMINT hide);

/**
 * �Ѹ��������Ϊ���ڵ�ǰ���������
 *
 * @param pwin			����ָ�롣
 * @param pcomp			Ҫ��������ָ�롣
 */
void vm_focus_component(struct window_t* pwin, struct component_base_t* pcomp);

/**
 * ���ñ�ǩ�����֣����ú����ֻ������¸��µ������ϡ�
 *
 * @param pwin			��ǩ�����Ĵ���ָ�롣
 * @param component		��ǩָ�롣
 * @param text			��Ҫ���õ�label������֡�
 */
void vm_set_label_text(struct window_t* pwin, struct component_base_t* component, VMWSTR text);

/**
 * ���������
 *
 * @param pwin			���������Ĵ���ָ�롣
 * @param id			������ʶ�š�
 * @param x				��������ϽǺ����ꡣ
 * @param y				��������Ͻ������ꡣ
 * @param width			������ȡ�
 * @param height		�����߶ȡ�
 * @param nitem			�����Ŀ�ĸ�����
 * @param items			�����Ŀ������ָ�롣
 *
 * @return				���������ָ�룬����NULL��ʾ����ʧ�ܡ�
*/
struct component_base_t* vm_create_browser(struct window_t* pwin, VMINT id, VMINT x, VMINT y,
	VMINT width, VMINT height, VMINT nitem, struct browser_item_t* items);

/**
 * �������������ݡ�
 *
 * @param component		��������
 * @param items			�����Ŀ��
 * @param nitems		�����Ŀ������
*/
void vm_set_browser_items(struct component_base_t* component, struct browser_item_t* items, VMINT nitems);

#define BROWSER_TEXT_COLOR			11
#define BROWSER_SELECT_BG_COLOR		12
#define BROWSER_SCROLLBAR_BG_COLOR	13
#define BROWSER_SCROLLBAR_BOX_COLOR	14

/**
 * ������������ɫ��
 *
 * @param browserbox		�����ָ�룬���ָ������������������κζ���������
 * @param where				������ɫ��λ�ã���BROWSERBOX�������塣
 * @param color				��ɫ��
*/
void vm_set_browserbox_color(struct component_base_t* browserbox, VMINT where, VMINT color);


/**
 * �����������
 *
 * @param comp		��������
*/
void vm_browser_click(struct component_base_t* comp);

/**
 * ��������������������ͼ�η�ʽ��ʾ�ٷֱȣ������������ֳ����ִ�н��ȡ�
 *
 * @param pwin		��������ָ�롣
 * @param id		�����ţ���һ�����������Ψһ��
 * @param x			���������Ͻǵ�X���ꡣ
 * @param y			���������Ͻǵ�Y���ꡣ
 * @param width		��������ȡ�
 * @param height	�������߶ȡ�
 *
 * @return			���ؽ�����ָ�룬����NULL��ʾ����ʧ�ܡ�
 */
struct component_base_t* vm_create_gauge(struct window_t* pwin, VMINT id, VMINT x, VMINT y,
	VMINT width, VMINT height);

/**
 * ���ý��ȱ�Ľ��ȣ������԰ٷֱȱ�ʾ��
 *
 * @param pwin		��������������ָ�롣
 * @param gauge		������ָ�롣
 * @param percent	���Ȱٷֱȣ�ʹ��0-100��ʾ0%-100%��
 */
void vm_set_gauge_progress(struct window_t* pwin, struct component_base_t* gauge, 
	VMINT percent);

/**
 * ���ô��ڵ�ʽ��������Ĭ����û�б������������������Ա���԰Ѵ��ڵ�ʽ������Ϊ����
 * �����������ı�׼��ۡ������ھ߱���������������ͻ�����Ҳ��Ӧ��С������
 * �����������ʱ���������Ļ�ϵ�Y������ڴ��ڱ������߶ȼӴ������ʱ������Y�����
 * ����<br>
 * ����ʽ��������±�<br>
 * <ul>
 * <li>WS_HAS_TITLE�������б�������
 * <li>WS_HAS_SKBAR���������������
 * </ul>
 * ע�⣺�������Ա�Ѿ��򴰿����������Ȼ�����ô���ʽ�����Ѿ����������ڴ����ϵ�
 * λ�ò��ᷢ���仯��������ô���ʽ������Ӧ���ڴ������ں���á��������ô���ʽ����
 * �������������´��ڣ���������Ѿ�ʹ��vm_active_window()�������������ʽ�����
 * ��Ա��Ҫ����vm_graphic_flush_screen()����������Ļ��
 *
 * @param pwin		�����ô��ڵ�ָ�롣
 * @param style		ʽ��������ʽ�������û����������һ��
 */
void vm_set_window_style(struct window_t *pwin, VMINT style);

/**
 * ���ô��ڱ��⡣
 *
 * @param pwin		Ҫ���ñ���Ĵ���ָ�롣
 * @param title		���ڱ��⡣
 */
void vm_set_window_title(struct window_t *pwin, VMWSTR title);

/**
 * ��ô����û�����ĸ߶ȡ�
 *
 * @param pwin		����ָ�롣
 *
 * @return			�����û�����ĸ߶ȡ�
 */
VMINT vm_get_window_user_region_height(struct window_t *pwin);

/**
 * �����������ڣ����������Ǹ����ڸ������ϵ�һ��С���ڣ�������WINDOW��ģ̬�Ի�
 * ��
 *
 * @param parent_window			�������ڹ����ĸ����ڡ�
 * @param id					�����˵�����ı�š�
 * @param x						�����������Ͻ�X���ꡣ
 * @param y						�����������Ͻ�Y���ꡣ
 * @param width					�������ڿ�ȡ�
 * @param height				�������ڸ߶ȡ�
 *
 * @return			���ص�������ָ�룬����NULL��ʾʧ�ܡ�
 */
struct window_t* vm_create_popup_window(struct window_t* parent_window, VMINT id, 
	VMINT x, VMINT y, VMINT width, VMINT height);

/**
 * ���������˵������ÿ�����ڶ����Լ��ĵ����˵��������˵�Ĭ�Ϻʹ���������϶˶������
 * ������ȫ��ģʽ����ô�˵��ĵײ��ʹ��ڵײ����롣�����˵�Ĭ�ϵ���λ����������Ϸ���
 * �˵���С��λ����ϵͳ�Զ�����vm_set_component_position�������ò˵���λ�á�
 *
 * @param win				ӵ�в˵��Ĵ��ڣ�ÿ������ֻ�ܹ���һ�������˵���������ظ�
 *							��������ô�ϲ˵��ᱻ�Զ��ͷŵ���
 * @param id				���ID�š�
 * @return					���ص����˵�ָ�롣
 */
struct component_base_t* vm_create_popup_menu(struct window_t* win, VMINT id);

/**
 * �򵯳��˵�������Ӳ˵���(menu item)�������˵���Զ�׷�ӵ����ֵܲ˵����β����
 * ���û���ֵܲ˵��������Ĳ˵������丸�˵���ĵ�һ���������˵���˵���ĳ�����
 * �����£�
 * component_base_t* menu = vm_create_pop vm_create_popup_menu(myWindow, POPUP_MENU_ID);
 * vm_add_menu_item(menu, vm_ucs2_string("MENU-1"), 1, 0);
 * vm_add_menu_item(menu, vm_ucs2_string("MENU-2"), 2, 0);
 * vm_add_menu_item(menu, vm_ucs2_string("MENU-3"), 3, 0);
 * vm_add_menu_item(menu, vm_ucs2_string("MENU-1.1"), 4, 1);
 * vm_add_menu_item(menu, vm_ucs2_string("MENU-1.2"), 5, 1);
 * vm_add_menu_item(menu, vm_ucs2_string("MENU-1.3"), 6, 1);
 * vm_add_menu_item(menu, vm_ucs2_string("MENU-1.2.1"), 7, 5);
 * ִ�������ϴ���󣬲˵����߼��ṹ���Ա������£�
 * MENU-1
 *   |_____MENU-1.1
 *	 |_____MENU-1.2
 *   |        |______MENU_1.2.1
 *   |_____MENU-1.3
 * MENU-2
 * MENU-3
 *   
 * @param menu				�����˵�ָ�롣
 * @param label				�˵�������֡�
 * @param menuItemId			�˵���ID�ţ��ɹ�Ӧ�ó����ж����Ǹ��˵���ѡ�С���ֵӦ��
 *							Ϊ����0������������һ������ֻ��Ӧһ�������˵��������
 *                          һ�������˵�������Ĳ˵�ID��Ӧ����Ψһ�ġ�
 * @param parentMenuItemId		�������˵���ID�ţ������0���ʾ���һ��˵������Ӳ˵���
 *
 * @return					����0��ʾ��ӳɹ�������Ϊʧ�ܡ�
 */
VMINT vm_add_menu_item(struct component_base_t *menu, VMWSTR label,
	VMUINT menuItemId, VMUINT parentMenuItemId);

/**
 * ���õ����˵���������ø��������˵�������ԣ�����������ʾ���ֵ�����
 * �����ز˵��
 *
 * @param menu				ָ�򵯳��˵������ָ�롣
 * @param menuItemId	�����ò˵����ID�š�			
 * @param label				��ʾ���֣�����ΪNULL��ʾ����Ҫ�޸����֡�
 * @param visible			��ΪTRUE��ʾҪ��ʾ�˵�����ΪFALSE��ʾҪ���ز˵���
 * 
 * @return					����0��ʾ���óɹ�������Ϊʧ�ܡ�
*/
VMINT vm_set_menu_item(struct component_base_t *menu, VMUINT menuItemId, 
	VMWSTR label, VMINT visible);

/**
 * ��ʾĳ�����ڵĵ����˵����ú�����������vm_close_popup_menu�����������෴��
 *
 * @param window			����ָ�롣
 * @return					0��ʾ�򿪵����˵��ɹ�������Ϊʧ�ܡ�
 */
VMINT vm_popup_menu(struct window_t *window);

/**
 * �ر�ĳ�����ڵĵ����˵����ú��������ú�vm_pop_menu�������෴��
 *
 * @param window			����ָ�롣
 */
void vm_close_popup_menu(struct window_t *window);

/**
 * ��������ڴ����ϵ�λ�úʹ�С��������������ǵ���λ�ã������Զ����´������ݣ�
 * �����Ҫ�ڵ���������ˢ�´��ڣ������vm_update_window()������������λ�õ����
 * ����:
 * 
 * �б�(listbox)
 * ��ť(button)
 * ��ǩ�����(browser)
 * �༭��(editbox)
 * ��ѡ��(checkbox)
 * ���ο�(sharpe)
 * ��ǩ(lable)
 * ͼ��(image)
 *
 * @param comp				Ҫ���������ָ�롣
 * @param x					������Ͻ�X���ꡣ
 * @param y					������Ͻ�Y���ꡣ
 * @param width				�����ȡ�
 * @param height			����߶ȡ�
 */
void vm_set_component_position(struct component_base_t *comp, VMINT x, VMINT y, 
	VMINT width, VMINT height);

/**
 * ˢ�´��ڣ���������ᵼ�´�������������ˢ�µ���Ļ�ϣ����´��ڲ��Ǽ���ڡ�
 *
 * @param pwin				Ҫˢ�µĴ���ָ�롣
 */
void vm_update_window(struct window_t *pwin);

/*	�������ֵ�����	*/
#define ALPHABIT		1			// ��ĸ���ͣ��������ĺͷ��š�
#define PASSWORD		2			// �������ͣ���������������Ǻ�'*'��ʾ��
#define NUMERIC			3			//�������ͣ������ĶԻ���ֻ����������

/**
 * �����༭��
 * 
 * 
 * @param pwin					�༭������Ĵ��ڡ�
 * @param id					�༭���š�
 * @param x						�༭�����Ͻ�X���ꡣ
 * @param y						�༭�����Ͻ�Y���ꡣ
 * @param width					�༭���ȡ�
 * @param height				�༭��߶ȡ�
 * @param type					ALPHABIT��PASSWORD��
 *
 * @return						�༭��ָ�룬����NULL��ʾʧ�ܡ�
*/
struct component_base_t* vm_create_editbox(struct window_t* pwin, VMINT id, VMINT x, VMINT y,
	VMINT width, VMINT height, VMUSHORT type);

/**
* ���ñ༭���ڵ����֡�
* 
* @param edit_comp				��Ҫ���õĴ��������
* @param text			        ��Ҫ�������ֵ����ݡ�
*/
void vm_set_editbox_text(struct component_base_t* edit_comp, VMWSTR text);

/**
* ������ѡ���
* 
*
* @param pwin					�༭���ڹ����Ĵ��ڡ�
* @param id						�༭���ڱ�š�
* @param x						�༭�������Ͻ�X���ꡣ
* @param y						�༭�������Ͻ�Y���ꡣ
*
* @return			����CHECKBOXָ�룬����NULL��ʾʧ�ܡ�
*/
struct component_base_t* vm_create_checkbox(struct window_t* pwin, VMINT id, VMINT x, VMINT y);

#ifdef __cplusplus
}
#endif

#endif