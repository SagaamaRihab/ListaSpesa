cmake_minimum_required(VERSION 3.20)
project(ListaSpesa)

set(CMAKE_CXX_STANDARD 17)

include_directories(src)

add_executable(ListaSpesa
        src/main.cpp
        src/Item.cpp
        src/ShoppingList.cpp
        src/User.cpp
        src/ConsoleObserver.cpp
)

# === GoogleTest ===
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/release-1.12.1.zip
)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(UnitTests
        tests/test_item.cpp
        tests/test_shoppinglist.cpp
        tests/test_user.cpp
        src/Item.cpp
        src/ShoppingList.cpp
        src/User.cpp
        src/ConsoleObserver.cpp
)


target_link_libraries(UnitTests gtest gtest_main)

include(GoogleTest)
gtest_discover_tests(UnitTests)


