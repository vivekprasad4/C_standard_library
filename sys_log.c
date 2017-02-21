#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#define __PCF_FILE__   __FILE__
#define __PCF_LINE__   __LINE__

#define pcf_debug()                                                    pcf_DebugSupport_debugger(__PCF_FILE__, __PCF_LINE__)
#define pcf_debug_info(__TEXT_MESSAGE__)                               pcf_DebugSupport_debuggerMsg(__PCF_FILE__, __PCF_LINE__, __TEXT_MESSAGE__, (uint8_t)1)
#define pcf_debug_error(__TEXT_MESSAGE__)                              pcf_DebugSupport_debuggerMsg(__PCF_FILE__, __PCF_LINE__, __TEXT_MESSAGE__, (uint8_t)2)
#define pcf_report_to_stderror(__TEXT_MESSAGE__)                       fprintf(stderr, "pcf:error(%s:%d:%s)", __PCF_FILE__, __PCF_LINE__, __TEXT_MESSAGE__)
#define pcf_report_error()                                             pcf_DebugSupport_reportError(__PCF_FILE__, __PCF_LINE__)
#define pcf_report_error_with_mesage(__TEXT_MESSAGE__)                 pcf_DebugSupport_reportErrorMsg(__PCF_FILE__, __PCF_LINE__, __TEXT_MESSAGE__)
#define pcf_report_unexpected_error()                                  pcf_DebugSupport_reportUnexpectedError(__PCF_FILE__, __PCF_LINE__)
#define pcf_report_unexpected_error_with_message(__TEXT_MESSAGE__)     pcf_DebugSupport_reportUnexpectedErrorMsg(__PCF_FILE__, __PCF_LINE__, __TEXT_MESSAGE__)

#define pcf_assert(___CONDITION__)                                     if (!(___CONDITION__)) pcf_DebugSupport_assert \
                                                                              (#___CONDITION__,__PCF_FILE__, __PCF_LINE__, (Cstring_t)0); else (void) 0
#define pcf_assert_with_message(___CONDITION__, __TEXT_MESSAGE__)      if (!(___CONDITION__)) pcf_DebugSupport_assert(#___CONDITION__,\
                                                                              __PCF_FILE__, __PCF_LINE__, __TEXT_MESSAGE__); else (void) 0
#define pcf_check_for_null_pointer(__PTR_TO_CHECK__)                   if (!(__PTR_TO_CHECK__)) pcf_DebugSupport_checkForNullPointer(#__PTR_TO_CHECK__,\
                                                                              __PCF_FILE__, __PCF_LINE__); else (void) 0

typedef const char * Cstring_t;

static const char msg_MAIN[]            = {"Embedded Phi C Framework Debug Log"};
static const char msg_EOL[]             = {"\n"};
static const char msg_LOG[]             = {"Log File"};
static const char msg_VERB_L[]          = {"Verbosity Level"};
static const char msg_TIME_EN[]         = {"Time Stamp Enabled"};
static const char msg_LINE_BK[]         = {"--------------------------------------------------------------------------------"};

static const char msg_Serverity[]       = {"Serverity"};
static const char* serverity_Tag[]      = { "None","Live","Info","Warn","Debug","Error","Fatal","Panic"};
static const char msg_Tag[]             = {"Tag"};
static const char msg_Message_header[]  = {"Debug Message"};

/** @brief Enum for Log Level */
typedef enum {
    enEPCFLogLevelNone = 0,     /**< None Log                           */
    enEPCFLogLevelLive,         /**< Live Log                           */
    enEPCFLogLevelInfo,         /**< Info Log                           */
    enEPCFLogLevelWarn,         /**< Warn Log                           */
    enEPCFLogLevelDebug,        /**< Debug Log                          */
    enEPCFLogLevelError,        /**< Error Log                          */
    enEPCFLogLevelFatal,        /**< Fatal Log                          */
    enEPCFLogLevelPanic,        /**< Panic Log                          */
    enEPCFLogLevelMax           /**< Used for Boundry Checking of Enum  */
} EnEPCFDebugLogLevel_t;

/** @brief Enum for Log Level */
typedef enum {
    enEPCFLogDeviceConsole = 0, /**< None Log                           */
    enEPCFLogDeviceFile,        /**< Live Log                           */
    enEPCFLogLevelAdapter,      /**< Info Log                           */
    enEPCFLogDeviceMax          /**< Used for Boundry Checking of Enum  */
} EnEPCFDebugDeviceType_t;

/** @brief Logger flags */
typedef enum {
    enEPCFLogTimeEnable = 0,    /**< Time Logging Enable                */
    enEPCFLogTimeDisable,       /**< Time Logging Disable               */
    enEPCFLogTimeMax            /**< Used for Boundry Checking of Enum  */
} EnEPCFDebugLogTime_t;

/** @brief File Logger configuration structure.
 *  @details  Used for printing the Log info to the File System.
 */
typedef struct
{
    Cstring_t                 filename;         /**< Log File Name              */
    EnEPCFDebugLogLevel_t     verbosityLevel;   /**< Verbocity Level of Logger  */
    EnEPCFDebugLogTime_t      timeStampFlag;    /**< Time stamp for Logging     */
} EPCFDebugDeviceFileCfg_t;

/** @brief Console Logger configuration structure. 
 *  @details  Used for printing the Log info to the Standrad output.
 */
typedef struct
{
    EnEPCFDebugLogLevel_t     verbosityLevel;   /**< Verbocity Level of Logger  */
    EnEPCFDebugLogTime_t      timeStampFlag;    /**< Time stamp for Logging     */
} EPCFDebugDeviceConsoleCfg_t;

/** @brief Logger configuration structure. */
typedef struct {
    EnEPCFDebugDeviceType_t   loggerType;       /**< Log Device Type/ID : define's type of Logger device  */
    void *                    loggerCfg;        /**< Configuration Stucture of the Logger device          */
} EPCFDebugLoggerCfg_t;


#define _DEVICE_CFG(member)   ((EPCFDebugDeviceFileCfg_t*)(debugDeviceCfg.loggerCfg))->member

static char debugMsgBuffer[500] = {};

static EPCFDebugDeviceFileCfg_t fileLogger =
{
    ((Cstring_t)"./epcf_logger.log"),
    enEPCFLogLevelError,
    enEPCFLogTimeEnable
};

/* Used variables */
static EPCFDebugLoggerCfg_t debugDeviceCfg;
static int32_t _pcf_DebugSupport_fileLogWrite();
static void _pcf_DebugSupport_File_log_info();

//pcf_DebugSupport_formatCallback_t epcfDebugCallback;

bool pcf_DebugSupport_init()
{
    bool retValue = false;

    debugDeviceCfg.loggerType = enEPCFLogDeviceFile;
    debugDeviceCfg.loggerCfg = (void*)&fileLogger;

    _pcf_DebugSupport_File_log_info();
    return (retValue);
}

void pcf_DebugSupport_checkForNullPointer(Cstring_t pointerToCheck, Cstring_t file, int line)
{
	sprintf(debugMsgBuffer, "%-9d  %-5s  NULL ptr in variable '%s' in %s at line %d%s", enEPCFLogLevelDebug, (char *)serverity_Tag[enEPCFLogLevelDebug], (char*)pointerToCheck,(char *)file,line,(char *)msg_EOL );
	_pcf_DebugSupport_fileLogWrite();
}

void pcf_DebugSupport_reportError(Cstring_t file, int line)
{
	sprintf(debugMsgBuffer, "%-9d  %-5s  ERROR Reporting in %s at line %d%s", enEPCFLogLevelError, (char *)serverity_Tag[enEPCFLogLevelError],(char *)file,line,(char *)msg_EOL );
	_pcf_DebugSupport_fileLogWrite();
}

void pcf_DebugSupport_reportErrorMsg(Cstring_t file, int line, Cstring_t message)
{
	sprintf(debugMsgBuffer, "%-9d  %-5s  Reporting Error with msg: '%s' in %s at line %d%s", enEPCFLogLevelError, (char *)serverity_Tag[enEPCFLogLevelError],(char*)message,(char *)file,line,(char *)msg_EOL );
	_pcf_DebugSupport_fileLogWrite();
}

void pcf_DebugSupport_reportUnexpectedError(Cstring_t file, int line)
{
	sprintf(debugMsgBuffer, "%-9d  %-5s  Reporting Unexpected Error in %s at line %d%s", enEPCFLogLevelFatal, (char *)serverity_Tag[enEPCFLogLevelFatal],(char *)file,line,(char *)msg_EOL );
	_pcf_DebugSupport_fileLogWrite();
}

void pcf_DebugSupport_reportUnexpectedErrorMsg(Cstring_t file, int line, Cstring_t message)
{
	sprintf(debugMsgBuffer, "%-9d  %-5s  Reporting Unexpected Error with msg: '%s' in %s at line %d%s", enEPCFLogLevelFatal, (char *)serverity_Tag[enEPCFLogLevelFatal],(char*)message,(char *)file,line,(char *)msg_EOL );
	_pcf_DebugSupport_fileLogWrite();
}

void pcf_DebugSupport_debugger(Cstring_t file, int line)
{
	sprintf(debugMsgBuffer, "%-9d  %-5s  Debug info in %s at line %d%s", enEPCFLogLevelDebug, (char *)serverity_Tag[enEPCFLogLevelDebug],(char *)file,line,(char *)msg_EOL );
	_pcf_DebugSupport_fileLogWrite();
}

void pcf_DebugSupport_debuggerMsg(Cstring_t file, int line, Cstring_t message, uint8_t messageType)
{
	if (messageType == 1)
		sprintf(debugMsgBuffer, "%-9d  %-5s  Debug info with msg: '%s' in %s at line %d%s", enEPCFLogLevelInfo, (char *)serverity_Tag[enEPCFLogLevelInfo],(char*)message,(char *)file,line,(char *)msg_EOL );
	else if (messageType == 2)
		sprintf(debugMsgBuffer, "%-9d  %-5s  Debug error with msg: '%s' in %s at line %d%s", enEPCFLogLevelError, (char *)serverity_Tag[enEPCFLogLevelError],(char*)message,(char *)file,line,(char *)msg_EOL );

	_pcf_DebugSupport_fileLogWrite();
}

void pcf_DebugSupport_assert(Cstring_t condition, Cstring_t file, int line, Cstring_t message)
{

}

//******************************************************************************************************************/
//  List of ALL Static Function of Logger.c
//******************************************************************************************************************/

void _pcf_DebugSupport_File_log_info()
{
    sprintf(debugMsgBuffer, "%-34s%s", (char*)msg_MAIN, (char *)msg_EOL);
    _pcf_DebugSupport_fileLogWrite();
    
    sprintf(debugMsgBuffer, "%-19s : %s%s", (char *)msg_LOG ,_DEVICE_CFG(filename), (char *)msg_EOL);
    _pcf_DebugSupport_fileLogWrite(debugMsgBuffer);
    
    sprintf(debugMsgBuffer, "%-19s : %-2d%s", (char *)msg_VERB_L , _DEVICE_CFG(verbosityLevel), (char *)msg_EOL);
    _pcf_DebugSupport_fileLogWrite(debugMsgBuffer);
    
    sprintf(debugMsgBuffer, "%-19s : %s%s", (char *)msg_TIME_EN , (char *)"ENABLED", (char *)msg_EOL);
    _pcf_DebugSupport_fileLogWrite(debugMsgBuffer);

    sprintf(debugMsgBuffer, "%-19s%s", (char *)msg_LINE_BK , (char *)msg_EOL);
    _pcf_DebugSupport_fileLogWrite(debugMsgBuffer);

    sprintf(debugMsgBuffer, "%-9s  %-5s  %s%s", (char *)msg_Serverity, (char *)msg_Tag, (char*)msg_Message_header,(char *)msg_EOL );
    _pcf_DebugSupport_fileLogWrite(debugMsgBuffer);

    //sprintf(debugMsgBuffer, "%-9s  %-5s  %s%s", (char *)msg_Serverity, (char *)msg_Tag, (char*)msg_Message_header,(char *)msg_EOL );
    sprintf(debugMsgBuffer, "%-19s%s", (char *)msg_LINE_BK , (char *)msg_EOL);
    _pcf_DebugSupport_fileLogWrite(debugMsgBuffer);
}

static int32_t _pcf_DebugSupport_fileLogWrite()
{
    /* Open file pointer */

    FILE *fp ;
    //((EPCFDebugDeviceFileCfg_t*)(debugDeviceCfg.loggerCfg))->verbosityLevel
    //if(_DEVICE_CFG())
    //{
		fp=fopen(_DEVICE_CFG(filename), "a");
		if (fp == NULL) return (-1);

		/* Write key in file */
		fprintf(fp, "%s", debugMsgBuffer);
		//fprintf(stdout, "%s", debugMsgBuffer);

		/* Close file pointer */
		fclose(fp);
    //}
    return (0);
}

int main()
{
	char * test = (char *)0;
	//pcf_DebugSupport_init(myDebugCallBack);
	pcf_DebugSupport_init();
	pcf_debug();
    pcf_debug_info("MY Testing of debug");
    pcf_check_for_null_pointer(test);
    pcf_report_error();
    pcf_report_error_with_mesage("pcf_report_error_with_mesage");
    pcf_report_unexpected_error();
    pcf_report_unexpected_error_with_message("pcf_report_unexpected_error_with_message");
	printf("\r\ndebug Tesing Done\n\r");
    
    return 0;
}
