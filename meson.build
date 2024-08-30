project('datastructures', 'cpp',
    default_options : ['warning_level=3', 'cpp_std=c++20'])

# Compiler setup
cc = meson.get_compiler('cpp')
if cc.get_id() == 'gcc'
    add_project_arguments('-std=c++2a', language : 'cpp')
endif

# Include directory
incdir = include_directories('inc')

# GoogleTest subproject setup
gtest_proj = subproject('gtest')
gtest_dep = gtest_proj.get_variable('gtest_dep')

# Test source files only (no main application files)
test_srcs = [
    'test/SplayTree.cpp'
]

# Define test executable using GoogleTest
test_executable = executable('splaytree_tests',
                            test_srcs,
                            dependencies : [gtest_dep],
                            include_directories : incdir,
                            c_args : ['-std=c++2a'])

# Register the test
test('SplayTreeTests', test_executable)