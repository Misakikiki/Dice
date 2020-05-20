#pragma once

#include "CQMsgSend.h"
#include "CQEVEMsg.h"
/*
讨论组消息(Type=4)

subtype		子类型，目前固定为1
msgId	消息ID
fromDiscuss	来源讨论组
fromQQ		来源QQ号
msg			消息内容
font		字体

本子程序会在酷Q【线程】中被调用，请注意使用对象等需要初始化(CoInitialize,CoUninitialize)
名字如果使用下划线开头需要改成双下划线
返回非零值,消息将被拦截,最高优先不可拦截
*/
#define EVE_DiscussMsg_EX(Name)																	\
	void Name(CQ::EVEDiscussMsg & eve);															\
	EVE_DiscussMsg(Name)																		\
	{																							\
		CQ::EVEDiscussMsg tep(subType, msgId, fromDiscuss, fromQQ, msg, font);					\
		Name(tep);\
		return tep._EVEret;																		\
	}																							\
	void Name(CQ::EVEDiscussMsg & eve)


namespace CQ
{
	struct EVEDiscussMsg : EVEMsg
	{
		long long fromDiscuss; //讨论组号

		EVEDiscussMsg(int subType, int msgId, long long fromDiscuss, long long fromQQ, const char* msg, int font) noexcept;

		bool leave() const noexcept; //退出讨论组
		
		// 通过 EVEMsg 继承
		msg sendMsg() const noexcept override;
		int sendMsg(const char*) const noexcept override;
		int sendMsg(const std::string&) const noexcept override;
	};
}
