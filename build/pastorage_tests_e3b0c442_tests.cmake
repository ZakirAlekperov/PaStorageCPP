add_test([=[PasswordEntryTest.StoresTitle]=]  /Users/zakiralekperov/Documents/PaStorage/build/pastorage_tests [==[--gtest_filter=PasswordEntryTest.StoresTitle]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[PasswordEntryTest.StoresTitle]=]
  PROPERTIES
    
    DEF_SOURCE_LINE [==[/Users/zakiralekperov/Documents/PaStorage/tests/PasswordEntryTest.cpp:28]==]
    WORKING_DIRECTORY [==[/Users/zakiralekperov/Documents/PaStorage/build]==]
    SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==]
    
)
add_test([=[PasswordEntryTest.StoresUsername]=]  /Users/zakiralekperov/Documents/PaStorage/build/pastorage_tests [==[--gtest_filter=PasswordEntryTest.StoresUsername]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[PasswordEntryTest.StoresUsername]=]
  PROPERTIES
    
    DEF_SOURCE_LINE [==[/Users/zakiralekperov/Documents/PaStorage/tests/PasswordEntryTest.cpp:44]==]
    WORKING_DIRECTORY [==[/Users/zakiralekperov/Documents/PaStorage/build]==]
    SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==]
    
)
add_test([=[PasswordEntryTest.UpdatesUsername]=]  /Users/zakiralekperov/Documents/PaStorage/build/pastorage_tests [==[--gtest_filter=PasswordEntryTest.UpdatesUsername]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[PasswordEntryTest.UpdatesUsername]=]
  PROPERTIES
    
    DEF_SOURCE_LINE [==[/Users/zakiralekperov/Documents/PaStorage/tests/PasswordEntryTest.cpp:60]==]
    WORKING_DIRECTORY [==[/Users/zakiralekperov/Documents/PaStorage/build]==]
    SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==]
    
)
add_test([=[PasswordEntryTest.RejectsEmptyTitle]=]  /Users/zakiralekperov/Documents/PaStorage/build/pastorage_tests [==[--gtest_filter=PasswordEntryTest.RejectsEmptyTitle]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[PasswordEntryTest.RejectsEmptyTitle]=]
  PROPERTIES
    
    DEF_SOURCE_LINE [==[/Users/zakiralekperov/Documents/PaStorage/tests/PasswordEntryTest.cpp:81]==]
    WORKING_DIRECTORY [==[/Users/zakiralekperov/Documents/PaStorage/build]==]
    SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==]
    
)
set(pastorage_tests_TESTS [==[PasswordEntryTest.StoresTitle]==] [==[PasswordEntryTest.StoresUsername]==] [==[PasswordEntryTest.UpdatesUsername]==] [==[PasswordEntryTest.RejectsEmptyTitle]==])
