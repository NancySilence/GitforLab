/*!
 *	\class	CLogger
 *	\brief	��¼��־��
 *	\n		�����־������������ļ������죩���׼���
 *  \n		ʹ��ʱ���ȵ���Init()����ָ����ǰ����������־ģʽ����־�ļ�·����ʱ�����ʶ
 *  \n		��־��ΪDebug, Info, Warn, Error���࣬���ȼ���������LOG_LEVEL����
 *	\n		����LOG_LEVEL�󣬴��ڵ��ڸõȼ�����־�������������Ĭ��LOG_LEVELΪLOG_INFOTYPE�������Info, Warn, Error������־
 *	\n		��ʹ��Ԥ����������LOG_ALL, LOG_DEBUG, LOG_INFO, LOG_WARN, LOG_ERROR, LOG_NONE����LOG_LEVEL�Ķ��壬���ȼ�����
 *	\n		Ԥ����������(LOG_ALL��)�����LOG_LEVEL�겻����Ч
 *	\n		����������־ģʽ���ļ�·����ʱ�����ʶ���������ʹ��set�����޸�
 *	\date	2012-2-23 
 *	\author zhujunjie(zhujunjie@software.ict.ac.cn)	
*/

#ifndef CLOGGER_H
#define CLOGGER_H

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;

#define LOG_TOCONSOLE	0		//��־�������׼�����Ĭ��
#define LOG_TOFILE		1		//��־������ļ������죩

#define LOG_WITHTIME	0		//��־����ʱ�����Ĭ�ϣ�
#define LOG_WITHOUTTIME	1		//��־��ʹ��ʱ���

#define LOG_INFOTYPE	0		//Info��־����
#define LOG_STATTYPE	1		//ͳ����־����
#define LOG_WARNTYPE	2		//Warn��־����
#define LOG_ERRORTYPE	3		//Error��־����
#define LOG_DEBUGTYPE	-1		//Debug��־����
#define LOG_ALLTYPE		-5		//������־����
#define LOG_NONETYPE	5		//����������־����

#define LOG_LEVEL		LOG_INFOTYPE	//��־�ȼ���Ĭ��ΪInfo�ȼ�

class CLogger
{
public:
	//------------------���캯������������-------------------
	/*! 
	* \fn CLogger()
	* \brief ��¼��־�๹�캯������ʼ�����г�Ա�����������������ʼ��Ϊcout
	* \return ��
	* \author zhujunjie
	* \date 2012-2-23
	*/
	CLogger();

	/*! 
	* \fn ~CLogger()
	* \brief ��¼��־����������������־�ļ��򿪣���ر�
	* \return ��
	* \author zhujunjie
	* \date 2012-2-23
	*/
	~CLogger();
public:

	/*! 
	* \fn int Init(string appname, int logmode = LOG_TOCONSOLE, string logpath = "", int timeflag = LOG_WITHTIME)
	* \brief ��ʼ��������ָ������������־ģʽ����־�ļ�·����ʱ�����ʶ
	* \param[in] appname	��ǰ������
	* \param[in] logmode	��־ģʽ��Ĭ���������׼���
	* \param[in] logpath	��־�ļ�·����Ĭ��Ϊ��ǰĿ¼
	* \param[in] timeflag	ʱ�����ʶ��Ĭ��Ϊʹ��ʱ���
	* \return �ɹ��򷵻�0
	* \author zhujunjie
	* \date 2012-2-23
	*/
	int Init(string appname, int logmode = LOG_TOCONSOLE, string logpath = "", int timeflag = LOG_WITHTIME);
	
	/*! 
	* \fn int LogDebug(string logcode, string &msg)
	* \brief ��¼Debug������־
	* \param[in] logcode	��־����
	* \param[in] msg		��־��Ϣ
	* \return �ɹ��򷵻�0��-1Ϊ��¼����-2Ϊ���ݵ�ǰ��־�ȼ�������־δ����¼
	* \author zhujunjie
	* \date 2012-2-23
	*/
	int LogDebug(string logcode, string &msg);

	/*! 
	* \fn int LogInfo(string logcode, string &msg)
	* \brief ��¼Info������־
	* \param[in] logcode	��־����
	* \param[in] msg		��־��Ϣ
	* \return �ɹ��򷵻�0��-1Ϊ��¼����-2Ϊ���ݵ�ǰ��־�ȼ�������־δ����¼
	* \author zhujunjie
	* \date 2012-2-23
	*/
	int LogInfo(string logcode, string &msg);

	/*! 
	* \fn int LogStat(string logcode, string &msg)
	* \brief ��¼ͳ��������־
	* \param[in] logcode	��־����
	* \param[in] msg		��־��Ϣ
	* \return �ɹ��򷵻�0��-1Ϊ��¼����-2Ϊ���ݵ�ǰ��־�ȼ�������־δ����¼
	* \author zhujunjie
	* \date 2012-2-23
	*/
	int LogStat(string logcode, string &msg);

	/*! 
	* \fn intLogWarn(string logcode, string &msg)
	* \brief ��¼Warn������־
	* \param[in] logcode	��־����
	* \param[in] msg		��־��Ϣ
	* \return �ɹ��򷵻�0��-1Ϊ��¼����-2Ϊ���ݵ�ǰ��־�ȼ�������־δ����¼
	* \author zhujunjie
	* \date 2012-2-23
	*/
	int LogWarn(string logcode, string &msg);

	/*! 
	* \fn int LogError(string logcode, string &msg)
	* \brief ��¼Error������־
	* \param[in] logcode	��־����
	* \param[in] msg		��־��Ϣ
	* \return �ɹ��򷵻�0��-1Ϊ��¼����-2Ϊ���ݵ�ǰ��־�ȼ�������־δ����¼
	* \author zhujunjie
	* \date 2012-2-23
	*/
	int LogError(string logcode, string &msg);
	
	/*! 
	* \fn void setAppName(string appname)
	* \brief ������set������ָ��������
	* \param[in] appname	������
	* \return ��
	* \author zhujunjie
	* \date 2012-2-23
	*/
	void setAppName(string appname);

	/*! 
	* \fn void setLogMode(int logmode)
	* \brief ��־ģʽset������ָ����־ģʽ
	* \param[in] logmode	��־ģʽ
	* \return ��
	* \author zhujunjie
	* \date 2012-2-23
	*/
	void setLogMode(int logmode);

	/*! 
	* \fn void setLogPath(string logpath)
	* \brief ��־�ļ�·��set������ָ����־�ļ�·��
	* \param[in] logpath	��־�ļ�·��
	* \return ��
	* \author zhujunjie
	* \date 2012-2-23
	*/
	void setLogPath(string logpath);

	/*! 
	* \fn void setTimeFlag(int timeflag)
	* \brief ʱ�����ʶset������ָ��ʱ�����ʶ
	* \param[in] timeflag	ʱ�����ʶ
	* \return ��
	* \author zhujunjie
	* \date 2012-2-23
	*/
	void setTimeFlag(int timeflag);

	/*! 
	* \fn void setOutputStream(streambuf *buf)
	* \brief ��־�����set������ָ����־���������
	* \param[in] buf	IO������
	* \return ��
	* \author zhujunjie
	* \date 2012-2-23
	*/
	void setOutputStream(streambuf *buf);

private:
	
	/*! 
	* \fn //WriteLog(int logtype, string logcode, string &msg)
	* \brief д��־����������־�������׼������ļ�
	* \param[in] logtype	��־���ͣ�Debug, Info, Warn, Error�ȣ�
	* \param[in] logcode	��־����
	* \param[in] msg		��־��Ϣ
	* \return �ɹ��򷵻�0������Ϊ����
	* \author zhujunjie
	* \date 2012-2-23
	*/
	int WriteLog(int logtype, string logcode, string &msg);

	/*! 
	* \fn string formatPath(string path)
	* \brief ��ʽ��·����ȷ��·����"/"��"\"��β
	* \param[in] path	δ��ʽ����·��
	* \return ��ʽ�����·��
	* \author zhujunjie
	* \date 2012-2-23
	*/
	string formatPath(string path);

	/*! 
	* \fn inline int getCurDay()
	* \brief ���� yyyymmdd ��ʽ�ĵ�ǰ����
	* \return yyyymmdd ��ʽ�ĵ�ǰ����
	* \author zhujunjie
	* \date 2012-2-23
	*/
	inline int getCurDay();

public:

private:
	string strAppName;		/**< ��ǰ������ */
	int iLogMode;			/**< ��־ģʽ */
	string strLogPath;		/**< ��־�ļ�·�� */
	int iTimeFlag;			/**< ʱ�����ʶ */
	string strLogFileName;	/**< ��־�ļ��� */
	ofstream sLogFile;		/**< ��־�ļ������ */
	iostream sOutputStream;	/**< ��־�����������Ϊ��׼������ļ� */
	int iCurDay;			/**< ��ǰ���� */
};
#endif
