#pragma once
#include "bufstream.h"
#include <string>

#define DEBUGINFO "文件:" << __FILE__ << ",行数:" << __LINE__ << ",输出:"

namespace CQ
{
	class logstream : public CQstream
	{
		int flag;
		std::string title;
	public:
		logstream(std::string title, int Log_flag) noexcept;

		// 通过 CQstream 继承
		void send() noexcept override;
	};

	class logger
	{
		std::string title;
	public:
		logger(std::string title) noexcept;
		void setTitle(std::string title) noexcept;

		void Debug(const std::string& msg) const noexcept;
		void Info(const std::string& msg) const noexcept;
		void InfoSuccess(const std::string& msg) const noexcept;
		void InfoRecv(const std::string& msg) const noexcept;
		void InfoSend(const std::string& msg) const noexcept;
		void Warning(const std::string& msg) const noexcept;
		void Error(const std::string& msg) const noexcept;
		void Fatal(const std::string& msg) const noexcept;

		void Debug(const char* msg) const noexcept;
		void Info(const char* msg) const noexcept;
		void InfoSuccess(const char* msg) const noexcept;
		void InfoRecv(const char* msg) const noexcept;
		void InfoSend(const char* msg) const noexcept;
		void Warning(const char* msg) const noexcept;
		void Error(const char* msg) const noexcept;
		void Fatal(const char* msg) const noexcept;

		logstream Debug() const noexcept;
		logstream Info() const noexcept;
		logstream InfoSuccess() const noexcept;
		logstream InfoRecv() const noexcept;
		logstream InfoSend() const noexcept;
		logstream Warning() const noexcept;
		logstream Error() const noexcept;
		logstream Fatal() const noexcept;
	};
}
