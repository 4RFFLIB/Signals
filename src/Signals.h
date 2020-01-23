#ifndef _SIGNALS_h
#define _SIGNALS_h


template<typename...> class Signals;

//void function parameters
template <>
class Signals<>
{
private:
	bool flag;

public:
	Signals() {
		flag = false;
	}

	template <typename SLOT>
	bool connect(SLOT funcSlot, bool keepsignal=false) {
		if (flag) {
			funcSlot();
			flag = keepsignal;
			return 1;
		}
		return 0;
	}

	template <typename OBJECT, typename SLOT>
	bool connect(OBJECT *obj, SLOT funcSlot, bool keepsignal=false) {
		if (flag) {
			(obj->*funcSlot)();
			flag = keepsignal;
			return 1;
		}
		return 0;
	}

	void emit(void) {
		flag = true;
	}
};

//1 function parameters
template <typename A>
class Signals<A>
{
private:
	A _param1;
	bool flag;

public:
	Signals() {
		flag = false;
	}

	template <typename SLOT>
	bool connect(SLOT funcSlot, bool keepsignal=false) {
		if (flag) {
			funcSlot(_param1);
			flag = keepsignal;
			return 1;
		}
		return 0;
	}

	template <typename OBJECT, typename SLOT>
	bool connect(OBJECT *obj, SLOT funcSlot, bool keepsignal=false) {
		if (flag) {
			(obj->*funcSlot)(_param1);
			flag = keepsignal;
			return 1;
		}
		return 0;
	}

	void emit(A param1) {
		_param1 = param1;
		flag = true;
	}
};

//2 function parameters
template <typename A, typename B>
class Signals<A, B>
{
private:
	A _param1;
	B _param2;
	bool flag;

public:
	Signals() {
		flag = false;
	}

	template <typename SLOT>
	bool connect(SLOT funcSlot, bool keepsignal=false) {
		if (flag) {
			funcSlot(_param1, _param2);
			flag = keepsignal;
			return 1;
		}
		return 0;
	}

	template <typename OBJECT, typename SLOT>
	bool connect(OBJECT *obj, SLOT funcSlot, bool keepsignal=false) {
		if (flag) {
			(obj->*funcSlot)(_param1, _param2);
			flag = keepsignal;
			return 1;
		}
		return 0;
	}

	void emit(A param1, B param2) {
		_param1 = param1;
		_param2 = param2;
		flag = true;
	}
};

#endif
