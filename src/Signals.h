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
	void connect(SLOT funcSlot, bool keepsignal=false) {
		if (flag) {
			funcSlot();
			flag = keepsignal;
		}
	}

	template <typename OBJECT, typename SLOT>
	void connect(OBJECT *obj, SLOT funcSlot, bool keepsignal=false) {
		if (flag) {
			(obj->*funcSlot)();
			flag = keepsignal;
		}
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
	void connect(SLOT funcSlot, bool keepsignal=false) {
		if (flag) {
			funcSlot(_param1);
			flag = keepsignal;
		}
	}

	template <typename OBJECT, typename SLOT>
	void connect(OBJECT *obj, SLOT funcSlot, bool keepsignal=false) {
		if (flag) {
			(obj->*funcSlot)(_param1);
			flag = keepsignal;
		}
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
	void connect(SLOT funcSlot, bool keepsignal=false) {
		if (flag) {
			funcSlot(_param1, _param2);
			flag = keepsignal;
		}
	}

	template <typename OBJECT, typename SLOT>
	void connect(OBJECT *obj, SLOT funcSlot, bool keepsignal=false) {
		if (flag) {
			(obj->*funcSlot)(_param1, _param2);
			flag = keepsignal;
		}
	}

	void emit(A param1, B param2) {
		_param1 = param1;
		_param2 = param2;
		flag = true;
	}
};

#endif
