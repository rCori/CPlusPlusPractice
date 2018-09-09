default: Sales_item.cpp Sales_item.h Main.cpp
	g++ Sales_item.cpp Main.cpp -o SalesItemTest

test1: Sales_item.cpp Sales_item.h Test1.cpp test1Input
	g++ Sales_item.cpp Test1.cpp -o Test1
	chmod +x Test1
	./Test1 < test1Input
	rm Test1

test2: Sales_item.cpp Sales_item.h Test2.cpp test2Input
	g++ Sales_item.cpp Test2.cpp -o Test2
	chmod +x Test2
	./Test2 < test2Input
	rm Test2
