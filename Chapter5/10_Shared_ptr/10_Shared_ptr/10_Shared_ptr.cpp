#include <iostream>
#include <memory>

using namespace std;

int main() {
	//shared_ptr
	//{
	//	//shared_ptr 代表的是共享所有权，即多个shared_ptr 可以共享同一块内存
	//	auto wA = shared_ptr<int>(new int(20));
	//	{
	//		auto wA2 = wA;
	//		cout << ((wA2.get() != nullptr) ? (*wA2.get()) : -1) << endl; //20
	//		cout << ((wA.get() != nullptr) ? (*wA.get()) : -1) << endl; //20
	//		cout << wA2.use_count() << endl;  // 引用计数：2
	//		cout << wA.use_count() << endl;  // 2
	//	}
	//	// cout << wA2.use_count() << endl;
	//	cout << wA.use_count << endl;
	//	// shared_ptr 内部是利用引用计数来实现内存的自动管理，每当复制一个shared_ptr，
	//	// 引用计数会+1，当一个shared_ptr 离开作用域，引用计数会-1，
	//	// 当引用计数为0的时候，则delete内存
	//}

	// move 语法
	auto wAA = std::make_shared<int>(30);
	auto wAA2 = std::move(wAA); // 此时 wAA 等于 nullptr， wAA2.use_count()=1
	cout << ((wAA.get() != nullptr) ? (*wAA.get()) : -1) << endl; //-1
	cout << ((wAA2.get() != nullptr) ? (*wAA2.get()) : -1) << endl; //30
	cout << wAA.use_count() << endl; // 0
	cout << wAA2.use_count() << endl; // 1
	// 将wAA对象 move 给 wAA2，意味着 w 放弃了对内存的所有权和管理，此时 wAA 对象等于nullptr
	// 而wAA2获得了对象所有权，但因为此时 wAA 已不再持有对象，因此 wAA2 的引用计数为1
	return 0;
}