add_executable(engine_test

        main.cpp

)

target_link_libraries(engine_test PRIVATE jupiter_engine SDL3::SDL3)

add_custom_command(TARGET engine_test POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:SDL3::SDL3>
        $<TARGET_FILE_DIR:engine_test>
)