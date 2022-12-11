module;
#include <string>
#include <spdlog/spdlog.h>

export module libmodule;

export namespace lib
{
	void log(std::string text);
}

module :private;
void lib::log(std::string text)
{
	spdlog::default_logger()->info(text);
};
