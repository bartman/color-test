all:
	cmake -S. -Bbuild -DCMAKE_BUILD_TYPE=Debug
	cmake --build build

clean:
	rm -rf build
