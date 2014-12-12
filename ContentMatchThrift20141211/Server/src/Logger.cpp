#include "Logger.h"
#include <sstream>
#include <ctime>

using namespace std;

/*! 
* \fn CLogger()
* \brief ��¼��־�๹�캯������ʼ�����г�Ա�����������������ʼ��Ϊcout
* \return ��
* \author zhujunjie
* \date 2012-2-23
*/
CLogger::CLogger():sOutputStream(cout.rdbuf())
{
	strAppName = "";
	iLogMode = 0;
	strLogPath = "";
	iTimeFlag = 0;
	strLogFileName = "";
	iCurDay = 0;
}

/*! 
* \fn ~CLogger()
* \brief ��¼��־����������������־�ļ��򿪣���ر�
* \return ��
* \author zhujunjie
* \date 2012-2-23
*/
CLogger::~CLogger()
{
	if (sLogFile.is_open())
	{
		sLogFile.close();
	}
}

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
int CLogger::Init(string appname, int logmode, string logpath, int timeflag)
{
	strAppName = appname;
	iLogMode = logmode;
	strLogPath = formatPath(logpath);
	iTimeFlag = timeflag;
	return 0;
}

/*! 
* \fn int LogDebug(string logcode, string &msg)
* \brief ��¼Debug������־
* \param[in] logcode	��־����
* \param[in] msg		��־��Ϣ
* \return �ɹ��򷵻�0��-1Ϊ��¼����-2Ϊ���ݵ�ǰ��־�ȼ�������־δ����¼
* \author zhujunjie
* \date 2012-2-23
*/
int CLogger::LogDebug(string logcode, string &msg)
{
#if defined(LOG_DEBUG) || defined(LOG_ALL)
	return WriteLog(LOG_DEBUGTYPE, logcode, msg);
#elif defined(LOG_INFO) || defined(LOG_WARN) || defined(LOG_ERROR) || defined(LOG_NONE)
	return -2;
#else
	if (LOG_LEVEL <= LOG_DEBUGTYPE)
	{
		return WriteLog(LOG_DEBUGTYPE, logcode, msg);
	}
	return -2;
#endif
}

/*! 
* \fn int LogInfo(string logcode, string &msg)
* \brief ��¼Info������־
* \param[in] logcode	��־����
* \param[in] msg		��־��Ϣ
* \return �ɹ��򷵻�0��-1Ϊ��¼����-2Ϊ���ݵ�ǰ��־�ȼ�������־δ����¼
* \author zhujunjie
* \date 2012-2-23
*/
int CLogger::LogInfo(string logcode, string &msg)
{
#if defined(LOG_DEBUG) || defined(LOG_INFO) || defined(LOG_ALL)
	return WriteLog(LOG_INFOTYPE, logcode, msg);
#elif defined(LOG_WARN) || defined(LOG_ERROR) || defined(LOG_NONE)
	return -2;
#else
	if (LOG_LEVEL <= LOG_INFOTYPE)
	{
		return WriteLog(LOG_INFOTYPE, logcode, msg);
	}
	return -2;
#endif
}

/*! 
* \fn int LogStat(string logcode, string &msg)
* \brief ��¼ͳ��������־
* \param[in] logcode	��־����
* \param[in] msg		��־��Ϣ
* \return �ɹ��򷵻�0��-1Ϊ��¼����-2Ϊ���ݵ�ǰ��־�ȼ�������־δ����¼
* \author zhujunjie
* \date 2012-2-23
*/
int CLogger::LogStat(string logcode, string &msg)
{
#if defined(LOG_DEBUG) || defined(LOG_INFO) || defined(LOG_ALL) || defined(LOG_STAT)
	return WriteLog(LOG_INFOTYPE, logcode, msg);
#elif defined(LOG_WARN) || defined(LOG_ERROR) || defined(LOG_NONE)
	return -2;
#else
	if (LOG_LEVEL <= LOG_STATTYPE)
	{
		return WriteLog(LOG_STATTYPE, logcode, msg);
	}
	return -2;
#endif
}

/*! 
* \fn intLogWarn(string logcode, string &msg)
* \brief ��¼Warn������־
* \param[in] logcode	��־����
* \param[in] msg		��־��Ϣ
* \return �ɹ��򷵻�0��-1Ϊ��¼����-2Ϊ���ݵ�ǰ��־�ȼ�������־δ����¼
* \author zhujunjie
* \date 2012-2-23
*/
int CLogger::LogWarn(string logcode, string &msg)
{
#if defined(LOG_DEBUG) || defined(LOG_INFO) || defined(LOG_WARN) || defined(LOG_ALL)
	return WriteLog(LOG_WARNTYPE, logcode, msg);
#elif defined(LOG_ERROR) || defined(LOG_NONE)
	return -2;
#else
	if (LOG_LEVEL <= LOG_WARNTYPE)
	{
		return WriteLog(LOG_WARNTYPE, logcode, msg);
	}
	return -2;
#endif
}

/*! 
* \fn int LogError(string logcode, string &msg)
* \brief ��¼Error������־
* \param[in] logcode	��־����
* \param[in] msg		��־��Ϣ
* \return �ɹ��򷵻�0��-1Ϊ��¼����-2Ϊ���ݵ�ǰ��־�ȼ�������־δ����¼
* \author zhujunjie
* \date 2012-2-23
*/
int CLogger::LogError(string logcode, string &msg)
{
#if defined(LOG_DEBUG) || defined(LOG_INFO) || defined(LOG_WARN) || defined(LOG_ERROR) || defined(LOG_ALL)
	return WriteLog(LOG_ERRORTYPE, logcode, msg);
#elif defined(LOG_NONE)
	return -2;
#else
	if (LOG_LEVEL <= LOG_ERRORTYPE)
	{
		return WriteLog(LOG_ERRORTYPE, logcode, msg);
	}
	return -2;
#endif
}

/*! 
* \fn void setAppName(string appname)
* \brief ������set������ָ��������
* \param[in] appname	������
* \return ��
* \author zhujunjie
* \date 2012-2-23
*/
void CLogger::setAppName(string appname)
{
	strAppName = appname;
}

/*! 
* \fn void setLogMode(int logmode)
* \brief ��־ģʽset������ָ����־ģʽ
* \param[in] logmode	��־ģʽ
* \return ��
* \author zhujunjie
* \date 2012-2-23
*/
void CLogger::setLogMode(int logmode)
{
	iLogMode = logmode;
}

/*! 
* \fn void setLogPath(string logpath)
* \brief ��־�ļ�·��set������ָ����־�ļ�·��
* \param[in] logpath	��־�ļ�·��
* \return ��
* \author zhujunjie
* \date 2012-2-23
*/
void CLogger::setLogPath(string logpath)
{
	strLogPath = logpath;
}

/*! 
* \fn void setTimeFlag(int timeflag)
* \brief ʱ�����ʶset������ָ��ʱ�����ʶ
* \param[in] timeflag	ʱ�����ʶ
* \return ��
* \author zhujunjie
* \date 2012-2-23
*/
void CLogger::setTimeFlag(int timeflag)
{
	iTimeFlag = timeflag;
}

/*! 
* \fn void setOutputStream(streambuf *buf)
* \brief ��־�����set������ָ����־���������
* \param[in] buf	IO������
* \return ��
* \author zhujunjie
* \date 2012-2-23
*/
void CLogger::setOutputStream(streambuf *buf)
{
	sOutputStream.rdbuf(buf);
}

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
int CLogger::WriteLog(int logtype, string logcode, string &msg)
{
	if (iLogMode == LOG_TOCONSOLE)
	{
		sOutputStream.rdbuf(cout.rdbuf());
	}
	else if (iLogMode == LOG_TOFILE)
	{
		int day = getCurDay();
		if (iCurDay != day)
		{
			sLogFile.close();
			iCurDay = day;
			stringstream ss("");
			ss << strLogPath << strAppName << '_' << iCurDay << ".log";
			strLogFileName = ss.str();
		}
		if (!sLogFile.is_open())
		{
			sLogFile.open(strLogFileName.c_str(), fstream::out | fstream::app);
			if (sLogFile.fail())
			{
				cout << "Open log file error" << endl;
				return -1;
			}
		}
		sOutputStream.rdbuf(sLogFile.rdbuf());
	}
	else
	{
		cout << "Log mode error!" << endl;
		return -1;	
	}

	time_t t = time(NULL) ;
	struct tm *p;
	p = localtime(&t);
	char timestr[30];
	memset(timestr,0,30);
	if (iTimeFlag == LOG_WITHTIME)
	{		
		sprintf(timestr,"<%4d-%02d-%02d %02d:%02d:%02d>", 1900 + p->tm_year, 1 + p->tm_mon, p->tm_mday, p->tm_hour, p->tm_min, p->tm_sec);
		sOutputStream << timestr;
	}
	sOutputStream << "<[App][" << strAppName << "]><[";
	if (logtype == LOG_DEBUGTYPE)
	{
		sOutputStream << "DebugCode][" << logcode << "]><[DebugMsg][";
	}
	if (logtype == LOG_INFOTYPE)
	{
		sOutputStream << "InfoCode][" << logcode << "]><[InfoMsg][";
	}
	else if (logtype == LOG_STATTYPE)
	{
		sOutputStream << "StatCode][" << logcode << "]><[InfoMsg][";
	}
	else if (logtype == LOG_WARNTYPE)
	{
		sOutputStream << "WarnCode][" << logcode << "]><[WarnMsg][";
	}
	else if (logtype == LOG_ERRORTYPE)
	{
		sOutputStream << "ErrorCode][" << logcode << "]><[ErrorMsg][";
	}
	sOutputStream << msg << "]>" << endl;

	if (iLogMode == LOG_TOFILE)
	{
		sLogFile.flush();
	}

	return 0;
}

/*! 
* \fn string formatPath(string path)
* \brief ��ʽ��·����ȷ��·����"/"��"\"��β
* \param[in] path	δ��ʽ����·��
* \return ��ʽ�����·��
* \author zhujunjie
* \date 2012-2-23
*/
string CLogger::formatPath(string path)
{
	if (path.length() == 0 || path[path.length() -1] == '/' || path[path.length() - 1] == '\\')
	{
		return path;
	}
	else
	{
#ifdef WIN32		
		return path + '\\';
#else
		return path + '/';
#endif
	}
}

/*! 
* \fn inline int getCurDay()
* \brief ���� yyyymmdd ��ʽ�ĵ�ǰ����
* \return yyyymmdd ��ʽ�ĵ�ǰ����
* \author zhujunjie
* \date 2012-2-23
*/
int CLogger::getCurDay()
{
	time_t t = time(NULL);
	struct tm *tp = localtime(&t);
	return (tp->tm_year + 1900) * 10000 + (tp->tm_mon + 1) * 100 + tp->tm_mday;
}

