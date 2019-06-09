#pragma once

#include <lcmansoft/forward.hpp>

#include <string_view>

namespace lc::mansoft::access {
	enum class PrincipalKind {
		USER, GROUP, SPECIAL
	};
}

namespace lc::mansoft {
	MANSOFT_API class Principal {
	private:
		std::string name;
		access::PrincipalKind type;
	protected:
		Principal(const Principal&) = default;
		Principal(Principal&&) = default;
		Principal(access::PrincipalKind kind, const std::string& name);
		Principal(access::PrincipalKind kind, std::string&& name);
	public:
		virtual ~Principal() = default;
		std::string_view getPrincipalName()const;
		bool isMemberOf(const access::Group&);
	};
}


