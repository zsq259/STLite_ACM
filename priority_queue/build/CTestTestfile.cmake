# CMake generated Testfile for 
# Source directory: /home/zsq259/home/STLite_ACM/priority_queue
# Build directory: /home/zsq259/home/STLite_ACM/priority_queue/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test([=[test_five.memcheck]=] "bash" "-c" "/home/zsq259/home/STLite_ACM/priority_queue/build/five.memcheck | diff /home/zsq259/home/STLite_ACM/priority_queue/data/five.memcheck/answer.txt -")
set_tests_properties([=[test_five.memcheck]=] PROPERTIES  _BACKTRACE_TRIPLES "/home/zsq259/home/STLite_ACM/priority_queue/CMakeLists.txt;19;add_test;/home/zsq259/home/STLite_ACM/priority_queue/CMakeLists.txt;0;")
add_test([=[test_five]=] "bash" "-c" "/home/zsq259/home/STLite_ACM/priority_queue/build/five | diff /home/zsq259/home/STLite_ACM/priority_queue/data/five/answer.txt -")
set_tests_properties([=[test_five]=] PROPERTIES  _BACKTRACE_TRIPLES "/home/zsq259/home/STLite_ACM/priority_queue/CMakeLists.txt;19;add_test;/home/zsq259/home/STLite_ACM/priority_queue/CMakeLists.txt;0;")
add_test([=[test_four.memcheck]=] "bash" "-c" "/home/zsq259/home/STLite_ACM/priority_queue/build/four.memcheck | diff /home/zsq259/home/STLite_ACM/priority_queue/data/four.memcheck/answer.txt -")
set_tests_properties([=[test_four.memcheck]=] PROPERTIES  _BACKTRACE_TRIPLES "/home/zsq259/home/STLite_ACM/priority_queue/CMakeLists.txt;19;add_test;/home/zsq259/home/STLite_ACM/priority_queue/CMakeLists.txt;0;")
add_test([=[test_four]=] "bash" "-c" "/home/zsq259/home/STLite_ACM/priority_queue/build/four | diff /home/zsq259/home/STLite_ACM/priority_queue/data/four/answer.txt -")
set_tests_properties([=[test_four]=] PROPERTIES  _BACKTRACE_TRIPLES "/home/zsq259/home/STLite_ACM/priority_queue/CMakeLists.txt;19;add_test;/home/zsq259/home/STLite_ACM/priority_queue/CMakeLists.txt;0;")
add_test([=[test_one.memcheck]=] "bash" "-c" "/home/zsq259/home/STLite_ACM/priority_queue/build/one.memcheck | diff /home/zsq259/home/STLite_ACM/priority_queue/data/one.memcheck/answer.txt -")
set_tests_properties([=[test_one.memcheck]=] PROPERTIES  _BACKTRACE_TRIPLES "/home/zsq259/home/STLite_ACM/priority_queue/CMakeLists.txt;19;add_test;/home/zsq259/home/STLite_ACM/priority_queue/CMakeLists.txt;0;")
add_test([=[test_one]=] "bash" "-c" "/home/zsq259/home/STLite_ACM/priority_queue/build/one | diff /home/zsq259/home/STLite_ACM/priority_queue/data/one/answer.txt -")
set_tests_properties([=[test_one]=] PROPERTIES  _BACKTRACE_TRIPLES "/home/zsq259/home/STLite_ACM/priority_queue/CMakeLists.txt;19;add_test;/home/zsq259/home/STLite_ACM/priority_queue/CMakeLists.txt;0;")
add_test([=[test_three.memcheck]=] "bash" "-c" "/home/zsq259/home/STLite_ACM/priority_queue/build/three.memcheck | diff /home/zsq259/home/STLite_ACM/priority_queue/data/three.memcheck/answer.txt -")
set_tests_properties([=[test_three.memcheck]=] PROPERTIES  _BACKTRACE_TRIPLES "/home/zsq259/home/STLite_ACM/priority_queue/CMakeLists.txt;19;add_test;/home/zsq259/home/STLite_ACM/priority_queue/CMakeLists.txt;0;")
add_test([=[test_three]=] "bash" "-c" "/home/zsq259/home/STLite_ACM/priority_queue/build/three | diff /home/zsq259/home/STLite_ACM/priority_queue/data/three/answer.txt -")
set_tests_properties([=[test_three]=] PROPERTIES  _BACKTRACE_TRIPLES "/home/zsq259/home/STLite_ACM/priority_queue/CMakeLists.txt;19;add_test;/home/zsq259/home/STLite_ACM/priority_queue/CMakeLists.txt;0;")
add_test([=[test_two.memcheck]=] "bash" "-c" "/home/zsq259/home/STLite_ACM/priority_queue/build/two.memcheck | diff /home/zsq259/home/STLite_ACM/priority_queue/data/two.memcheck/answer.txt -")
set_tests_properties([=[test_two.memcheck]=] PROPERTIES  _BACKTRACE_TRIPLES "/home/zsq259/home/STLite_ACM/priority_queue/CMakeLists.txt;19;add_test;/home/zsq259/home/STLite_ACM/priority_queue/CMakeLists.txt;0;")
add_test([=[test_two]=] "bash" "-c" "/home/zsq259/home/STLite_ACM/priority_queue/build/two | diff /home/zsq259/home/STLite_ACM/priority_queue/data/two/answer.txt -")
set_tests_properties([=[test_two]=] PROPERTIES  _BACKTRACE_TRIPLES "/home/zsq259/home/STLite_ACM/priority_queue/CMakeLists.txt;19;add_test;/home/zsq259/home/STLite_ACM/priority_queue/CMakeLists.txt;0;")
