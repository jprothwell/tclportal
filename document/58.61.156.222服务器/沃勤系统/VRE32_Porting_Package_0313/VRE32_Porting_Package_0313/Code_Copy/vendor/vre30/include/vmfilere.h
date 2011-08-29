#ifndef		_VM_FILE_REMAP_
#define		_VM_FILE_REMAP_

#include "vmsys.h"
#include "vmio.h"

#define REMAP_FILENAME_MAX_LEN 260
//#define REMAP_FILENAME_MAX_LEN 48


#define VM_PERMISSION_SYS_DRV  1
#define VM_PERMISSION_USR_DRV  2

/**
 * ��Ӧ�ñ����ļ���
 *
 * @param filename		��UCS2��ʽ������ļ�·����
 * @param mode			�ļ���ģʽ������MODE_READ����д��MODE_WRITE����
 *						�����ļ�����������Ǵ���֮��MODE_CREATE_ALWAYS_WRITE����
 * @param binary		TRUE��ʾ�Զ����Ƹ�ʽ���ļ���FALSE��ʾ��ASCII��ʽ���ļ���
 *
 * @return				�ɹ����򷵻طǸ�����������Ϊ�������ʾʧ�ܡ�
 */
VMFILE vm_file_open_remap(const VMWSTR filename, VMUINT mode, VMUINT binary);


/**
 * ɾ��Ӧ�ñ����ļ���
 * 
 * @param filename		��UCS2�����ʽ���ļ�·����
 *
 * @return				����0��ʾ�ɹ�������Ϊʧ�ܡ�
 */
VMINT vm_file_delete_remap(const VMWSTR filename);


/**
 * Ӧ�ñ����ļ���������
 * 
 * @param filename		��UCS2��ʽ�����ԭʼ�ļ�·����
 * @param newname		��UCS2��ʽ�����Ŀ���ļ�·����
 *
 * @return				����0��ʾ�ɹ�������Ϊʧ�ܡ�
 */
VMINT vm_file_rename_remap(const VMWSTR filename, const VMWSTR newname);


/**
 * ��Ӧ�ñ��ز��Ҹ���Ŀ¼�µ��ļ�������ʹ��*ͨ�����
 *
 * @param pathname			����·����
 * @param info				�ҵ����ļ���Ϣ��
 *
 * @return					���ظ�����ʾʧ�ܣ����򷵻ش��ڻ����0��һ�����Ҿ����
 */
VMINT vm_find_first_remap(VMWSTR pathname, struct vm_fileinfo_t* info);


/**
 * ����Ӧ�ñ���Ŀ¼��
 *
 * @param dirname		��UCS2��ʽ�����·������
 *
 * @return				����0��ʾ�ɹ�������Ϊʧ�ܡ�
 */
VMINT vm_file_mkdir_remap(const VMWSTR dirname);


/**
 * ɾ��Ӧ�ñ���Ŀ¼��
 *
 * @param dirname		��UCS2��ʽ����ı�ɾ��·������
 *
 * @return				����0��ʾ�ɹ�������Ϊʧ�ܡ�
 */
VMINT vm_file_rmdir_remap(const VMWSTR dirname);

/**
 * ���Ҹ���Ŀ¼�µ��ļ�������ʹ��*ͨ�����
 *
 * @param pathname			����·����
 * @param direntry				�ҵ����ļ���Ŀ¼��Ϣ��
 *
 * @return					���ظ�����ʾʧ�ܣ����򷵻ش��ڻ����0��һ�����Ҿ����
 */
VMINT vm_find_first_remap_ext(VMWSTR pathname,  vm_fileinfo_ext * direntry);

/**
 * �����ļ����ԡ�
 * ���õ�ֵ���ܰ���VM_FS_ATTR_VOLUME��VM_FS_ATTR_DIR��VM_FS_LONGNAME_ATTR
 * �ļ����Ե�ֵΪ����������ֵ������ֵ��ο��ļ����Եĺ궨�塣
 *
 * @param filename   �ļ���(��ȫ·��)��
 * @param attributes  �ļ����ԡ�
 *
 * @return       ����0��ʾ�ɹ�������Ϊʧ�ܡ�
 */
VMINT vm_file_set_attributes_remap(const VMWSTR filename, VMBYTE attributes);

/**
 * ��ȡ�ļ����ԡ�
 * �ļ����Ե�ֵΪ����������ֵ������ֵ��ο��ļ����Եĺ궨�塣
 *
 * @param filename  �ļ���(��ȫ·��)��
 *
 * @return �����ļ����ԣ�����Ϊʧ�ܡ�
 */
VMINT vm_file_get_attributes_remap(const VMWSTR filename);

#endif
