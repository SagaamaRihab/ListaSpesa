if(EXISTS "C:/ListaSpesa/cmake-build-debug/UnitTests[1]_tests.cmake")
  include("C:/ListaSpesa/cmake-build-debug/UnitTests[1]_tests.cmake")
else()
  add_test(UnitTests_NOT_BUILT UnitTests_NOT_BUILT)
endif()
