#pragma once

namespace RSL_core {
using namespace std;

template<typename T, typename ...Args>
static unique_ptr<T> make_unique(Args&& ...args) {
	return unique_ptr<T>(new T(forward<Args>(args)...));
}
}
