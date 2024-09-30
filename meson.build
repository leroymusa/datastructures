project('datastructures', 'cpp',
    default_options : ['warning_level=3', 'cpp_std=c++20'])

# Compiler setup
cc = meson.get_compiler('cpp')
if cc.get_id() == 'gcc'
    add_project_arguments('-std=c++2a', language : 'cpp')
endif

# Include directory
incdir = include_directories('inc', 'inc/physics', '/usr/include/eigen3')

# GoogleTest subproject setup
gtest_proj = subproject('gtest')
gtest_dep = gtest_proj.get_variable('gtest_dep')

test_srcs = [
    'main.cpp' ,
    'test/SplayTree.cpp' ,
    'test/KruskalTest.cpp' ,
    'test/SuffixTreeTest.cpp' ,
    'test/FibonacciHeapTest.cpp' ,
    'test/PrimsAlgorithmTest.cpp' ,
    'test/TrieTest.cpp' , 
    'test/SegmentTreeTest.cpp' ,
    'test/TreapTest.cpp' ,
    'test/DisjointSetTest.cpp' ,
    'test/BloomFilterTest.cpp' ,
    'test/FenwickTreeTest.cpp' ,
    'test/vEBTreeTest.cpp' ,
    'test/SPHFluidTest.cpp' ,
    'test/AhoCorasickTest.cpp'
]

impl_srcs = [
    'inc/Kruskal.cpp' ,
    'inc/SuffixTree.cpp' ,
    'inc/PrimsAlgorithm.cpp' ,
    'inc/Trie.cpp' ,
    'inc/SegmentTree.cpp' ,
    'inc/DisjointSet.cpp' ,
    'inc/BloomFilter.cpp' ,
    'inc/FenwickTree.cpp' ,
    'inc/vEBTree.cpp' ,
    'inc/physics/main.cpp' , 
    'inc/physics/SPHKernel.cpp' ,
    'inc/physics/FluidSimulator.cpp' ,
    'inc/physics/Particle.cpp' ,
    'inc/AhoCorasick.cpp'
]

test_executable = executable('datastructures_tests',
                            test_srcs + impl_srcs,
                            dependencies : [gtest_dep],
                            include_directories : incdir,
                            c_args : ['-std=c++2a'])

test('DataStructuresTests', test_executable)