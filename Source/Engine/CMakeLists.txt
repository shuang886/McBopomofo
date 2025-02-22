cmake_minimum_required(VERSION 3.6)
project(McBopomofoLMLib)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(gramambular2)

include_directories("Gramambular")
add_library(McBopomofoLMLib
        AssociatedPhrases.h
        AssociatedPhrases.cpp
        KeyValueBlobReader.cpp
        KeyValueBlobReader.h
        ParselessPhraseDB.cpp
        ParselessPhraseDB.h
        ParselessLM.cpp
        ParselessLM.h
        PhraseReplacementMap.h
        PhraseReplacementMap.cpp
        UserOverrideModel.h
        UserOverrideModel.cpp
        UserPhrasesLM.h
        UserPhrasesLM.cpp)

# Let CMake fetch Google Test for us.
# https://github.com/google/googletest/tree/main/googletest#incorporating-into-an-existing-cmake-project
include(FetchContent)

FetchContent_Declare(
        googletest
        # Specify the commit you depend on and update it regularly.
        URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Test target declarations.
add_executable(McBopomofoLMLibTest
        KeyValueBlobReaderTest.cpp
        ParselessLMTest.cpp
        ParselessPhraseDBTest.cpp
        PhraseReplacementMapTest.cpp
        UserOverrideModelTest.cpp
        UserPhrasesLMTest.cpp)
target_link_libraries(McBopomofoLMLibTest gtest_main McBopomofoLMLib gramambular2_lib)
include(GoogleTest)
gtest_discover_tests(McBopomofoLMLibTest)

add_custom_target(
        runMcBopomofoLMLibTest
        COMMAND ${CMAKE_CURRENT_BINARY_DIR}/McBopomofoLMLibTest
)
add_dependencies(runMcBopomofoLMLibTest McBopomofoLMLibTest)

# Benchmark target; to run, manually uncomment the lines below.
#
# find_package(benchmark)
# add_executable(ParselessLMBenchmark
#         ParselessLMBenchmark.cpp)
# target_link_libraries(ParselessLMBenchmark McBopomofoLMLib benchmark::benchmark)
