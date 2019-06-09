#include "pch.h"
#include "Extension.hpp"

using namespace lc::mansoft::extension;

Extension::Extension(const std::filesystem::path& p) :mod(LoadLibrary(p.c_str())), extensionInitFn((ExtensionInitFn*)GetProcAddress(mod, L"ExtensionInit")) {}

Extension::~Extension() {
	extensionRefs.clear();//Need to clear before unloading the Library, otherwise issues.
	FreeLibrary(mod);
}

void Extension::load() {
	for (auto&& ext : extensionRefs)
		ext->load(this);
}

void Extension::unload() {
	for (auto&& ext : extensionRefs)
		ext->unload(this);
}

void Extension::saveState(StateManager& stateMan) {
	for (auto&& ext : extensionRefs)
		ext->saveState(this, &stateMan);
}

void Extension::loadState(StateManager& stateMan) {
	for (auto&& ext : extensionRefs)
		ext->loadState(this, &stateMan);
}

void Extension::registerExtension(std::unique_ptr<ExtensionObject>&& obj) {
	extensionRefs.push_back(std::move(obj));
}