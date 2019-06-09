#pragma once

#include <cstdint>

#ifdef MANAGEMENTSOFTWARELIBRARY_EXPORTS
#define MANSOFT_API __declspec(dllexport)
#else
#define MANSOFT_API __declspec(dllimport)
#endif

namespace lc::mansoft {
	class StateManager;
	class Principal;
}

namespace lc::mansoft::object {
	class Object;
	class ObjectACL;
	class ObjectRef;
	class FileObject;
}

namespace lc::mansoft::exception {
	class AccessError;
	class AuthorizationError;
};

namespace lc::mansoft::ui {
	class UIScreen;
	class UITab;
}

namespace lc::mansoft::user {
	class User;
	class UserRef;
}

namespace lc::mansoft::extension {
	class Extension;
}

namespace lc::mansoft::access {
	class AccessKind;
	class AccessController;
	class ObjectOwner;
	class Group;
	class PrincipalRef;
}

namespace lc::mansoft::state {
	class StorageRoot;
	class Storable;
	class ProtectedStorage;
}
