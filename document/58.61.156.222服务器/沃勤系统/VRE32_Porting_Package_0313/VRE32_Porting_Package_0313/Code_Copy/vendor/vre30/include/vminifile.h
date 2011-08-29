#ifndef VMINIFILE_H
#define VMINIFILE_H

#ifdef __cplusplus
extern "C"
{

#endif

/*֧�ֵ�ini�ļ���С*/	
#define MAX_FILE_SIZE 1024
	
/*section��ʼ����*/
#define INI_SECTION_LEFT_BRACE '['
/*section�ҽ�������*/
#define INI_SECTION_RIGHT_BRACE ']'

/**
 * ��ini�ļ���һ���ַ���ֵ
 * ������ʱȡĬ��ֵ
 * 
 * @param section	��ȡsection
 * @param key	��ȡkey
 * @param value	��ȡֵ
 * @param size	��ȡ����
 * @param default_value	Ĭ��ֵ
 * @param file �ļ���
 * 
 * @return 1�ɹ���0ʧ��
 */
int vm_read_profile_string( char *section, char *key,char *value, int size,char *default_value, char *file);

/**
 * ��ini�ļ���ȡһ������ֵ
 * ������ʱȡĬ��ֵ
 * 
 * @param section	��ȡsection
 * @param key	��ȡkey
 * @param default_value	Ĭ��ֵ
 * @param file	�ļ���
 * 
 * @return ��ȡֵ
 */
int vm_read_profile_int( char *section, char *key,int default_value, char *file);

/**
 * ��ini�ļ�д��һ���ַ���ֵ
 * �ļ�������ʱ����һ�����ļ���section������ʱ���һ��section��key������ʱ���һ��key��key����ʱ����value
 * Ŀǰ�汾�����ļ���СΪ1k
 * 
 * @param section	д��section
 * @param key	д��key
 * @param value	д��ֵ
 * @param file	�ļ���
 * 
 * @return	1�ɹ���0ʧ�� 
 */
int vm_write_profile_string( char *section, char *key,char *value, char *file);

#ifdef __cplusplus
}; //end of extern "C" {
#endif

#endif //end of INI_FILE_H_

