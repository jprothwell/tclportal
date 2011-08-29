#ifdef __VRE__
#include "mmi_include.h"
#include "vmopt.h"
#include "vmsys.h"
#include "vmlog.h"


VMUINT8* vre_buildin_app_array[5];

/*初始化内置游戏数组*/
#if defined __VRE_QCIF__
	#ifdef __MMI_VRE_GAME_QQBALL__
	extern const __align(4) VMUINT8 qqball_qcif_vxp[];
	#endif
	#ifdef __MMI_VRE_GAME_FFL__
	extern const __align(4) VMUINT8 ffl_qcif_vxp[];
	#endif
	#ifdef __MMI_VRE_GAME_DICE__
	extern const __align(4) VMUINT8 dice_qcif_vxp[];
	#endif
	#ifdef __MMI_VRE_GAME_STAR__
	extern const __align(4) VMUINT8 star_qcif_vxp[];
	#endif
#elif defined __VRE_QVGA__
	#ifdef __MMI_VRE_GAME_QQBALL__
	extern const __align(4) VMUINT8 qqball_qvga_vxp[];
	#endif
	#ifdef __MMI_VRE_GAME_FFL__
	extern const __align(4) VMUINT8 ffl_qvga_vxp[];
	#endif
	#ifdef __MMI_VRE_GAME_DICE__
	extern const __align(4) VMUINT8 dice_qvga_vxp[];
	#endif
	#ifdef __MMI_VRE_GAME_STAR__
	extern const __align(4) VMUINT8 star_qvga_vxp[];
	#endif
	#ifdef __MMI_VRE_GAME_YZDMX__
	extern const __align(4) VMUINT8 yzdmx_qvga_vxp[];
	#endif
#elif defined __VRE_WQVGA__
	#ifdef __MMI_VRE_GAME_QQBALL__
	extern const __align(4) VMUINT8 qqball_wqvga_vxp[];
	#endif
	extern const __align(4) VMUINT8 ffl_wqvga_vxp[];
	extern const __align(4) VMUINT8 dice_wqvga_vxp[];
	#ifdef __MMI_VRE_GAME_STAR__
	extern const __align(4) VMUINT8 star_wqvga_vxp[];
	#endif
	#ifdef __MMI_VRE_GAME_YZDMX__
	extern const __align(4) VMUINT8 yzdmx_wqvga_vxp[];
	#endif
#elif defined __VRE_HVGA__
	extern const __align(4) VMUINT8 qqball_hvga_vxp[];
	#ifdef __MMI_VRE_GAME_FFL__
	extern const __align(4) VMUINT8 ffl_hvga_vxp[];
	#endif
	extern const __align(4) VMUINT8 dice_hvga_vxp[];
	#ifdef __MMI_VRE_GAME_STAR__
	extern const __align(4) VMUINT8 star_hvga_vxp[];
	#endif
	#ifdef __MMI_VRE_GAME_YZDMX__
	extern const __align(4) VMUINT8 yzdmx_hvga_vxp[];
	#endif
#endif

VMUINT8 vm_init_default_game(void)
{
	VMUINT8 count = 0;
#if defined __VRE_QCIF__
	#ifdef __MMI_VRE_GAME_FFL__
	vre_buildin_app_array[count++] = (VMUINT8 *)ffl_qcif_vxp;
	#endif
	#ifdef __MMI_VRE_GAME_STAR__
	vre_buildin_app_array[count++] = (VMUINT8 *)star_qcif_vxp;
	#endif
	#ifdef __MMI_VRE_GAME_DICE__
	vre_buildin_app_array[count++] = (VMUINT8 *)dice_qcif_vxp;
	#endif
	#ifdef __MMI_VRE_GAME_QQBALL__
	vre_buildin_app_array[count++] = (VMUINT8 *)qqball_qcif_vxp;
	#endif
#elif defined __VRE_QVGA__
	#ifdef __MMI_VRE_GAME_FFL__
	vre_buildin_app_array[count++] = (VMUINT8 *)ffl_qvga_vxp;
	#endif
	#ifdef __MMI_VRE_GAME_STAR__
	vre_buildin_app_array[count++] = (VMUINT8 *)star_qvga_vxp;
	#endif
	#ifdef __MMI_VRE_GAME_DICE__
	vre_buildin_app_array[count++] = (VMUINT8 *)dice_qvga_vxp;
	#endif
	#ifdef __MMI_VRE_GAME_QQBALL__
	vre_buildin_app_array[count++] = (VMUINT8 *)qqball_qvga_vxp;
	#endif
	#ifdef __MMI_VRE_GAME_YZDMX__
	vre_buildin_app_array[count++] = (VMUINT8 *)yzdmx_qvga_vxp;
	#endif
#elif defined __VRE_WQVGA__
	#ifdef __MMI_VRE_GAME_FFL__
	vre_buildin_app_array[count++]= (VMUINT8 *)ffl_wqvga_vxp;
	#endif
	#ifdef __MMI_VRE_GAME_STAR__
	vre_buildin_app_array[count++]= (VMUINT8 *)star_wqvga_vxp;
	#endif	
	#ifdef __MMI_VRE_GAME_DICE__
	vre_buildin_app_array[count++]= (VMUINT8 *)dice_wqvga_vxp;
	#endif
	#ifdef __MMI_VRE_GAME_QQBALL__
	vre_buildin_app_array[count++]= (VMUINT8 *)qqball_wqvga_vxp;
	#endif
	#ifdef __MMI_VRE_GAME_YZDMX__
	vre_buildin_app_array[count++] = (VMUINT8 *)yzdmx_wqvga_vxp;
	#endif
#elif defined __VRE_HVGA__
	#ifdef __MMI_VRE_GAME_FFL__
	vre_buildin_app_array[count++]= (VMUINT8 *)ffl_hvga_vxp;
	#endif
	#ifdef __MMI_VRE_GAME_STAR__
	vre_buildin_app_array[count++]= (VMUINT8 *)star_hvga_vxp;
	#endif
	#ifdef __MMI_VRE_GAME_DICE__
	vre_buildin_app_array[count++]= (VMUINT8 *)dice_hvga_vxp;
	#endif
	#ifdef __MMI_VRE_GAME_QQBALL__
	vre_buildin_app_array[count++]= (VMUINT8 *)qqball_hvga_vxp;
	#endif
	#ifdef __MMI_VRE_GAME_YZDMX__
	vre_buildin_app_array[count++] = (VMUINT8 *)yzdmx_hvga_vxp;
	#endif
#endif
	return count;
}

#endif
