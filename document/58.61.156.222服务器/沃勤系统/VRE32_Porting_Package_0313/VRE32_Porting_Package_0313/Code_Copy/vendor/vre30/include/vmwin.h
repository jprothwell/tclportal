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
 * 列表框条目。
 */
struct list_item_t {
	VMINT iconid;				/* 图标编号，设为-1表示没有图标。	*/
	VMINT value;				/* 项目的值。						*/
	VMWCHAR label[50];			/* 显示标签。						*/
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
 * 窗口有标题栏。
 */
#define WS_HAS_TITLE	1

/*
 * 窗口有软键栏。
 */
#define WS_HAS_SKBAR	2

struct window_t 
{
	VMINT id;									// 窗口的编号。
	VMINT x;									// 窗口的X坐标。
	VMINT y;									// 窗口的Y坐标。
	VMINT width;								// 窗口的宽度。
	VMINT height;								// 窗口的高度。
	VMWCHAR title[50];							// 窗口的标题。
	VMINT style;								// 窗口的风格。
	struct window_t* parent_window;				// 弹出窗口归属的父亲窗口。
	struct component_base_t* left_softkey;		// 左软键。
	struct component_base_t* right_softkey;		// 右软键。
	struct component_base_t* comp_root;			// 归属到本窗口的组件根节点。
	struct component_base_t* focus_component;	// 当前窗口聚焦的组件。
	struct component_base_t* popup_menu;		// 窗口弹出菜单对象。
	VMINT (*winproc)(int message, int param);	// 用户注册的回调函数。
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
 * 浏览器条目。
 */
struct browser_item_t {
	VMINT id;				/* 条目编号	*/
	VMINT type;				/* 条目类型	*/
	VMWCHAR label[255];		/* 条目显示的文字 */
	VMCHAR herf[255];		/* 超连接地址 */
	VMINT selectable;		/* 能否被选中 */
};

/**
 * 浏览器组件。
 */
struct browser_t {
	VMINT nitem;						/* 条目总数 */
	VMINT point;						/* 当前指向条目编号*/		
	VMINT sel_item;						/* 被选中的条目编号 */
	VMINT text_color;					/* 条目文字颜色 */
	VMINT sel_bg_color;					/* 选中条目文字颜色 */
	VMINT scr_bar_color;				/* 滚动条颜色 */
	VMINT scr_bg_color;					/* 滚动条背景色 */
	VMINT win_bagin_po;					/* 显示窗口的起始条目编号 */
	VMINT win_row_total;				/* 显示窗口的行总数 */
	struct browser_item_t * bitems;		/* 浏览器条目数组 */
};

/**
 * 进度条。
 */
struct gauge_t {
	VMINT percent;						/* 进度。			*/
};

/*
 * 下载信息。
 */
struct download_info_t{
	char herf[255];
	short label[255];
};

/*
 * 窗口系统的主题。
 */
struct window_scheme_t {
	VMINT win_bgcolor;					/* 窗口客户区的背景颜色。*/
	VMINT win_sys_bgcolor;				/* 窗口系统区的背景颜色。*/
	VMINT win_text_color;				/* 窗口的文字颜色。*/
	VMINT win_sktext_color;				/* 窗口软键栏的文字颜色。*/
	VMINT win_title_height;				/* 窗口标题栏的高度。*/
	VMINT win_skbar_height;				/* 窗口状态栏的高度。*/
	VMINT listbox_bgcolor;				/* 列表框的背景颜色。*/
	VMINT listbox_text_color;			/* 列表框的文字颜色。*/
	VMINT listbox_sel_bgcolor;			/* 列表框选中条目的背景颜色。*/
	VMINT listbox_scrbar_box_color;		/* 列表框的滚动块颜色。*/
	VMINT listbox_scrbar_bgcolor;		/* 列表框滚动条的背景颜色。*/
};

/*
 * 弹出菜单项。
 */
struct vm_menu_item_t {
	VMWCHAR label[50];								/* 菜单的名称，即在菜单项中显示的字符。			*/
	VMINT value;									/* 菜单项的值，应用程序不应该修改该值。			*/
	VMINT visible;									/* 菜单项本菜单项是否可见，如果该菜单项不可见 
	                                                   那么该菜单项下的子菜单也不可见。				*/
	
	struct vm_second_level_menu_list_t *second_level_list;
};

/*
 * 弹出一级菜单列表。
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
 * 弹出二级菜单项。
 */
struct vm_second_level_menu_item_t {
	VMWCHAR label[50];
	VMINT value;
	VMINT visible;
};

/*
 * 弹出二级菜单列表。
 */
struct vm_second_level_menu_list_t {
	VMINT selidx;
	VMINT nsize;
	VMINT nitem;
	struct rect_t rect;
	struct vm_second_level_menu_item_t *items;
};

/*
 * 编辑框。
 */
struct editbox_t 
{
	VMUSHORT type;							/* 编辑框的文字类型。	*/
	VMWCHAR text[255];						/* 编辑框的内容。		*/
	VMUSHORT canDrawCusor;					/* 是否需要画游标的标志 */
};

/*
 * 单选框。
 */
struct checkbox_t 
{
	VMINT select;							/* 是否被选择了。		*/
};

/**
 * 按钮按下消息，param字段给出指向被按下按钮的指针。
 */
#define VM_WM_BUTTON_CLICK		1

/**
 * 列表框选项被点击或者按下OK键消息，用于捕获用户点击列表框某个选项事件，
 * param字段给出被点击的列表框对象指针。
 */
#define VM_WM_LISTBOX_CLICK		3

/**
 * 键盘按下消息，param字段给出按键的keycode。
 */
#define VM_WM_KEYDOWN			4

/**
 * 键盘释放消息，param字段给出按键的keycode。
 */
#define VM_WM_KEYUP				5

/**
 * 笔按下消息，param字段的高位2字节为点击的横坐标，低位2字节为点击的纵坐标。
 */
#define VM_WM_PEN_TAP			6

/**
 * 笔释放消息，param字段的高2字节为释放点的横坐标，低位2字节为释放点的纵坐标。
 */
#define VM_WM_PEN_RELEASE		7

/**
 * VRE处于活动状态，此时构建于VRE之上的应用程序处于可执行状态。
 */
#define VM_WM_ACTIVATE			8

/**
 * VRE处于去活状态，此时构建于VRE之上的应用程序必须暂停所有的屏幕更新、音频播
 * 放等动作，以便手机执行去活的其他活动，比如接听电话、看短信等。
 */
#define VM_WM_INACTIVATE		9

/**
 * 窗口重绘消息，此时窗口子系统已经把活跃窗口上的组件绘制完毕，应用程序可以
 * 用这个消息在界面上增加绘制自己的图形。
 */
#define VM_WM_PAINT				12

/**
 * 窗口左软键按下。
 */
#define VM_WM_LEFT_SOFTKEY_CLICK	10

/**
 * 窗口右软键按下。
 */
#define VM_WM_RIGHT_SOFTKEY_CLICK	11

/**
 * 列表框条目改变消息，param参数给出了发出消息的列表框对象指针。
 */
#define VM_WM_LISTBOX_CHANGED	13

/**
 * 浏览窗口请求下载消息，param参数给出了download_info_t 对象指针。
 */
#define VM_WM_BROWSER_DOWNLOAD		16

/**
 * 菜单被选中消息，param参数给出了struct vm_menu_item_t指针，这是被选中
 * 菜单项目的指针。
 */
#define VM_WM_MENU_SELECTED			18

/**
 * VRE系统退出前的窗口消息。
 */
#define	VM_WM_QUIT					20

/**
 * 创建窗口。
 *
 * @param id			窗口标识号，用于唯一标识窗口。
 * @param x				窗口左上角横坐标。
 * @param y				窗口左上角纵坐标。
 * @param width			窗口宽度。
 * @param height		窗口高度。
 * 
 * @return				返回窗口指针，如果创建窗口失败则返回NULL。
 */
struct window_t* vm_create_window(VMINT id, VMINT x, VMINT y, VMINT width, VMINT height);

/**
 * 设置窗口获得输入焦点的组件，获得输入焦点的组件能够捕获所有的按键消息。
 *
 * @param pwin			窗口指针。
 * @param comp			要激活的组件。
 */
void vm_set_focus(struct window_t* pwin, struct component_base_t* comp);

/**
 * 设置窗口组件的前景颜色。
 *
 * @param component		被设置的组件。
 * @param color			前景颜色。
 */
void vm_set_component_color(struct component_base_t* component, VMINT color);

/**
 * 设置窗口组件的背景颜色。
 *
 * @param component		被设置的组件。
 * @param color			背景颜色。
 */
void vm_set_component_bgcolor(struct component_base_t* component, VMINT color);

/**
 * 设置窗口组件的背景图。
 *
 * @param component		被设置的组件。
 * @param image			背景图。
 */
void vm_set_component_bgimage(struct component_base_t* component, VMINT image);

/**
 * 创建按钮。
 *
 * @param pwin			按钮归属的窗口指针。
 * @param id				组件的ID
 * @param x				按钮左上角横坐标。
 * @param y				按钮左上角纵坐标。
 * @param width			按钮的宽度。
 * @param height		按钮的高度。
 * @param label			按钮的文字。
 *
 * @return				返回按钮指针，返回NULL表示创建按钮失败。
 */
struct component_base_t* vm_create_button(struct window_t* pwin, VMINT id, VMINT x, VMINT y,
	VMINT width, VMINT height, VMWSTR label);

/**
 * 创建图象，图象就是窗口上的一幅静止图象，不能捕获输入。
 *
 * @param pwin			图象归属的窗口指针。
 * @param id			图象标识号。
 * @param x				图象左上角横坐标。
 * @param y				图象左上角纵坐标。
 * @param width			图象宽度。
 * @param height		图象高度。
 * @param resid			图象所使用的图片资源编号。
 * 
 * @return				返回图象指针，返回NULL表示创建图象失败。
 */
struct component_base_t* vm_create_image(struct window_t* pwin, VMINT id, VMINT x, VMINT y,
	VMINT width, VMINT height, VMINT resid);

/**
 * 创建简单图形，目前只支持矩形色块，用于提供简单的颜色背景。
 *
 * @param pwin			图形归属窗口指针。
 * @param x				图形左上角横坐标。
 * @param y				图形左上角纵坐标。
 * @param width			图形的宽度。
 * @param height		图形的高度。
 * @param bgcolor		图形的背景颜色。
 *
 * @return				返回图形对象指针，返回NULL表示创建失败。
 */
struct component_base_t* vm_create_shape(struct window_t* pwin, VMINT x, VMINT y,
	VMINT width, VMINT height, VMINT bgcolor);

/**
 * 创建列表框，该列表框默认是有边框的。
 *
 * @param pwin			列表框归属的窗口指针。
 * @param id			列表框标识号。
 * @param x				列表框左上角横坐标。
 * @param y				列表框左上角纵坐标。
 * @param width			列表框宽度。
 * @param height		列表框高度。
 * @param nitem			列表项目的个数。
 * @param items			列表项目的数组指针。
 *
 * @return				返回列表框指针，返回NULL表示创建失败。
 */
struct component_base_t* vm_create_listbox(struct window_t* pwin, VMINT id, VMINT x, VMINT y,
	VMINT width, VMINT height, VMINT nitem, struct list_item_t* items);

/**
 * 设置列表框是否需要边框。
 *
 * @param component		列表框对象。
 * @param is_border		是否需要设置边框，TRUE是表示需要设置边框的，FALSE则表示不需要。
 */
void vm_set_listbox_border (struct component_base_t* component, VMINT is_border);

/**
 * 更新列表框的内容。
 *
 * @param component		列表框对象。
 * @param items			列表条目。
 * @param nitems		列表条目数量。
 */
void vm_set_listbox_items(struct component_base_t* component, struct list_item_t* items, VMINT nitems);

/**
 * 设定列表框中的选中项目，列表框中的条目编号从0开始，最后一个条目的编号是n-1，如果给定的选中
 * 条目索引超出列表条目以外系统则不做任何操作。
 *
 * @param component		列表框对象。
 * @param index			被选中的条目编号。
 */
void vm_set_listbox_selidx(struct component_base_t* component, VMINT index);

/**
 * 获得列表框被选中条目的索引，索引编号从0开始，返回-1表示当前没有任何条目被选中。
 *
 * @param component		列表框组件指针。
 *
 * @return				返回被选中的条目编号，编号从0开始，返回-1表示列表框没有选中条目。
 */
VMINT vm_get_listbox_selidx(struct component_base_t* component);

/**
 * 设置列表框的ICON的长和宽。
 *
 * @param component		指向列表框组件的指针。
 * @param width			ICON图片的宽度。
 * @param height		ICON图片的高度。
 */
void vm_set_listbox_icon_size(struct component_base_t* component, 
	VMUINT8 width, VMUINT8 height);

/**
 * 创建标签，标签是窗口上的一段静态文字，用于显示信息。
 *
 * @param pwin			标签归属窗口指针。
 * @param id			标签标识号。
 * @param x				标签左上角横坐标。
 * @param y				标签左上角纵坐标。
 * @param width			标签宽度。
 * @param height		标签高度。
 * @param text			标签文字。
 *
 * @return				返回标签指针，返回NULL表示创建失败。
 */
struct component_base_t* vm_create_label(struct window_t* pwin, VMINT id, VMINT x, VMINT y,
	VMINT width, VMINT height, VMWSTR text);

/**
 * 设置标签的对齐格式。
 *
 * @param component		标签指针
 * @param align			对齐方式
 */
void vm_set_label_alignment(struct component_base_t* component, VMINT align);

#define LISTBOX_TEXT_COLOR			1
#define LISTBOX_SELECT_TEXT_COLOR	2	
#define LISTBOX_SELECT_BG_COLOR		3
#define LISTBOX_SCROLLBAR_BG_COLOR	4
#define LISTBOX_SCROLLBAR_BOX_COLOR	5
#define LISTBOX_SELECT_BG_IMAGE		6

/**
 * 设置列表框的颜色。
 *
 * @param listbox			列表框指针，如果指向其他类型组件则无任何动作发生。
 * @param where				设置颜色的位置，见LISTBOX常量定义。
 * @param color				颜色。
 */
void vm_set_listbox_color(struct component_base_t* listbox, VMINT where, VMINT color);

/**
 * 关闭窗口，窗口内的所有组件绘会被自动删除，窗口对象也会被自动删除。
 *
 * @param pwin			被关闭的窗口指针。
 */
void vm_close_window(struct window_t* pwin);

/**
 * 注册窗口回调函数，应用程序在创建窗口后必须调用本函数以捕获窗口事件。
 *
 * @param pwin			要捕获事件的窗口指针。
 * @param f				窗口事件回调函数。
 *
 * @return				返回0表示事件已经由应用程序处理，不需要系统处理。返回1表示
 *						需要系统还需要处理这个事件。
 */
void vm_reg_winproc(struct window_t* pwin, int (*f)(int message, int param));

/**
 * 设置窗口的左软键。
 *
 * @param pwin			窗口指针。
 * @param is_left		设置为TRUE表示这是左软键，否则就是右软键。
 * @param id			左软键按钮的ID。
 * @param label			左软键的标题。
 *
 * @return				左软键按钮指针。
 */
struct component_base_t* vm_set_window_softkey(struct window_t* pwin, VMINT is_left, 
	VMINT id, VMWSTR label);

/**
 * 把给定的窗口设定为活跃窗口，在VRE窗口系统中，任一时刻都只能有一个活跃窗口，活跃
 * 窗口能够捕获所有的键盘和笔输入。
 *
 * @param pwin			要激活的窗口。
 */
void vm_active_window(struct window_t* pwin);

/**
 * 初始化窗口子系统，这个函数必须在使用窗口子系统之前调用。
 */
void vm_init_window_system(void);

/**
 * 关闭窗口子系统，这个函数只供VRE内部使用，建立在窗口系统之上的应用程序调用这个函数
 * 可能会引起不可预测的后果。
 */
void vm_shutdown_window_system(void);

/**
 * 在窗口中找到给定ID的组件。
 *
 * @param pwin			窗口指针。
 * @param id			组件标识号。
 *
 * @return				找到则返回组件指针，否则返回NULL。
 */
struct component_base_t* vm_find_component(struct window_t* pwin, VMINT id);

/**
 * 隐藏或者显示组件。
 *
 * @param pwin			组件归属的窗口指针。
 * @param pcomp			组件指针。
 * @param hide			设为TRUE则隐藏组件，否则显示组件。
 */
void vm_hide_component(struct window_t* pwin, struct component_base_t* pcomp, VMINT hide);

/**
 * 把给定组件设为窗口当前激活组件。
 *
 * @param pwin			窗口指针。
 * @param pcomp			要激活的组件指针。
 */
void vm_focus_component(struct window_t* pwin, struct component_base_t* pcomp);

/**
 * 设置标签的文字，设置后文字会立即新更新到界面上。
 *
 * @param pwin			标签归属的窗口指针。
 * @param component		标签指针。
 * @param text			需要设置到label里的文字。
 */
void vm_set_label_text(struct window_t* pwin, struct component_base_t* component, VMWSTR text);

/**
 * 创建浏览框。
 *
 * @param pwin			浏览框归属的窗口指针。
 * @param id			浏览框标识号。
 * @param x				浏览框左上角横坐标。
 * @param y				浏览框左上角纵坐标。
 * @param width			浏览框宽度。
 * @param height		浏览框高度。
 * @param nitem			浏览项目的个数。
 * @param items			浏览项目的数组指针。
 *
 * @return				返回浏览框指针，返回NULL表示创建失败。
*/
struct component_base_t* vm_create_browser(struct window_t* pwin, VMINT id, VMINT x, VMINT y,
	VMINT width, VMINT height, VMINT nitem, struct browser_item_t* items);

/**
 * 更新浏览框的内容。
 *
 * @param component		浏览框对象。
 * @param items			浏览条目。
 * @param nitems		浏览条目数量。
*/
void vm_set_browser_items(struct component_base_t* component, struct browser_item_t* items, VMINT nitems);

#define BROWSER_TEXT_COLOR			11
#define BROWSER_SELECT_BG_COLOR		12
#define BROWSER_SCROLLBAR_BG_COLOR	13
#define BROWSER_SCROLLBAR_BOX_COLOR	14

/**
 * 设置浏览框的颜色。
 *
 * @param browserbox		浏览框指针，如果指向其他类型组件则无任何动作发生。
 * @param where				设置颜色的位置，见BROWSERBOX常量定义。
 * @param color				颜色。
*/
void vm_set_browserbox_color(struct component_base_t* browserbox, VMINT where, VMINT color);


/**
 * 浏览框处理函数。
 *
 * @param comp		浏览框对象。
*/
void vm_browser_click(struct component_base_t* comp);

/**
 * 创建进度条，进度条以图形方式表示百分比，可以用来表现程序的执行进度。
 *
 * @param pwin		归属窗口指针。
 * @param id		组件编号，在一个窗口里必须唯一。
 * @param x			进度条左上角的X坐标。
 * @param y			进度条左上角的Y坐标。
 * @param width		进度条宽度。
 * @param height	进度条高度。
 *
 * @return			返回进度条指针，返回NULL表示创建失败。
 */
struct component_base_t* vm_create_gauge(struct window_t* pwin, VMINT id, VMINT x, VMINT y,
	VMINT width, VMINT height);

/**
 * 设置进度表的进度，进度以百分比表示。
 *
 * @param pwin		进度条归属窗口指针。
 * @param gauge		进度条指针。
 * @param percent	进度百分比，使用0-100表示0%-100%。
 */
void vm_set_gauge_progress(struct window_t* pwin, struct component_base_t* gauge, 
	VMINT percent);

/**
 * 设置窗口的式样，窗口默认是没有标题栏和软键栏，程序员可以把窗口的式样设置为有着
 * 标题和软键栏的标准外观。当窗口具备标题和软键栏后，其客户区域也相应缩小，即往
 * 窗口增加组件时，组件在屏幕上的Y坐标等于窗口标题栏高度加创建组件时给出的Y坐标参
 * 数。<br>
 * 窗口式样定义见下表：<br>
 * <ul>
 * <li>WS_HAS_TITLE。窗口有标题栏。
 * <li>WS_HAS_SKBAR。窗口有软键栏。
 * </ul>
 * 注意：如果程序员已经向窗口增加了组件然后设置窗口式样，已经加入的组件在窗口上的
 * 位置不会发生变化，因此设置窗口式样函数应当在创建窗口后调用。此外设置窗口式样函
 * 数不会主动更新窗口，如果窗口已经使用vm_active_window()函数激活，在设置式样后程
 * 序员需要调用vm_graphic_flush_screen()函数更新屏幕。
 *
 * @param pwin		被设置窗口的指针。
 * @param style		式样，窗口式样可以用或运算叠加在一起。
 */
void vm_set_window_style(struct window_t *pwin, VMINT style);

/**
 * 设置窗口标题。
 *
 * @param pwin		要设置标题的窗口指针。
 * @param title		窗口标题。
 */
void vm_set_window_title(struct window_t *pwin, VMWSTR title);

/**
 * 获得窗口用户区域的高度。
 *
 * @param pwin		窗口指针。
 *
 * @return			窗口用户区域的高度。
 */
VMINT vm_get_window_user_region_height(struct window_t *pwin);

/**
 * 创建弹出窗口，弹出窗口是覆盖在父窗口上的一个小窗口，类似于WINDOW的模态对话
 * 框。
 *
 * @param parent_window			弹出窗口归属的父窗口。
 * @param id					弹出菜单组件的编号。
 * @param x						弹出窗口左上角X坐标。
 * @param y						弹出窗口左上角Y坐标。
 * @param width					弹出窗口宽度。
 * @param height				弹出窗口高度。
 *
 * @return			返回弹出窗口指针，返回NULL表示失败。
 */
struct window_t* vm_create_popup_window(struct window_t* parent_window, VMINT id, 
	VMINT x, VMINT y, VMINT width, VMINT height);

/**
 * 创建弹出菜单组件，每个窗口都有自己的弹出菜单。弹出菜单默认和窗口软键栏上端对起，如果
 * 窗口是全屏模式，那么菜单的底部和窗口底部对齐。弹出菜单默认弹出位置在左软键上方，
 * 菜单大小和位置由系统自动管理。vm_set_component_position不能设置菜单的位置。
 *
 * @param win				拥有菜单的窗口，每个窗口只能够有一个弹出菜单，如果是重复
 *							创建，那么老菜单会被自动释放掉。
 * @param id				组件ID号。
 * @return					返回弹出菜单指针。
 */
struct component_base_t* vm_create_popup_menu(struct window_t* win, VMINT id);

/**
 * 向弹出菜单组件增加菜单项(menu item)，新增菜单项被自动追加到其兄弟菜单项的尾部，
 * 如果没有兄弟菜单项则加入的菜单项是其父菜单项的第一个。创建菜单与菜单项的程序序
 * 列如下：
 * component_base_t* menu = vm_create_pop vm_create_popup_menu(myWindow, POPUP_MENU_ID);
 * vm_add_menu_item(menu, vm_ucs2_string("MENU-1"), 1, 0);
 * vm_add_menu_item(menu, vm_ucs2_string("MENU-2"), 2, 0);
 * vm_add_menu_item(menu, vm_ucs2_string("MENU-3"), 3, 0);
 * vm_add_menu_item(menu, vm_ucs2_string("MENU-1.1"), 4, 1);
 * vm_add_menu_item(menu, vm_ucs2_string("MENU-1.2"), 5, 1);
 * vm_add_menu_item(menu, vm_ucs2_string("MENU-1.3"), 6, 1);
 * vm_add_menu_item(menu, vm_ucs2_string("MENU-1.2.1"), 7, 5);
 * 执行完以上代码后，菜单的逻辑结构可以表述如下：
 * MENU-1
 *   |_____MENU-1.1
 *	 |_____MENU-1.2
 *   |        |______MENU_1.2.1
 *   |_____MENU-1.3
 * MENU-2
 * MENU-3
 *   
 * @param menu				弹出菜单指针。
 * @param label				菜单项的文字。
 * @param menuItemId			菜单项ID号，可供应用程序判断是那个菜单被选中。该值应该
 *							为大于0的整数。对于一个窗口只对应一个弹出菜单的组件，
 *                          一个弹出菜单的组件的菜单ID号应该是唯一的。
 * @param parentMenuItemId		所归属菜单的ID号，如果是0则表示向第一层菜单加入子菜单。
 *
 * @return					返回0表示添加成功，否则为失败。
 */
VMINT vm_add_menu_item(struct component_base_t *menu, VMWSTR label,
	VMUINT menuItemId, VMUINT parentMenuItemId);

/**
 * 设置弹出菜单项，包括设置给定弹出菜单项的属性，包括更换显示文字的内容
 * 和隐藏菜单项。
 *
 * @param menu				指向弹出菜单组件的指针。
 * @param menuItemId	需设置菜单项的ID号。			
 * @param label				显示文字，设置为NULL表示不需要修改文字。
 * @param visible			设为TRUE表示要显示菜单，设为FALSE表示要隐藏菜单。
 * 
 * @return					返回0表示设置成功，否则为失败。
*/
VMINT vm_set_menu_item(struct component_base_t *menu, VMUINT menuItemId, 
	VMWSTR label, VMINT visible);

/**
 * 显示某个窗口的弹出菜单，该函数的作用与vm_close_popup_menu函数的作用相反。
 *
 * @param window			窗口指针。
 * @return					0表示打开弹出菜单成功，否则为失败。
 */
VMINT vm_popup_menu(struct window_t *window);

/**
 * 关闭某个窗口的弹出菜单，该函数的作用和vm_pop_menu的作用相反。
 *
 * @param window			窗口指针。
 */
void vm_close_popup_menu(struct window_t *window);

/**
 * 设置组件在窗口上的位置和大小，这个函数仅仅是调整位置，不会自动更新窗口内容，
 * 如果需要在调整后立即刷新窗口，请调用vm_update_window()函数。可设置位置的组件
 * 包括:
 * 
 * 列表(listbox)
 * 按钮(button)
 * 标签浏览器(browser)
 * 编辑框(editbox)
 * 单选框(checkbox)
 * 矩形框(sharpe)
 * 标签(lable)
 * 图形(image)
 *
 * @param comp				要调整的组件指针。
 * @param x					组件左上角X坐标。
 * @param y					组件左上角Y坐标。
 * @param width				组件宽度。
 * @param height			组件高度。
 */
void vm_set_component_position(struct component_base_t *comp, VMINT x, VMINT y, 
	VMINT width, VMINT height);

/**
 * 刷新窗口，这个函数会导致窗口内容立即被刷新到屏幕上，哪怕窗口不是激活窗口。
 *
 * @param pwin				要刷新的窗口指针。
 */
void vm_update_window(struct window_t *pwin);

/*	输入文字的类型	*/
#define ALPHABIT		1			// 字母类型，包括中文和符号。
#define PASSWORD		2			// 密码类型，会在输入框里以星号'*'显示。
#define NUMERIC			3			//数字类型，弹出的对话框只能输入数字

/**
 * 创建编辑框。
 * 
 * 
 * @param pwin					编辑框归属的窗口。
 * @param id					编辑框编号。
 * @param x						编辑框左上角X坐标。
 * @param y						编辑框左上角Y坐标。
 * @param width					编辑框宽度。
 * @param height				编辑框高度。
 * @param type					ALPHABIT或PASSWORD。
 *
 * @return						编辑框指针，返回NULL表示失败。
*/
struct component_base_t* vm_create_editbox(struct window_t* pwin, VMINT id, VMINT x, VMINT y,
	VMINT width, VMINT height, VMUSHORT type);

/**
* 设置编辑框内的文字。
* 
* @param edit_comp				需要设置的窗口组件。
* @param text			        需要设置文字的内容。
*/
void vm_set_editbox_text(struct component_base_t* edit_comp, VMWSTR text);

/**
* 创建单选择框。
* 
*
* @param pwin					编辑窗口归属的窗口。
* @param id						编辑窗口编号。
* @param x						编辑窗口左上角X坐标。
* @param y						编辑窗口左上角Y坐标。
*
* @return			返回CHECKBOX指针，返回NULL表示失败。
*/
struct component_base_t* vm_create_checkbox(struct window_t* pwin, VMINT id, VMINT x, VMINT y);

#ifdef __cplusplus
}
#endif

#endif