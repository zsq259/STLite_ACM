# CMake generated Testfile for 
# Source directory: /home/zsq259/home/STLite_ACM/vector
# Build directory: /home/zsq259/home/STLite_ACM/vector/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test([=[test_four.memcheck]=] "bash" "-c" "/home/zsq259/home/STLite_ACM/vector/build/four.memcheck | diff /home/zsq259/home/STLite_ACM/vector/data/four.memcheck/answer.txt -")
set_tests_properties([=[test_four.memcheck]=] PROPERTIES  _BACKTRACE_TRIPLES "/home/zsq259/home/STLite_ACM/vector/CMakeLists.txt;19;add_test;/home/zsq259/home/STLite_ACM/vector/CMakeLists.txt;0;")
add_test([=[test_four]=] "bash" "-c" "/home/zsq259/home/STLite_ACM/vector/build/four | diff /home/zsq259/home/STLite_ACM/vector/data/four/answer.txt -")
set_tests_properties([=[test_four]=] PROPERTIES  _BACKTRACE_TRIPLES "/home/zsq259/home/STLite_ACM/vector/CMakeLists.txt;19;add_test;/home/zsq259/home/STLite_ACM/vector/CMakeLists.txt;0;")
add_test([=[test_one.memcheck]=] "bash" "-c" "/home/zsq259/home/STLite_ACM/vector/build/one.memcheck | diff /home/zsq259/home/STLite_ACM/vector/data/one.memcheck/answer.txt -")
set_tests_properties([=[test_one.memcheck]=] PROPERTIES  _BACKTRACE_TRIPLES "/home/zsq259/home/STLite_ACM/vector/CMakeLists.txt;19;add_test;/home/zsq259/home/STLite_ACM/vector/CMakeLists.txt;0;")
add_test([=[test_one]=] "bash" "-c" "/home/zsq259/home/STLite_ACM/vector/build/one | diff /home/zsq259/home/STLite_ACM/vector/data/one/answer.txt -")
set_tests_properties([=[test_one]=] PROPERTIES  _BACKTRACE_TRIPLES "/home/zsq259/home/STLite_ACM/vector/CMakeLists.txt;19;add_test;/home/zsq259/home/STLite_ACM/vector/CMakeLists.txt;0;")
add_test([=[test_three.memcheck]=] "bash" "-c" "/home/zsq259/home/STLite_ACM/vector/build/three.memcheck | diff /home/zsq259/home/STLite_ACM/vector/data/three.memcheck/answer.txt -")
set_tests_properties([=[test_three.memcheck]=] PROPERTIES  _BACKTRACE_TRIPLES "/home/zsq259/home/STLite_ACM/vector/CMakeLists.txt;19;add_test;/home/zsq259/home/STLite_ACM/vector/CMakeLists.txt;0;")
add_test([=[test_three]=] "bash" "-c" "/home/zsq259/home/STLite_ACM/vector/build/three | diff /home/zsq259/home/STLite_ACM/vector/data/three/answer.txt -")
set_tests_properties([=[test_three]=] PROPERTIES  _BACKTRACE_TRIPLES "/home/zsq259/home/STLite_ACM/vector/CMakeLists.txt;19;add_test;/home/zsq259/home/STLite_ACM/vector/CMakeLists.txt;0;")
add_test([=[test_two.memcheck]=] "bash" "-c" "/home/zsq259/home/STLite_ACM/vector/build/two.memcheck | diff /home/zsq259/home/STLite_ACM/vector/data/two.memcheck/answer.txt -")
set_tests_properties([=[test_two.memcheck]=] PROPERTIES  _BACKTRACE_TRIPLES "/home/zsq259/home/STLite_ACM/vector/CMakeLists.txt;19;add_test;/home/zsq259/home/STLite_ACM/vector/CMakeLists.txt;0;")
add_test([=[test_two]=] "bash" "-c" "/home/zsq259/home/STLite_ACM/vector/build/two | diff /home/zsq259/home/STLite_ACM/vector/data/two/answer.txt -")
set_tests_properties([=[test_two]=] PROPERTIES  _BACKTRACE_TRIPLES "/home/zsq259/home/STLite_ACM/vector/CMakeLists.txt;19;add_test;/home/zsq259/home/STLite_ACM/vector/CMakeLists.txt;0;")
