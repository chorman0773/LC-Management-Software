#pragma once


#include <filesystem>
#include <memory>
#include <cstdint>

#include "forward.hpp"

#ifdef _WIN32
#include "windows/windows_ext.inl"
#endif

namespace lc::mansoft::extension {
	extern"C" using ExtensionInitFn = std::int32_t(Extension*);

	MANSOFT_API class ExtensionObject {
	private:
		friend class Extension;
	protected:
		virtual void load(Extension*) = 0;
		virtual void unload(Extension*) = 0;
		virtual void saveState(Extension*, StateManager*) = 0;
		virtual void loadState(Extension*, StateManager*) = 0;
	public:
		virtual ~ExtensionObject() = default;
	};

	MANSOFT_API class Extension {
	private:
		_detail::libhandle mod;
		ExtensionInitFn* extensionInitFn;
		std::vector<std::unique_ptr<ExtensionObject>> extensionRefs;
	public:
		Extension(const std::filesystem::path& extpath);
		~Extension();
		void registerExtension(std::unique_ptr<ExtensionObject>&&);
		void load();
		void unload();
		void saveState(StateManager&);
		void loadState(StateManager&);
	};

}