#include "Logger.h"
#include <sstream>
#include <ctime>

using namespace std;

/*! 
* \fn CLogger()
* \brief 记录日志类构造函数，初始化所有成员变量，其中输出流初始化为cout
* \return 无
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
* \brief 记录日志类析构函数，若日志文件打开，则关闭
* \return 无
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
* \brief 初始化函数，指定程序名，日志模式，日志文件路径，时间戳标识
* \param[in] appname	当前程序名
* \param[in] logmode	日志模式，默认输出到标准输出
* \param[in] logpath	日志文件路径，默认为当前目录
* \param[in] timeflag	时间戳标识，默认为使用时间戳
* \return 成功则返回0
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
* \brief 记录Debug类型日志
* \param[in] logcode	日志代码
* \param[in] msg		日志信息
* \return 成功则返回0，-1为记录错误，-2为根据当前日志等级，该日志未被记录
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
* \brief 记录Info类型日志
* \param[in] logcode	日志代码
* \param[in] msg		日志信息
* \return 成功则返回0，-1为记录错误，-2为根据当前日志等级，该日志未被记录
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
* \brief 记录统计类型日志
* \param[in] logcode	日志代码
* \param[in] msg		日志信息
* \return 成功则返回0，-1为记录错误，-2为根据当前日志等级，该日志未被记录
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
* \brief 记录Warn类型日志
* \param[in] logcode	日志代码
* \param[in] msg		日志信息
* \return 成功则返回0，-1为记录错误，-2为根据当前日志等级，该日志未被记录
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
* \brief 记录Error类型日志
* \param[in] logcode	日志代码
* \param[in] msg		日志信息
* \return 成功则返回0，-1为记录错误，-2为根据当前日志等级，该日志未被记录
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
* \brief 程序名set方法，指定程序名
* \param[in] appname	程序名
* \return 无
* \author zhujunjie
* \date 2012-2-23
*/
void CLogger::setAppName(string appname)
{
	strAppName = appname;
}

/*! 
* \fn void setLogMode(int logmode)
* \brief 日志模式set方法，指定日志模式
* \param[in] logmode	日志模式
* \return 无
* \author zhujunjie
* \date 2012-2-23
*/
void CLogger::setLogMode(int logmode)
{
	iLogMode = logmode;
}

/*! 
* \fn void setLogPath(string logpath)
* \brief 日志文件路径set方法，指定日志文件路径
* \param[in] logpath	日志文件路径
* \return 无
* \author zhujunjie
* \date 2012-2-23
*/
void CLogger::setLogPath(string logpath)
{
	strLogPath = logpath;
}

/*! 
* \fn void setTimeFlag(int timeflag)
* \brief 时间戳标识set方法，指定时间戳标识
* \param[in] timeflag	时间戳标识
* \return 无
* \author zhujunjie
* \date 2012-2-23
*/
void CLogger::setTimeFlag(int timeflag)
{
	iTimeFlag = timeflag;
}

/*! 
* \fn void setOutputStream(streambuf *buf)
* \brief 日志输出流set方法，指定日志输出流缓存
* \param[in] buf	IO流缓存
* \return 无
* \author zhujunjie
* \date 2012-2-23
*/
void CLogger::setOutputStream(streambuf *buf)
{
	sOutputStream.rdbuf(buf);
}

/*! 
* \fn //WriteLog(int logtype, string logcode, string &msg)
* \brief 写日志函数，将日志输出到标准输出或文件
* \param[in] logtype	日志类型（Debug, Info, Warn, Error等）
* \param[in] logcode	日志代码
* \param[in] msg		日志信息
* \return 成功则返回0，负数为错误
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
* \brief 格式化路径，确保路径以"/"或"\"结尾
* \param[in] path	未格式化的路径
* \return 格式化后的路径
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
* \brief 返回 yyyymmdd 格式的当前日期
* \return yyyymmdd 格式的当前日期
* \author zhujunjie
* \date 2012-2-23
*/
int CLogger::getCurDay()
{
	time_t t = time(NULL);
	struct tm *tp = localtime(&t);
	return (tp->tm_year + 1900) * 10000 + (tp->tm_mon + 1) * 100 + tp->tm_mday;
}

