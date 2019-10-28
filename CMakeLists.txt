cmake_minimum_required(VERSION 3.15)
project(SDA)

set(CMAKE_CXX_STANDARD 17)

add_executable(SDA main.cpp src/EcOrdin2.cpp include/EcOrdin2.h include/Program.h src/Matrice.cpp include/Matrice.h src/Prime.cpp include/Prime.h src/Meniu.cpp include/Meniu.h include/SelectionSort.h src/SelectionSort.cpp include/BubbleSort.h src/BubbleSort.cpp  src/MergeSort.cpp include/MergeSort.h include/Sortari.h include/Diverse.h include/QuickSort.h src/QuickSort.cpp include/CountingSort.h src/CountingSort.cpp include/Unelte.h src/Unelte.cpp src/ShellSort.cpp include/ShellSort.h src/RadixSort.cpp include/RadixSort.h src/RadixSortIntregi.cpp include/RadixSortIntregi.h)
